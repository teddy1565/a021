#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char st[100];
    sprintf(st,"12312321312312");
    char *str = st;
    str = malloc(sizeof(char)*100);
    printf("%s\n",str);
    return 0;
}