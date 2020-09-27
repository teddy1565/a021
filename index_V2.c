#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
static int ctoi(char c){
    if(c=='1')return 1;
    else if(c=='2')return 2;
    else if(c=='3')return 3;
    else if(c=='4')return 4;
    else if(c=='5')return 5;
    else if(c=='6')return 6;
    else if(c=='7')return 7;
    else if(c=='8')return 8;
    else if(c=='9')return 9;
    return 0;
}
static char itoc(int n){
    if(n==1)return '1';
    else if(n==2)return '2';
    else if(n==3)return '3';
    else if(n==4)return '4';
    else if(n==5)return '5';
    else if(n==6)return '6';
    else if(n==7)return '7';
    else if(n==8)return '8';
    else if(n==9)return '9';
    return '0';
}
static char *itoa(int num){
    char *result = (char*)malloc(sizeof(char)*10);
    result[10] = '\0';
    int index=9;
    while(num>0&&index>=0){
        result[index] = itoc(num%10);
        num/=10;index--;
    }
    return &result[index+1];
}
static char *Add(char *s1,char *s2){
    if(strlen(s1)<strlen(s2)){
        return Add(s2,s1);
    }
    const int Leng = strlen(s1);
    char *result = (char*)malloc(sizeof(char)*(Leng+2));
    result[Leng+1] = '\0';
    char *temp = (char*)malloc(sizeof(char)*(Leng+2));
    temp[Leng-strlen(s2)]='\0';
    for(int i=0;i<(Leng - strlen(s2));i++){
        temp[i] = '0';
    }
    strcat(temp,s2);
    for(int i=Leng-1;i>=0;i--){
        int sum = (ctoi(s1[i])+ctoi(temp[i])+ctoi(result[i+1]));
        result[i+1] = itoc(sum%10);
        result[i] = itoc(sum/10);
    }
    if(result[0]!='0')return result;
    while(*++result=='0');
    return result;
}

static char *Sub(char *s1,char *s2){
    if(strlen(s1)<strlen(s2)){
        return Sub(s2,s1);
    }else if(strlen(s1)==strlen(s2)){
        for(int i=0;i<=strlen(s1);i++){
            if(i==strlen(s1))return "0";
            if(ctoi(s1[i])<ctoi(s2[i])){
                return Sub(s2,s1);
            }else if(s1[i]==s2[i])continue;
            break;
        }
    }
    for(int i=0;i<=strlen(s1);i++){
        if(i==strlen(s1))return s2;
        if(s1[i]!='0')break;

    }
    for(int i=0;i<=strlen(s2);i++){
        if(i==strlen(s2))return s1;
        if(s2[i]!='0')break;
    }
    int Leng = strlen(s1);
    char *temp = (char*)malloc(sizeof(char)*(Leng+1));
    temp[Leng] = '\0';
    for(int i=Leng-1,tens=1,m=strlen(s2)-1;i>=0;i--){
        if(m>=0){
            if(tens!=1){
                temp[i] = itoc(9-ctoi(s2[m]));m--;
            }else{
                temp[i] = itoc(10-ctoi(s2[m]));
                if(s2[m]!='0')tens=0;
                m--;
            }
        }else{
            temp[i] = '9';
        }
    }
    char *p = Add(s1,temp);
    while(*++p=='0');
    return p;
}
static char *Mul(char *s1,char*s2){return "hello mul";}
static char *Div(char *s1,char*s2){return "hello div";}
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