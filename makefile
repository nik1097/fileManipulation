all:
	g++ -std=c++14 -g  pgm.cpp ppm.cpp rotator.cpp rotatorDriver.cpp -o main
aliases:
	alias rotator='./main'
clean:
	rm -f -r *.o main main.dSYM