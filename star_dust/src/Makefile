CC = gcc
CFLAGS = -Wall -Wextra -I.

TARGET = star_dust

build: $(TARGET)

star_dust: star_dust.c
	$(CC) -o $@ $^ $(CFLAGS)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)

pack:
	zip -r 311CA_StroeTeodora_Tema2.zip *.c *.h Makefile README

.PHONY: build run clean pack