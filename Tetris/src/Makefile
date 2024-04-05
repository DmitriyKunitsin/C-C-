CC = gcc
CFLAGS = -Wall -Werror -Wextra
CURSES = -lncurses

BUILD_DIR = build

TARGET = $(BUILD_DIR)/app
SRC = main.c
FIGURE = figures/figuresForGames.c
MENU = menu/menu_for_game.c
COMMON = includes/common.h

OBJECTS = $(BUILD_DIR)/$(notdir $(FIGURE:.c=.o)) $(BUILD_DIR)/$(notdir $(MENU:.c=.o))

.PHONY: format clean all

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(OBJECTS) $(CURSES)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(notdir $(FIGURE:.c=.o)): $(FIGURE) $(COMMON) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(notdir $(MENU:.c=.o)): $(MENU) $(COMMON) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

format:
	clang-format -n -style=file $(SRC)
	clang-format -i -style=file $(SRC)

rebuild: clean all go

go: $(TARGET) format
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
