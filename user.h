#ifndef USER
#define USER
#include<stdbool.h>
#define USERIDLEN 64
#define USERTOKENLEN 1024
typedef struct user{
    char user_id[USERIDLEN];
    char token[USERTOKENLEN];
    _Bool refresh;
}player,user;
 
#endif

