#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")


SOCKET xopen(const char* address, unsigned short port);
int xwrite(SOCKET sock, const char* src, int size);
int xread(SOCKET sock, char* dst, int size);


int main(void) {
    // HTTP - Request to receive the page
    char*     http = "GET https://www.google.com/search?q=duboviy HTTP/1.0\r\n"\
                     "Host: google.com\r\n\r\n";
    int       res;
    SOCKET    sock;
    FILE*     fp;
    char      buf[4096]; // Data receiving buffer 4-KB
    WSADATA   data;

    if(WSAStartup(MAKEWORD(2, 0), &data) != 0)
        exit(1);

    sock = xopen("google.com", 80); // Connection to the server
    if(sock == NULL)
        exit(2);
    puts("Connection server...");

    // Send an HTTP request to the server
    if(xwrite(sock, http, strlen(http)))
        puts("Start downloading data...");
    else
        goto error;

    Sleep(1000u);

    // Create a file to write a page
    fp = fopen("C:\\downloaded_page.html", "w+");

    // Read the page (by 4-KB blocks each iteration)
    while((res = xread(sock, buf, sizeof(buf))) > 0) {
        buf[res] = '\0';
        fwrite(buf, sizeof(char), strlen(buf), fp);
    }
    fflush(fp);
    fclose(fp);

    puts("File successfully downloaded.");
error:
    closesocket(sock);
    WSACleanup();

    getchar();
    return 0;
}


// function to establish a connection to the server
SOCKET xopen(const char* address, unsigned short port) {
    SOCKET  sock;
    sockaddr_in addr;
    hostent* host = NULL;

    memset(&addr, 0, sizeof(sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);
    host = gethostbyname(address);
    if(host == NULL)
        return  NULL;
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == INVALID_SOCKET)
        return NULL;
    if(connect(sock, (sockaddr*)&addr, sizeof(sockaddr_in)) == SOCKET_ERROR )
        return  NULL;
    return sock;
}

// Sending data to the server
int xwrite(SOCKET sock, const char* src, int size) {
    return (send(sock, src, size, NULL) == SOCKET_ERROR) ? 0 : 1;
}

// Read data from the server
int xread(SOCKET sock, char* dst, int size) {
    int  res = recv(sock, dst, size, NULL);
    if(res == SOCKET_ERROR)
        return -1;
    return res;
}
