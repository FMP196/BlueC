/**
 * usage.c
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
#include <usage.h>


/* usage()
 * shows all arguments that can be passed to the program
 */
void usage(char *progname)
{
	fprintf(stdout, "bluec - bluetooth scanning for nearby devices\n"
	                "Usage:  %s [options] ...\n"
	                "Where options are:\n"
	                " -h, --help       display this message and exit\n"
	                " -V, --verbose    verbose mode activated\n"
	                " -s, --scan       scan for nearby bluetooth devices\n"
	                " -l, --log FILE   device logging\n"
	                " -t, --time SEC   time to wait for the scanning\n"
	                "\n", progname);
}
