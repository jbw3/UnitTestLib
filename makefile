# Makefile for Unit Test Library

CXX = g++
TARGET = libunittest.a

.PHONY: all
all: $(TARGET)

$(TARGET): unittest.o
	ar rcs $(TARGET) unittest.o

unittest.o: unittest.cpp unittest.h
	$(CXX) -c unittest.cpp

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
