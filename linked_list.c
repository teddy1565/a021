#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[10];
    int age;
    struct node *next;
};
int main(){
    struct node *head,*ptr,*newptr;
    newptr = (struct node*)malloc(sizeof(struct node));
    strcpy(newptr->name,"teddy");
    newptr->age = 20;
    newptr->next = NULL;
    head = ptr = newptr;
    newptr = (struct node*)malloc(sizeof(struct node));
    strcpy(newptr->name,"david");
    newptr->age = 50;
    newptr->next=NULL;
    ptr->next = newptr;
    ptr = head;

    while(ptr!=NULL){
        printf("%s\n",ptr->name);
        ptr = ptr->next;
    }
}