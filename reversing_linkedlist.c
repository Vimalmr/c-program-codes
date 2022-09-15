#include<stdio.h>
#include<stdlib.h>

struct node{ //structure node
    int data;
    struct node *next;
}*head=NULL,*new,*temp,*rest;

struct node *reverse(struct node *first){ //structure function to reverse the linked list
    if((first==NULL)||(first->next==NULL)){
        return first; //returning first
    }
    rest=reverse(first->next); //recursive function
    first->next->next=first; //Assiging the address to next in rest
    first->next=NULL;
    return rest; //Returning rest
}

int main(){ //Main function
    int opt,c=1,val;
    while(c){
        printf("*** MENU ***\n1)Insert\n2)Display\n3)Reversal\n4)Exit\nEnter the option => "); //Getting option from the user to carry on particular opertion
        scanf("%d",&opt);

        if(opt==1){ //Insertion
            printf("Enter the value => "); //Value is entered to add to the list
            scanf("%d",&val);
            new = (struct node*)malloc(sizeof(struct node));
            temp=head;
            new->data=val;
            new->next=NULL;
            if(head==NULL){
                new->next=NULL;
                head=new;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=new;
                printf("\nNode is inserted successfully\n\n"); //Confirmation message to user
            }
        }

        else if(opt==2){ //Display
            temp=head;
            if(head==NULL){
                printf("List is empty\n\n");
            }
            else{
                while(temp->next!=NULL){
                    printf("%d -> ",temp->data);
                    temp=temp->next;
                }
                printf("%d -> NULL\n\n",temp->data);
            }
        }

        else if(opt==3){ //Reversing
            head=reverse(head); //Calling function
            printf("List is reversed\n"); //Confirmation
        }

        else if(opt==4){ //Exiting the program
            c=0;
            printf("Exiting...\n");
        }
    }
}