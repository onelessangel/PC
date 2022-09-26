CC = gcc
CFLAGS = -I.

TARGET = image_editor

build: $(TARGET)

$(TARGET): *.c *.h
	$(CC) -o $@ $^ $(CFLAGS)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)

pack:
	zip -r 311CA_StroeTeodora_Tema3.zip *.c *.h Makefile README

.PHONY: build run clean pack
