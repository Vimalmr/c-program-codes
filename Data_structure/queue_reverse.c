#include <stdio.h>
#include <string.h>

int stack[20],que[20],q[20],top=0,first=0,len;

void queue(int value){
    que[top++]=value;
}

void push(int value){
    stack[first++]=value;
}

void pop(){
    for(int i=len-1;i>=0;i--){
        queue(stack[i]);
        first--;
    }
}

void dequeue(){
    for(int i=0;i<len;i++){
        push(que[i]);
        top--;
    }
}

void reverse(){
    dequeue();
    pop();
    printf("Reversed\n");
}

void display(){
    for(int i=0;i<len;i++){
        printf("%d ->",que[i]);
    }
    printf(" NULL\n");
}

int main(){ //Main function
    int opt,c=1,val;
    while(c){
        printf("*** MENU ***\n1)Insert\n2)Display\n3)Reversal\n4)Exit\nEnter the option => "); //Getting option from the user to carry on particular opertion
        scanf("%d",&opt);

        if(opt==1){ //Insertion
            printf("Enter the value to be inserted => ");
            scanf("%d",&val);
            queue(val);
            len=top;
        }
        
        else if(opt==2){
            display();
        }

        else if(opt==3){
            reverse();
        }

        else if(opt==4){
            c=0;
            printf("Exiting\n");
        }

        else{
            printf("Input is Wrong\n");
        }
    }
}
