#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char *String;
static const int strLen = 600;
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
static char *ctob(char n){
    if(n=='1')return "0001";
    else if(n=='2')return "0010";
    else if(n=='3')return "0011";
    else if(n=='4')return "0100";
    else if(n=='5')return "0101";
    else if(n=='6')return "0110";
    else if(n=='7')return "0111";
    else if(n=='8')return "1000";
    else if(n=='9')return "1001";
    return "0000";
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
static void Split_string(int String_length,char **String_array,char *str,char c){
    for(int i=0,p=0;i<3;i++){
        for(int j=p;j<=String_length;j++){
            if(str[j]==c||str[j]=='\0'||str[j]=='\n'){
                String_array[i] = &str[p];
                str[j]='\0';
                j++;p=j;
                break;
            }
        }
    }
}
static int string_length(char *str){
    int i=0;
    while(str[i]!='\n'&&str[i]!='\0')i++;
    return i;
}
/*add calcution*/
static char *Add(char *Left_string,char *Right_string){
    String result = malloc(sizeof(char)*strLen);
    String Left = malloc(sizeof(char)*strLen);
    String Right = malloc(sizeof(char)*strLen);
    //Declare Left and Right string to save keyin data
    //prevent overflow
    int Left_string_length=string_length(Left_string);
    int Right_string_length=string_length(Right_string);
    memcpy(Left,Left_string,strLen);
    memcpy(Right,Right_string,strLen);
    //calcution
    for(int i=Left_string_length-1,j=Right_string_length-1,k=strLen-1,temp=0;k>=0;k--){
        if(i>=0&&j>=0){
            result[k] = itoc((temp+ctoi(Left[i])+ctoi(Right[j]))%10);
            temp = (ctoi(Left[i])+ctoi(Right[j])+temp)/10;
            i--;j--;
        }else if(i>=0){
            result[k] = itoc((ctoi(Left[i])+temp)%10);
            temp = (ctoi(Left[i])+temp)/10;
            i--;
        }else if(j>=0){
            result[k] = itoc((ctoi(Right[j])+temp)%10);
            temp = (ctoi(Right[j]+temp)+temp)/10;
            j--;
        }else{
            result[k] = itoc(0+temp);
            temp = 0;
        }
    }
    //return pointer
    for(int i=0;i<strLen;i++){
        if(result[i]!='0')return &result[i];
    }
    return "0\0";
}
/*sub calcution*/
static char *Sub(char *Left_string,char *Right_string){
    String result = malloc(sizeof(char)*strLen);
    String Left = malloc(sizeof(char)*strLen);
    String Right = malloc(sizeof(char)*strLen);
    memcpy(Left,Left_string,strLen);
    memcpy(Right,Right_string,strLen);
    int Left_string_length = string_length(Left);
    int Right_string_length = string_length(Right);
    result[strLen-1]=itoc(10-ctoi(Right[Right_string_length-1]));
    for(int i=strLen-2,j=Right_string_length-2;i>=0;i--,j--){
        if(j>=0)result[i] = itoc(9-ctoi(Right[j]));
        else result[i] = '9';
    }
    char *answer = Add(Left,&result[strLen-Left_string_length]);
    return &answer[1];
}
/*Multiplication calcution*/
static char *Mul(char *Left_string,char *Right_string){
    String Left = malloc(sizeof(char)*strLen); //宣告字元陣列 存放輸入的資料 strLen為本題上限
    String Right = malloc(sizeof(char)*strLen);
    memcpy(Left,Left_string,strLen);//複製資料到函式內部變數 由於是傳入pointer 為了避免錯誤的存取 因此另外存放值
    memcpy(Right,Right_string,strLen);//外部輸入的資料整體EX: {'1','2','3','\0','+','\0','4','5','6','\0'} 因此傳不同的地址 作為不同的字串
    int Left_string_length = string_length(Left);
    int Right_string_length = string_length(Right);//取得字串長度
    String ans = malloc(sizeof(char)*strLen);//宣告存放答案的陣列 strLen為此題上限(600)
    memset(ans,'0',strLen);//預設全為'0'用以處理資料 其性質如 int sum=0;
    for(int i=Left_string_length;i>0;i--){//遍歷Left陣列
        for(int j=Right_string_length;j>0;j--){//遍歷Right陣列
            //res作為計算的暫存陣列 其長度res_length為n+2 n為加權位數 10^n 2為10進制個位數上限 9*9=81
            int res_length = (Left_string_length-i)+(Right_string_length-j)+2;
            char *res = malloc(sizeof(char)*res_length);
            //字元個位數轉ｉｎｔ後相乘
            int num = ctoi(Left[i-1])*ctoi(Right[j-1]);
            //將num轉型為*char 並存入暫存陣列
            memcpy(res,itoa(num),res_length);
            int res_p=0;
            while(res[res_p]!='\0'&&res[res_p]!='\n')res_p++;
            //因為不確定 相成後的num位數為1或2因此用res_p取得其位置
            for(int s=0;s<res_length-2;s++,res_p++){
                //補上0作為加權
                res[res_p]='0';
            }
            res[res_p]='\0';
            memcpy(ans,Add(ans,res),strLen);
            //將所有個位數相成加權後的字串相加
        }
    }
    return ans;
}
/*Division Calcution*/
static int Div_expansion_match_A_to_B(char *s1,char *s2){ //check string A = B ? if A == B return 0 else return 1
    int i=0;
    int def = 0;
    if(string_length(s1)!=string_length(s2))return 1;
    while(s1[i]!='\n'&&s1[i]!='\0'&&s2[i]!='\n'&&s2[i]!='\0'){
        if(s1[i]!=s2[i])def++;
        i++;
    }
    if(def!=0)return 1;
    return 0;
}
static int Div_expansion_match_zero_string(char *s){
    int a=0;
    int zero_counter=0;
    while(s[a]!='\0'&&s[a]!='\n'){
        if(s[a]=='0')zero_counter++;
        a++;
    }
    if(a==zero_counter)return 1;
    return 0;
}
static int Div_expansion_compare_A_and_B(char *divisor,char *dividend){//need to know that who is bigger
    //example input :(12,456)
    int divisor_length = string_length(divisor);
    int dividend_length = string_length(dividend);
    char *divisor_complement;
    printf("%s , %s\n",divisor,dividend);
    if(divisor_length>dividend_length)return 0;
    else if(divisor_length<dividend_length){
        divisor_complement = malloc(sizeof(char)*dividend_length+1);
        for(int i=0;i<dividend_length;i++){
            if(i<(dividend_length-divisor_length)){
                divisor_complement[i] = '0';
            }else{
                divisor_complement[i] = divisor[i-divisor_length];
            }
            printf("complement:%s\n",divisor_complement);
        }
    }
    printf("divisor_complement:%s\ndividend:%s\n",divisor_complement,dividend);
    return 0;
}
static char *Div(char *Left_string,char *Right_string){
    /*initial setting*/
    /*
        copy Left and Right string prevention operation overflow
        Left s
    */
    int dividend_length = string_length(Left_string);
    int divisor_length = string_length(Right_string);
    String dividend = malloc(sizeof(char)*dividend_length);
    String divisor = malloc(sizeof(char)*divisor_length);
    memcpy(dividend,Left_string,dividend_length);
    memcpy(divisor,Right_string,divisor_length);
    /*simple filter*/
    /*
        if dividend equal divisor return 1
        else if dividend equal 2*divisor return 2
        else if dividend equal 0 then return 0
     */
    if(Div_expansion_match_A_to_B(dividend,divisor)==0)return "1";
    else if(Div_expansion_match_A_to_B(dividend,Mul(divisor,"2"))==0)return "2";
    if(Div_expansion_match_zero_string(dividend)==1||Div_expansion_match_zero_string(divisor)==1)return "0";
    /*calcu*/
    char *temp_dividend;
    char *remainder;
    char *quotient;
    Div_expansion_compare_A_and_B("12","456");
    return "---end---";
}
int main(){
    String keyin = malloc(sizeof(char)*600);
    while(fgets(keyin,strLen,stdin)!=NULL){
        char *Split_char[3];
        int String_length = string_length(keyin);
        Split_string(String_length,Split_char,keyin,' ');
        if(Split_char[1][0]=='+')printf("%s",Add(Split_char[0],Split_char[2]));
        else if(Split_char[1][0]=='-')printf("%s",Sub(Split_char[0],Split_char[2]));
        else if(Split_char[1][0]=='*')printf("%s",Mul(Split_char[0],Split_char[2]));
        else if(Split_char[1][0]=='/')printf("%s",Div(Split_char[0],Split_char[2]));
        printf("\n");
    }
    return 0;
}