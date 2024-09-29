#include "dns_server.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string ipAddress = "0.0.0.0";
    int port = 53;

    if (argc > 1) {
        ipAddress = argv[1];
    }

    if (argc > 2) {
        port = std::stoi(argv[2]);
    }

    std::cout << "Starting DNS server on " << ipAddress << ":" << port << std::endl;

    DnsServer server(ipAddress, port);
    server.run();

    return 0;
}
