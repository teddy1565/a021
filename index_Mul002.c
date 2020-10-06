#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char **split_str(char *str,char target){
    int i,target_n=1,j,k;
    char **string;
    for(i=0;i<strlen(str);i++){
        if(str[i]==target)target_n++;
    }
    string = (char**)malloc(sizeof(char)*target_n);
    for(i=0;i<target_n;i++){
        string[i] = (char*)malloc(sizeof(char)*strlen(str));
    }
    for(i=0,j=0;i<target_n;i++){
        for(k=0;j<strlen(str);j++,k++){
            if(str[j]==target){
                j++;k++;
                break;
            }
            string[i][k] = str[j];
        }
        string[i][k] = '\0';
    }
    printf("%s\t%s\t%s\n",string[0],string[1],string[2]);
    return string;
}
int main(){
    char keyin[600];
    while(fgets(keyin,600,stdin)){
        char **data;
        data = split_str(keyin,' ');
    }
    return 0;
}
