objects = LineEdit.o main.o SqStack.o

test : $(objects)
	clang++ -o test $(objects)
main.o : LineEdit.h
LineEdit.o : LineEdit.h
SqStack.o : SqStack.h

.PHONY : clean
clean : 
	rm test $(objects)
