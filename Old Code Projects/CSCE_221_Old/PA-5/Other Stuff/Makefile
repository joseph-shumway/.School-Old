MAIN = main

$(MAIN): main.cpp graph.h
	$(CXX) -g -std=c++17 -Wall -Wextra -Wpedantic -o $(MAIN) $<


run: $(MAIN)
	./$(MAIN)

clean: 
	rm -f $(MAIN)


#
#A simple makefile for compiling a c++ project

