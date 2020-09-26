#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char *String;
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
static char *itoa(int n){
    int length = 0;
    int ncpy = n;
    while(ncpy!=0){
        ncpy/=10;
        length++;
    }
    String result = malloc(sizeof(char)*length);
    for(int i=length-1;i>=0;i--){
        result[i] = itoc(n%10);
        n/=10;
    }
    return result;
}
int get_string_length(char *str){
    int length=0;
    while(str[length]!='\n'&&str[length]!='\0')length++;
    return length;
}

char *calcution(char *str1,char *str2){
    int s1_length = get_string_length(str1);
    int s2_length = get_string_length(str2);
    String *ans = malloc(sizeof(char)*(s1_length+s2_length));
    memset(ans,'0',(s1_length+s2_length));
    for(int i=s1_length;i>0;i--){
        for(int j=s2_length;j>0;j--){
            int res_length = ((s1_length-i)+(s2_length-j)+2);
            char *res = malloc(sizeof(char)*res_length);
            int num = ctoi(str1[i-1])*ctoi(str2[j-1]);
            memcpy(res,itoa(num),res_length);
            int res_p=0;
            while(res[res_p]!='\0')res_p++;
            for(int s=0;s<res_length-2;s++,res_p++){
                res[res_p]='0';
            }
            res[res_p]='\0';
        }
    }
    return "hello world";
}
int main(){
    String numA = malloc(sizeof(char)*500);
    String numB = malloc(sizeof(char)*500);
    scanf("%s",numA);
    scanf("%s",numB);
    printf("%s\n",calcution(numA,numB));
    return 0;
}