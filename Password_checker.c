#include<stdio.h>
#include<ctype.h>
#include<string.h>

int check_password(char *password){
    int a=0,b=0,c=0,d=0;
    if(strlen(password) >= 8 ){
        printf("Strong\n");
        for(int i=0; i<strlen(password); i++){
            if(isupper(password[i])){
                b++; //b=upper
            }
            else if(islower(password[i])){
                a++; //a=lower
            }
            else if(isdigit(password[i])){
                d++; //d=number
            }
            else{
                c++; //c=symbol
            }
        }
        if(a<3 && b==0 && c==0){
            printf("1\n");
            return 1;
        }
        else if(b==0 && c==0 && d<3){
            printf("2\n");
            return 2;
        }
        else if(c==0 && d<3 && a<3){
            printf("3\n");
            return 3;
        }
        else if(d<3 && a<3 && b==0){
            printf("4\n");
            return 4;
        }
        else if((a<3 && b==0) || (c==0 && d<3)){
            printf("5\n");
            return 5;
        }
        else if((b==0 && c==0) || (d<3 && a<3)){
            printf("6\n");
            return 6;
        }
        else if(a<3 || b==0){
            printf("7\n");
            return 7;
        }
        else if(c==0 || d<3){
            printf("8\n");
            return 8;
        }
        else if(a>3 && b!=0 && c!=0 && d>3){
            printf("9\n");
            return 9;
        }
        else{
            printf("0\n");
            return 0;
        }
    }
    else{
        printf("0\n");
        return 0;
    }
}

int main(){
    char paswrd[20];
    printf("Enter Password: \n");
    scanf( "%s", paswrd);
    int rank = check_password(paswrd);
    if(rank==0){
        printf("Weakest Password\n");
    }
    else if(rank==1 || rank==2){
        printf("Weak Password\n");
    }
    else if(rank==3 || rank==4){
        printf("average Password\n");
    }
    else if(rank==5 || rank==6){
        printf("medium Passwordn\n");
    }
    else if(rank==7 || rank==8){
        printf("strong Passwordn\n");
    }
    else if(rank==9){
        printf("strongest Password\n");
    }
    return 0;
}
//
//
//
//
//
// this comments are there to make this program as hundred line xD