#include<stdio.h>

int main(){
    int n;
    printf("Enter the no.of lines : ");
    scanf("%d",&n);
    int a=n;
    for(int i=1;i<=n;i++){
        for(int k=0;k<a;k++){
            printf(" ");
        }
        a--;
        for(int j=0;j<i*2-1;j++){
            if(j==0 || j==i*2-2 || i==n)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
}