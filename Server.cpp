#include "Server.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")

Server::Server()
{
    m_serverSocket = INVALID_SOCKET;
}
Server:: ~Server() = default;


int Server::init(const char* host, const char* port)
{
    WSADATA wsaData;
    int iResult;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != 0)
    {
        std::cout << "WSAStartup failed: " << iResult << '\n';
        return 1;
    }
    struct addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    struct addrinfo *result = nullptr;
    iResult = getaddrinfo(host, port, &hints, &result);
    if(iResult != 0)
    {
        std::cout << "Getaddrinfo failed: " << iResult << '\n';
        WSACleanup();
        return 1;
    }
    struct addrinfo *ptr = nullptr;
    m_serverSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol);
    if(m_serverSocket == INVALID_SOCKET)
    {
        std::cout << "Socket error: " << iResult << '\n';
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    iResult = connect(m_serverSocket,ptr->ai_addr,(int)ptr->ai_addrlen);
    if(iResult == SOCKET_ERROR)
    {
        std::cout << "Connect error: " << WSAGetLastError() << '\n';
        freeaddrinfo(result);
        closesocket(m_serverSocket);
        WSACleanup();
        return 1;
        
    }
    freeaddrinfo(result);
    return 0;
}
int Server::sendData(const char* buf, int len)
{
    int iResult;

    iResult = send(m_serverSocket, buf, len, 0);
    if (iResult == SOCKET_ERROR) {
        std::cout << "Error at send data" <<  WSAGetLastError() << '\n';
        closesocket(m_serverSocket);
        WSACleanup();
        return 1;
    }

    return 0;
}
int Server::recieveData(char* buf, int len)
{
    int iResult;

    iResult = recv(m_serverSocket, buf, len, 0);
    if (iResult == SOCKET_ERROR) {
        std::cout << "Error at recieve data" <<  WSAGetLastError() << '\n';
        closesocket(m_serverSocket);
        WSACleanup();
        return 1;
    }

    return 0;
}
void Server::close()
{
    closesocket(m_serverSocket);
    WSACleanup();
}