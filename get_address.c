#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *String = malloc(sizeof(char)*600);
    char **s = malloc(sizeof(char)*3);
    fgets(String,600,stdin);
    char *p = malloc(sizeof(char)*600);
    for(int j=0,i=0,k=0;i<600;i++){
        *(p+j) = &String[i];j++;
        if(String[i]==' '){
            *(p+i)='\0';
            *(s+k) = p;
            k++;i++;j=0;
            break;
        }
    }
}