#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL,*new,*temp,*back;

int main(){
    int opt,cho,cho1,c=1,val;
    while(c){
        printf("\n*** Menu ***\n1)insertion\n2)Deletion\n3)Display\n4)Exit\nEnter the Option => ");
        scanf("%d",&opt);
        
        if(opt==1){ //Insertion
            printf("Where do you want to insert?\n1)Front\n2)End\nEnter the choice =>");
            scanf("%d",&cho);
            printf("Enter the value to be inserted =>");
            scanf("%d",&val);
            switch (cho){ 

                case 1: //Insert @ front
                new=(struct node*)malloc(sizeof(struct node));
                temp=head;
                new->data=val;
                if(head==NULL){
                    head=new;
                    new->next=head;
                }
                else{
                    new->next=head;
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    temp->next=new;
                    head=new;
                }
                printf("Node is inserted successfully\n");
                break;
                
                case 2: //Insert @ back
                new=(struct node*)malloc(sizeof(struct node));
                temp=head;
                new->data=val;
                if(head==NULL){
                    head=new;
                    new->next=head;
                }
                else{
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    temp->next=new;
                    new->next=head;
                }
                printf("Node is inserted successfully\n");
                break;

                default: //Error
                    printf("Entered input is wrong\n");
                    break;
            }
        }

        else if(opt==2){ //Deletion
            printf("Where to delete the node?\n1)Front\n2)End\nEnter the choice =>");
            scanf("%d",&cho1);
            switch (cho1){

                case 1: //Deletion @ front
                temp=head;
                if(head==NULL){
                    printf("Node is empty\n");
                }
                else if(head->next==head){
                    head=NULL;
                    free(head);
                    printf("Node is deleted\n");
                }
                else{
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    temp->next=head->next;
                    free(head);
                    head=temp->next;
                    printf("Node is deleted\n");
                }
                break;

                case 2: //Deletion @ back
                temp=head;
                if(head==NULL){
                    printf("Node is empty\n");
                }
                else if(head->next==head){
                    head=NULL;
                    printf("Node is deleted\n");
                }
                else{
                    while(temp->next!=head){
                        back=temp;
                        temp=temp->next;
                    }
                    back->next=head;
                    free(temp);
                    printf("Node is deleted\n");
                }
                break;

                default: //Error
                    printf("Entered input is wrong\n");
                    break;
            }
        }

        else if(opt==3){ //Display
            temp=head;
            if(head==NULL){
                printf("List is empty\n");
            }
            else{
                while(temp->next!=head){
                    printf("%d --> ",temp->data);
                    temp=temp->next;
                }
                printf("%d...\n",temp->data);
            }
        }

        else if(opt==4){ //Exit
            printf("Exiting...\n");
            break;
        }

        else{ //Error
            printf("Entered option is wrong\n");
        }
    }
}
