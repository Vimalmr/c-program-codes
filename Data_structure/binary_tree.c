#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *l,*r;
    int data;
}*root=NULL,*t,*new,*a[10];

void inorder(struct node *w){
    if(w==NULL){
        printf("NULL ");
    }
    else{
        inorder(w->l);
        printf("%d ",w->data);
        inorder(w->r);
    }
}

void preorder(struct node *w){
    if(w==NULL){
        printf("NULL ");
    }
    else{
        printf("%d ",w->data);
        preorder(w->l);
        preorder(w->r);
    }
}

void postorder(struct node *w){
    if(w==NULL){
        printf("NULL ");
    }
    else{
        postorder(w->l);
        postorder(w->r);
        printf("%d ",w->data);
    }
}

int main(){
    int c=1,fl=0,i=-1,j=-1,opt;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert => ");
    scanf("%d",&new->data);
    new->l=NULL;
    new->r=NULL;
    i++;
    a[i]=new;
    if(j==-1){
        j++;
        root=new;
    }
    while(c){
        printf("Enter the data to insert => ");
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        new->l=NULL;
        new->r=NULL;
        i++;
        a[i]=new;
        if(fl==0){
            t=a[j];
            t->l=new;
            fl=1;
        }
        else{
            t=a[j];
            t->r=new;
            fl=0;
            j++;
        }
        printf("Press (1) to continue and (0) to exit\nEnter here => ");
        scanf("%d",&c);
    }

    printf("Which way you want to traverse the tree\nPress (1) for Inorder\nPress (2) for Preoder\nPress (3) for postorder\nEnter the option => ");
    scanf("%d",&opt);
    switch (opt){
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            printf("Wrong input\n");
    }
    printf("\n");
}