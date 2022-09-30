#include<stdio.h>
void tower_hanoi(int n,int a,int b,int c)
{
	if(n>0)
	{
		tower_hanoi(n-1,a,c,b);
		printf("%d->%d \n",a,c);
		tower_hanoi(n-1,b,a,c);
	}
}
int main()
{
    int n;
    printf("Enter No . Of Disk => ");
    scanf("%d",&n);
	tower_hanoi(n,100,200,300);
}
