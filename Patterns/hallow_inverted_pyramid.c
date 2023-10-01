#include<stdio.h>

int main(){
    int n;
    printf("Enter the no.of lines : ");
    scanf("%d",&n);
    int a=1;
    for(int i=n;i>0;i--){
        for(int k=1;k<a;k++){
            printf(" ");
        }
        a++;
        for(int j=0;j<i*2-1;j++){
            if(j==0 || j==i*2-2 || i==n)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
}