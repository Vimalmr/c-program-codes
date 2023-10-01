#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	char ip[15];
	scanf("%s",ip);
	int fo=atoi(strtok(ip,"."));
	
	if(fo>=0 && fo<=126){
		printf("Class A");
	}
	else if(fo>=127 && fo<=191){
		printf("Class B");
	}
	else if(fo>=192 && fo<=223){
		printf("Class C");
	}
	else if(fo>=224 && fo<=239){
		printf("Class D");
	}
	else if(fo>=240 && fo<=255){
		printf("Class E");
	}
	else{
		printf("Inncorrect input");
	}
	
}
