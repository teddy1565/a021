#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int strLen = 600;
char **Split_String(char *input,char split_c){
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
int ctoi(char c){
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
char itoc(int n){
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
char *itoa(int num){
    char *result = (char*)malloc(sizeof(char)*10);
    result[10] = '\0';
    int index=9;
    while(num>0&&index>=0){
        result[index] = itoc(num%10);
        num/=10;index--;
    }
    return &result[index+1];
}
char *Add(char *s1,char *s2){
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
    free(temp);
    if(result[0]!='0')return result;
    while(*++result=='0');
    return result;
}

char *Sub(char *s1,char *s2){
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
char *Mul_expansion_classic(char *s1,char *s2){
    if(strlen(s1)+strlen(s2)>8)return "too big";
    char *result = (char*)malloc(sizeof(strlen(s1)+strlen(s2)));
    result = itoa(atoi(s1)*atoi(s2));
    return result;
}
char *Mul(char *s1,char*s2){
    for(int i=0;i<=strlen(s1);i++){
        if(i==strlen(s1))return "0";
        if(s1[i]!='0')break;
    }
    for(int i=0;i<=strlen(s2);i++){
        if(i==strlen(s2))return "0";
        if(s2[i]!='0')break;
    }
    char *a,*b,*c,*d;
    int n = strlen(s1)/2,m = strlen(s2)/2;
    if(strlen(s1)<5&&strlen(s2)<5)return Mul_expansion_classic(s1,s2);
    b = (char*)malloc(sizeof(char)*((strlen(s1)/2)+1));b[(strlen(s1)/2)] = '\0';
    d = (char*)malloc(sizeof(char)*((strlen(s2)/2)+1));d[(strlen(s2)/2)] = '\0';
    if(strlen(s1)&1){
        a = (char*)malloc(sizeof(char)*((strlen(s1)/2)+2));a[(strlen(s1)/2)+1] = '\0';
        for(int i=0,m=0;i<strlen(s1);i++){
            if(i<=(strlen(s1)/2)){a[i] = s1[i];}
            else{b[m] = s1[i];m++;}
        }
    }else{
        a = (char*)malloc(sizeof(char)*(strlen(s1)/2)+1);a[(strlen(s1)/2)] = '\0';
        for(int i=0,m=0;i<strlen(s1);i++){
            if(i<(strlen(s1)/2)){a[i] = s1[i];}
            else{b[m] = s1[i];m++;}
        }
    }
    if(strlen(s2)&1){
        c = (char*)malloc(sizeof(char)*((strlen(s2)/2)+2));c[(strlen(s2)/2)+2] = '\0';
        for(int i=0,m=0;i<strlen(s2);i++){
            if(i<=(strlen(s2)/2)){c[i] = s2[i];}
            else{d[m] = s2[i];m++;}
        }
    }else{
        c = (char*)malloc(sizeof(char)*((strlen(s2)/2)+1));c[(strlen(s2)/2)+1] = '\0';
        for(int i=0,m=0;i<strlen(s2);i++){
            if(i<(strlen(s2)/2)){c[i] = s2[i];}
            else{d[m] = s2[i];m++;}
        }
    }
    char *A = (char*)malloc(sizeof(char)*(strlen(a)+strlen(c)+n+m+1));
    char *A_power = (char*)malloc(sizeof(char)*(n+m+1));
    A_power[n+m]='\0';
    for(int i=0;i<n+m;i++){
        A_power[i]='0';
    }
    A[0]='\0';
    if(strlen(a)+strlen(c)<=8)strcat(A,Mul_expansion_classic(a,c));
    else strcat(A,Mul(a,c));
    strcat(A,A_power);
    char *B1 = (char*)malloc(sizeof(char)*(strlen(a)+strlen(d)+n+1));
    char *B1_power = (char*)malloc(sizeof(char)*(n+1));
    B1_power[n] = '\0';
    for(int i=0;i<n;i++){
        B1_power[i]='0';
    }
    B1[0]='\0';
    if(strlen(a)+strlen(d)<=8)strcat(B1,Mul_expansion_classic(a,d));
    else strcat(B1,Mul(a,d));
    strcat(B1,B1_power);
    char *B2 = (char*)malloc(sizeof(char)*(strlen(c)+strlen(b)+m+1));
    char *B2_power = (char*)malloc(sizeof(char)*(m+1));
    B2_power[m] = '\0';
    for(int i=0;i<m;i++){
        B2_power[i]='0';
    }
    B2[0]='\0';
    if(strlen(c)+strlen(b)<=8)strcat(B2,Mul_expansion_classic(c,b));
    else strcat(B2,Mul(c,b));
    strcat(B2,B2_power);
    char *C = (char*)malloc(sizeof(char)*(strlen(b)+strlen(d)+1));
    C[0]='\0';
    if(strlen(b)+strlen(d)<=8)strcat(C,Mul_expansion_classic(b,d));
    else strcat(C,Mul(b,d));
    return "0";
}
char *Div(char *s1,char*s2){return "hello div";}
int main(){
    char input[strLen];
    while(fgets(input,strLen,stdin)!=NULL){
        char **s = Split_String(input,' ');
        char *res;
        if(*s[1]=='+')res = Add(s[0],s[2]);
        else if(*s[1]=='-')res = Sub(s[0],s[2]);
        else if(*s[1]=='*')res = Mul(s[0],s[2]);
        else if(*s[1]=='/')res = Div(s[0],s[2]);
        printf("%s\n",res);
        free(s);
    }
    return 0;
}