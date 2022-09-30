#include<stdio.h> //unfinished
#include<stdlib.h>

struct node {
    int data;
    struct node *next,*back;
}*head=NULL,*new,*temp,*temp1;

int main(){
    int opt,c=1,cho,cho1,val,val1;
    while(c){
        printf("*** Menu ***\n1)Insert\n2)Display\n3)Delete\n4)Exit\nEnter the option => ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            printf("How do you want insert?\n1)Front\n2)Middle\n3)Back\nEnter the choice => ");
            scanf("%d",&cho);
            printf("Enter the value to be inserted => ");
            scanf("%d",&val);
            switch(cho){
                case 1:
                new=(struct node *)malloc(sizeof(struct node));
                new->data=val;
                new->back=NULL;
                if(head==NULL){
                    new->next=NULL;
                    head=new;
                }
                else{
                    new->next=head;
                    head->back=new;
                    head=new;
                }
                printf("Node inserted\n");
                break;

                case 2:
                new=(struct node *)malloc(sizeof(struct node));
                new->data=val;
                temp=head;
                if(head==NULL){
                    new->next=NULL;
                    new->back=NULL;
                    head=new;
                }
                else{
                    printf("enter after which data should node be inserted => ");
                    scanf("%d",&val1);
                    while(temp->data!=val1 && temp->next!=NULL){
                        temp=temp->next;
                    }
                    if(temp->data==val1){
                        if(temp->next==NULL){
                            new->next=NULL;
                            new->back=temp;
                            temp->next=new;
                        }
                        else{
                        new->next=temp->next;
                        new->back=temp;
                        temp->next=new;
                        new->next->back=new;
                    }}
                    else{
                        printf("List is empty\n");
                    }
                break;

                case 3:
                new=(struct node *)malloc(sizeof(struct node));
                new->data=val;
                new->next= NULL;
                if(head==NULL){
                    new->back=NULL;
                    head=new;
                }
                else{
                    temp=head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    new->back=temp;
                    temp->next=new;
                }
                printf("Node inserted\n");
                break;

                default:
                printf("Wrong option\n");
                break;
            }}
            break;

            case 2:
            temp=head;
            if(head==NULL){
                printf("List is empty\n");
            }
            else{
                while(temp->next!=NULL){
                    printf("%d -> ",temp->data);
                    temp=temp->next;
                }
                printf("%d -> NULL\n",temp->data);
            }
            break;

            case 3:
            printf("How do you want delete?\n1)Front\n2)Middle\n3)Back\nEnter the choice => ");
            scanf("%d",&cho1);
            switch(cho1){
                case 1:
                temp=head;
                if(head==NULL){
                    printf("List is empty\n");
                }
                else if(head->next==NULL){
                    free(temp);
                    head=NULL;
                    printf("Node deleted\n");
                }
                else{
                    temp->next->back=NULL;
                    head=temp->next;
                    free(temp);
                    printf("Node deleted\n");
                }
                break;

                case 2:
                temp=head;
                if(head==NULL){
                    printf("List is empty\n");
                }
                else if(head->next==NULL){
                    free(temp);
                    head=NULL;
                    printf("Node deleted\n");
                }
                else{
                    printf("Enter, before which data should node be deleted => ");
                    scanf("%d",&val1);
                    while(temp->data!=val1 && temp->next!=NULL){
                    temp=temp->next;
                    }
                    if(temp->data==val1){
                        temp->back->next=temp->next;
                        temp->next->back=temp->back;
                        free(temp);
                    }
                }
                printf("Node deleted\n");
                break;

                case 3:
                temp=head;
                if(head==NULL){
                    printf("List is empty\n");
                }
                else if(head->next==NULL){
                    free(temp);
                    head=NULL;
                    printf("Node deleted\n");
                }
                else{
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->back->next=NULL;
                    free(temp);
                }
                printf("Node deleted\n");
                break;
            }
            break;

            case 4:
            c=0;
            printf("Exiting...\n");
            break;

            default:
            printf("Wrong input\n");
            break;
        }
    }
}
