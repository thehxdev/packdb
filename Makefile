CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic
CFLAGS += -Werror -Wno-unused-result
CFLAGS += -Og -ggdb
LIBS :=


SRC_DIR := ./src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:.c=.o)

BUILD_DIR := ./build
BIN := $(BUILD_DIR)/packdb

$(BIN): dir $(OBJ_FILES)
	$(CC) -o $(BIN) $(OBJ_FILES)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $<

dir:
	mkdir -p build

clean:
	rm -rf $(BUILD_DIR) $(SRC_DIR)/*.o
