BUILD_CONFIG ?= debug

ifeq ($(BUILD_CONFIG), release)
    BUILD_CONFIG_NAME := release
    CPPFLAGS = -02 -fno-omit-frame-pointer -DNDEBUG -D_NDEBUG -g
else
    BUILD_CONFIG_NAME := debug
    CPPFLAGS = -g -O0 -DDEBUG -D_DEBUG
endif

#############################################^#######################
#CC = distcc /usr/bin/g++ do not define CC and CXX in Makefile,define

SRC_DIR := $(shell find . -type d)
INC_DIR := $(addprefix -I,$(SRC_DIR))
SRC_DIR +=
INC_DIR += -Isrc -Isrc/gtest -Itest/{{PROJECT_NAME_LO}} -Iinclude
LIB_DIR = -L/lib/$(BUILD_CONFIG_NAME)
LIBS += -Wl,-Bstatic

DESTDIR = ../bin/$(BUILD_CONFIG_NAME)/

DESTNAME = {{PROJECT_NAME_LO}}

OUTPUT = ../build/$(BUILD_CONFIG_NAME)/{{PROJECT_NAME_LO}}

DEST = $(DESTDIR)/$(DESTNAME)

SRCS = $(shell find $(SRC_DIR) -maxdepth 3 -name "*.cpp")
OBJS = $(patsubst %.cpp, $(OUTPUT)/%.o, $(SRCS))
DEPS = $(patsubst %.o, %.d, $(OBJS))

SRCS2 = $(shell find $(SRC_DIR) -maxdepth 3 -name "*.c")
OBJS2 = $(patsubst %.cpp, $(OUTPUT)/%.o, $(SRCS2))
DEPS2 = $(patsubst %.o, %.d, $(OBJS2))

SRCS3 = $(shell find $(SRC_DIR) -maxdepth 3 -name "*.cc")
OBJS3 = $(patsubst %.cpp, $(OUTPUT)/%.o, $(SRCS3))
DEPS3 = $(patsubst %.o, %.d, $(OBJS3))

$(foreach dir, $(SRC_DIR), $(eval OBJ_DIR += $(OUTPUT)/$(dir)))
#$(shell touch Makefile)
CPPFLAGS += -Wall -fcheck-new -fexceptions -fnon-call-exceptions -std=c++11
LDFLAGS = $(LIB_DIR) $(LIBS)

$(shell rm -f $(DEST))
$(shell rm -rf build)
$(shell mkdir -p $(DESTDIR))

all: $(DEST)
$(shell mkdir -p $(sort $(OBJ_DIR)))
-include $(DEPS) $(DEPS2) $(DEPS3)

$(DEST): $(OBJS) $(OBJS2) $(OBJS3)
    @echo
    @echo "\033[0;32;1mINC_DIR: $(INC_DIR)\033[0;33;1m"
    @echo
    @echo "\033[0;32;1m$(CXX) -o $@ $< $(LDFLAGS)\033[0;33;1m"
    @$(CXX) -o $@ $< $(LDFLAGS)
    @echo
    @echo "\033[0;31;1m--- make ok !!! $(DEST) ---\033[0;33;1m"
    @echo -e "\033[0m"

$(OUTPUT)/%.o: %.cpp
    @echo "\033[0;32;1m$(CXX) $(CPPFLAGS) -c $< -o $@\033[0;33;1m"
    @$(CXX) -o $@ -c $< $(CPPFLAGS) $(INC_DIR)

$(OUTPUT)/%.d: %.cpp
    @set -e; rm -f $@; \
    $(CXX) -MM $(CPPFLAGS) $(INC_DIR) $< > $@.$$$$; \
    sed 's,.*\.o[ :]*,$(patsubst %.d,%,o,$@) $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

$(OUTPUT)/%.o: %.c
    @echo "\033[0;32;1m$(CC) $(CPPFLAGS) -c $< -o $@\033[0;33;1m"
    @$(CC) -o $@ -c $< $(CPPFLAGS) $(INC_DIR)

$(OUTPUT)/%.d: %.c
    @set -e; rm -f $@; \
    $(CC) -MM $(CPPFLAGS) $(INC_DIR) $< > $@.$$$$;  \
    sed 's,.*\.o[ :]*,$(patsubst %.d,%,o,$@) $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

$(OUTPUT)/%.o: %.cc
    @echo "\033[0;32;1m$(CC) $(CPPFLAGS) -c $< -o $@\033[0;33;1m"
    @$(CC) -o $@ -c $< $(CPPFLAGS) $(INC_DIR)

$(OUTPUT)/%.d: %.cc
    @set -e; rm -f $@;  \
    $(CC) -MM $(CPPFLAGS) $(INC_DIR) $< > $@.$$$$;  \
    sed 's,.*\.o[ :]*,$(patsubst %.d,%,o,$@) $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

#$(shell echo $$(svn info | grep Revision) > $(DESTDIR)/version.txt)
#$(shell echo $$(svn info | grep "Last Changed Rev") > $(DESTDIR)/update.txt)

clean:
    @echo
    @echo "\033[0;32;1mrm -rf $(OUTPUT) $(DEST)\033[0;33;1m]]
    @rm -rf $(OUTPUT) $(DEST)
    @echo "\033[0;31;1m--- clean $(DEST) ---\033[0;33;1m"
    @echo -e "\033[0m"