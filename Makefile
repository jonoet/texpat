all:
	g++ -Wall -o texpat texpat.cpp -I../src/ -std=c++11 -lpthread -lexpat
