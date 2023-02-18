#include "Control.h"
#include "Server.h"
//#define 1024 1024


int main()
{
    // Controller con;
    // con.run();
    // return 0;

    // Initialize Winsock
    Server Server;
    const char *host = "localhost";
    const char *port = "27015";
    char sendbuf[] = "this is a test";
    char recvbuf[1024];

    // Connect to server
    if (!Server.init(host, port)) {
        std::cerr << "Could not connect to server" << std::endl;
        return 1;
    }

    // Send data to server
    if (!Server.sendData(sendbuf, sizeof(sendbuf))) {
        std::cerr << "Send failed" << std::endl;
        return 1;
    }

    // Receive data from server
    int bytesReceived = Server.recieveData(recvbuf, 1024);
    if (bytesReceived == -1) {
        std::cerr << "Receive failed" << std::endl;
        return 1;
    }
    else {
        std::cout << "Received " << bytesReceived << " bytes: " << recvbuf << std::endl;
    }

    // Close the connection
    Server.close();

    return 0;
}