objects = main.o BiTree.o LinkQueue.o

test : $(objects)
	clang++ -o test $(objects)

LinkQueue.o : LinkQueue.h
BiTree.o : BiTree.h
main.o : BiTree.h

.PHONY : clean
clean:
	rm test $(objects)
