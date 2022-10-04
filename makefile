all:
	g++ -std=c++14 -Wall -g  pgm.cpp ppm.cpp rotator.cpp rotatorDriver.cpp -o main

clean:
	rm -f -r *.o main main.dSYM