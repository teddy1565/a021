#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct karatsuba{
    int n,m;
    char *a;
    char *b;
    char *c;
    char *d;
};
typedef struct{
    char* (*itoa)(int);
}transfer;
typedef struct{
    struct power{
        int A;
        int B1;
        int B2;
        int C;
    }power;
    char *a;
    char *b1;
    char *b2;
    char *c;
    char *ans;
    char *tmp;
    char* (*rescat)(char *str,int power);
}karatsuba_result;
char *itoa(int num){
    int get_len = num;
    int i;
    for(i=0;get_len!=0;get_len/=10,i++);
    char *res = (char*)malloc(sizeof(char)*(i+1));
    char *refresh = (char*)malloc(sizeof(char)*(i+1));
    res[i]='\0';
    for(int j=i-1;j>=0;j--){
        res[j] = ((num%10)+'0');
        num/=10;
    }
    memcpy(refresh,res,strlen(res));
    free(res);
    res=NULL;
    return refresh;
}
char *Mul_expansion_cat_power(char *str,int power){
    char *res = (char*)malloc(sizeof(char)*(strlen(str)+power+1));
    char *refresh = (char*)malloc(sizeof(char)*(strlen(str)+power+1));
    int i,m;
    for(i=0;i<strlen(str);i++){
        res[i] = str[i];
    }
    for(m=0;m<power;m++,i++){
        res[i] = '0';
    }
    res[i]='\0';
    memcpy(refresh,res,strlen(res));
    refresh[strlen(res)]='\0';
    free(res);res=NULL;
    return refresh;
}
static char *Add(char *left,char *right){
    char *str1,*str2;
    str1 = (char*)malloc(sizeof(char)*strlen(left)+1);
    str2 = (char*)malloc(sizeof(char)*strlen(right)+1);
    memcpy(str1,left,strlen(left)+1);
    memcpy(str2,right,strlen(right)+1);
    int Length = strlen(str1)>strlen(str2)?strlen(str1):strlen(str2);
    char *refresh = (char*)malloc(sizeof(char)*(Length+2));
    char *res = (char*)malloc(sizeof(char)*(Length+2));
    refresh[Length+1]='\0';
    int i,m,s,tmp;
    for(i=Length,m=strlen(str1)-1,s=strlen(str2)-1,tmp=0;i>=0;i--,m--,s--){
        int num = (m>=0?str1[m]-'0':0)+(s>=0?str2[s]-'0':0)+tmp;
        tmp=0;
        refresh[i] = (num%10)+'0';
        tmp = num/10;
    }
    for(i=0;i<strlen(refresh);i++){
        if(refresh[i]!='0')break;
    }
    memcpy(res,&refresh[i],strlen(refresh)-i);
    res[strlen(refresh)-i]='\0';
    free(refresh);refresh=NULL;
    if(res[0]=='\0'){
        res[0]='0';res[1]='\0';
    }
    free(str1);
    free(str2);
    str1=NULL;
    str2=NULL;
    return res;
}
static struct karatsuba Mul_expansion_karatsuba_parser(char *left,char *right){
    char *str1,*str2;
    str1 = (char*)malloc(sizeof(char)*strlen(left)+1);
    str2 = (char*)malloc(sizeof(char)*strlen(right)+1);
    memcpy(str1,left,strlen(left)+1);
    memcpy(str2,right,strlen(right)+1);
    struct karatsuba result;
    int length_s1 = strlen(str1);
    int length_s2 = strlen(str2);
    char *getStr_tmp;
    result.a = (char*)malloc(sizeof(char)*(((length_s1&1)?length_s1/2+1:length_s1/2)+1));
    getStr_tmp = (char*)malloc(sizeof(char)*(((length_s1&1)?length_s1/2+1:length_s1/2)+1));
    for(int i=((length_s1&1)?length_s1/2+1:length_s1/2)-1;i>=0;i--){
        getStr_tmp[i] = str1[i];
    }
    getStr_tmp[((length_s1&1)?length_s1/2+1:length_s1/2)]='\0';
    memcpy(result.a,getStr_tmp,strlen(getStr_tmp));
    result.a[strlen(getStr_tmp)]='\0';
    free(getStr_tmp);getStr_tmp=NULL;
    result.c = (char*)malloc(sizeof(char)*(((length_s2&1)?length_s2/2+1:length_s2/2)+1));
    getStr_tmp = (char*)malloc(sizeof(char)*(((length_s2&1)?length_s2/2+1:length_s2/2)+1));
    for(int i=((length_s2&1)?length_s2/2+1:length_s2/2)-1;i>=0;i--){
        getStr_tmp[i] = str2[i];
    }
    getStr_tmp[((length_s2&1)?length_s2/2+1:length_s2/2)]='\0';
    memcpy(result.c,getStr_tmp,strlen(getStr_tmp));
    result.c[strlen(getStr_tmp)]='\0';
    free(getStr_tmp);getStr_tmp=NULL;
    result.b = (char*)malloc(sizeof(char)*((length_s1/2)+1));
    getStr_tmp = (char*)malloc(sizeof(char)*((length_s1/2)+1));
    for(int i=((length_s1&1)?length_s1/2+1:length_s1/2),m=0;i<=length_s1;i++,m++){
        if(i==length_s1){
            getStr_tmp[m]='\0';
            break;
        }
        getStr_tmp[m] = str1[i];
    }
    memcpy(result.b,getStr_tmp,strlen(getStr_tmp));
    result.b[strlen(getStr_tmp)]='\0';
    free(getStr_tmp);getStr_tmp=NULL;
    result.d = (char*)malloc(sizeof(char)*((length_s1/2)+1));
    getStr_tmp = (char*)malloc(sizeof(char)*((length_s1/2)+1));
    for(int i=((length_s2&1)?length_s2/2+1:length_s2/2),m=0;i<=length_s2;m++,i++){
        if(i==length_s2){
            getStr_tmp[m]='\0';
            break;
        }
        getStr_tmp[m] = str2[i];
    }
    memcpy(result.d,getStr_tmp,strlen(getStr_tmp));
    result.d[strlen(getStr_tmp)]='\0';
    free(getStr_tmp);getStr_tmp=NULL;
    result.n = length_s1/2;
    result.m = length_s2/2;
    free(str1);free(str2);
    str1=NULL;str2=NULL;
    printf("%s\t%s\t%s\t%s\n",result.a,result.b,result.c,result.d);
    return result;
}
static char *Mul(char *str1,char *str2){
    
    transfer transfer;
    transfer.itoa = itoa;
    karatsuba_result res;
    int length_s1 = strlen(str1);
    int length_s2 = strlen(str2);
    if(length_s1+length_s2<4){
        res.ans=transfer.itoa(atoi(str1)*atoi(str2));
        return res.ans;
    }
    int Length = length_s1+length_s2;
    struct karatsuba str = Mul_expansion_karatsuba_parser(str1,str2);
    res.rescat = Mul_expansion_cat_power;
    if(strlen(str.a)+strlen(str.c)<9)res.a = transfer.itoa(atoi(str.a)*atoi(str.c));
    else if(strlen(str.a)+strlen(str.c)>8)res.a = Mul(str.a,str.c);
    res.power.A = str.n+str.m;
    res.tmp = res.rescat(res.a,res.power.A);
    free(res.a);
    res.a=NULL;
    res.a = (char*)malloc(sizeof(char)*(strlen(res.tmp)+1));
    memcpy(res.a,res.tmp,(strlen(res.tmp)+res.power.A));
    res.a[strlen(res.tmp)]='\0';
    free(res.tmp);
    res.tmp=NULL;
    if(strlen(str.a)+strlen(str.d)<9)res.b1 = transfer.itoa(atoi(str.a)*atoi(str.d));
    else if(strlen(str.a)+strlen(str.d)>8)res.b1 = Mul(str.a,str.d);
    res.power.B1 = str.n;
    res.tmp = res.rescat(res.b1,res.power.B1);
    free(res.b1);
    res.b1=NULL;
    res.b1 = (char*)malloc(sizeof(char)*(strlen(res.tmp)+1));
    memcpy(res.b1,res.tmp,(strlen(res.tmp)+res.power.B1));
    res.b1[strlen(res.tmp)]='\0';
    free(res.tmp);res.tmp=NULL;
    if(strlen(str.c)+strlen(str.b)<9)res.b2 = transfer.itoa(atoi(str.c)*atoi(str.b));
    else if(strlen(str.c)+strlen(str.b)>8)res.b2 = Mul(str.c,str.b);
    res.power.B2 = str.m;
    res.tmp = res.rescat(res.b2,res.power.B2);
    free(res.b2);
    res.b2=NULL;
    res.b2 = (char*)malloc(sizeof(char)*(strlen(res.tmp)+1));
    memcpy(res.b2,res.tmp,(strlen(res.tmp)+res.power.B2));
    res.b2[strlen(res.tmp)]='\0';
    free(res.tmp);
    res.tmp=NULL;
    if(strlen(str.b)+strlen(str.d)<9)res.c = transfer.itoa(atoi(str.b)*atoi(str.d));
    else if(strlen(str.b)+strlen(str.d)>8)res.c = Mul(str.b,str.d);
    res.power.C = 0;/*c has problem*/
    res.tmp = Add(res.a,res.b1);
    res.ans = Add(res.tmp,res.b2);
    free(res.tmp);
    res.tmp = Add(res.ans,res.c);
    free(res.ans);
    res.ans = (char*)malloc(sizeof(char)*(strlen(res.tmp)+1));
    memcpy(res.ans,res.tmp,strlen(res.tmp));
    res.ans[strlen(res.tmp)]='\0';
    free(res.tmp);
    res.tmp = NULL;
    
    free(res.a);
    free(res.b1);
    free(res.b2);
    free(res.c);
    free(str.a);
    free(str.b);
    free(str.c);
    free(str.d);
    res.a=NULL;res.b1=NULL;res.b2=NULL;res.c=NULL;str.a=NULL;str.b=NULL;str.c=NULL;str.d=NULL;
    return res.ans;
}

int main(){
    printf("%s\n",Mul("999999999999999999999999999999999999999999999999999999999999","9999999999999999999999999999999999999999999999999999999999999999999999"));
    return 0;
}