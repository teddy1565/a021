#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *str = "hello world";
    char *Scp = "mother fucker";
    char *p = str;
    char *s = p;
    p = Scp;
    str = p;
    p = str;
    return 0;
}