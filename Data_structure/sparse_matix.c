#include<stdio.h>
#include<stdlib.h>

struct node{
    int data,c,r;
    struct node *next;
}*head=NULL,*new,*temp;

int row=0,col=0;

void insert(){
    int c=1,val;
    while(c){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value => ");
        scanf("%d",&val);
        printf("Enter the row => ");
        scanf("%d",&new->r);
        printf("Enter the column => ");
        scanf("%d",&new->c);
        if(new->r>row){
            row=new->r;
        }
        if(new->c>col){
            col=new->c;
        }
        new->data=val;
        new->next=NULL;
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
        printf("Inserted\n");
        printf("Do you still need to add elements?\n0)No\n1)Yes\nEnter here => ");
        scanf("%d",&c);
    }
    temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void addr(){
    for(int i=0;i<=row;i++){
        int sum=0;
        temp=head;
        while(temp!=NULL){
            if(temp->r==i){
            sum+=temp->data;}
            temp=temp->next;
        }
        printf("Sum of row %d = %d\n",i,sum);
    }
}

void addc(){
    for(int i=0;i<=col;i++){
        temp=head;
        int sum=0;
        while(temp!=NULL){
            if(temp->c==i){
            sum+=temp->data;}
            temp=temp->next;
        }
        printf("Sum of column %d = %d\n",i,sum);
    }
}

int main(){
    int c=1,opt;
    while(c){
        printf("\n*** MENU ***\nPress (1) Insert value\nPress (2) Add Rows\nPress (3) Add columns\nPress (4) Exit\nEnter the option => ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            insert();
            break;

            case 2:
            addr();
            break;

            case 3:
            addc();
            break;

            case 4:
            c=0;
            break;

            default:
            printf("Entered option is not valid\n");
        }
    }
}  
