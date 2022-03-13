#ifndef AUTHORTOKEN
#define AUTHORTOKEN
#include <stdlib.h>
#include "user.h"
#ifdef __cplusplus
extern "C"
{
#endif

struct memory {
   char *response;
   size_t size;
 };
 
static size_t cb(void *data, size_t size, size_t nmemb, void *userp);
int GetAuthorToken(user* puser,char* client_secret,char* redirect_uri,char* client_id,char *code);
int JsonAnalyse(char* JsonRaw,user* puser);

#ifdef __cplusplus
}
#endif

#endif
