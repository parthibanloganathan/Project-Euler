CC  = clang++
CXX = clang++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

.PHONY: default
default: $(basename $(wildcard problem*.cpp))

.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(basename $(wildcard problem*.cpp)) *.txt $(basename $(wildcard resource*.cpp))

.PHONY: all
all: clean default
