#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("%d\n",15&1);//1
    printf("%d\n",16&1);//0
    printf("%d\n",12&12);//12
    printf("%d\n",12&11);//8
    printf("%d\n",12&9);//8
    printf("%d\n",12&6);//4
    printf("%d\n",0&0);//0
    printf("%d\n",1&1);//1
    return 0;
}