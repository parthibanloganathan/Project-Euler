CC  = clang++
CXX = clang++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

.PHONY: default
default: $(basename $(wildcard problem*.cpp))

.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(basename $(wildcard problem*.cpp))

.PHONY: all
all: clean default
