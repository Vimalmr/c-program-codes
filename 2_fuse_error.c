#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
  char name[20],dp[20],ds[20];
  long int phone;
  int tk_count;
  struct node *next;
}*top=NULL,*newnode,*temp;
void enqueue(int val){
  
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter your name: ");
  scanf("%s",newnode->name);
  newnode->tk_count=val;
  printf("\n1:Erode\n2:Perundurai\n3:Avinashi\n4:Coimbatore\nEnter your area of departure\nEnter here=> ");
  scanf("%s",newnode->dp);
  printf("\n1:Erode\n2:Perundurai\n3:Avinashi\n4:Coimbatore\nEnter your area of destination\nEnter here=> ");
  scanf("%s",newnode->ds);
  printf("You are boarding from %s and you are destination is %s\n",newnode->dp,newnode->ds);
  newnode->next=NULL;
  if(top==NULL)
  temp=top=newnode;
  else{
    temp->next=newnode;
    temp=newnode;
  }
}
void dequeue(){
    temp=top;
    top=top->next;
    free(temp);
}
void display(){
  temp=top;
  while(temp!=NULL){
    printf("\nCustomer name : %s\nDeparture : %s\nDestination : %s\nNo.of tickets booked : %d",temp->name,temp->dp,temp->ds,temp->tk_count);
    printf("\n");
    temp=temp->next;
  }
}

int m=10;

int main(){
    int c=1,ct=0,log,inde,tick=0,d=1;
    char adname[15],pswd[15];
    char admin[10]= "abhinandan";
    char cpswd[10]= "123456mass";
    while(c){
        printf("\n*** MENU ***\nPress (1) for Admin Login\nPress (2) for User Login\nPress (3) displaying total tickets\nPress (4) to exit\nEnter here => ");
            scanf("%d",&log);
            if(log==1){
                printf("Enter user name => ");
                scanf("%s",adname);
                printf("Enter Password => ");
                scanf("%s",pswd);
                int uc=0,pc=0;
                for(int i=0;i<strlen(adname);i++){
                    if(admin[i]!=adname[i]){
                        uc=1;
                        break;
                    }
                }
                for(int i=0;i<strlen(pswd);i++){
                    if(cpswd[i]!=pswd[i]){
                        pc=1;
                        break;
                    }
                }
                if(uc==0 && pc==0){
                    while(d){
                    printf("\nTotal seat capacity = %d\n",m);
                    printf("Total passengers = %d",ct);
                    printf("Current seat capacity = %d\n",m-ct);
                    printf("Do you want increase or decrease?\n(To decrease enter in negative)\nEnter here => ");
                    scanf("%d",&inde);
                    if(inde>=0){
                        m+=inde;
                    }
                    else{
                        if(abs(inde)>m-ct){
                            printf("Given value is greater than current capacity\n");
                        }
                        else{
                            m+=inde;
                        }
                    }
                    printf("Press (1) to continue and (0) to exit");
                    scanf("%d",&d);
                }
                }
                else{
                    printf("Incorrect username or password\n");
                }
            }
            else if(log==2){
                printf("\n*** Welcome Coustmer ***\nTotal no. of seats available = %d\nTotal passengers = %d\nHow much ticket you want to buy\nEnter here => ",m-ct,ct);
                scanf("%d",&tick);
                ct+=tick;
                if(ct>m){
                    printf("Seats are fulled\n");
                    ct-=tick;
                }
                else{
                    enqueue(tick);
                }
            }
            else if(log==3){
                printf("\nDisplaying...\n");
                display();
            }
            else if(log==4){
                c=0;
                printf("\nExiting\n");
            }
        }
    }