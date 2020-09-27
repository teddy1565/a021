#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a,b;
    for(int i=0;i<1000000;i++){
        a = 1073741822;
        b = 1073741822;
        int c = a+b;
        if((i&1)==0){a--;b--;}
        else{a++;b++;}
        printf("%d\n",a+b);
    }
    printf("%d\n",a+b);
    return 0;
}