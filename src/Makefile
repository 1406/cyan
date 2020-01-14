CC := gcc
CFLAGS := -Wall -O2 -g
TARGET := cyan.elf
SOURCE := $(wildcard *.c)
OBJECT := $(SOURCE:.c=.o)

.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: install
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/cyan

.PHONY: clean
clean:
	-rm -f $(TARGET) $(OBJECT)
