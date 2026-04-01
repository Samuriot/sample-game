#include "network.h"

// include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <sstream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <fcntl.h>

void Network::Network(int portNum) {
  this->address.sin_family = AF_INET;
  this->address.sin_addr.s_addr = INADDR_ANY;
  this->address.sin_port = htons(portNum);
}

void Network::setup_udp() {
  this->server = socket(AF_INET, SOCK_DGRAM, 0);
  bind(this->server, (struct sockaddr*) &this->address, sizeof(address));
  
  int flags = fcntl(this->server, F_GETFL, 0);
  fcntl(this->server, F_SETFL, flags | O_NONBLOCK);
}

void Network::send_packet() {

}
