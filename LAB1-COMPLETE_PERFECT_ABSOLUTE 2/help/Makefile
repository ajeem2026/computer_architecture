# Step 1: Compiler
CC = gcc

# Step 2: Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Step 3: Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Step 4: Target executable
TARGET = main

# Step 5: Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# The wildcard function is used to get a list of all '.c' files in the 'src' directory.

# Step 6: Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
# The patsubst function is used to replace the '.c' extension with '.o' for each source file.

# Step 7: Default target
.PHONY: all clean
# The .PHONY target declares 'all' and 'clean' as phony targets (targets that do not represent actual files).

# Step 8: Default target builds the executable
all: $(BUILD_DIR) $(TARGET)

# Step 9: Create the build directory
$(BUILD_DIR):
	# Create the build directory if it doesn't exist
	mkdir -p $(BUILD_DIR)

# Step 10: Build the executable from object files
$(TARGET): $(OBJS)
	# Step 11: Link the object files to create the executable
	$(CC) $(CFLAGS) -o $@ $^
# $@ is replaced with the target, so it represents the name of the executable.
# $^ is replaced with the list of dependencies, so it represents all the object files.
# this converts to 'gcc -Wall -Wextra -std=c11 -o main file1.o file2.o file3.o' etc.

# Step 12: Compile each source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	# Step 13: Compile each source file into an object file
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c -o $@ $<
# $@ is replaced with the target, as in step 10-11.
# $< is replaced with the first prerequisite, which is the source file.
# this converts to 'gcc -Wall -Wextra -std=c11 -I include -c -o build/file1.o src/file1.c' etc.

# Step 14: Clean up generated files
clean:
	# Step 15: Remove the build directory and the executable
	rm -rf $(BUILD_DIR) $(TARGET)
