#include "dns_server.h"
#include "dns_packet.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

DnsServer::DnsServer(const std::string& address, int port) 
    : _address(address), _port(port) {}

void DnsServer::run() {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    serverAddr.sin_port = htons(_port);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Failed to bind socket." << std::endl;
        close(serverSocket);
        return;
    }

    char buffer[512];
    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientAddrLen = sizeof(clientAddr);
        ssize_t recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0,
                                   (sockaddr*)&clientAddr, &clientAddrLen);
        if (recvLen > 0) {
            processDnsQuery(serverSocket, buffer, recvLen);
        }
    }

    close(serverSocket);
}

void DnsServer::processDnsQuery(int clientSocket, const char* buffer, size_t length) {
    DnsPacket packet;
    if (packet.parse(buffer, length)) {
        packet.createResponse();
        sendto(clientSocket, packet.data(), packet.size(), 0, nullptr, 0);
    }
}
