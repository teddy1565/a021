//不確定online judge是否有阻止動態配置
#include<stdio.h>
#include<stdlib.h>

int main(){
    char *input = (char*)malloc(sizeof(char)*(500+1));
    memset(input,'0',500);
    while(fgets(input,500,stdin)!=NULL){
        printf("%s",input);
    }
    return 0;
}