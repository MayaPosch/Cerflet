/*
	HelloCerflet.cpp - example of HTTP Cerflet usage.
	
	Revision 0
	
	Notes:
			- Basic Hello World example.
			
	2016/05/18, Maya Posch
	(c) Nyanko.ws
*/


#include <httpcerflet.h>

#include <iostream>
#include <string>

using namespace std;


class HelloRequestHandler :	public HTTPRequestHandler {
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
		Application& app = Application::instance();
        app.logger().information("Request from " + request.clientAddress().toString());
		
		response.setChunkedTransferEncoding(false);
        response.setContentType("text/html");
		
		std::ostream& ostr = response.send();
		ostr << "<!DOCTYPE html><html><head><title>Hello World</title></head>";
		ostr << "<body><p>Hello World!</p></body></html>";
	}	
};


int main(int argc, char** argv) {
	// 0. Initialise: create Cerflet instance and set routing.
	HttpCerflet cf;
	RoutingMap map;
	map["/"] = &createInstance<HelloRequestHandler>;
	cf.routingMap(map);
	
	// 1. Start the server	
	return cf.run(argc, argv);
}
