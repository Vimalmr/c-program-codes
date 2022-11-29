#include<stdio.h>

int main(){
    int a[10]={0},n,val;
    printf("Enter the total no. of Inputs = ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data to be inserted = ");
        scanf("%d",&val);
        int k=val%10;
        if(a[k]==0){
            a[k]=val;
        }
        else{
            int c=1;
            while(1){
                int l = 7 - (val%7);
                int pp = (k+(l*c))%10;
                if(a[pp]==0){
                    a[pp]=val;
                    break;
                }
                else{
                    c++;
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("Element at position %d: %d\n",i,a[i]);
    }
}
