#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct karatsuba{
    char *a;
    char *b;
};
static struct karatsuba getStruct(char *s,char *r){
    struct karatsuba res;
    res.a = (char*)malloc(sizeof(char)*101);
    res.a[100] = '\0';
    res.b = (char*)malloc(sizeof(char)*101);
    res.b[100] = '\0';
    for(int i=0;i<=strlen(s);i++){
        if(i==strlen(s)){
            res.a[i]='\0';
            break;
        }
        res.a[i] = s[i];
    }
    for(int i=0;i<=strlen(r);i++){
        if(i==strlen(s)){
            res.b[i]='\0';
            break;
        }
        res.b[i] = r[i];
    }
    return res;
}
int main(){
    struct karatsuba struct_str = getStruct("hello","world");
    printf("%s\n",struct_str.a);
    printf("%s\n",struct_str.b);
    free(struct_str.a);
    free(struct_str.b);
    struct_str.a = NULL;
    struct_str.b = NULL;
    printf("%s\n",struct_str.a);
    printf("%s\n",struct_str.b);
    return 0;
}