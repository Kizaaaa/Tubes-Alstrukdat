main: 
	gcc main.c ADT/EntryMachine/entrymachine.c ADT/EntryMachine/charmachine.c ADT/Graf/graf.c ADT/Kicau/kicau.c ADT/ListProfil/listprofil.c Program/Pcolor/pcolor.c ADT/DateTime/datetime.c ADT/DateTime/time.c Program/Draf/Draf.c Program/Pcolor/pcolor.c boolean.h -o main

driverdatetime:
	gcc ADT/DateTime/datetime.c ADT/DateTime/time.c -o driverdatetime

driverentrymachine:
	gcc ADT/EntryMachine/charmachine.c ADT/EntryMachine/entrymachine.c -o driverentrymachine

drivergraf:
	gcc ADT/Graf/graf.c -o drivergraf

driverkicau:
	gcc ADT/Kicau/kicau.c -o driverkicau

driverlinkedlist:
	gcc ADT/LinkedList/listlinier.c -o driverlinkedlist

driverlinkedliststack:
	gcc ADT/LinkedListStack/LLStackD.c -o driverlinkedliststack

driverlinkedlisttweet:
	gcc ADT/LinkedListTweet/listliniertweet.c -o driverlinkedlisttweet

driverlistdin:
	gcc ADT/ListDin/listdin.c -o driverlistdin

driverlistdintweet:
	gcc ADT/ListDinLLTweet/listdintweet.c -o driverlistdintweet

driverprofil:
	gcc ADT/ListProfil/listprofil.c -o driverprofil

driverstatic:
	gcc ADT/Static/Static.c -o driverstatic

driverstack:
	gcc ADT/Stack/stack.c -o driverstack

driverstackdraf:
	gcc ADT/StackDraf/stackdraf.c -o driverstackdraf

drivertree:
	gcc ADT/Tree/tree.c -o drivertree
	
driverutas:
	gcc ADT/Utas/utas.c -o driverutas









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

# UNIT TESTS MATRIX

SRC_MATRIX = ADT/Matrix/matrix.c
SRC_TEST = ADT/Matrix/tests/mmatrix.c
OBJ_MATRIX = $(SRC_MATRIX:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Matrix/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mmatrix: $(OBJ_MATRIX) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_matrix: mmatrix $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mmatrix
	@if ./mmatrix < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UNIT TESTS PROFILE

SRC_PROFILE = ADT/Matrix/profile.c
SRC_TEST = ADT/Matrix/tests/mprofile.c
OBJ_PROFILE = $(SRC_PROFILE:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Matrix/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mprofile: $(OBJ_PROFILE) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_profile: mprofile $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mprofile
	@if ./mprofile < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UNIT TESTS QUEUE

SRC_QUEUE = ADT/Queue/queue.c
SRC_TEST = ADT/Queue/tests/mqueue.c
OBJ_QUEUE = $(SRC_QUEUE:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Queue/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mqueue: $(OBJ_QUEUE) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_queue: mqueue $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mqueue
	@if ./mqueue < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UNIT TESTS STACK

SRC_STACK = ADT/Stack/stack.c
SRC_TEST = ADT/Stack/tests/mstack.c
OBJ_STACK = $(SRC_STACK:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Stack/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mstack: $(OBJ_STACK) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_stack: mstack $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mstack
	@if ./mstack < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


# UNIT TESTS TREE

SRC_TREE = ADT/Tree/tree.c
SRC_TEST = ADT/Tree/tests/mtree.c
OBJ_TREE = $(SRC_TREE:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Tree/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mtree: $(OBJ_TREE) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_tree: mtree $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mtree
	@if ./mtree < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UNIT TESTS UTAS

SRC_UTAS = ADT/Utas/utas.c
SRC_TEST = ADT/Utas/tests/mutas.c
OBJ_UTAS = $(SRC_UTAS:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Utas/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mutas: $(OBJ_UTAS) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_utas: mutas $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mutas
	@if ./mutas < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


# UNIT TESTS GRAF

SRC_GRAF = ADT/Graf/graf.c
SRC_TEST = ADT/Graf/tests/mgraf.c
OBJ_GRAF = $(SRC_GRAF:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Graf/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mgraf: $(OBJ_GRAF) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_graf: mgraf $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mgraf
	@if ./mgraf < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@
