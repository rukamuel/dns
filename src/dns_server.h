#ifndef DNS_SERVER_H
#define DNS_SERVER_H

#include <string>

class DnsServer {
public:
    DnsServer(const std::string& address, int port);
    void run();

private:
    std::string _address;
    int _port;

    void handleClient(int clientSocket);
    void processDnsQuery(int clientSocket, const char* buffer, size_t length);
};

#endif
