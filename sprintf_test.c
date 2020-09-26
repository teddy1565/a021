#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i = 9999;
    char *test;
    int k = sprintf(test,"%d",i);
    for(int j=0;test[j]!='\0'&&test[j]!='\n';j++){
        printf("%d\n",j);
    }
    printf("%s\n%d\n",test,k);
    return 0;
}