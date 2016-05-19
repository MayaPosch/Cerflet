/*
	httpcerflet.cpp - Implementation for the HTTP Cerflet class.
	
	Revision 0
	
	Features:
			- 
	
	Notes:
			- 
			
	2016/05/18, Maya Posch
	(c) Nyanko.ws
*/


#include "httpcerflet.h"

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/HelpFormatter.h>

using Poco::Net::HTTPServer;
using Poco::Net::ServerSocket;
using Poco::Net::HTTPServerParams;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;


void HttpCerflet::routingMap(RoutingMap& m) {
	map = m;
}


void HttpCerflet::initialize(Application& self) {
	loadConfiguration();
	ServerApplication::initialize(self);
}

void HttpCerflet::uninitialize() {
	ServerApplication::uninitialize();
}


void HttpCerflet::defineOptions(OptionSet& options) {
	ServerApplication::defineOptions(options);

	options.addOption(
	Option("help", "h", "display argument help information")
		.required(false)
		.repeatable(false)
		.callback(OptionCallback<HttpCerflet>(
			this, &HttpCerflet::handleHelp)));
}


void HttpCerflet::handleHelp(const std::string& name, const std::string& value) {
	HelpFormatter helpFormatter(options());
	helpFormatter.setCommand(commandName());
	helpFormatter.setUsage("OPTIONS");
	helpFormatter.setHeader(
		"A web server.");
	helpFormatter.format(std::cout);
	stopOptionsProcessing();
	_helpRequested = true;
}


int HttpCerflet::main(const vector<string>& args) {
	if (!_helpRequested) {
		unsigned short port = (unsigned short) config().getInt("HttpCerflet.port", 9980);

		ServerSocket svs(port);
		HTTPServer srv(new RequestHandlerFactory(map), svs, new HTTPServerParams);
		srv.start();
		waitForTerminationRequest();
		srv.stop();
	}
	
	return Application::EXIT_OK;
}
