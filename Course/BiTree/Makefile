objects = main.o BiTree.o LinkQueue.o

test : $(objects)
	clang++ -o test -g $(objects)

LinkQueue.o : LinkQueue.h
	clang++ -c -g LinkQueue.cpp
BiTree.o : BiTree.h
	clang++ -c -g BiTree.cpp
main.o : BiTree.h
	clang++ -c -g main.cpp
.PHONY : clean
clean:
	rm test $(objects)
