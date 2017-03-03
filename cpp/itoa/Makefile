# Generic C++ building makefile.
#

CXXFLAGS := -g -O0 -std=c++11 -I../submodules/Catch/include
LDFLAGS :=

SRC1 := itoa.cpp unittest.cpp
TARGET1 := unittest

SRC2 := itoa.cpp benchmark.cpp
TARGET2 := benchmark

TARGETS := $(TARGET1) $(TARGET2)

love: $(TARGETS)


$(TARGET1): $(SRC1)
	g++ $(CXXFLAGS) $(LDFLAGS) $(SRC1) -o $(TARGET1)

$(TARGET2): $(SRC2)
	g++ $(CXXFLAGS) $(LDFLAGS) $(SRC2) -o $(TARGET2)

test: $(TARGET1)
	./$(TARGET1)

