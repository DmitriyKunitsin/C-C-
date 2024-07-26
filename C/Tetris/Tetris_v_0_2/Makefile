GCC=gcc
CFLAG= -Wall -Werror -Wextra
NCURSES=-lncurses
GAME_C=src/*.c
NAME_GAME=./out/game_tetris



game:
	$(GCC) $(CFLAG) $(GAME_C) $(NCURSES) -o $(NAME_GAME)
	$(NAME_GAME)


clang:
	clang-format -n ./src/*.c
	clang-format -i ./src/*.c


clean:
	rm -rf $(NAME_GAME)