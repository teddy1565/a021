#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char a[100];
    scanf("%s",a);
    char *s = (char*)malloc(sizeof(char)*100);
    s[100]='\0';
    memcpy(s,a,100);
    printf("%d\t%d\n",a[strlen(a)]=='\0',s[strlen(s)]=='\0');
    printf("%lu\t%lu\n",strlen(a),strlen(s));
    return 0;
}