test : main.o SqStack.o
	clang++ *.o -o test

main.o : main.cpp BracketMatch.h
	clang++ -c main.cpp
SqStack.o : SqStack.cpp SqStack.h
	clang++ -c SqStack.cpp
clean :
	rm test *.o
