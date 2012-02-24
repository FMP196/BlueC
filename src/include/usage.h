/**
 * usage.h
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


#ifndef __USAGE_H__
#define __USAGE_H__

#define ARG_LONG_OPTIONS {{"help",    no_argument, 0, 'h'},\
                          {"verbose", no_argument, 0, 'V'},\
                          {"scan",    no_argument, 0, 's'},\
                          {"log",     required_argument, 0, 'l'},\
                          {"time",    required_argument, 0, 't'},\
                          {0,0,0,0},\
                          {0,0,0,0}};


void usage(char *progname);

#endif /*__USAGE_H__*/
