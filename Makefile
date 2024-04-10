# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := linked_list

BUILD_DIR := ./build
SRC_DIRS := ./src

# Find all the C and C++ files we want to compile
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# Prepends BUILD_DIR and appends .o to every src file.
# e.g. ./your_dir/hello.c -> ./build/./your_dir/hello.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to the compiler so that it can find the header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)

INC_FLAGS := $(addprefix -I, $(INC_DIRS))

# The C compiler of choice, clang also works.
CC = gcc

# Compiler flags
CLFAGS=-Wall -g

# THE -MMD and -MP flags together generate Makefiles automatically.
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP


# Finally, we can build.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/

# Include the .d Makefiles. The - at the front sppresses the errors of missing Makefiles.
-include $(DEPS)
