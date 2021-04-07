objects = main.o Maze.o SqStack.o

test : $(objects)
	clang++ -o test $(objects)
main.o : Maze.h
Maze.o : Maze.h
SqStack.o : SqStack.h

.PHONY : clean
clean : 
	rm test $(objects)

