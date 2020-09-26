/*error example*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char *transfer(){
    char *strings = (char*)malloc(sizeof(char)*100);
    sprintf(strings,"hello world");
    printf("%lu\n",strlen(strings));
    return strings;
}
int main(){
    char *st = transfer();
    printf("%s",st);
    return 0;
}
