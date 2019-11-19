CC=gcc
CFLAGS=-Wall -O2 -g
TARGET=cyan.elf
OBJECT=main.o lexer.o

.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECT)
