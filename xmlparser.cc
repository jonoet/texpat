#include "xmlparser.h"
#include <cstring>
using namespace std;

bool XMLParser::Create() {
	parser_ = XML_ParserCreate(NULL);
	if (parser_ == NULL)	
		return false;
	XML_SetUserData(parser_, (void *) this);
	XML_SetStartElementHandler(parser_, StartHandler);
	XML_SetEndElementHandler(parser_, EndHandler);
	XML_SetCharacterDataHandler(parser_, DataHandler);
	return true;
}

bool XMLParser::Parse(const char *buffer, int len, bool last) {
	if (parser_ == NULL)	
		return false;
	if(len <= 0)
		len = strlen(buffer);
	return XML_Parse(parser_, buffer, len, last) != 0;
}

