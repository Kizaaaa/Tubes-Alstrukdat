CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mdatetime

main_program: $(OBJ_MAIN) $(OBJ_DATETIME)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mdatetime $(OBJ_MAIN) $(OBJ_DATETIME) $(OBJ_TEST) $(TEST_RESULTS)

# UNIT TESTS 
################### UNIT TEST DATETIME ###################
SRC_DATETIME = ADT/DateTime/datetime.c
SRC_TEST = ADT/DateTime/tests/mdatetime.c
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/DateTime/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mdatetime: $(OBJ_DATETIME) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_datetime: mdatetime $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mdatetime
	@if ./mdatetime < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

################### UNIT TEST DRAFT ###################
SRC_DRAFT = ADT/Draft/draft.c
SRC_TEST = ADT/Draft/tests/mdraft.c
OBJ_DRAFT = $(SRC_DRAFT:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Draft/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mdraft: $(OBJ_DRAFT) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_draft: mdraft $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mdraft
	@if ./mdraft < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

################### UNIT TEST ENTRYMACHINE ###################
SRC_ENTRYMACHINE = ADT/Entrymachine/entrymachine.c
SRC_TEST = ADT/Entrymachine/tests/mentrymachine.c
OBJ_ENTRYMACHINE = $(SRC_ENTRYMACHINE:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Entrymachine/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mentrymachine: $(OBJ_ENTRYMACHINE) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_entrymachine: mentrymachine $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mentrymachine
	@if ./mentrymachine < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@