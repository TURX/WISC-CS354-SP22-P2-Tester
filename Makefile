UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MY_CC := gcc
endif
ifeq ($(UNAME_S), Darwin)
	MY_CC := clang
endif

all: a.out
run: a.out
	./a.out <in.txt
test: test.out
	./test.out <test/in.txt >test/out.txt
	diff test/out.txt test/ans.txt
a.out: enigma_functions.c enigma_driver.c
	$(MY_CC) -g enigma_functions.c enigma_driver.c -Wall
test.out: enigma_functions.c tester.c
	$(MY_CC) -g enigma_functions.c tester.c -Wall -o test.out
clean:
	@rm -rf a.out a.out.dSYM test.out test.out.dSYM test/in.txt test/out.txt test/ans.txt
