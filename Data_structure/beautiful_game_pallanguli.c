#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*a=NULL,*b=NULL,*new,*ta,*tb;

int sum1=0,sum2=0,sum=0,play=0;

void makeup(){
    for(int i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=5;
        if(a==NULL){
            new->next=NULL;
            ta=a=new;
        }
        else{
            new->next=a;
            a=new;
        }
    }
    for(int i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=5;
        if(b==NULL){
            new->next=NULL;
            tb=b=new;
        }
        else{
            new->next=b;
            b=new;
        }
    }
    ta->next=b;
    tb->next=a;
}

void printReverse(struct node* head)
{ 
    if (head == a){
       return;
    }
    printReverse(head->next);
    printf("%d ", head->data);
}

void display(){
    ta=a;
    printf(" -<A side>-\n");
    printf("  1 2 3 4 5\n--------------\n| ");
    for(int i=1;i<=5;i++){
        printf("%d ",ta->data);
        ta=ta->next;
    }
    printf("|\n| ");
    printReverse(b);
    printf("|\n--------------\n  5 4 3 2 1\n -<B side>-\n");
}

int checka(){
    ta=a;
    int k=0; 
    for(int i=0;i<5;i++){
        if(ta->data==0){
            k++;
        }
        ta=ta->next;
    }
    if(k==5){
        tb=b;
        for(int i=0;i<5;i++){
            sum2+=tb->data;
            tb=tb->next;
        }
        return 0;
    }
    else{
        return 1;
    }
}

int checkb(){
    tb=b;
    int k=0; 
    for(int i=0;i<5;i++){
        if(tb->data==0){
            k++;
        }
        tb=tb->next;
    }
    if(k==5){
        ta=a;
        for(int i=0;i<5;i++){
            sum1+=ta->data;
            ta=ta->next;
        }
        return 0;
    }
    else{
        return 1;
    }
}

void gamea(int opt){
    ta=a;
    int op=1;
    for(int i=1;i<opt;i++){
        ta=ta->next;
    }
    if(ta->data==0){
        printf("The Entered position doesn't have any values\n");
        return;
    }
    while(op){
        int c=ta->data;
        ta->data=0;
        for(int i=1;i<=c;i++){
            ta=ta->next;
            ta->data+=1;
        }
        ta=ta->next;
        if(ta->data==0){
            op=0;
            ta=ta->next;
            sum1+=ta->data;
            ta->data=0;
        }
    }
    play=1;
}

void gameb(int opt){
    tb=b;
    int op=1;
    for(int i=1;i<opt;i++){
        tb=tb->next;
    }
    if(tb->data==0){
        printf("The Entered position doesn't have any values\n");
        return;
    }
    while(op){
        int c=tb->data;
        tb->data=0;
        for(int i=1;i<=c;i++){
            tb=tb->next;
            tb->data+=1;
        }
        tb=tb->next;
        if(tb->data==0){
            op=0;
            tb=tb->next;
            sum2+=tb->data;
            tb->data=0;
        }
    }
    play=0;
}

int main(){
    int c=1,opt;
    printf("\n*** Welcome to PALLANGULI ***\n");
    makeup();
    printf("--- Pallanguli Game starts ---\n\n");
    display();
    printf("\n");
    while(c){
        if(play==0){
            if(checka()){
                again1:
                printf("Mr.A, Where do you want to start : ");
                scanf("%d",&opt);
                if(opt<=5 && opt>0){
                    gamea(opt);
                    display();
                    printf("A = %d\nB = %d\n\n",sum1,sum2);
                }
                else{
                    printf("Wrong input\n");
                    goto again1;
                }
            }
            else{
                c=0;
            }
        }

        if(play==1){
            if(checkb()){
                again2:
                printf("Mr.B, Where do you want to start : ");
                scanf("%d",&opt);
                if(opt<=5 && opt>0){
                    gameb(opt);
                    display();
                    printf("A = %d\nB = %d\n\n",sum1,sum2);
                }
                else{
                    printf("Wrong input\n");
                    goto again2;
                }
            }
            else{
                c=0;
            }
        }
    }
    if(sum1>sum2){
        printf("%d => A is the winner\n",sum1);
    }
    else if(sum2>sum1){
        printf("%d => B is the winner\n",sum2);
    }
    else if(sum1==sum2){
        printf("%d => A and %d => B, So Match is Draw\n",sum1,sum2);
    }
}
