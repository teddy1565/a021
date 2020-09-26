#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int strLen = 600;
static char **Split_String(char *input,char split_c){
    int input_length = strlen(input)+1;
    char **string_array = (char**)malloc(sizeof(char)*input_length);
    for(int i=0,p=0,m=0;i<=input_length;i++){
        if(input[i]==split_c||i==input_length){
            string_array[m] = &input[p];
            input[i]='\0';
            p = i+1;
            m++;
            continue;
        }
    }
    return string_array;
}
static char *Add(char *s1,char *s2){
    
    
}
int main(){
    char input[strLen];
    while(fgets(input,strLen,stdin)!=NULL){
        char **s = Split_String(input,' ');
        if(*s[1]=='+')printf("%s\n",Add(s[0],s[2]));
        else if(*s[1]=='-')printf("%s\n",Sub(s[0],s[2]));
        else if(*s[1]=='*')printf("%s\n",Mul(s[0],s[2]));
        else if(*s[1]=='/')printf("%s\n",Div(s[0],s[2]));
    }
    return 0;
}