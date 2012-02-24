/**
 * struct.c
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __STRUCT_H__
#define __STRUCT_H__

#define  MAX_DEVICE_NUMBERS  255     /* max. number of discovered devices */
#define  MAX_TIMELEN_QUERY   10      /* the inquiry lasts for at most (1.28 * MAX_TIMELEN_QUERY) seconds*/

/* device struct */
typedef struct device_t
{
	char name[50];      /* device name */
	char macaddr[20];   /* MAC address */
} device_t;


/* list of devices */
typedef struct devlist_t
{
	struct device_t device;
	struct devlist_t *next;
} devlist_t;


#endif /*__STRUCT_H__*/
