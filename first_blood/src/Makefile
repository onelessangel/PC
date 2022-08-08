# Stroe Teodora - 311CA

CC = gcc
CFLAGS = -Wall -Wextra

TARGETS = ninel vectsecv codeinvim nomogram

build: $(TARGETS)

ninel: ninel.c
		$(CC) ninel.c -o ninel $(CFLAGS)

vectsecv: vectsecv.c
		$(CC) vectsecv.c -o vectsecv $(CFLAGS)

codeinvim: codeinvim.c
		$(CC) codeinvim.c -o codeinvim $(CFLAGS)
		
nomogram: nomogram.c
		$(CC) nomogram.c -o nomogram $(CFLAGS)

pack:
		zip -r 311CA_TeodoraStroe_Tema1.zip *.c *.h Makefile README

clean:
		rm -f $(TARGETS)

.PHONY:
		pack clean build
