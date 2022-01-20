CFLAGS=-g -O0 -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror
VFLAGS=--leak-check=full --track-origins=yes --show-reachable=yes
SRC_C_FILES=$(wildcard src/*.c)
SRC_H_FILES=$(wildcard src/*.h)
TEST_C_FILES=$(wildcard test/*.c)
TEST_H_FILES=$(wildcard test/*.h)

wordsort.o: $(SRC_C_FILES) $(SRC_H_FILES)
	gcc $(CFLAGS) -o $@ $<

tests.o: $(TEST_C_FILES) $(SRC_C_FILES) $(TEST_H_FILES) $(SRC_H_FILES)
	gcc $(CFLAGS) -o $@ $(TEST_C_FILES) $(SRC_C_FILES)

clean:
	rm $(wildcard *.o)

valgrind: wordsort.o
	valgrind $(VFLAGS) $(realpath $<)

test: tests.o
	valgrind $(VFLAGS) $(realpath $<)
