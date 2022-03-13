#include "include.h"

#define USERSIZE 1345
/*
typedef struct user{
    char* user_id;
    char* token;
    _Bool refresh;
}player,user;
*/
//"AAAAAAAAAAAAAAAAAAAAAI0kzU2RALT4obX__P1X0qg"
//access_token:EwAgA+pvBAAUKods63Ys1fGlwiccIFJ+qE1hANsAAc+YxNTbkBYM995xGpA03Jd32XLv+VrsOFITvN+MfK5y10LNGThzQGQbBa2B+wY8XtDhvH5Ok326CpvKn06U2zw5b3650BjS8ht5xo2VxGxLii97Y9gNPy62mBC+TKZkHQLfgIRd7T0VT7azSZR65XMn271C994foPrtEpjBr15LJQgs1y/GYqJK5hL3m5p/P7ojhqXBw21hAGwY56lnsdlIjAwOIdKeUS/Z7WifCubJeSKRhGGMEY5SS/LvPR8hXcztTajUGEisTHmgiXjvHyJ8SqoJ6aWpyLV1tjWfNGwGZDujIywFVmeAqFipc56WIEwYOf5sx/UFcKelZyD4Q5EDZgAACD+zVWQtkKzH8AE5Bs8LZg8xGLWY2jKt6tik465OXUc/HKN6+C4Ia4kpD66g7uerRHV51VeHGJsB+KbvEkOJdwbnYRb0RxDTaZXyooYenJXYCCwxTA43mjQ3zSxuz3h88qO2EO0DLtFQToaUOMXwgdi50+PZI3tGwokxVVBwDyJhiBDc/GUWQC7OukqCi10E0FLfn8QuVSh0nU8bpmsDH/KmieMYHQHt7bzh1KIK6Z4vyKbMc+LiXdTPOmFi1X4Bz6lmcE7IBVDlARsnGiQzx6t3sr0I0HxUL6cK9gFScV8oab0Aruyqh9LoBg3B+MRCS5pPy5Pjbz2tTS22C+CsUipapeR5btkbZJ6plYOz/5tuY07Ij/H+Zr6PphOVpS9NLqpp04bS9J3Iiwm6ExYNL5cxKN1HUsSShwql0iKzCXKB5kNUSNSX0i5s2upzunueLDOWdjPrZNW4xdAr6mI6oVlrf7N6Tlkrb92yrgr2yPl5oR4Q/Yl/qlpMcCNs9hcB5Eap/IpVG8kXZ1XPOzFeedei49a7Dfg37c1lSGLgLPle5rOGGZyyZiQJ0tJ1jFoKcHSsT5pXbVQasrjhBwNTHdioP2AJDH1PkIZJ3F21yDYQXB37b4JXcX8p4yfgcJvkCsz0XEszlt7gWEvyaPHimilhKPXhxZWlSkgfFgI=

int UserFilePrintf(user* puser);
int UserFileRead(user* puser,char* username);

