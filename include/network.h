struct InputPacket {
  uint32_t tick;
  int8_t left;
  int8_t right;
  int8_t jump;
};

struct StatePacket {
  uint32_t tick;
  int32_t p1_x, p1_y;
  int32_t p2_x, p2_y;
}

class Network {
  private:
    int server;
    struct sockaddr_in address;
  public:
    Host();
    ~Host();
    void setup_udp();
    void send_packet();
    void receive_packet();
};
