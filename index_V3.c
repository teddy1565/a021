#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int strLen = 600;
static char **Split_String(char *input,char split_c){
    int input_length = strlen(input)+1;
    char **string_array = (char**)malloc(sizeof(char)*input_length);
    for(int i=0,p=0,m=0;i<input_length;i++){
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
void Add(char *s1,char *s2){

}
void Sub(char *s1,char *s2){

}
void Mul(char *s1,char *s2){

}
void Div(char *s1,char *s2){

}
int main(){
    char input[strLen];
    while(fgets(input,strLen,stdin)!=NULL){
        char **s = Split_String(input,' ');
        if(*s[1]=='+')Add(s[0],s[2]);
        else if(*s[1]=='-')Sub(s[0],s[2]);
        else if(*s[1]=='*')Mul(s[0],s[2]);
        else if(*s[1]=='/')Div(s[0],s[2]);
        printf("1");
    }
    return 0;
}