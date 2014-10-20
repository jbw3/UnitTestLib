# Makefile for Unit Test Library

CXX = g++
TARGET = libunittest.a

.PHONY: all
all: $(TARGET)

$(TARGET): unittestgroup.o
	ar rcs $(TARGET) unittestgroup.o

unittestgroup.o: unittestgroup.cpp unittestgroup.h
	$(CXX) -c unittestgroup.cpp

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
