CC = g++
COMPILER_FLAGS_DEBUG = -g -Wall -std=c++14
COMPILER_FLAGS_RELEASE = -Wall -std=c++14 -O3
OUTPUT = catalan-numbers

ifeq ($(DEBUG), 1)
catalan-numbers: main.cpp
	$(CC) main.cpp $(COMPILER_FLAGS_DEBUG) -o $(OUTPUT)
else
catalan-numbers: main.cpp 
	$(CC) main.cpp $(COMPILER_FLAGS_RELEASE) -o $(OUTPUT)
endif

clean:
	rm $(OUTPUT)