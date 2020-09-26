#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*error example*/
int main(){
    char *str = "abcdef";
    char *p = "12345";
    str = *str^*p;
    p = *p^*str;
    str = *str ^ *p;
    return 0;
}
/*reference data:
    https://stackoverflow.com/questions/26569728/using-xor-with-pointers-in-c
*/