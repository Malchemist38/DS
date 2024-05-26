CC = gcc
CFLAGS = -Wall -std=gnu99

SRC_FILES = $(wildcard *.c)

EXECUTABLES = $(patsubst %.c, %, $(SRC_FILES))

all: $(EXECUTABLES)

%: %.c
        $(CC) $(CFLAGS) $< -o $@

clean:
        rm -f $(EXECUTABLES)

.PHONY: all clean