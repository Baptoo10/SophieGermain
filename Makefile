CC ?= gcc

CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
  -Wshadow -Wpointer-arith -mavx2 -mpopcnt -maes -mbmi2 \
  -march=native -mtune=native -O3

HEADER = SophieGermain.h
SOURCES = SophieGermain.c

sophiegermain: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ -lgmp


all: sophiegermain

.PHONY: clean

clean:
	rm -f sophiegermain
