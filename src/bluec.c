/**
 * bluec.c
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
#include <stdbool.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
//--
#include <list/devlist.h>
#include <support.h>
#include <lib/device.h>
#include <usage.h>
#include <lib/struct.h>


int main(int argc, char *argv[])
{
	int choice;
	bool toprint = false;
	struct devlist_t *devlist = NULL;

	while (true)
	{
		int index = 0;
		static struct option long_options[] = ARG_LONG_OPTIONS;
		
		if ((choice = getopt_long(argc, argv, "hVt:sl:", long_options, &index)) == -1)
			break;
		
		switch (choice) {
			case 'V':
				fprintf(stderr, "%s: '-V' function is not yet implemented\n", argv[0]);
				break;
			case 't':
				fprintf(stderr, "%s: '-t' function is not yet implemented\n", argv[0]);
				break;
			case 's':
				fprintf(stdout, "\nScanning bluetooth start ... \n");
				device_scan(&devlist);
				devlist_print(devlist);
				break;
			case 'l':
				fprintf(stderr, "%s: '-l' function not yet implemented\n", argv[0]);
				break;
			case 'h':
			case '?':
			default:
				toprint = true;
				break;
		}
	}

	/* invalid args */
	if (optind < argc) {
		fprintf(stdout, "%s: invalid argument: ", argv[0]);
		while (optind < argc)
			fprintf(stdout, "'%s' ", argv[optind++]);
		fprintf(stdout, "\n");
		toprint = true;
	}
	else if (optind == 1)
		toprint = true;
	
	if (toprint)
		usage(argv[0]);
	
	return (EXIT_SUCCESS);
}
