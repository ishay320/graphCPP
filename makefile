C = g++
F = -Wall -g
Main = main
obj = graph

all: $(Main).o $(obj).o
	$(C) $(F) $^ -o run

%.o:%.cpp
	$(C) $(F) $< -c

clear:
	-rm -f run *.o
.phony: all clear 