int main(int argc,char *argv[]){
    UrlSummon(NULL,0);
    printf("%ld\n",strlen("Ba2B+wY8XtDhvH5Ok326CpvKn06U2zw5b3650BjS8ht5xo2VxGxLii97Y9gNPy62mBC+TKZkHQLfgIRd7T0VT7azSZR65XMn271C994foPrtEpjBr15LJQgs1y/GYqJK5hL3m5p/P7ojhqXBw21hAGwY56lnsdlIjAwOIdKeUS/Z7WifCubJeSKRhGGMEY5SS/LvPR8hXcztTajUGEisTHmgiXjvHyJ8SqoJ6aWpyLV1tjWfNGwGZDujIywFVmeAqFipc56WIEwYOf5sx/UFcKelZyD4Q5EDZgAACD+zVWQtkKzH8AE5Bs8LZg8xGLWY2jKt6tik465OXUc/HKN6+C4Ia4kpD66g7uerRHV51VeHGJsB+KbvEkOJdwbnYRb0RxDTaZXyooYenJXYCCwxTA43mjQ3zSxuz3h88qO2EO0DLtFQToaUOMXwgdi50+PZI3tGwokxVVBwDyJhiBDc/GUWQC7OukqCi10E0FLfn8QuVSh0nU8bpmsDH/KmieMYHQHt7bzh1KIK6Z4vyKbMc+LiXdTPOmFi1X4Bz6lmcE7IBVDlARsnGiQzx6t3sr0I0HxUL6cK9gFScV8oab0Aruyqh9LoBg3B+MRCS5pPy5Pjbz2tTS22C+CsUipapeR5btkbZJ6plYOz/5tuY07Ij/H+Zr6PphOVpS9NLqpp04bS9J3Iiwm6ExYNL5cxKN1HUsSShwql0iKzCXKB5kNUSNSX0i5s2upzunueLDOWdjPrZNW4xdAr6mI6oVlrf7N6Tlkrb92yrgr2yPl5oR4Q/Yl/qlpMcCNs9hcB5Eap/IpVG8kXZ1XPOzFeedei49a7Dfg37c1lSGLgLPle5rOGGZyyZiQJ0tJ1jFoKcHSsT5pXbVQasrjhBwNTHdioP2AJDH1PkIZJ3F21yDYQXB37b4JXcX8p4yfgcJvkCsz0XEszlt7gWEvyaPHimilhKPXhxZWlSkgfFgI="));

    char code[64];
/*    if(!GetOAuthAccessToken(code,0)){
        return 0;
    }
    printf("GetOAuthAccessToken success\n");*/
    user* puser=malloc(sizeof(user));
    sprintf(puser->user_id,"AAAAAAAAAAAAAAAAAAAAAI0kzU2RALT4obX__P1X0qg");
    sprintf(puser->token,"EwAgA+pvBAAUKods63Ys1fGlwiccIFJ+qE1hANsAAc+YxNTbkBYM995xGpA03Jd32XLv+VrsOFITvN+MfK5y10LNGThzQGQbBa2B+wY8XtDhvH5Ok326CpvKn06U2zw5b3650BjS8ht5xo2VxGxLii97Y9gNPy62mBC+TKZkHQLfgIRd7T0VT7azSZR65XMn271C994foPrtEpjBr15LJQgs1y/GYqJK5hL3m5p/P7ojhqXBw21hAGwY56lnsdlIjAwOIdKeUS/Z7WifCubJeSKRhGGMEY5SS/LvPR8hXcztTajUGEisTHmgiXjvHyJ8SqoJ6aWpyLV1tjWfNGwGZDujIywFVmeAqFipc56WIEwYOf5sx/UFcKelZyD4Q5EDZgAACD+zVWQtkKzH8AE5Bs8LZg8xGLWY2jKt6tik465OXUc/HKN6+C4Ia4kpD66g7uerRHV51VeHGJsB+KbvEkOJdwbnYRb0RxDTaZXyooYenJXYCCwxTA43mjQ3zSxuz3h88qO2EO0DLtFQToaUOMXwgdi50+PZI3tGwokxVVBwDyJhiBDc/GUWQC7OukqCi10E0FLfn8QuVSh0nU8bpmsDH/KmieMYHQHt7bzh1KIK6Z4vyKbMc+LiXdTPOmFi1X4Bz6lmcE7IBVDlARsnGiQzx6t3sr0I0HxUL6cK9gFScV8oab0Aruyqh9LoBg3B+MRCS5pPy5Pjbz2tTS22C+CsUipapeR5btkbZJ6plYOz/5tuY07Ij/H+Zr6PphOVpS9NLqpp04bS9J3Iiwm6ExYNL5cxKN1HUsSShwql0iKzCXKB5kNUSNSX0i5s2upzunueLDOWdjPrZNW4xdAr6mI6oVlrf7N6Tlkrb92yrgr2yPl5oR4Q/Yl/qlpMcCNs9hcB5Eap/IpVG8kXZ1XPOzFeedei49a7Dfg37c1lSGLgLPle5rOGGZyyZiQJ0tJ1jFoKcHSsT5pXbVQasrjhBwNTHdioP2AJDH1PkIZJ3F21yDYQXB37b4JXcX8p4yfgcJvkCsz0XEszlt7gWEvyaPHimilhKPXhxZWlSkgfFgI=");
    puser->refresh=true;
    FILE *fp;
    fp=fopen("user","rb");
    if(fp!=0){
        fread(puser,USERSIZE,USERSIZE,fp);
        fclose(fp);
    }

    printf("%s\n",puser->user_id);
    printf("%s\n",puser->token);
    printf("%d\n",puser->refresh);

    char client_secret[]="yMz7Q~MN.Fj.qonO4pHhequoZOepVY~uOKGqp";
    char redirect_uri[]="http://localhost:10604/callback";
    char client_id[]="d2a916ba-1bd0-4255-825e-07671bf56fe1";
    //GetAuthorToken(puser, client_secret,redirect_uri,client_id,code);
   /* if(fprintf(fp,"%s",(char*)puser)){
        printf("%s\n",(char*)puser);
    }*/
    fp=fopen("user","wb+");
    
    if(fp==0){
        return 0;
    }
    printf("%ld",sizeof(*puser));
    fwrite((char*)puser,sizeof(*puser),1,fp);
    fclose(fp);
    return 0;
}

int UserFilePrintf(user* puser){
    return 0;
}

int UserFileRead(user* puser,char* username){

    FILE* fp;
    char file[6+strlen(username)];
    sprintf(file,"user_%s",username);
    fp=fopen(file,"rb+");
    return 0;
}
