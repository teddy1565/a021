#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static char *rec(char *s1){
    char str[strlen(s1)];
    for(int i=0;i<strlen(s1);i++){
        str[i]=s1[i];
    }
    char *p = str;
    return &str[0];
}
int main(){
    char *s = rec("123456");
    char *f = rec("42312");
    printf("%s\n%s\n",s,f);
    return 0;
}
//0x00007ffeefbff740