#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char string[600];
const int strLen = 600;
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
char *add(string Left,string Right,int L,int R){
    if(L<R){
        string temp_str;
        L = L^R;
        R = L^R;
        L = L^R;
        memset(temp_str,'\0',strLen);
        memcpy(Right,temp_str,strLen);
        memcpy(Left,Right,strLen);
        memcpy(temp_str,Left,strLen);
    }
    char *result = malloc(sizeof(char)*strLen);
    memset(result,'0',strLen);
    int end=L;
    result[end+1]='\0';
    for(int i=L,temp=0;i>=0;i--){
        int bit_num = 0;
        if(R!=0)bit_num=ctoi(Left[L-1])+ctoi(Right[R-1]);
        else if(R==0&&L!=0)bit_num=ctoi(Left[L-1]);
        else if(R==0&&L==0){
            bit_num = temp;
            temp = 0;
        }
        if(temp!=0){
            bit_num = bit_num+temp;
            temp=0;
        }
        if(bit_num>=10){
            temp = bit_num/10;
            bit_num = bit_num%10;
        }
        result[i]=itoc(bit_num);
        R--;L--;
    }
    if(result[0]=='0'){
        string temp;
        memset(temp,'\0',strLen);
        for(int i=0;i<end;i++){
            temp[i]=result[i+1];
        }
        memcpy(result,temp,strLen);
    }
    return result;
}
char *sub(string Left,string Right,int L,int R){
    char *str = malloc(sizeof(char)*strLen);
    string complement;
    memset(complement,'\0',strLen);
    memset(str,'\0',strLen);
    int biger=0;
    if(L==R){
        for(int i=0;i<L;i++){
            if(ctoi(Left[i])>ctoi(Right[i])){
                biger=1;
                break;
            }else if(ctoi(Left[i])<ctoi(Right[i])){
                biger=2;
                break;
            }
        }
        if(biger==0){
            str[0]='0';
            str[1]='\0';
            return str;
        }
    }
    if(L>R||biger==1){
        for(int i=L-1,j=R;i>=0;i--,j--){
            if(i==L-1)complement[i] = itoc((10-ctoi(Right[j-1])));
            else if(j!=0)complement[i] = itoc((9-ctoi(Right[j-1])));
            else if(j==0)complement[i] = '9';
        }
        str = add(Left,complement,L,L);
    }
    if(R>L||biger==2){
        for(int i=R-1,j=L;i>=0;i--,j--){
            if(i==R-1)complement[i] = itoc((10-ctoi(Left[j-1])));
            else if(j!=0)complement[i]=itoc((9-ctoi(Left[j-1])));
            else if(j==0)complement[i]='9';
        }
        str = add(Right,complement,R,R);
    }
    string temp;
    memset(temp,'\0',strLen);
    memcpy(temp,str,strLen);
    memset(str,'\0',strLen);
    if(L>R||biger==1){
        for(int i=0,c=0,m=0;temp[i+1]!='\0'&&temp[i+1]!='\n';i++){
            if(temp[i+1]=='0'&&c==0)continue;
            else if(temp[i+1]!='0')c=1;
            str[m] = temp[i+1];m++;
        }
    }else if(R>L||biger==2){
        for(int i=0,c=0,m=1;temp[i+1]!='\0'&&temp[i+1]!='\n';i++){
            if(temp[i+1]=='0'&&c==0)continue;
            else if(temp[i+1]!='0')c=1;
            str[m] = temp[i+1];m++;
        }
        str[0]='-';
    }
    return str;
}
int multiplication_expansion_get_karatsuba_exponentiation_power(char *str){
    int i=0;
    char *res = malloc(sizeof(char)*strLen);
    memset(res,'\0',strLen);
    while(str[i]!='^')i++;
    for(int j=0;str[i]!='\n'&&str[i]!='\0';j++,i++){
        if(str[i+1]=='+')break;
        res[j] = str[i+1];
    }
    return atoi(res);
}
char *multiplication_expansion_format_string_to_karatsuba(string str,int string_length){
    char *res = malloc(sizeof(char)*strLen);
    memset(res,'\0',strLen);
    int n = string_length%2==0?(string_length/2):(string_length/2)+1;
    for(int i=0;i<n;i++){
        res[i] = str[i];
    }
    char snas[10];
    int reservation = sprintf(snas,"%d",string_length/2);
    for(int m=n,i=n+2+reservation;m<string_length;i++,m++){
        res[i] = str[m];
    }
    res[n] = '^';
    for(int i=0;i<reservation;i++){
        res[n+1+i]=snas[i];
    }
    res[n+reservation+1]='+';
    return res;
}
char *multiplication_exponsion_refresh_string_exponsion_add_exponentiation_power(char *s,int exponentiation_power){
    printf("expon_start:%s\n",s);
    int power = multiplication_expansion_get_karatsuba_exponentiation_power(s);
    int expon_power = exponentiation_power;
    string c_power;
    string c_expon_power;
    char *refresh=malloc(sizeof(char)*strLen);
    memset(c_power,'\0',strLen);
    memset(c_expon_power,'\0',strLen);
    memset(refresh,'\0',strLen);
    int c_power_bit,c_expon_power_bit;
    c_power_bit = sprintf(c_power,"%d",power+expon_power);
    c_expon_power_bit = sprintf(c_expon_power,"%d",expon_power);
    for(int i=0;i<power;i++){
        refresh[i]=s[i];
    }
    refresh[power]='^';
    for(int i=0;i<c_power_bit;i++){
        refresh[power+1+i] = c_power[i];
    }
    for(int i=power+c_power_bit+1,l=power;s[l]!='\n'&&s[l]!='\0';l++){
        if(s[l]=='+'){
            for(int j=l;s[j]!='\n'&&s[j]!='\0';j++,i++){
                refresh[i] = s[j];
            }
            for(int j=i+1,sr=0;sr<c_expon_power_bit;sr++,j++){
                refresh[j] = c_expon_power[sr];
            }
            refresh[i]='^';
            break;
        }
    }
    printf("expon_end:%s\n",refresh);
    return refresh;
}
char *multiplication_exponsion_refresh_string_exponsion_check_string_length(char *str){
    int operator_counter_position[600];
    int operator_counter=0;
    char *refresh = malloc(sizeof(char)*strLen);
    memset(operator_counter,0,600);
    for(int i=0;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='+'){
            operator_counter_position[operator_counter]=i;
            operator_counter++;
        }
    }
    for(int i=0,j=0;i<operator_counter;i++){
        memset(refresh,'\0',strLen);
        for(int k=0;j<operator_counter_position[i];j++,k++){
            if(str[j]=='^'){
                //call *multiplication_expansion_format_string_to_karatsub
                //reference multiplication_expansion_format_karatsuba_string_refresh
                
            }
            refresh[k] = str[j];
        }
    }
}
char *multiplication_expansion_format_karatsuba_string_refresh(char *str){
    char *refresh_string = malloc(sizeof(char)*strLen);
    char multiplication_exponentiation_power[100];
    memset(multiplication_exponentiation_power,'\0',100);
    memset(refresh_string,'\0',100);

    for(int i=0;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='^'){
            for(int m=0,j=i+1;str[j]!='\0'&&str[j]!='\n';j++,m++){
                if(str[j]=='+')break;
                multiplication_exponentiation_power[m] = str[j];
            }
            memcpy(refresh_string,multiplication_expansion_format_string_to_karatsuba(refresh_string,i),strLen);
            break;
        }
        refresh_string[i] = str[i];
    }
    memcpy(refresh_string,multiplication_exponsion_refresh_string_exponsion_add_exponentiation_power(refresh_string,atoi(multiplication_exponentiation_power)),strLen);
    multiplication_exponsion_refresh_string_exponsion_check_string_length(refresh_string);
    for(int i=0;str[i]!='\n'&&str[i]!='\0';i++){
        if(str[i]=='+'){
            int j=0;
            while(refresh_string[j]!='\0'&&refresh_string[j]!='\n')j++;
            for(int k=j;str[i]!='\n'&&str[i]!='\0';k++,i++){
                refresh_string[k]=str[i];
            }
            break;
        }
    }
    return refresh_string;
}

