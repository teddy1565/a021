#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void transfer(char *s){
    char *p = (char*)malloc(sizeof(char)*(strlen(s)));
    memcpy(p,s,strlen(s));
    p[0]='f';
}
int main(){
    char *s = (char*)malloc(sizeof(char)*50);
    scanf("%s",s);
    printf("%s\n",s);
    transfer(s);
    printf("%s\n",s);
    return 0;
}
