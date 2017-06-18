main:main.o stack.o queue.o tree.o
	g++ main.o stack.o queue.o tree.o -o main

main.o:main.cpp include/stack.h include/queue.h include/tree.h
	g++ -std=c++11 -c main.cpp

stack.o:stack.cpp include/stack.h
	g++ -std=c++11 -c stack.cpp

queue.o:queue.cpp include/queue.h
	g++ -std=c++11 -c queue.cpp

tree.o:tree.cpp include/tree.h include/queue.h
	g++ -std=c++11 -c tree.cpp

clean:
	rm main *.o