char *mul(string Left_string,string Right_string,int Left_string_length,int Right_string_length){
    char *Left,*Right;
    int L=0,R=0;
    if(Left_string_length>5){
        Left = multiplication_expansion_format_string_to_karatsuba(Left_string,Left_string_length);
        printf("first:%s\n",Left);
        L = multiplication_expansion_get_karatsuba_exponentiation_power(Left);
        if(L>5){
            printf("refresh:%s\n",multiplication_expansion_format_karatsuba_string_refresh(Left));
        }
    }
    if(Right_string_length>5){
        Right = multiplication_expansion_format_string_to_karatsuba(Right_string,Right_string_length);
    }
    return "======";
}
int main(){
    string str;
    string Right_string;
    string Left_string;
    memset(str,'\0',strLen);
    while(fgets(str,strLen,stdin)!=NULL){
        memset(Left_string,'\0',strLen);
        memset(Right_string,'\0',strLen);
        int operator=0;
        int L=0,R=0;
        for(int i=0;str[i]!='\n'&&str[i]!='\0';i++){
            if(str[i]==' ')continue;
            else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
                operator = i;
                break;
            }
            Left_string[L]=str[i];L++;
        }
        for(int i=operator+1;str[i]!='\n'&&str[i]!='\0';i++){
            if(str[i]==' ')continue;
            Right_string[R]=str[i];R++;
        }
        if(str[operator]=='+') printf("%s",add(Left_string,Right_string,L,R));
        else if(str[operator]=='-') printf("%s",sub(Left_string,Right_string,L,R));
        else if(str[operator]=='*')printf("%s",mul(Left_string,Right_string,L,R));
        printf("\n");
    }
    return 0;
}