#ifndef __XMLPARSER__
#define __XMLPARSER__

#include <cstdio>
#include <expat.h>

class XMLParser {
	protected:
		XML_Parser parser_;
	public:
		XMLParser() { parser_ = NULL; }
		~XMLParser() {
			if (parser_ != NULL)
				XML_ParserFree(parser_);
			parser_ = NULL;
		}
		bool Create();
		bool Parse(const char *buffer, int len = -1, bool last = true);
	
		virtual void OnStart(const XML_Char *name, const XML_Char **atts) {
			printf ("We got a start element %s\n", name);
			return;
		}
		virtual void OnEnd(const XML_Char *name) {
			printf ("We got an end element %s\n", name);
			return;
		}
		virtual void OnData(const XML_Char *s, int len) {
			printf ("We got %d bytes of data\n", len);
			return;
		}

		static void StartHandler(void *userdata, const XML_Char *name, const XML_Char **atts) {
			XMLParser* pThis = ((XMLParser *) userdata);
			pThis->OnStart(name, atts);
		}
		static void EndHandler(void *userdata, const XML_Char *name) {
			XMLParser* pThis = ((XMLParser *) userdata);
			pThis->OnEnd(name);
		}
		static void DataHandler(void *userdata, const XML_Char *s, int len) {
			XMLParser* pThis = ((XMLParser *) userdata);
			pThis->OnData(s, len);
		}
};

#endif
