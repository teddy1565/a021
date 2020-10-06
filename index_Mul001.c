#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    return &res[i];
}
static char *Mul_expansion_add(char *left,char *right){
    return "hello world";
}
static char *Mul(char *left,char *right){
    static char a[600],b[600],c[600],d[600];
    static char a_power[600],b1_power[600],b2_power[600];
    char tmp_A[600],tmp_B1[600],tmp_B2[600],tmp_C[600];
    char *A,*B,*C;
    int aLength = (strlen(left)&1)?(strlen(left)/2)+1:strlen(left)/2;
    int cLength = (strlen(right)&1)?(strlen(right)/2)+1:strlen(right)/2;
    int bLength = strlen(left)-aLength;
    int dLength = strlen(right)-cLength;
    int i,m;
    tmp_A[0]='\0';
    tmp_B1[0]='\0';
    tmp_B2[0]='\0';
    tmp_C[0]='\0';
    for(i=0;i<=aLength;i++){
        if(i==aLength){
            a[i]='\0';
            break;
        }
        a[i] = left[i];
    }
    for(i=0;i<=cLength;i++){
        if(i==cLength){
            c[i]='\0';
            break;
        }
        c[i] = right[i];
    }
    for(i=aLength,m=0;i<=strlen(left);i++,m++){
        if(i==strlen(left)){
            b[m] = '\0';
            break;
        }
        b[m] = left[i];
    }
    for(i=cLength,m=0;i<=strlen(right);i++,m++){
        if(i==strlen(right)){
            d[m] = '\0';
            break;
        }
        d[m] = right[i];
    }
    for(i=0;i<=(strlen(left)/2)+(strlen(right)/2);i++){
        if(i==((strlen(left)/2)+(strlen(right)/2))){
            a_power[i]='\0';
            break;
        }
        a_power[i]='0';
    }
    for(i=0;i<=strlen(left)/2;i++){
        if(i==strlen(left)/2){
            b1_power[i]='\0';
            break;
        }
        b1_power[i]='0';
    }
    for(i=0;i<=strlen(right)/2;i++){
        if(i==strlen(right)/2){
            b2_power[i]='\0';
            break;
        }
        b2_power[i]='0';
    }
    if(strlen(a)+strlen(c)<9){
        A = itoa(atoi(a)*atoi(c));
        strcat(tmp_A,A);
        /*free(A);A = NULL;*/
        strcat(tmp_A,a_power);
    }
    if(strlen(a)+strlen(d)<9){
        B = itoa(atoi(a)*atoi(d));
        strcat(tmp_B1,B);
        /*free(B);B=NULL;*/
        strcat(tmp_B1,b1_power);
    }
    if(strlen(c)+strlen(b)<9){
        B = itoa(atoi(c)*atoi(d));
        strcat(tmp_B2,B);
        /*free(B);B=NULL;*/
        strcat(tmp_B2,b2_power);
    }
    if(strlen(b)+strlen(d)<9){
        C = itoa(atoi(b)*atoi(d));
        /*strcat(tmp_C,C);*/
        free(C);C=NULL;
    }
    printf("[\t%s\t%s\t%s\t%s\t]\n",tmp_A,tmp_B1,tmp_B2,tmp_C);
    return "hello world";
}
int main(){
    char keyin[600];
    char left[600];
    char right[600];
    char operator;
    while(fgets(keyin,600,stdin)!=NULL){
        split(keyin,left,&operator,right);
        Mul(left,right);
    }
    return 0;
}
