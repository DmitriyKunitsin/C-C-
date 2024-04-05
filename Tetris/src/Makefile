CC = gcc
CFLAGS = -Wall -Werror -Wextra
CURSES = -lncurses


TARGET = app
SRC = main.c

.PHONY: format

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(CURSES)

format:
	clang-format -n -style=file $(SRC)
	clang-format -i -style=file $(SRC)

rebuild: clean go


go: $(TARGET) format
	./app

clean:
	rm -rf $(TARGET)
