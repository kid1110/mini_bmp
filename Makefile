CC:=clang
CCFLAGS?= -std=c17 -Wall -Wextra -Werror -g -IInclude

TARGET:=mini-image

SRC := \
	src/main.c \
	src/bmp.c \
	src/bmpinfo.c

OBJ = \
	build/main.o \
	build/bmp.o \
	build/bmpinfo.o
ifeq ($(OS),Windows_NT)
	CC := gcc
	RM:= del /Q
	TARGET := $(TARGET).exe
else
	RM:= rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/main.o: src/main.c
	$(CC) $(CCFLAGS) -c $< -o $@
build/bmp.o: src/bmp.c
	$(CC) $(CCFLAGS) -c $< -o $@
build/bmpinfo.o: src/bmpinfo.c
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -rf build/*.o $(TARGET)

.PHONY: all clean
