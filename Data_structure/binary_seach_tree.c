#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *l,*r;
}*root=NULL,*new,*temp;

int main(){
    int c=1,x=0;
    while(c){
        printf("Enter the value to be inserted\nEnter here => ");
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        new->l=NULL;
        new->r=NULL;
        temp=root;
        while(temp!=NULL){
            if(new->data < temp->data){
                if(temp->l != NULL){
                    temp=temp->l;
                }
                else{
                    temp->l=new;
                    temp=NULL;
                }
            }
            else{
                if(temp->r != NULL){
                    temp=temp->r;
                }
                else{
                    temp->r=new;
                    temp=NULL;
                }
            }
        }
        if(root==NULL){
            root=new;
        }
        printf("Press (1) to continue and (0) to exit\nEnter here => ");
        scanf("%d",&c);
    }
    printf("\nExited the insertion mode\n");
    temp=root;
    printf("\nWhat number do you to search\nEnter the Value => ");
    scanf("%d",&x);
    while(temp != NULL && temp->data != x ){
        if(x<temp->data){
            temp=temp->l;
        }
        else{
            temp=temp->r;
        }
    }
    if(temp!=NULL){
        printf("%d if found in the tree\n",temp->data);
    }
    else{
    printf("%d is not found in the tree\n",temp->data);
    }
}