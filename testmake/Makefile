DEFAULT_VARIABLES := $(.VARIABLES)

###########################
# Configuration variables #
###########################

CC = gcc
LD = gcc
BINARY = hello
BUILD = build
TEST = test
UNITY = unity
UNITYFOLDER = ./unity


#######################
# Generated variables #
#######################

SRC = hello.c main.c
OBJ = $(SRC:%.c=$(BUILD)/%.o)
TARGET_BINARY = $(BUILD)/$(BINARY)

TESTSRC= hello.c test.c
TESTOBJ = $(TESTSRC:%.c=$(BUILD)/%.o)
TARGET_TEST = $(BUILD)/$(TEST)

UNITYSRC = $(shell find $(UNITYFOLDER) -name "*.c")
UNITYOBJ = $(UNITYSRC:./%.c=$(BUILD)/%.o)
UNITY_TARGET = $(BUILD)/$(UNITYFOLDER)/$(UNITY)


###########
# Targets #
###########

all: $(TARGET_BINARY)

clean:
	rm -f $(TARGET_BINARY)
	rm -f $(OBJ)
	rm -f $(UNITY_TARGET)
	rm -f $(UNITYOBJ)
	rm -f $(TARGET_TEST)
	rm -f $(TESTOBJ)
	
	rm -df $(dir $(OBJ))
	rm -df $(BUILD)
	rm -df $(UNITY)
	

####################
# Actually do this #
####################

$(TARGET_BINARY): $(OBJ)
	$(LD) -o $(TARGET_BINARY) $(OBJ) #länkar alla objektfiler till en exekverbar binärfil

$(TARGET_TEST): $(TESTOBJ) $(UNITY_TARGET)
	$(LD) $(TESTOBJ) -L $(BUILD)/$(UNITYFOLDER) -lunity -o $(TARGET_TEST) #-lunity skulle kunna bytas mot UNITYOB

$(UNITY_TARGET): $(UNITYOBJ)
	ar rcs $(UNITY_TARGET) $(UNITYOBJ)

################
# More targets #
################


build/%.o: %.c
	@[ -e $(dir $@) ] || mkdir -p $(dir $@) # Create build directory if it does not exist
	$(CC) -c -o $@ $<

unity: $(TARGET_UNITY)

	
test: $(TARGET_TEST)
	$(TARGET_TEST)


.PHONY: all clean test



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

