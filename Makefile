#
# Makefile for CS 2620 Assignment 3
#
# Author: Tyler Justinen-Teite
# Feb. 11, 2020
#

PROJECT_DIR = a3
PROGRAM_CMATRIXEXT = CMatrixExt
PROGRAM_CMATRIXPRO = CMatrixPro

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

all : $(PROGRAM_CMATRIXEXT) $(PROGRAM_CMATRIXPRO)
	$(PROGRAM_CMATRIXEXT) $(PROGRAM_CMATRIXPRO)

#Part one of the assignment
CMatrixExt : CMatrixExt
CMatrixExt : CMatrixExt.o testMatrixExt.o
	$(CCC) $(CCCFLAGS) $^ -o $@

#Part two of the assignment
CMatrixPro : CMatrixPro
CMatrixPro : CMatrixPro.o testMatrixPro.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) -c $(CCCFLAGS) $<


clean:
	rm -f *.o *~ *% $(PROGRAM_CMATRIXEXT) $(PROGRAM_CMATRIXPRO) *# .#*

clean-all: clean
	rm -f CMatrixExt CMatrixPro
