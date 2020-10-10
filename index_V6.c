#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*declare typedef*/
typedef char result[600];
/*struct for index_V6*/
typedef struct{
    char left[600];
    char right[600];
    char operator;
}input_DATA;
/*tool function*/
void split(char *str,char *left,char *operator,char *right){
    while(*str!=' '){
        *left++ = *str++;
    }
    *left='\0';
    *str='\0';
    while(*++str!=' '){
        *operator = *str;
    }
    while(*++str!='\0'){
        if(*str=='\n')break;
        *right++ = *str;
    }
    *right = '\0';
}
void initialization_D(input_DATA s){
    input_DATA r;
    if(strlen(s.left)<strlen(s.right)){
        memcpy(r.right,s.left,strlen(s.left)+1);
        memcpy(r.left,s.right,strlen(s.right)+1);
        r.operator = s.operator;
    }
    s = r;
}
/*main calculation function*/
static char *Add(input_DATA str){
    result res;
    return str.left;
}
static char *Sub(input_DATA str){
    return str.left;
}
static char *Mul(input_DATA str){
    return str.left;
}
static char *Div(input_DATA str){
    return str.left;
}
int main(){
    char keyin[600];
    input_DATA str;
    char *p;
    while(fgets(keyin,600,stdin)!=NULL){
        split(keyin,str.left,&str.operator,str.right);
        if(str.operator=='+')p=Add(str);
        else if(str.operator=='-')p=Sub(str);
        else if(str.operator=='*')p=Mul(str);
        else if(str.operator=='/')p=Div(str);
        printf("%s\n",p);
        //free(p);
    }
    return 0;
}