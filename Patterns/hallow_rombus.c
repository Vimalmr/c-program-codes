#include<stdio.h>

int main(){
    int n;
    printf("Enter total number of lines : ");
    scanf("%d",&n);
    int a=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                for(int k=0;k<a;k++){
                    printf(" ");
                }
                a--;
            }
            if(i==0 || i==n-1 || j==0 || j==n-1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
