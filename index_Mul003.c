#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *Mul_expansion_add(char *left,char *right){
    int length = strlen(right)<strlen(left)?strlen(left):strlen(right);
    char *result = (char*)malloc(sizeof(char)*(length+2));
    int i,j,k,tmp,num;
    result[length+1] = '\0';
    for(i=length,j=strlen(left)-1,k=strlen(right)-1,tmp=0;i>=0;i--,j--,k--){
        num = (j<0?0:(left[j]-'0')) + (k<0?0:(right[k]-'0')) + tmp;
        tmp = 0;
        result[i] = (num%10)+'0';
        tmp = (num/10);
    }
    for(i=0;result[i]=='0';i++);
    if(i==strlen(result))return "0";
    else return result;
}
char *Mul(char *s1,char *s2){
    char *tmp;
    char *tmp_res;
    char *add_res;
    char *res = (char*)malloc(sizeof(char)*(strlen(s1)+strlen(s2)+1));
    char *power_str;
    memset(res,'0',strlen(s1)+strlen(s2));
    res[strlen(s1)+strlen(s2)]='\0';
    for(int i=strlen(s2)-1,power=0,temp=0;i>=0;i--,power++){
        tmp = (char*)malloc(sizeof(char)*(strlen(s1)+2));
        tmp_res = (char*)malloc(sizeof(char)*(strlen(s1)+power+2));
        tmp_res[0] = '\0';
        if(power!=0){
            power_str = (char*)malloc(sizeof(char)*(power));
            memset(power_str,'0',power);
            power_str[power]='\0';
        }else{
            power_str = (char*)malloc(sizeof(char)*(1));
            power_str[0]='\0';
        }
        tmp[strlen(s1)+1]='\0';
        for(int j=strlen(s1)-1;j>=0;j--){
            int num = ((s1[j]-'0')*(s2[i]-'0'))+temp;
            temp =0;
            tmp[j+1] = ((num%10)+'0');
            temp = num/10;
        }
        tmp[0] = (temp+'0');
        strcat(tmp_res,tmp);
        strcat(tmp_res,power_str);
        add_res = Mul_expansion_add(res,tmp_res);
        int s;
        for(s=0;s<strlen(add_res);s++){
            if(add_res[s]!='0')break;
        }
        strcpy(res,&add_res[s]);
        free(add_res);add_res=NULL;
        free(tmp_res);tmp_res=NULL;
        free(tmp);tmp=NULL;
        free(power_str);power_str=NULL;
        temp = 0;
    }
    return res;
}
int main(){
    char *ans = Mul("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999","9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    printf("%s\n",ans);
    free(ans);
    ans=NULL;
    return 0;
}