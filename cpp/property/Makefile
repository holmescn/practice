# Generic C++ building makefile.
#

CXXFLAGS := -std=c++11 -I../submodules/Catch/include
LDFLAGS :=

SRC1 := property.cpp
TARGET1 := property
TARGETS := $(TARGET1)

love: $(TARGETS)


$(TARGET1): $(SRC1)
	g++ $(CXXFLAGS) $(LDFLAGS) $(SRC1) -o $(TARGET1)

test: $(TARGETS)
	./$(TARGET1)

