#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

void monitor_connections() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }

    const char* interfaces[] = {"eth0", "wlan0", "cellular0", nullptr};
    struct ifreq ifr;

    for (const char** iface = interfaces; *iface; iface++) {
        strncpy(ifr.ifr_name, *iface, IFNAMSIZ);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            std::cout << *iface << ": " 
                     << ((ifr.ifr_flags & IFF_UP) ? "UP" : "DOWN")
                     << "\n";
        }
    }
    close(sock);
}


void configure_firewall() {
    std::cout << "Performing firewall checks...\n";
    
    // Test 1: Check if basic TCP sockets are allowed
    int tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_sock < 0) {
        perror("TCP socket creation failed");
    } else {
        std::cout << "✓ TCP sockets allowed\n";
        close(tcp_sock);
    }
}
