GCC=gcc
CFLAG= -Wall -Werror -Wextra -std=c11 -Wpedantic
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
NCURSES=-lncurses
GAME_C=src/*.c
NAME_GAME=./$(BUILD_DIR)/game_tetris
GUI := gui/cli/game_frontend.c
SRC := ./brick_game/tetris/src
BUILD_DIR := build
DOCS_DIR := docs
DIST_DIR := dist
TESTS_DIR := tests
REPORT_DIR := report
BIN_DIR := bin

OS := $(shell uname -s)


ifeq ($(OS), Darwin)
	LIB_FLAGS := $(shell pkg-config --static --cflags --libs check ncurses)
else
	LIB_FLAGS :=  -I/src/brick_game/tetris/inc -L/build/ -lcheck -lsubunit -lncurses -lm
endif

all: install

install: tetris.a | build_dir
	@mkdir -p $(BIN_DIR)
	doxygen
	$(GCC) $(CFLAG) game.c $(GUI) $(NCURSES) $(BUILD_DIR)/tetris.a -o $(BIN_DIR)/game_tetris $(LIB_FLAGS)

tetris.a: build_dir
	$(GCC) $(CFLAG) -c $(SRC)/defines.c $(NCURSES) -o $(BUILD_DIR)/def.o
	$(GCC) $(CFLAG) -c $(SRC)/fsm.c $(NCURSES) -o $(BUILD_DIR)/fsm.o
	$(GCC) $(CFLAG) -c $(SRC)/game_backend.c $(NCURSES) -o $(BUILD_DIR)/game_backend.o
	$(GCC) $(CFLAG) -c $(SRC)/objects.c $(NCURSES) -o $(BUILD_DIR)/objects.o
	$(GCC) $(CFLAG) -c gui/cli/game_frontend.c $(NCURSES) -o $(BUILD_DIR)/frontend.o -g
	ar rc $(BUILD_DIR)/tetris.a $(BUILD_DIR)/*.o
	ranlib $(BUILD_DIR)/tetris.a
	rm -rf $(BUILD_DIR)/*.o

uinstall:
	rm -rf $(DOCS_DIR) $(BUILD_DIR)

build_dir: 
	mkdir -p $(BUILD_DIR)

dist_dir:
	mkdir -p $(DIST_DIR)	

dist: dist_dir 
	tar cf $(DIST_DIR)/tetris-1.0.tar $(BUILD_DIR) $(DOCS_DIR)

dvi:
	cd docs/html && open index.html	

test: 
	$(GCC) $(CFLAG) $(TESTS_DIR)/tetris_cli_tests.c brick_game/tetris/src/tetris_test.c $(BUILD_DIR)/tetris.a -o $(TESTS_DIR)/tetris_test $(LIB_FLAGS)
	./$(TESTS_DIR)/tetris_test

gcov_report:
	$(GCC) $(CFLAG) $(GCOV_FLAGS) -c $(SRC)/defines.c $(NCURSES) -o $(BUILD_DIR)/def.o
	$(GCC) $(CFLAG) $(GCOV_FLAGS) -c $(SRC)/fsm.c $(NCURSES) -o $(BUILD_DIR)/fsm.o
	$(GCC) $(CFLAG) $(GCOV_FLAGS) -c $(SRC)/game_backend.c $(NCURSES) -o $(BUILD_DIR)/game_backend.o
	$(GCC) $(CFLAG) $(GCOV_FLAGS) -c $(SRC)/objects.c $(NCURSES) -o $(BUILD_DIR)/objects.o
	ar rc $(BUILD_DIR)/tetris.a $(BUILD_DIR)/*.o
	ranlib $(BUILD_DIR)/tetris.a
	rm -rf $(BUILD_DIR)/tetris.o
	$(GCC) $(CFLAG) $(TESTS_DIR)/tetris_cli_tests.c $(SRC)/tetris_test.c $(BUILD_DIR)/tetris.a -o $(TESTS_DIR)/tetris_test $(LIB_FLAGS) -lgcov
	./$(TESTS_DIR)/tetris_test
	rm -rf $(REPORT_DIR)
	mkdir $(REPORT_DIR)
	lcov -o $(REPORT_DIR)/testing.info -c -d .
	genhtml -o report $(REPORT_DIR)/testing.info
	open $(REPORT_DIR)/index.html

valgrind-test :
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s --track-origins=yes $(TESTS_DIR)/tetris_test


format : check
	clang-format --style=file:"../materials/linters/.clang-format" -i */*.c */*/*/*.c 

check :
	@clang-format --style=file:"../materials/linters/.clang-format" -n */*.c */*/*/*.c 



clang:
	clang-format -n /*.c
	clang-format -i /*.c


clean:
	@rm -rf $(NAME_GAME)
	@rm -rf $(BIN_DIR)
	@rm -rf $(BUILD_DIR)/*
	@rm -rf $(DOCS_DIR)
	@rm -rf $(DIST_DIR)
	@rm -rf $(BUILD_DIR)
	@rm -rf $(REPORT_DIR)
	@rm -rf $(TESTS_DIR)/tetris_test
	@rm -rf records.txt