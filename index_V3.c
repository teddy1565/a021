#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define strLen 600
static char **Split_String(char *input,char split_c){
    int input_length = strlen(input)+1;
    char **string_array = (char**)malloc(sizeof(char)*input_length);
    int i,p,m;
    for(i=0,p=0,m=0;i<input_length;i++){
        if(input[i]==split_c||input[i]=='\n'){
            input[i]='\0';
            string_array[m] = &input[p];
            p = i+1;
            m++;
            continue;
        }
    }
    return string_array;
}
static char *Add(char *s1,char *s2){
    char AD1[600];char AD2[600];
    int i;
    if(strlen(s1)<strlen(s2))return Add(s2,s1);
    for(i=0;i<=strlen(s1);i++){
        if(i==strlen(s1)){
            AD1[i] = '\0';
        }
        AD1[i] = s1[i];
    }
    return "hello add";
}
static char *Sub(char *s1,char *s2){
    return "hello sub";
}
static char *Mul(char *s1,char *s2){
    return "hello mul";
}
static char *Div(char *s1,char *s2){
    return "hello div";
}
int main(){
    char input[strLen];
    while(fgets(input,strLen,stdin)!=NULL){
        char **s = Split_String(input,' ');
        if(*s[1]=='+')Add(s[0],s[2]);
        else if(*s[1]=='-')Sub(s[0],s[2]);
        else if(*s[1]=='*')Mul(s[0],s[2]);
        else if(*s[1]=='/')Div(s[0],s[2]);
        free(s);
    }
    return 0;
}
