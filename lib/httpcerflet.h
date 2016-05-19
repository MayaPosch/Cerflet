/*
	httpcerflet.h - Header for the HTTP Cerflet class.
	
	Revision 0
	
	Notes:
			- 
			
	2016/05/18, Maya Posch
	(c) Nyanko.ws
*/


#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/OptionSet.h>

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::OptionSet;


#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;


template<typename T> 
HTTPRequestHandler* createInstance() { return new T; }

typedef map<string, HTTPRequestHandler* (*)()> RoutingMap;


class RequestHandlerFactory: public HTTPRequestHandlerFactory {
public:
	RequestHandlerFactory(RoutingMap& m): 
		map(m) {
    }
	
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) {
		string path = request.getURI();
		try {
			HTTPRequestHandler* handler = map.at(path)();
			return handler;
		}
        catch (const out_of_range& oor) { return 0; }
    }
	
private:
	RoutingMap map;
};


class HttpCerflet: public ServerApplication {
public:
    HttpCerflet(): _helpRequested(false) { }
    ~HttpCerflet() { }
	
	void routingMap(RoutingMap& m);

protected:
    void initialize(Application& self);
    void uninitialize();
    void defineOptions(OptionSet& options);
    void handleHelp(const string& name, const string& value);
	int main(const vector<string>& args);

private:
    bool _helpRequested;
	RoutingMap map;
};
