#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *s = "hello world";
    printf("%lu\n%lu\n",strlen(s),strlen(s)+1);
    char *i = (char*)malloc(sizeof(char*)*(strlen(s)));
    printf("i_length:%lu\n",strlen(i));    
    return 0;
}
//if use strlen get string length
//use this length need+1;