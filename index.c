#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* gcc -g -std=c11 -Werror -ansi -pedantic index_V7.c -o a.out */
/*struct*/
typedef struct{
    char res[600];
}String;
typedef struct{
    struct power{
        int n,m;
    }power;
    char a[600],b[600],c[600],d[600];
}Karatsuba_str_format;
typedef struct{
    struct power_str{
        char a[600],b[600],c[600],d[600];
    }power;
    char a[600],b[600],c[600],d[600];
    String temp;
}Karatsuba_result_str;
/*tool*/
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
int swap(char *s1,char *s2){
    char tmp[600];
    int n=0;
    if(strlen(s1)<strlen(s2)){
        strcpy(tmp,s1);
        strcpy(s1,s2);
        strcpy(s2,tmp);
        n=1;
    }
    return n;
}
static String Add_expansion_process(char *res){
    int i,m;
    char *response;
    String sresponse;
    for(i=0;i<=strlen(res);i++){
        if(i==strlen(res)){
            response = (char*)malloc(sizeof(char)*(2));
            response[0]='0';
            response[1]='\0';
            break;
        }else if(res[i]!='0'){
            response = (char*)malloc(sizeof(char)*(strlen(res)-i+1));
            memmove(response,&res[i],strlen(res));
            response[strlen(res)-i]='\0';
            break;
        }
    }
    free(res);
    strcpy(sresponse.res,response);
    free(response);
    return sresponse;
}
static int Zero_check(char *s1,char *s2){
    int i;
    int m = strlen(s1);
    int n = strlen(s2);
    int f=0;
    for(i=0;i<=m;i++)if(s1[i]!='0')break;
    f = i==m?1:0;
    for(i=0;i<=n;i++)if(s2[i]!='0')break;
    f = i==n?1:0;
    return f;
}
static String Add(char *str1,char *str2){
    char *result = (char*)malloc(sizeof(char)*(strlen(str1)+2));
    int i,j,m,tmp,num;
    result[strlen(str1)+1]='\0';
    for(i=strlen(str1),j=strlen(str1)-1,m=strlen(str2)-1,tmp=0;i>=0;i--,j--,m--){
        num = (j>=0?str1[j]-'0':0)+(m>=0?str2[m]-'0':0)+tmp;
        tmp=0;
        result[i] = (num%10)+'0';
        tmp = num/10;
    }
    return Add_expansion_process(result);
}
static String Sub(char *str1,char *str2){
    char *rev = (char*)malloc(sizeof(char)*(strlen(str1)+1));
    String str;
    int i,j,m,tmp,num;
    rev[strlen(str1)]='\0';
    for(i=strlen(str1)-1,j=10,m=strlen(str2)-1;i>=0;i--,m--){
        rev[i] = (j-(m>=0?str2[m]-'0':0))+'0';
        if(str2[m]!='0')j=9;
    }
    strcpy(str.res,rev);
    free(rev);rev=NULL;
    str = Add(str1,str.res);
    rev = (char*)malloc(sizeof(char)*(strlen(str.res)));
    for(i=1;i<strlen(str.res);i++)if(str.res[i]!='0')break;
    for(j=0;i<strlen(str.res);i++,j++)rev[j] = str.res[i];
    if(j!=0)rev[j] = '\0';
    else{
        rev[0]='0';
        rev[1]='\0';
    }
    strcpy(str.res,rev);
    free(rev);rev=NULL;
    return str;
}
static String Mul_expansion_itoa(int n){
    String response;
    int i,len,r=n;
    for(len=0;n!=0;len++)n/=10;
    response.res[len+1]='\0';
    for(;len>=0;len--){
        response.res[len] = (r%10)+'0';
        r/=10;
    }
    return response;
}
static Karatsuba_str_format Mul_expansion_process(char *str1,char *str2){
    Karatsuba_str_format res;
    int i,m,str_parse_length;
    /*A*/
    str_parse_length = (strlen(str1)&1)?(strlen(str1)/2)+1:strlen(str1)/2;
    res.power.n = strlen(str1)/2;
    for(i=0;i<str_parse_length;i++){
        res.a[i] = str1[i];
    }
    res.a[i]='\0';
    /*B*/
    str_parse_length = strlen(str1)/2;
    for(m=0;i<strlen(str1);i++,m++){
        res.b[m] = str1[i];
    }
    res.b[m]='\0';
    /*C*/
    str_parse_length = (strlen(str2)&1)?(strlen(str2)/2)+1:strlen(str2)/2;
    res.power.m = strlen(str2)/2;
    for(i=0;i<str_parse_length;i++){
        res.c[i] = str2[i];
    }
    res.c[i]='\0';
    /*D*/
    str_parse_length = strlen(str2)/2;
    for(m=0;i<strlen(str2);i++,m++){
        res.d[m] = str2[i];
    }
    res.d[m]='\0';
    return res;
}
static String Mul(char *str1,char *str2){
    String response;
    Karatsuba_str_format str;
    Karatsuba_result_str result;
    int i,num;
    str = Mul_expansion_process(str1,str2);
    strcpy(response.res,str1);
    if(strlen(str.a)+strlen(str.c)>8){
        result.temp=Mul(str.a,str.c);
        for(i=0;i<str.power.n+str.power.m;i++){
            result.power.a[i]='0';
        }
        result.power.a[i]='\0';
        strcpy(result.a,result.temp.res);
        strcat(result.a,result.power.a);
    }else if(strlen(str.a)+strlen(str.c)<=8){
        result.temp = Mul_expansion_itoa(atoi(str.a)*atoi(str.c));
        for(i=0;i<str.power.n+str.power.m;i++){
            result.power.a[i]='0';
        }
        result.power.a[i]='\0';
        strcpy(result.a,result.temp.res);
        strcat(result.a,result.power.a);
    }
    if(strlen(str.a)+strlen(str.d)>8){
        result.temp=Mul(str.a,str.d);
        for(i=0;i<str.power.n;i++){
            result.power.b[i]='0';
        }
        result.power.b[i]='\0';
        strcpy(result.b,result.temp.res);
        strcat(result.b,result.power.b);
    }else if(strlen(str.a)+strlen(str.d)<=8){
        result.temp=Mul_expansion_itoa(atoi(str.a)*atoi(str.d));
        for(i=0;i<str.power.n;i++){
            result.power.b[i]='0';
        }
        result.power.b[i]='\0';
        strcpy(result.b,result.temp.res);
        strcat(result.b,result.power.b);
    }
    if(strlen(str.c)+strlen(str.b)>8){
        result.temp=Mul(str.c,str.b);
        for(i=0;i<str.power.m;i++){
            result.power.c[i]='0';
        }
        result.power.c[i]='\0';
        strcpy(result.c,result.temp.res);
        strcat(result.c,result.power.c);
    }else if(strlen(str.c)+strlen(str.b)<=8){
        result.temp = Mul_expansion_itoa(atoi(str.c)*atoi(str.b));
        for(i=0;i<str.power.m;i++){
            result.power.c[i]='0';
        }
        result.power.c[i]='\0';
        strcpy(result.c,result.temp.res);
        strcat(result.c,result.power.c);
    }
    if(strlen(str.b)+strlen(str.d)>8){
        result.temp=Mul(str.b,str.d);
        strcpy(result.d,result.temp.res);
    }else if(strlen(str.b)+strlen(str.d)<=8){
        result.temp = Mul_expansion_itoa(atoi(str.b)*atoi(str.d));
        strcpy(result.d,result.temp.res);
    }
    if(strlen(str1)+strlen(str2)>8){
        /*printf("%s\t%s\n%s\t%s\n",result.a,result.b,result.c,result.d);*/
        response = Add(result.a,result.b);
        response = Add(response.res,result.c);
        response = Add(response.res,result.d);
    }else if(strlen(str1)+strlen(str2)<=8){
        num = atoi(str1)*atoi(str2);
        for(i=9;i>=0;i--){
            result.temp.res[i]=((num>0?num%10:0)+'0');
            num/=10;
        }
        result.temp.res[10]='\0';
        for(i=0;i<=10;i++){
            if(i==10){
                response.res[0]='0';
                response.res[1]='\0';
            }
            if(result.temp.res[i]!='0')break;
        }
        if(i!=10){
            for(num=0;i<=10;i++,num++){
                response.res[num] = result.temp.res[i];
            }
        }
    }
    return response;
}
static int Div_expansion_match(char *s1,char *s2){
    int state=0;
    int i,leng = strlen(s1);
    int n=0;
    if(strlen(s2)>strlen(s1)){
        state = 1;
    }else if(strlen(s1)==strlen(s2)){
        state = 2;
        for(i=0;i<leng;i++){
            n = (s1[i]-'0')-(s2[i]-'0');
            if(n>0){
                state = 0;
                break;
            }else if(n<0){
                state = 1;
                break;
            }
        }
    }
    return state;
}
static String Div(char *str1,char *str2){
    /*  0:s1    >   s2 */
    /*  1:s1    <   s2 */
    /*  2:s1    =   s2 */
    String response;
    String Division_n = Add("0","0");
    String MOD_num = Add("0","0");
    String Split_str,tmp;
    int i,m=0,s,k=0,u;
    if(Zero_check(str1,str2)==0){
        while(m<strlen(str1)){
            if(MOD_num.res[0]=='0'){
                for(i=0;i<strlen(str2);i++,m++){
                    Split_str.res[i] = str1[m];
                }
            }else{
                strcpy(Split_str.res,MOD_num.res);
                for(i=strlen(Split_str.res),u=0;u<strlen(str2);m++,u++,i++){
                    Split_str.res[i] = str1[m];
                }
            }
            Split_str.res[i]='\0';
            do{ 
                tmp = Mul(str2,Division_n.res);
                s = Div_expansion_match(Split_str.res,tmp.res);
                Division_n = Add(Division_n.res,"1");
            }while(s==0);
            Division_n = Sub(Division_n.res,"1");
            if(s==1){
                tmp = Mul(str2,Division_n.res);
                s = Div_expansion_match(Split_str.res,tmp.res);
                MOD_num = s==0?Sub(Split_str.res,tmp.res):Split_str;
                if(s==0){
                    response.res[k]=Division_n.res[0];k++;
                }else{
                    response = Add(response.res,Division_n.res);
                }
            }else if(s==2){
                MOD_num = Add("0","0");
                response.res[k] = Division_n.res[0];k++;
            }
            Division_n = Add("0","0");
        }
        response.res[k]='\0';
    }else{
        response = Add("0","0");
    }
    return response;
}
int main(){
    char keyin[600],left[600],right[600],operator;
    int a=0;
    String r;
    while(fgets(keyin,600,stdin)!=NULL){
        split(keyin,left,&operator,right);
        a = swap(left,right);
        if(operator=='+')r = Add(left,right);
        else if(operator=='-')r = Sub(left,right);
        else if(operator=='*')r = Mul(left,right);
        else if(operator=='/')r = Div(left,right);
        if(a==1&&operator=='-')printf("-%s\n",r.res);
        else printf("%s\n",r.res);
    }
    return 0;
}
