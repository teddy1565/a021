#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char *String;
const int strLen = 600;
void Split_string(char **String_array,char *str,char c){
    int str_length = 0;
    while(str[str_length]!='\n'&&str[str_length]!='\0')str_length++;
    for(int i=0,temp=0,p=0;i<3;i++){
        while(temp<=str_length){
            if(str[temp]==c||temp==str_length){
                String_array[i] = &str[p];
                str[temp]='\0';
                temp++;
                p = temp;
                break;
            }
            temp++;
        }
    }
}
int main(){
    String keyin = malloc(sizeof(char)*600);
    while(fgets(keyin,strLen,stdin)!=NULL){
        char *String_array[3];
        Split_string(String_array,keyin,' ');
        printf("%s\n",String_array[0]);
        printf("%s\n",String_array[1]);
        printf("%s\n",String_array[2]);
        return 0;
    }
    return 0;
}