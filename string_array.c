#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char *strin(){
    char *T = malloc(sizeof(char)*100);
    sprintf(T,"I want shout\n");
    return T;
}
int main(){
    char *T1 = malloc(sizeof(char)*1000); 
    char *T2 = malloc(sizeof(char)*1000); 
    char *T3 = malloc(sizeof(char)*1000); 
    char **SA = malloc(sizeof(char)*4);
    sprintf(T1,"Hello world\n");
    sprintf(T2,"I am Bitch\n");
    sprintf(T3,"suck my dick\n");
    SA[0] = T1;
    SA[1] = T2;
    SA[2] = T3;
    char S[1000];
    //printf("%s\n",strin());
    memcpy(S,strin(),1000);
    SA[3] = &S[0];
    printf("%s\n",SA[3]);
    // *(SA+0) = T1;
    // *(SA+1) = T2;
    // *(SA+2) = T3;
    //printf("%s",T1);
    // for(int i=0;i<3;i++){
    //     printf("%s\n",SA[i]);
    // }
    return 0;
}