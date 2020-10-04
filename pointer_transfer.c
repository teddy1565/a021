#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void transfer(char *s){
    char *p = s;
    p[0]='f';
}
int main(){
    char *str = (char*)malloc(sizeof(char)*50);
    scanf("%s",str);
    printf("%s\n",str);
    transfer(str);
    printf("%s\n",str);
    return 0;
}
