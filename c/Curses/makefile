PROG=window
all:    $(PROG)
CC=gcc
INCLUDE=/usr/include/curses
MODULE=curses
CFLAGS=-g -Wall -ansi
%:  %.c ;   $(CC) $(CFLAGS) -I$(INCLUDE) -o$@ $< -l$(MODULE)
clean:  ;   rm  $(PROG)