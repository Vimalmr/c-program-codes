#include<stdio.h>
#include<string.h>

char stack[100];int top=0;

void push(char a){
    stack[top++]=a;
}

void pop(){
    printf("%c",stack[--top]);
}

int main(){
    char a[100],b[100];
    printf("Enter string => ");
    scanf("%s",a);
    int l=strlen(a);
    for(int i=0;i<l;i++){
        push(a[i]);
    }
    for(int i=l-1;i>=0;i--){
        pop();
    }
    printf("\n");
}
