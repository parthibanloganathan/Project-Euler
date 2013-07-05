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
	rm *~ a.out core *.o
	ls | grep -v "\." | grep -v Makefile | xargs rm

.PHONY: all
all: clean default
