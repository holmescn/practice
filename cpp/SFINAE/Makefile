# Generic C++ building makefile.
#

CXXFLAGS := -g -O0 -I../submodules/Catch/include
LDFLAGS :=

SRC1 := unittest03.cpp
TARGET1 := unittest03
SRC2 := unittest11.cpp
TARGET2 := unittest11
TARGETS := $(TARGET1) $(TARGET2)

love: $(TARGETS)


$(TARGET1): $(SRC1)
	g++ $(CXXFLAGS) $(LDFLAGS) $(SRC1) -o $(TARGET1)

$(TARGET2): $(SRC2)
	g++ $(CXXFLAGS) $(LDFLAGS) -std=c++11 $(SRC2) -o $(TARGET2)

test: $(TARGETS)
	./$(TARGET1)
	./$(TARGET2)

