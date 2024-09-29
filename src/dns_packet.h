#ifndef DNS_PACKET_H
#define DNS_PACKET_H

#include <cstddef>

class DnsPacket {
public:
    bool parse(const char* data, size_t length);
    void createResponse();
    const char* data() const;
    size_t size() const;

private:
    char _buffer[512];
    size_t _length;
};

#endif
