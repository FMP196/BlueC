/**
 * scan.c
 *
 * This software is part of BlueC.
 * Copyright (C) 2011 Fabian Priftaj <fmp@linuxmail.org>
 *
 * BlueC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
//---
#include <device.h>
#include <devlist.h>
#include <support.h>

/* device_scan()
 * scan for bluetooth devices
 */
int device_scan(struct devlist_t **devlist)
{
	struct device_t device;
	inquiry_info *inquiry = NULL;

	int devno;           /* number of discovered devices */
	int device_id;       /* device number identifier */
	int sd;              /* socket descriptor */
	int i;
	
	/* get resource number of the first available local
	 * bluetooth adapter */
	if ((device_id = hci_get_route(NULL)) < 0)
		return (-1);
	
	/* open a bluetooth socket with the specified local
	 * device (id) number */
	if ((sd = hci_open_dev(device_id)) < 0)
		return (-1);

	if ((inquiry = (inquiry_info*)malloc(MAX_DEVICE_NUMBERS * sizeof(inquiry_info))) == NULL)
		return (-1);
	
	/* start device discovery */
	if ((devno = hci_inquiry(device_id, MAX_TIMELEN_QUERY, MAX_DEVICE_NUMBERS, NULL, &inquiry, IREQ_CACHE_FLUSH)) < 0)
		return (-1);
	
	for (i=0; i<devno; i++)
	{
		memset(&device.name, 0x00, sizeof(device.name));
		memset(&device.macaddr, 0x00, sizeof(device.macaddr));
		
		/* get the user-friendly name of the device */
		if (hci_read_remote_name(sd, &(inquiry+i)->bdaddr, sizeof(device.name), device.name, 0) < 0)
			strcpy(device.name, "[unknown]");
		
		/* converts a MAC device address to a string */
		ba2str(&(inquiry+i)->bdaddr, device.macaddr);
		
		/* add device to list */
		devlist_addnew(devlist, device);
	}
	
	free(inquiry);
	close(sd);
	
	return (1);
}
