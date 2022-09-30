#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    struct node *l,*r,*ne;
    int data;
}*head=NULL,*new,*temp;

int top=0;

void push ( struct node* x )  
{  
    if (head == NULL )  
    head = x ;  
    else  
    {  
        x->ne = head ;  
        head = x ;  
    }    
}  
struct node* pop()  
{    
    struct node* n = head ;  
    head = head->ne ;  
    return n ;  
}  

void inorder(struct node *w){
    if(w==NULL);
    else{
        inorder(w->l);
        printf("%c ",w->data);
        inorder(w->r);
    }
}

int main(){
    char x[30];
    int n,i;
    scanf("%s",x);
    n=strlen(x);
    for(int i=0;i<n;i++){
        if(x[i]!='*' && x[i]!='+' && x[i]!='-' && x[i]!='/' && x[i]!='^'){
            new=(struct node *)malloc(sizeof(struct node));
            new->r=new->l=NULL;
            new->data=x[i];
            push(new);
        }
        else{
            new=(struct node *)malloc(sizeof(struct node));
            new->data=x[i];
            temp=pop();
            new->l=temp;
            temp=pop();
            new->r=temp;
            push(new);
        }
    }
    head=pop();
    inorder(head);
    printf("\n");
}