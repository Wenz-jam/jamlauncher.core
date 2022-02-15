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

void GetOAuthAccessToken(char* accesstoken,_Bool debbug){
	struct sockaddr_in s_addr , c_addr;
	socklen_t addrlen =sizeof(struct sockaddr_in);
	int s_sockfd =socket(AF_INET,SOCK_STREAM,0);
	if(s_sockfd==-1){
		perror("socket error!");
		exit(1);
	}
	memset(&s_addr,0,addrlen);
	s_addr.sin_family=AF_INET;
	s_addr.sin_port=htons(PORT);
	s_addr.sin_addr.s_addr=inet_addr(IP);

	int opt=1;
	setsockopt(s_sockfd,SOL_SOCKET,SO_REUSEADDR,
		&opt,sizeof(opt));
	if(bind(s_sockfd,(const struct sockaddr *)&s_addr,addrlen)==-1){
		perror("bind error!");
		exit(1);
	}
	printf("bind successful\n");
	if(listen(s_sockfd,10)==-1){
		perror("liten error!");
		exit(1);
	}
	printf("listen successful\n");
	pthread_t ptid;
	while(1){
		int c_sockfd=accept(s_sockfd,(struct sockaddr *)&c_addr,&addrlen); 
		if(c_sockfd==-1){
			perror("accept error");
			exit(1);
		}
        if(UrlAnalyze(c_sockfd,accesstoken)){
            break;
        }
	}
    printf("%s\n",accesstoken);
	return ;
}

_Bool UrlAnalyze(int c_sockfd,char* accesstoken){
	char* buffer=malloc(sizeof(char)*128);
    memset(buffer,0,128);
	char c;
	while(1){
		if(read(c_sockfd,&c,1)==0){
            break;
        }
        strncat(buffer,( const char *)&c,1);
        if(c=='\n'){
            break;
        }
	}
    if(!strncmp("GET /callback?code=",buffer,19)){
        strncpy(accesstoken,&(buffer[19]),45);
	    write(c_sockfd,HTTPOK,15);
        write(c_sockfd,HTTPOK,strlen(HTTPOK));
	    shutdown(c_sockfd,SHUT_RDWR);
        return 1;
    }
	write(c_sockfd,HTTPOK,15);
    write(c_sockfd,HTTPOK,strlen(HTTPOK));
	shutdown(c_sockfd,SHUT_RDWR);
    return 0;
}
