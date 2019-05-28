
#include "E101.h"
#include "Gate.h"

void Gate::openSesame() {
    char ip_addr[15] = "130.195.6.196";
    unsigned short port = 1024;
    char message[] = "Please";
    char password[24];

    connect_to_server(ip_addr, port);
    send_to_server(message);
    receive_from_server(password);
    send_to_server(password);
}
