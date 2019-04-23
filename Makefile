all:
	g++ -Wall -o texpat texpat.cc xmlparser.cc -std=c++11 -lpthread -lexpat
