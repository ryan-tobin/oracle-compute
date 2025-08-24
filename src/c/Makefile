CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99 -fPIC
INCLUDES = -I../../include
SRCDIR = .
SOURCES = oracle_core.c temporal_engine.c prediction_kernel.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = liboracle.a

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

test: $(TARGET)
	$(CC) $(CFLAGS) $(INCLUDES) -L. -o test_oracle ../../tests/unit/test_core.c -loracle
	./test_oracle

install: $(TARGET)
	cp $(TARGET) /usr/local/lib/
	cp ../../include/oracle/*.h /usr/local/include/