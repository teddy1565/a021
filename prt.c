#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void show_str(char *str){
    while(*str++!='\n'){
        if(*str==' ')*str = '0';
        printf("%c ",*str);
    }
}
int main(){
    char str[600];
    fgets(str,600,stdin);
    show_str(str);
    printf("\n");
    return 0;
}
