#ifndef __SERVER__
#define __SERVER__

// #include <sys/socket.h>
// Including the header file `sys/socket.h`
#include <Winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")



class Server
{
private:
    SOCKET m_serverSocket;
public:
    Server();
    ~Server();

    int init(const char* host, const char* port);
    int sendData(const char* buf, int len);
    int recieveData(char* buf, int len);
    void close();
};









#endif