#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int fd, soc;
    struct sockaddr_in addr = {AF_INET, htons(PORT), INADDR_ANY};
    char buf1[BUF_SIZE], buf2[BUF_SIZE], res[BUF_SIZE * 2];

    fd = socket(AF_INET, SOCK_STREAM, 0);
    int r = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(fd, 3);

    printf("Server listening on port %d...\n", PORT);
    soc = accept(fd, NULL, NULL);

    read(soc, buf1, BUF_SIZE);
    read(soc, buf2, BUF_SIZE);

    unsigned int length = strlen(buf1) + strlen(buf2);
    write(soc, &length, sizeof(length));

    strcpy(res, buf1);
    strcat(res, buf2);
    write(soc, res, strlen(res));

    close(soc);
    close(fd);
    return 0;
}
