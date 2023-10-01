#include<stdio.h>

int main(){
    int n;
    printf("Enter the no.of lines : ");
    scanf("%d",&n);
    int a=1;
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            printf("  ");
        }
        for(int k=0;k<a;k++){
            if(k==a-1 || k==0 || i==1)
            printf("* ");
            else
            printf("  ");
        }
        a++;
        printf("\n");
    }
}