CC = gcc
CFLAGS=-std=c11# -Wall -Werror -Wextra
SRC=s21_matrix.c
TESTS=../tests/*.c
FLAG_TEST=-lcheck -lm -lsubunit
SRCS=$(wildcard s21_*.c)
OBJS=$(SRCS:.c=.o)


format:
	clang-format -n -style=file $(SRC)
	clang-format -i -style=file $(SRC)

s21_matrix.a:$(OBJS)
	@ar -rc s21_matrix.a $^
	@ranlib s21_matrix.a
	@rm -rf *.o

test: clean s21_matrix.a
	@gcc --coverage $(CFLAGS) $(TESTS) s21_matrix.a $(FLAG_TEST) -o test -g
	@./test

clean:
	@-rm -rf *.o *.gcno *.gcda *.info  test s21_matrix.a gcov_report report greport a.out *.txt *.dSYM
 