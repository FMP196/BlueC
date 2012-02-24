/**
 * devlist.h
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

#ifndef __DEVLIST_H__
#define __DEVLIST_H__

#include <stdbool.h>
//---
#include <lib/struct.h>

int devlist_addnew(struct devlist_t **list, struct device_t device);
int devlist_union(struct devlist_t **list, struct devlist_t *devlist);
void devlist_remove(struct devlist_t **list, struct device_t *device);
bool devlist_exists(struct devlist_t **list, struct device_t *device);
void devlist_destory(struct devlist_t **list);
void devlist_print(struct devlist_t *list);

#endif /*__DEVLIST_H__*/
