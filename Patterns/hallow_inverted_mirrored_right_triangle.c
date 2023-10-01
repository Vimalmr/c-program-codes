#include<stdio.h>

int main(){
    int n;
    printf("Enter the no.of lines : ");
    scanf("%d",&n);
    int a=1;
    for(int i=n;i>0;i--){
        for(int k=1;k<=i;k++){
            printf("  ");
        }
        for(int j=0;j<a;j++){
            if(j==a-1 || i==1 || j==0)
            printf("* ");
            else
            printf("  ");
        }
        a++;
        printf("\n");
    }
}