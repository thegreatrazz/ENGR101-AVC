
#include <cstdio>
#include "E101.h"

class Drive {
public:
    static void setSpeed(int speed) {
    }

    static void setAngle(int offset) {
    }
};

class Camera {
public:
    static void setAngle(int angle) {
    }
};

void tryPassword() {
    char id_addr[15] = "130.135.6.196";
    unsigned short port = 1024;
    char message[24] = "Please";

    connect_to_server(id_addr, port);
    send_to_server(message);
    receive_from_server(message);
    send_to_server(message);
}

int main() {
    printf("Hello world! Perfect!\n");
    tryPassword();
    return 0;
}
