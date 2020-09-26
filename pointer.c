#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a[50] = "hello world\0";
    char *p = a;
    p[1] = 'f';
    char *pp = &p[1];
    //char **pp = &p;
    return 0;
}