CC  = clang++
CXX = clang++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

.PHONY: default
default: $(basename $(wildcard problem*.cpp))

problem7: resource_prime.o

problem10: resource_prime.o

resource_prime.o: resource_prime.cpp resource_prime.h

.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(basename $(wildcard problem*.cpp)) $(basename $(wildcard resource*.cpp))

.PHONY: all
all: clean default
