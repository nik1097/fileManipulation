all:
	g++ -std=c++14 -g  pgm.cpp ppm.cpp rotator.cpp rotatorDriver.cpp -o rotator
clean:
	rm -f -r *.o rotator rotator.dSYM