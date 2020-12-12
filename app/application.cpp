#include <SmingCore.h>


void sendString(HttpRequest &request, HttpResponse &response) {
	response.sendString("super test string");
}

void sendFile(HttpRequest &request, HttpResponse &response) {
	String file = request.getQueryParameter("file");
	if(!fileExist(file)) {
		Serial.println("FILE DOES NOT EXIST.");
		response.code = HTTP_STATUS_NOT_FOUND;
		return;
	}

	response.sendFile(file);
}


HttpServer* server;

void onReady() {
	Serial.println("Starting server.");
	server->listen(80);
	Serial.println("Server started.");
}

void init() {
	Serial.begin(SERIAL_BAUD_RATE);
	Serial.systemDebugOutput(true);
	spiffs_mount_manual(RBOOT_SPIFFS_0, SPIFF_SIZE);

	HttpServerSettings settings;
	settings.maxActiveConnections = 10;
	settings.keepAliveSeconds = 0;
	settings.minHeapSize = -1;
	settings.useDefaultBodyParsers = true;
	settings.closeOnContentError = true;

	server = new HttpServer(settings);
	server->paths.setDefault(sendString);
	server->paths.set("/get", sendFile);

	Serial.println("Starting wifi.");
	WifiAccessPoint.config("test", "", WifiAuthMode::AUTH_OPEN, false, 3, 200);


	Serial.println("Before ready.");
	System.onReady(onReady);
}
