#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct reference_str{
    int n;
    int m;
    char A[600];
    char B[600];
};
struct result_str{
    char result[600];
    char *p;
};
static struct result_str Add(char *left,char *right){
    int length = strlen(right)<strlen(left)?strlen(left):strlen(right);
    char *result = (char*)malloc(sizeof(char)*(length+2));
    int i,j,k,tmp,num;
    struct result_str response;
    result[length+1] = '\0';
    for(i=length,j=strlen(left)-1,k=strlen(right)-1,tmp=0;i>=0;i--,j--,k--){
        num = (j<0?0:(left[j]-'0')) + (k<0?0:(right[k]-'0')) + tmp;
        tmp = 0;
        result[i] = (num%10)+'0';
        tmp = (num/10);
    }
    for(i=0;result[i]=='0';i++);
    if(i==strlen(result))response.p = result;
    else response.p = &result[i];
    free(result);
    result = NULL;
    return response;
}

static struct result_str classic_multiplitcation(struct reference_str str){
    int aLength = strlen(str.A);
    int bLength = strlen(str.B);
    struct result_str result;
    int i,j,k;
    char *temp = (char*)malloc(sizeof(char)*(aLength+2));
    char *response = (char*)malloc(sizeof(char)*(aLength+bLength+1));
    temp[aLength+1]='\0';
    response[aLength+bLength] = '\0';
    for(i=bLength-1;i>=0;i--){
        for(j=aLength-1;j>=0;j--){

        }
    }
    return result;
}
int main(){
    struct reference_str str = {100,100,"12346","123456789"};
    struct result_str R_str = classic_multiplitcation(str);
    struct result_str AddT = Add("11111","2");
    printf("%s\n",AddT.p);
    return 0;
}
