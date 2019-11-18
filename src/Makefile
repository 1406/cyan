CC=gcc
CFLAGS=-Wall -O2
TARGET=cyan
OBJECT=main.o

.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECT)