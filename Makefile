ASM=nasm
ASMFLAGS=-f elf64 -g -F dwarf

CC=gcc
LDFLAGS=-lX11

SRC=src/main.asm src/x11.asm src/event.asm src/render.asm
OBJ=$(SRC:src/%.asm=build/%.o)

BIN=PixelPoint

all: $(BIN)

build/%.o: src/%.asm
	mkdir -p build
	$(ASM) $(ASMFLAGS) $< -o $@

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(BIN)

clean:
	rm -rf build $(BIN)

test:
	$(CC) test/main.c -lX11 -o build/test/x11_test
