C = g++
F = -Wall -g
Main = main
obj = graph.cpp
testOBJ = Test.cpp TestConfig.cpp
test = $(subst .cpp , .o , $(testOBJ))

run: $(Main).o $(subst .cpp , .o , $(obj))
	$(C) $(F) $^ -o run

test: $(testOBJ) $(subst .cpp , .o , $(obj))
	$(C) $(F) $^ -o test

%.o:%.cpp
	$(C) $(F) $< -c

clear:
	-rm -f run *.o test
.phony: clear