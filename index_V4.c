//no use Dynamac
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int main(){
    char str[600];
    while(fgets(str,600,stdin)!=NULL){
        /*split str*/
        char Left[500],Right[500],operator,result[600];
        result[599]='\0';
        for(int i=0;i<strlen(str);i++){
            if(str[i]!=' '){
                Left[i] = str[i];
            }else break;
        }
        for(int i=0;i<strlen(str);i++){
            if(str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/')continue;
            else{
                operator = str[i];
                break;
            }
        }
        for(int i=0,m=0,f=0;i<strlen(str);i++){
            if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')f = 1;
            if(f==0)continue;
            else if(f!=0){
                if(str[i]=='\0'||str[i]==' '||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')continue;
                Right[m] = str[i];m++;
            }
        }
        if(operator=='+'){
            if(strlen(Left)<strlen(Right)){

            }else{
                int temp=0;
                int m;
                for(int i=strlen(Left)-1,m=2,k=strlen(Right)-1;i>=0;i--,m++,k--){
                    int ADD_num = ((Left[i]-'0')+(k>=0?Right[k]-'0':0)+temp);
                    result[strlen(result)-m] = itoc(ADD_num%10);    
                    temp = 0;
                    temp = ADD_num/10;
                }
                result[strlen(result)-m] = itoc(temp);
                printf("%s\n",&result[strlen(result)-m]);
            }
        }else if(operator=='-'){

        }else if(operator=='*'){

        }else if(operator=='/'){

        }
    }
    return 0;
}