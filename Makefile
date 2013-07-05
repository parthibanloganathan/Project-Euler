CC  = clang++
CXX = clang++

INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

executables = problem1
objects = problem1.o

.PHONY: default
default: $(executables)

.PHONY: clean
clean:
	rm *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
