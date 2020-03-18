# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g -Wall -pedantic
LDFLAGS=-g

all: test util.o

test: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o SuffixArray.o

DictionaryTrie.o: DictionaryTrie.h

DictionaryBST.o: DictionaryBST.h

DictionaryHashtable.o: DictionaryHashtable.h

SuffixArray.o: SuffixArray.h

util.o: util.h

clean:
	rm -f test *.gch *.o core* *~

