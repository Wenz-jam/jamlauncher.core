#include<stdio.h>

int UrlSummon(char* url,unsigned long url_size){
    if(url==NULL){
        printf("https://login.live.com/oauth20_authorize.srf?client_id=d2a916ba-1bd0-4255-825e-07671bf56fe1&redirect_uri=http://localhost:10604/callback&response_type=code&scope=XboxLive.signin offline_access\n");
        return 0;
    }
    else{
        return snprintf(url,url_size,"https://login.live.com/oauth20_authorize.srf?client_id=d2a916ba-1bd0-4255-825e-07671bf56fe1&redirect_uri=http://localhost:10604/callback&response_type=code&scope=XboxLive.signin offline_access");
    }
}
