# Generic C++ building makefile.
#

CXXFLAGS := -g -O0 -std=c++11 -I../submodules/Catch/include
LDFLAGS :=

SRC1 := unittest.cpp
TARGET1 := unittest
TARGETS := $(TARGET1)

love: $(TARGETS)


$(TARGET1): $(SRC1)
	g++ $(CXXFLAGS) $(LDFLAGS) $(SRC1) -o $(TARGET1)

test: $(TARGETS)
	./$(TARGET1)

