##
## Makefile per BlueC
## (C) 2011 Fabian Priftaj <fmp@linuxmail.org>
##

## Directory
SRC	= ./src
INC	= $(SRC)/include
LST	= $(SRC)/list
LIB	= $(SRC)/lib
DEP	= $(SRC) $(INC) $(LST) $(LIB)

CC	      = gcc
DEFINE	= -D_GNU_SOURCE -D__FORTIFY_SOURCE=2 -D__VERBOSE
DEBUG		= -g -ggdb -O2
LIBRARY	= -lbluetooth
OPTIONS	= -W -Wall -pedantic -std=c99
CFLAGS	= -I$(SRC) -I$(LST) -I$(LIB) -I$(INC) $(DEFINE) $(DEBUG) $(OPTIONS) -c
LFLAGS	= -o

all:	   bluec

debug:	CFLAGS := -D__DEBUG__ $(CFLAGS)
debug:	all


## COMPILING
%.o:		$(SRC)/%.c
			$(CC) $(CFLAGS) $(SRC)/$*.c

%.o:		$(LST)/%.c
			$(CC) $(CFLAGS) $(LST)/$*.c

%.o: 		$(LIB)/%.c
			$(CC) $(CFLAGS) $(LIB)/$*.c

## LINKING
bluec:		bluec.o support.o usage.o device.o devlist.o
				$(CC) $(LFLAGS) bluec bluec.o support.o usage.o device.o devlist.o $(LIBRARY)

## CLEANING
clean:
		rm -f *~ *.o *.c~ core* *.stackdump bluec

