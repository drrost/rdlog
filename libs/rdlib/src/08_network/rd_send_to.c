//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

static int open_socket(char *server, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        rd_printerr("socket creation failed...\n");
        exit(0);
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(server);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr,
        sizeof(servaddr)) != 0) {
        rd_printerr("connection with the server failed...\n");
        exit(0);
    }

    return sockfd;
}

void rd_send_to(char *server, int port, char *message) {
    int sockfd = open_socket(server, port);
    write(sockfd, message, rd_strlen(message));
    close(sockfd);
}
