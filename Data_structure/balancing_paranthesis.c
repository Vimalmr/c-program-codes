#include<stdio.h>
#include<string.h>

char str[10];
int len=0;

void add(char w){
    str[len++]=w;
}

int check(char w){
    if((w==')' && str[len-1]=='(') || (w=='}' && str[len-1]=='{') || (w==']' && str[len-1]=='[')){
        len--;
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char a[10];
    scanf("%s",a);
    int n=strlen(a),c=1;
    for(int i=0;i<n;i++){
         if(a[i]=='(' || a[i]=='{' || a[i]=='['){
            add(a[i]);
         }
         else if(a[i]==')' || a[i]=='}' || a[i]==']'){
            c=check(a[i]);
         }
         if(c==0){
            printf("Unbalanced\n");
            break;
         }
    }
    if(c==1 & len==0){
        printf("Balanced\n");
    }
    else{
        printf("Unbalanced\n");
    }
}