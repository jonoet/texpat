#include <iostream>
#include "xmlparser.h"
using namespace std;

class TestParser : public XMLParser {
		void OnStart(const XML_Char *name, const XML_Char **atts) {
			printf ("We got a start element %s\n", name);
			return;
		}
		void OnEnd(const XML_Char *name) {
			printf ("We got an end element %s\n", name);
			return;
		}
		void OnData(const XML_Char *s, int len) {
			printf ("We got %d bytes of data\n", len);
			return;
		}
};

int main() {
	cout << "Hola" << endl;
	TestParser parser;
	parser.Create();
	const char* buffer1 = "<ini><uno><dos>aaa</dos>fff<";
	const char* buffer2 = "/uno><uno>p</uno></ini>";
	parser.Parse(buffer1, -1,false);
	cout << "Siguiente" << endl;
	parser.Parse(buffer2);
	return 0;
}
