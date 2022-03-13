#include "include.h"
_Bool GetOAuthAccessToken(char* accesstoken,_Bool debbug){
	struct sockaddr_in s_addr , c_addr;
	socklen_t addrlen =sizeof(struct sockaddr_in);
	int s_sockfd =socket(AF_INET,SOCK_STREAM,0);
	if(s_sockfd==-1){
		perror("socket error!");
		return false;
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
		return -1;
	}
	printf("bind successful\n");
	if(listen(s_sockfd,10)==-1){
		perror("liten error!");
		return false;
	}
	printf("listen successful\n");
	pthread_t ptid;
	while(1){
		int c_sockfd=accept(s_sockfd,(struct sockaddr *)&c_addr,&addrlen); 
		if(c_sockfd==-1){
			perror("accept error");
			return false;
		}
        if(UrlAnalyze(c_sockfd,accesstoken)){
            break;
        }
	}
    close(s_sockfd);
    printf("%s\n",accesstoken);
	return true;
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
