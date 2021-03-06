#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define logInit(l) { \
	system("touch ../logFile.txt"); \
	l = fopen("../logFile.txt", "a"); \
}

#define logError(errNo, message) { \
	char errDesc[100] = "", temp[100] = ""; \
	strcat(errDesc, message); \
	strcat(errDesc, " "); \
	strerror_r(errNo, temp, 100); \
	strcat(errDesc, temp); \
	strcat(errDesc, "\n\0"); \
	fprintf(l, errDesc); \
	printf("Program Execution is Unsuccessful... Please chck logFile for more details\n"); \
	exit(EXIT_FAILURE); \
}

#define TCP_PORT 16000

#define BUFLEN 51200
#define SocketQueueSize 20

int openTCPClientSocket(char *, int);
int openTCPServerSocket(int, int);
