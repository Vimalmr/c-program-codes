#include<stdio.h>

int operation(int row, int col);

int killed;
int ter[8][8]={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};

int main(){
    int heli=0;
    int row,col,count;
    printf("How many choppers to land ?");
    scanf("%d",&heli);
    if(heli >= 0 ){
        for(int i=heli; i>=1; i--){
            printf("Enter the coordiantes to land the chopper [x,y = 1-8] #%d \n",i);
            printf("Enter X-coordinate: ");
            scanf("%d",&row);
            printf("Enter Y-coordinate: ");
            scanf("%d",&col);
            if(row > 0 && row <=8 && col > 0 && col <=8){
                count = operation(row-1, col-1);
            }
            else{
                printf("Give valid input in numbers between 1 to 8\n");
                break;
            }
        printf("%d terrorists has been killed totally. \n",count);
        }
    }
    else {
        printf("Give Valid input in numbers more than 0 \n");
    }

}

int operation(int row, int col){
    //row
    for(int i=0; i<8; i++){
        killed = killed + ter[row][i];
        ter[row][i] = 0;
    }

    // column
    for(int i=0; i<8; i++){
        killed = killed + ter[i][col];
		ter[i][col] = 0;
	}
    return killed;

}