#ifndef GETOAUTHACCESSTOKEN
#define GETOAUTHACCESSTOKEN
#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ifaddrs.h>
#include<string.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include<unistd.h>
#define	PORT 10604
#define IP "127.0.0.1"
#define ERROR404 "HTTP/1.1 404 Not Found\n\n"
#define HTTPOK "HTTP/1.1 200 OK\n\n"
void listen_again(int c_sockfd);
_Bool UrlAnalyze(int c_sockfd,char* accesstoken);
void GetOAuthAccessToken(char* accesstoken,_Bool debbug);
#endif
