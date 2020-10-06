#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *s = (char*)malloc(sizeof(char)*100);
    scanf("%s",s);
    printf("%s\n",showDeclare(s));
    return 0;
}