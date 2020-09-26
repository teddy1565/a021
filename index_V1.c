#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int strLen = 600;
static char **Split_String(char *input,char split_c){
    int input_length = 0;
    while(input[input_length]!='\0'&&input[input_length]!='\n')input_length++;
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
static int Get_string_length(char *str){
    int i=0;
    while(str[i]!='\n'&&str[i]!='\0')i++;
    return i;
}
static char *itoa(int n){
    int tens = 0;
    for(int ten_n = n-10;ten_n>=0;ten_n-=10){
        tens++;
    }
    n -= (tens)*10;
    char *result = (char*)malloc(sizeof(char)*2);
    memset(result,'0',2);
    result[1] = itoc(n);
    if(tens==0)return &result[1];
    result[0] = itoc(tens);
    return result;
}
static char *Add(char *L,char *R){
    int Left_length = Get_string_length(L);int Right_length = Get_string_length(R);
    char *p = L;
    if(Left_length<Right_length){
        p = R;R = L;L = p;
        Right_length = Right_length^Left_length;Left_length =  Left_length^Right_length;Right_length = Right_length^Left_length;
    }
    char *result = (char*)malloc(sizeof(char)*Left_length+1);
    memset(result,'0',Left_length);
    result[Left_length+1]='\0';
    for(int i=Left_length-1,j=Right_length-1,k=Left_length,temp=0;k>=0;k--){
        if(j>=0){
            result[k] = itoc((ctoi(L[i]) + ctoi(R[j]) + temp)%10);
            temp = (ctoi(L[i]) + ctoi(R[j])+temp)/10;
            i--;j--;
        }else if(i>=0){
            result[k] = itoc((ctoi(L[i])+temp)%10);
            temp = (ctoi(L[i])+temp)/10;
            i--;
        }else{
            result[k] = itoc(temp%10);
            temp = 0;
        }
    }
    for(int i=0;i<Left_length;i++){
        if(result[i]!='0')return &result[i];   
    }
    return &result[Left_length];
}
static char *Sub(char *L,char *R){
    int Left_length = Get_string_length(L);
    int Right_length = Get_string_length(R);
    char small = 'R';
    char *complement;
    char *p;
    if(Left_length<Right_length)small = 'L';
    else if(Left_length==Right_length){
        for(int i=0;i<Left_length;i++){
            if(ctoi(L[i])>ctoi(R[i]))break;
            else if(ctoi(L[i])==ctoi(R[i]))continue;
            else if(ctoi(L[i])<ctoi(R[i])){
                small = 'L';
                break;
            }
        }
    }
    if(small=='L'){
        p = R;R = L;L = p;
        Left_length = Left_length^Right_length;Right_length = Right_length^Left_length;Left_length = Left_length^Right_length;
    }
    complement = (char*)malloc(sizeof(char)*(Left_length));
    memset(complement,'0',Left_length);
    complement[Left_length] = '\0';
    complement[Left_length-1] = itoc(10-ctoi(R[Right_length-1]));
    for(int i=Right_length-2,m=Left_length-2;m>=0;m--){
        if(i>=0)complement[m] = itoc(9-ctoi(R[i]));
        else complement[m] = '9';
    }
    char *result = Add(L,complement);
    if(small == 'L'){
        result[0] = '-';
        return result;
    }
    return &result[1];
}
static char *Mul_expansion_classic_calcution(char *s1,char *s2){
    int s1_leng = Get_string_length(s1);
    int s2_leng = Get_string_length(s2);

}
static char *Mul(char *L,char *R){
    if(strlen(R)>strlen(L)){
        char *p = L;
        L = R;
        R = p;
    }
    char *Rcomplement,*Lcomplement;
    int R_len = strlen(R);
    int L_len = strlen(L);
    Lcomplement = L;
    if((L_len&1)==1){
        Lcomplement = (char*)malloc(sizeof(char)*L_len+2);
        Lcomplement[0] = '0';
        Lcomplement[1] = '\0';
        strcat(Lcomplement,L);
        L_len = strlen(Lcomplement);
    }
    if(R_len!=L_len){
        Rcomplement = (char*)malloc(sizeof(char)*(L_len));
        for(int i=0;i<(L_len-R_len);i++){
            Rcomplement[i] = '0';
            Rcomplement[i+1] = '\0';
        }
        strcat(Rcomplement,R);
    }else{
        Rcomplement = R;
    }
    
    printf("%s\n%s\n",Lcomplement,Rcomplement);
    
    return "A";
}
static char *Div(char *L,char *R){
    return "hello div";
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