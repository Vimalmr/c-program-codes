#include<stdio.h>

int main(){
    int n;
    printf("Enter total number of lines : ");
    scanf("%d",&n);
    int a=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int k=0;k<n;k++){
            printf("* ");
        }
        printf("\n");
    }
}