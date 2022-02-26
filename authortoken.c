#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "GetOAuthAccessToken.h"
#include "cJSON.h"
struct memory {
   char *response;
   size_t size;
 };
 
 static size_t cb(void *data, size_t size, size_t nmemb, void *userp)
 {
   size_t realsize = size * nmemb;
   struct memory *mem = (struct memory *)userp;
 
   char *ptr = realloc(mem->response, mem->size + realsize + 1);
   if(ptr == NULL)
     return 0;  /* out of memory! */
 
   mem->response = ptr;
   memcpy(&(mem->response[mem->size]), data, realsize);
   mem->size += realsize;
   mem->response[mem->size] = 0;
 
   return realsize;
 }
 
int main(int argc, char *argv[]){
    UrlSummon(NULL,0);
    char code[64];
    GetOAuthAccessToken(code,0);
    char client_secret[]="yMz7Q~MN.Fj.qonO4pHhequoZOepVY~uOKGqp";
    char redirect_uri[]="http://localhost:10604/callback";
    char client_id[]="d2a916ba-1bd0-4255-825e-07671bf56fe1";
    struct memory chunk = {0};
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://login.live.com/oauth20_token.srf");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        headers = curl_slist_append(headers, "Cookie: MSCC=54.86.50.139-US");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10 );
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        char data[256];
        sprintf(data,"client_id=%s&client_secret=%s&code=%s&grant_type=authorization_code&redirect_uri=%s",client_id,client_secret,&code[9],redirect_uri);

        printf("%s\n",data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
 /* send all data to this function  */
 	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
 
 /* we pass our 'chunk' struct to the callback function */
	 curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
    }
    printf("\n");
    printf("%s\n",chunk.response);
    curl_easy_cleanup(curl);
    cJSON* json=NULL,*accesstoken=NULL;
    json=cJSON_Parse(chunk.response);
    if(!json){
        printf("ERROR:%s",cJSON_GetErrorPtr());
    }
    else{
        accesstoken=cJSON_GetObjectItem(json,"access_token");
        if(accesstoken->type==cJSON_String){
            printf("%s\n",accesstoken->valuestring);
        }else{
            printf("%d\n",accesstoken->type);
        }
        accesstoken=cJSON_GetObjectItem(json,"refresh_token");
        if(accesstoken->type==cJSON_String){
            printf("%s\n",accesstoken->valuestring);
        }else{
            printf("%d\n",accesstoken->type);
        }
    }
    free(json);free(accesstoken);
    return (int)res;
}
