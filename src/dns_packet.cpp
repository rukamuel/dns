#include "dns_packet.h"
#include <cstring>

bool DnsPacket::parse(const char* data, size_t length) {
    if (length > sizeof(_buffer)) {
        return false;
    }
    std::memcpy(_buffer, data, length);
    _length = length;
    return true;
}

void DnsPacket::createResponse() {
    _buffer[2] |= 0x80;
}

const char* DnsPacket::data() const {
    return _buffer;
}

size_t DnsPacket::size() const {
    return _length;
}
