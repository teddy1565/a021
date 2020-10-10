#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Str_Length_for_a021 600
/*compiler option : [ gcc -g -std=c11 -Werror -ansi -pedantic index_V5.c -o a.out ] */

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
static char *itoa(int n){
    char *res = (char*)malloc(sizeof(char)*10);
    int i;
    for(i=9;i>=0;i--){
        res[i] = n>0?((n%10)+'0'):'0';
        n/=10;
    }
    for(i=0;i<10;i++){
        if(res[i]!='0')break;
    }
    return res;
}
static int Add(char *left,char *right){
    int length = strlen(right)<strlen(left)?strlen(left):strlen(right);
    char *result = (char*)malloc(sizeof(char)*(length+2));
    int i,j,k,tmp,num;
    result[length+1] = '\0';
    for(i=length,j=strlen(left)-1,k=strlen(right)-1,tmp=0;i>=0;i--,j--,k--){
        num = (j<0?0:(left[j]-'0')) + (k<0?0:(right[k]-'0')) + tmp;
        tmp = 0;
        result[i] = (num%10)+'0';
        tmp = (num/10);
    }
    for(i=0;result[i]=='0';i++);
    if(i==strlen(result))printf("0\n");
    else printf("%s\n",&result[i]);
    free(result);
    return 0;
}
static int Sub_expansion_complement_add(char *left,char *right){
    int length = strlen(right)<strlen(left)?strlen(left):strlen(right);
    char *result = (char*)malloc(sizeof(char)*(length+2));
    int i,j,k,tmp,num;
    result[length+1] = '\0';
    for(i=length,j=strlen(left)-1,k=strlen(right)-1,tmp=0;i>=0;i--,j--,k--){
        num = (j<0?0:(left[j]-'0')) + (k<0?0:(right[k]-'0')) + tmp;
        tmp = 0;
        result[i] = (num%10)+'0';
        tmp = (num/10);
    }
    for(i=1;result[i]=='0';i++);
    if(i==strlen(result))printf("0\n");
    else printf("%s\n",&result[i]);
    free(result);
    return 0;
}
static int Sub(char *left,char *right){
    int length = strlen(left);
    int i,m;
    char *complement = (char*)malloc(sizeof(char)*(strlen(left)+1));
    complement[length] = '\0';
    for(i=length-1,m=strlen(right)-1;right[m]=='0'&&m>0;i--,m--){
        complement[i] = '0';
    }
    complement[i] = ((10-(right[m]-'0'))+'0');
    for(i=i-1,m=m-1;i>=0;i--,m--){
        complement[i] = m>=0?((9-(right[m]-'0'))+'0'):'9';
    }
    Sub_expansion_complement_add(left,complement);
    free(complement);
    return 0;
}
static void Mul_expansion_Add(char *left,char *right,char *res){
    int length = strlen(res);
    int i,j,k,tmp,num;
    for(i=length,j=strlen(left)-1,k=strlen(right)-1,tmp=0;i>=0;i--,j--,k--){
        num = (j<0?0:(left[j]-'0')) + (k<0?0:(right[k]-'0')) + tmp;
        tmp = 0;
        res[i] = (num%10)+'0';
        tmp = (num/10);
    }
}
static void Mul_expansion_parser_str(char *left,char *right,char *res){
    int aLength = strlen(left);
    int cLength = strlen(right);
    int i,m;
    char *tmp = (char*)malloc(sizeof(char)*(strlen(res)));
    char *ptr,*itoa_ptr;
    char *a = (char*)malloc(sizeof(char)*(((aLength&1)?(aLength/2)+1:(aLength/2))+1));
    char *b = (char*)malloc(sizeof(char)*((aLength/2)+1));
    char *c = (char*)malloc(sizeof(char)*(((cLength&1)?(cLength/2)+1:(cLength/2))+1));
    char *d = (char*)malloc(sizeof(char)*((cLength/2)+1));
    memcpy(tmp,res,strlen(res));
    a[((aLength&1)?(aLength/2)+1:(aLength/2))]='\0';b[(aLength/2)] = '\0';
    c[((cLength&1)?(cLength/2)+1:(cLength/2))]='\0';c[(cLength/2)] = '\0';
    for(i=((aLength&1)?(aLength/2)+1:(aLength/2))-1;i>=0;i--){
        a[i] = left[i];
    }
    for(i=((cLength&1)?(cLength/2)+1:(cLength/2))-1;i>=0;i--){
        c[i] = right[i];
    }
    for(m=0,i=((cLength&1)?(cLength/2)+1:(cLength/2));i<cLength;i++,m++){
        d[m] = right[i];
    }
    for(m=0,i=((aLength&1)?(aLength/2)+1:(aLength/2));i<aLength;i++,m++){
        b[m] = left[i];
    }
    i = strlen(left)/2;m = strlen(right)/2;
    if(strlen(a)+strlen(c)<9){
        ptr = (char*)malloc(sizeof(char)*11);
        ptr[10] ='\0';
        itoa_ptr = itoa(atoi(a)*atoi(c));
        memcpy(ptr,itoa_ptr,10);
        free(itoa_ptr);itoa_ptr = NULL;
    }
}
static int Mul(char *left,char *right){
    /*ans = a*c*10^n + a*d*10^n + c*b*10^m + b*d */
    int i;
    char *res = (char*)malloc(sizeof(char)*(strlen(left)+strlen(right)+2));
    memset(res,'0',strlen(left)+strlen(right));
    res[strlen(left)+strlen(right)+1]='\0';
    for(i=0;i<strlen(left);i++){
        if(left[i]!='0')break;
    }
    if(i==strlen(left))return printf("0");
    for(i=0;i<strlen(right);i++){
        if(right[i]!='0')break;
    }
    if(i==strlen(right))return printf("0");
    if(strlen(left)+strlen(right)<9)return printf("%d\n",atoi(left)*atoi(right));
    else Mul_expansion_parser_str(left,right,res);
    free(res);
    res = NULL;
    return 0;
}
static int Div(char *left,char *right){
    return 0;
}
int main(){
    char keyin[Str_Length_for_a021];
    char Left[Str_Length_for_a021];
    char Right[Str_Length_for_a021];
    char operator;
    while(fgets(keyin,Str_Length_for_a021,stdin)!=NULL){
        split(keyin,Left,&operator,Right);
        if(operator=='+')Add(Left,Right);
        else if(operator=='-')Sub(Left,Right);
        else if(operator=='*')Mul(Left,Right);
        else if(operator=='/')Div(Left,Right);
    }
    return 0;
}
