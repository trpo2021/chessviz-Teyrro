APP_NAME = chess
LIB_NAME = chesslib
TEST_NAME = test
FILE_NAME = move.txt

CFLAGS = -Wall -Werror
CPPFLAGS = -MMD -I chess_test -I thirdparty -I src    

CC = gcc
CXX = clang++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = chess_test
TEST_OBJ_DIR = $(OBJ_DIR)/$(TEST_DIR)
THIRDPARTY_DIR = thirdparty


APP_PATH = $(BIN_DIR)/$(APP_NAME)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_DIR)/$(TEST_NAME)

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(TEST_OBJ_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d)
DEPS_TEST = $(TEST_OBJECTS:.o=.d) 

.PHONY: all
all: $(APP_PATH)
	

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.$(SRC_EXT) 
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
##################################################
.PHONY: test
test:$(TEST_PATH)

-include $(DEPS_TEST) 

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS_TEST) $^ -o $@

##################################################
.PHONY: run ex
run: $(APP_PATH)
	./$< $(SRC_DIR)/$(APP_NAME)/$(FILE_NAME)

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;