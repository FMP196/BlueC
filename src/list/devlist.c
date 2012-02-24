/**
 * devlist.c
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
#include <string.h>
//--
#include <devlist.h>

/* devlist_addnew()
 * add a new device into the device list
 */
int devlist_addnew(struct devlist_t **list, struct device_t device)
{
	struct devlist_t *temp;
	if ((temp = (struct devlist_t*)malloc(sizeof(struct devlist_t))) == NULL)
		return (-1);
	
	strncpy(temp->device.name, device.name, strlen(device.name));
	strncpy(temp->device.macaddr, device.macaddr, strlen(device.macaddr));

	temp->next = (*list);
	(*list) = temp;

	return (1);
}

/* devlist_destroy
 * remove all devices from the device list
 */
void devlist_destory(struct devlist_t **list)
{
	// TODO
}

/* devlist_print()
 * test-function: prints all elements inside the device list
 */
void devlist_print(struct devlist_t *devlist)
{
	int index = 0;
	fprintf(stdout, "Bluetooth device list\nNo.\tName\tMAC Address\n");
	while (devlist != NULL)
	{
		fprintf(stdout, "%d.\t%s\t%s\n", ++index, devlist->device.name, devlist->device.macaddr);
		devlist = devlist->next;
	}
	fprintf(stdout, "\n%d devices found!\n\n", index);
}
