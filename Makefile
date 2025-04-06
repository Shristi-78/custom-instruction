# Makefile for Heron's formula pseudo custom instruction

CXX=riscv64-linux-gnu-g++
CXXFLAGS=-static -march=rv64gc -mabi=lp64d
TARGET=heron
SRC=heron.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
