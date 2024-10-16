#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(PORT)};
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    int r = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

    char buf1[BUF_SIZE], buf2[BUF_SIZE], res[BUF_SIZE * 2];
    printf("Enter first string: ");
    fgets(buf1, BUF_SIZE, stdin);
    printf("Enter second string: ");
    fgets(buf2, BUF_SIZE, stdin);

    write(sock, buf1, strlen(buf1) + 1);
    write(sock, buf2, strlen(buf2) + 1);

    int length;
    read(sock, &length, sizeof(length));
    printf("Total length: %d\n", length);

    read(sock, res, BUF_SIZE * 2);
    printf("Concatenated string: %s\n", res);

    close(sock);
    return 0;
}
