#include <iostream>
#include "xmlparser.h"
using namespace std;


int main() {
	cout << "Hola" << endl;
	XMLParser parser;
	parser.Create();
	const char* buffer1 = "<ini><uno><dos>aaa</dos>fff<";
	const char* buffer2 = "/uno><uno>p</uno></ini>";
	parser.Parse(buffer1, -1,false);
	cout << "Siguiente" << endl;
	parser.Parse(buffer2);
	return 0;
}
