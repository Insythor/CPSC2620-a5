#
# Makefile for CS 2620 Assignment 5
#
# Author: Tyler Justinen-Teite
# Mar. 20, 2020
#

PROJECT_DIR = a5
PROGRAM_useStack = useStack

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

all : $(PROGRAM_useStack)
	$(PROGRAM_useStack)

#Part one of the assignment
useStack : useStack
useStack : useStack.o useStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean:
	rm -f *.o *~ *% $(PROGRAM_useStack) *# .#*

clean-all: clean
	rm -f useStack
