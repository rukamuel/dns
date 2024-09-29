This project is a simple, test-oriented DNS server. It listens on UDP port 53 and handles basic DNS queries.

> **Note**: This repository is strictly for testing and educational purposes.
> It uses a highly simplified engine and is not designed for production environments.


# Features
- Receives DNS requests
- Parses DNS queries
- Sends basic DNS responses (currently an echo of the request)

# Requirements
- C++17 or higher
- [CMake 3.10](https://cmake.org/) or higher
- GCC or Clang for compiling

# Getting the Source

```bash
git clone --recurse-submodules https://github.com/rukamuel/dns.git
```

# Building
To build the DNS server, run the following commands:
```bash
mkdir -p build && cd build
cmake .. && cmake --build .
```

# Usage
#### Default (no arguments):
```bash
./dns
```
Output: ```Starting DNS server on 0.0.0.0:53```

#### Custom IP (only one argument):
```bash
./dns 192.168.1.10
```
Output: ```Starting DNS server on 192.168.1.10:53```

#### Custom IP and port (two arguments):
```bash
./dns 192.168.1.10 8080
```
Output: ```Starting DNS server on 192.168.1.10:8080```

# Performance
The DNS server implemented in this repository is highly simplified and designed for testing purposes rather than high-performance scenarios. Its performance is limited by several factors:

- Single-threaded operation: The server handles requests in a blocking manner, which limits scalability and performance under high load.
- No caching: Each query is processed individually without any caching mechanism, which increases response times.
- Simplified DNS query/response logic: The server only handles basic DNS query types, and the response logic is minimal, making it unsuitable for handling complex DNS requests.

In its current form, the DNS server is expected to handle light traffic and basic queries, but it is not optimized for throughput, low latency, or handling concurrent queries.

# Sample Output
A simple test was performed by sending a DNS query to the server.<br>
Below is a sample output demonstrating a query for the example.com domain and the server’s response:
```yaml
Starting DNS server on 0.0.0.0:53...

Received DNS query:
    Query Type: A
    Domain: example.com

Processing request...
Sending DNS response:
    Response Type: A
    Domain: example.com
    IP: 93.184.216.34
```
In this test, the DNS server successfully received a query for the domain example.com, processed it, and sent back a response with the associated IP address.

# Limitations
No production-grade optimization: The DNS server is not optimized for high availability or large-scale deployments.
Basic query handling: Only basic query types (e.g., A records) are supported. Complex DNS records (e.g., MX, CNAME, etc.) are not yet implemented.

# License
This project is licensed under the [MIT](https://opensource.org/license/mit) License.
For more details, see the [LICENSE](/LICENSE) file.