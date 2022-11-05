#include<stdio.h>
#include<stdlib.h>

//Start.
//This is code is about a Traditional ancient game called pallanguli, played in Tamilnadu.
//So, I wrote code for the algorithm of the game and build it in 'C' programming language.

struct node{ //Defining the structure
    int data;
    struct node *next;
}*a=NULL,*b=NULL,*new,*ta,*tb;

int sum1=0,sum2=0,sum=0,play=0;

void makeup(){ //Creating the pallanguli setup using circular linkedlist.
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

void printReverse(struct node* head) //Here the linkedlist B is printed in reverse for user to understand the program well.
{ 
    if (head == a){
       return;
    }
    printReverse(head->next);
    printf("%d ", head->data);
}

void display(){ //Printing the No. of beads in the pallanguli.
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

int checka(){ //Checking whether the hole side is 0 or not.
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
//Algorithm/Program for the core of the game.
void gamea(int opt){ //For player A.
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

void gameb(int opt){ //For player B.
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

int main(){ //Main program
    int c=1,opt;
    printf("\n*** Welcome to PALLANGULI ***\n");
    makeup();
    printf("--- Pallanguli Game starts ---\n\n");
    display();
    printf("\n");
    while(c){ //Loop
        if(play==0){ //Player A
            if(checka()){
                again1:
                printf("Mr.A, Where do you want to start : ");
                scanf("%d",&opt);
                if(opt<=5 && opt>0){ //Checking if the given input is within the range.
                    gamea(opt); //Calling function gamea.
                    display(); //displaying
                    printf("A = %d\nB = %d\n\n",sum1,sum2);
                }
                else{
                    printf("Wrong input\n");
                    goto again1;
                }
            }
            else{ //for Termination.
                c=0;
            }
        }

        if(play==1){ //Player B
            if(checkb()){
                again2:
                printf("Mr.B, Where do you want to start : ");
                scanf("%d",&opt);
                if(opt<=5 && opt>0){ //Checking whether the given input is within the range or not.
                    gameb(opt); //Calling function gameb()
                    display(); //Displaying.
                    printf("A = %d\nB = %d\n\n",sum1,sum2);
                }
                else{
                    printf("Wrong input\n");
                    goto again2;
                }
            }
            else{ //for termination
                c=0;
            }
        }
    }
    //Announcing the result.
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
//EnD.
