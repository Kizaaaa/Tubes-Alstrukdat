CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mfoo

main_program: $(OBJ_MAIN) $(OBJ_FOO)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mfoo $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

# UNIT TESTS
SRC_FOO = ADT/Foo/foo.c
SRC_TEST = ADT/Foo/tests/mfoo.c
OBJ_FOO = $(SRC_FOO:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Foo/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mfoo: $(OBJ_FOO) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_foo: mfoo $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mfoo
	@if ./mfoo < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

######### UNIT TEST ENTRYMACHINE #########
SRC_ADT = $(SRC_CHAR) $(SRC_ENTRY) $(SRC_PCOLOR)
OBJ_ADT = $(SRC_ADT:.c=.o)

SRC_CHAR = ADT/EntryMachine/charmachine.c
SRC_ENTRY = ADT/EntryMachine/entrymachine.c

SRC_PCOLOR = ADT/pcolor/pcolor.c

OBJ_CHAR = $(SRC_CHAR:.c=.o)
OBJ_ENTRY = $(SRC_ENTRY:.c=.o)


entrymachine: $(OBJ_CHAR) $(OBJ_ENTRY)
	$(CC) $(CFLAGS) -o $@ $^ 


adt: $(OBJ_ADT)
	$(CC) $(CFLAGS) -o $@  main.c $(SRC_ADT)