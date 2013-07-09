CC  = clang++
CXX = clang++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

.PHONY: default
default: $(basename $(wildcard problem*.cpp))

problem7: problem7.o resource_prime.o

resource_prime.o: resource_prime.cpp resource_prime.h

problem7.o: problem7.cpp

.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(basename $(wildcard problem*.cpp)) $(basename $(wildcard resource*.cpp))

.PHONY: all
all: clean default
