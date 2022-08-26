#include<stdio.h>
#include<stdlib.h>

void insertAtBeginning(int); 
void insertAtEnd(int);
void insertBetween(int,int,int); 
void display();
void removeBeginning(); 
void removeEnd();
void removeSpecific(int);

//Structure in the name of 'node' to store the 'data' and hold the address in 'next'.

struct node{
    int data;
    struct node *next;
}*head=NULL;

//Main function.

int main(){
    int choice,value,choice1,loc1,loc2;
    while(1){ //loop.
        mainMenu: printf("\n*** MENU ***\n1. Insert \n2. Display \n3. Delete \n4. Exit \nEnter your choice: "); //Asking user for the action to be performed.
        scanf("%d",&choice); //getting user desired choice as input.
        switch(choice){
            case 1:	//Insertion.
            printf("\nEnter the value to be inserted: "); //Getting the value to be added.
            scanf("%d",&value);
            while(1){
            printf("\n** Where you want to insert: **\n1. At Beginning \n2. At End \n3. Between\nEnter your choice: "); //Asking user for where to insert values.
            scanf("%d",&choice1);
            switch(choice1){
                case 1:	//Insert at beginning.
                insertAtBeginning(value);
                break;
                case 2:	//Insert at end.
                insertAtEnd(value);
                break;
                case 3:	//Insert in between two values.
                printf("\nEnter the two values: "); 
                scanf("%d %d",&loc1,&loc2); 
                insertBetween(value,loc1,loc2); 
                break;
                default: //Warning user for wrong input.
                printf("\n**** Wrong Input!! Try again!!! ****\n\n"); 
                goto mainMenu;
                }
                goto subMenuEnd;
            }
            subMenuEnd:
            break; 
            case 2:	//Displaying the values.
            display();
            break;
            case 3:	//Deletion
            printf("\n** How do you want to Delete: **\n1. From Beginning \n2. From End \n3. Specific\nEnter your choice: "); //Asking user for what value to be deleted.
            scanf("%d",&choice1);
            switch(choice1){
                case 1:	//Deleting the the first value.
                removeBeginning();
                break;
                case 2:	//Deleting the final value.
                removeEnd(); 
                break;
                case 3:	//Deleting the value that is given by the user.
                printf("\nEnter the value which you want to delete: "); 
                scanf("%d",&loc2);
                removeSpecific(loc2); 
                break;
                default: //Warning user for wrong input.
                printf("\n**** Wrong Input!! Try again!! \n"); 
                goto mainMenu;
            }
            break; 
            case 4:	
            exit(0);
            default: //Warning user for wrong input.
            printf("\n**** Wrong input!!! Try again!! ****\n\n"); 
        }
    }
}

//Functions to perform the Specific actions

void insertAtBeginning(int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = value;
    if(head == NULL){
    newnode->next = NULL; 
    head = newnode;
    }
    else{
    newnode->next = head; 
    head = newnode;
    }
    printf("\n* Node inserted *\n");
}

void insertAtEnd(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("\n* Node inserted *\n");
}

void insertBetween(int value, int loc1, int loc2){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        struct node *temp = head,*temp1;
        while(temp1->data!=loc1 && temp->data!=loc2){
            temp1=temp;
            temp=temp->next;
        }
        newnode->next=temp1->next;
        temp1->next=newnode;
    }
    printf("\n* Node inserted *\n");
}

void removeBeginning(){
    if(head==NULL)
        printf("\n**** List is empty ****\n");
    else{
        struct node *temp=head;
        if(head->next==NULL){
            head==NULL;
            free(temp);
            printf("\n* Node deleted *\n");
        }
        else{
            head=temp->next;
            free(temp);
            printf("\n* Node deleted *\n");
        }
    }
}

void removeEnd(){
    if(head==NULL){
        printf("\n**** List is empty ****\n");
    }
    else{
        struct node *temp1 = head,*temp2;
        if(head->next==NULL){
            head==NULL;
            free(temp1);
        }
        else{
            while(temp1->next!=NULL){
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=NULL;
            free(temp1);
        }
        printf("\n* Node deleted *\n");
    }
}

void removeSpecific(int value){
    struct node *temp1 = head,*temp2;
    while(temp1->data!=value){
        if(temp1->next==NULL){
            printf("\n**** Given value doesn't exsist in this list ****\n");
            goto functionend;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=temp1->next;
    free(temp1);
    printf("\n* Node deleted *\n");
    functionend:
    printf("\n");
}

void display(){
    if(head == NULL){
        printf("\n**** List is Empty ****\n");
    }
    else{
        struct node *temp = head;
        printf("\nDisplaying Lists :-\n");
        while(temp->next!=NULL){
            printf("%d --> ",temp->data);
            temp=temp->next;
        }
        printf("\n%d --> NULL\n",temp->data);
    }
}