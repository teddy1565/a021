#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char Origin[600];
    char target[600];
    scanf("%s",Origin);
    //strcpy(target,Origin);
    memcpy(target,Origin,strlen(Origin));
    printf("%d\n",target[strlen(Origin)+1]=='\0');
}