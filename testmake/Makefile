###########################
# Configuration variables #
###########################

CC = gcc
LD = gcc
BINARY = hello
BUILD = build

#######################
# Generated variables #
#######################

SRC = $(shell find . -name "*.c")
OBJ = $(SRC:./%.c=$(BUILD)/%.o)
TARGET_BINARY = $(BUILD)/$(BINARY)

###########
# Targets #
###########

all: $(TARGET_BINARY)

clean:
	rm -f $(TARGET_BINARY)
	rm -f $(OBJ)
	rm -df $(dir $(OBJ))
	rm -df $(BUILD)

$(TARGET_BINARY): $(OBJ)
	$(LD) -o $(TARGET_BINARY) $(OBJ)

build/%.o: %.c
	@[ -e $(dir $@) ] || mkdir -p $(dir $@) # Create build directory if it does not exist
	$(CC) -c -o $@ $<

.PHONY: all clean
