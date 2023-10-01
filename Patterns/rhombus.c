#include<stdio.h>

int main(){
    int n;
    printf("Enter total number of lines : ");
    scanf("%d",&n);
    int a=n;
    for(int i=0;i<n;i++){
        for(int j=n;j>0;j--){
            if(j==n){
                for(int k=0;k<a;k++){
                    printf(" ");
                }
                a--;
            }
            printf("* ");
        }
        printf("\n");
    }
}