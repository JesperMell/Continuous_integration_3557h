DEFAULT_VARIABLES := $(.VARIABLES)
###########################
# Configuration variables #
###########################

CC = gcc
LD = gcc
AR = ar
LIB = libunity.a
BUILD = build
PREFIX = .

# Source files
SRC = $(wildcard src/*.c)
INC = $(wildcard src/*.h)

#######################
# Generated variables #
#######################

OBJ = $(SRC:%.c=$(BUILD)/%.o)
TARGET_LIB = $(BUILD)/$(LIB)

###########
# Targets #
###########

all: $(TARGET_LIB)

clean:
	rm -rf $(BUILD)

install: all
	mkdir -p $(PREFIX)/lib $(PREFIX)/inc
	cp $(TARGET_LIB) $(PREFIX)/lib/
	cp $(INC) $(PREFIX)/inc/

$(TARGET_LIB): $(OBJ)
	$(AR) rcs $(TARGET_LIB) $(OBJ)

build/%.o: %.c
	@[ -e $(dir $@) ] || mkdir -p $(dir $@) # Create build directory if it does not exist
	$(CC) -c -o $@ $<

.PHONY: all clean

#########
# Debug #
#########

# Set DEBUG_VAR by setting it when running make, e.g.: `DEBUG_VAR=1 make`
# 0 - Print nothing (default)
# 1 - Print out variables added in this Makefile and their values
# 2 - Print out all variables and their values
DEBUG_VAR ?= 0

ifeq ($(DEBUG_VAR), 1)
$(foreach v, \
	$(filter-out $(DEFAULT_VARIABLES) DEFAULT_VARIABLES, $(.VARIABLES)), \
	$(info $(v): $($(v)) ))
endif

ifeq ($(DEBUG_VAR), 2)
$(foreach v, \
	$(.VARIABLES), \
	$(info $(v): $($(v)) ))
endif
