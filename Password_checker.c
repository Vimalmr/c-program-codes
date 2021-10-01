#include<stdio.h>
#include<ctype.h>
#include<string.h>

int check_password(char *password){
    int a=0,b=0,c=0,d=0;
    if(strlen(password) >= 8 ){
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
            return 1;
        }
        else if(b==0 && c==0 && d<3){
            return 2;
        }
        else if(c==0 && d<3 && a<3){
            return 3;
        }
        else if(d<3 && a<3 && b==0){
            return 4;
        }
        else if((a<3 && b==0) || (c==0 && d<3)){
            return 5;
        }
        else if((b==0 && c==0) || (d<3 && a<3)){
            return 6;
        }
        else if(a<3 || b==0){
            return 7;
        }
        else if(c==0 || d<3){
            return 8;
        }
        else if(a>3 && b!=0 && c!=0 && d>3){
            return 9;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    char paswrd[25];
    printf("1. Password must be minimum of 8 characters. \n");
    printf("2. Password must have one Uppercase Character. \n");
    printf("3. Password must have three Lowercase Characters. \n");
    printf("4. Password must have one symbol. \n");
    printf("5. Password must have three Numeric Characters that are not sequential conditions \n");
    printf("Enter Password: ");
    scanf( "%s", paswrd);
    printf("\n");
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
        printf("medium Password\n");
    }
    else if(rank==7 || rank==8){
        printf("strong Password\n");
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
//
//
//
//
//
//
// this comments are there to make this program as hundred line xD
