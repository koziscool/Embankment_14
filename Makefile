
euler: euler.o utils.o
	g++ -o euler euler.o utils.o

euler.o: euler.cpp
	g++ -c euler.cpp

utils.o: utils.cpp
	g++ -c utils.cpp
	