#include "include.h"
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
 
int GetAuthorToken(user* puser,char* client_secret,char* redirect_uri,char* client_id,char *code){
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

        if(DEBUG)printf("data:%s\n",data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
 /* send all data to this function  */
 	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
 
 /* we pass our 'chunk' struct to the callback function */
	 curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
    }
    if(DEBUG)printf("\n");
    if(DEBUG)printf("%s\n",chunk.response);
    curl_easy_cleanup(curl);
    JsonAnalyse(chunk.response,puser);
    return (int)res;
}
int JsonAnalyse(char* JsonRaw,user* puser)
{
    cJSON* json=NULL,*child=NULL;
    json=cJSON_Parse(JsonRaw);
    if(!json){
        printf("ERROR:%s",cJSON_GetErrorPtr());
    }
    else{
        if((child=cJSON_GetObjectItem(json,"access_token"))==NULL){
        }
        else{
        if(child->type==cJSON_String){
            printf("access_token:%s\n",child->valuestring);
            
        }else{
            printf("%d\n",child->type);
        }
        }
    }
    free(json);free(child);
    return 0;
}
