#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int co;
	int exp;
	struct node *nxt;
}*poly1,*poly2,*res,*nw,*t1,*t2,*t3;

int main()
{
	int c,q;
	int p1;
	int p2;
	poly1=NULL;
	poly2=NULL;
	c=1;
	while(c)
	{
		printf("\n Press 1 to create poly1");
		printf("\n Press 2 to create poly2");
		printf("\n Press 3 to add two poly1 and poly2 ==>");
		scanf("%d",&q);
		switch(q)
		{
			case 1: 
			        p1=1;
			        poly1=NULL;
			        while (p1!=0)
			        {
			        	nw=(struct node *)malloc(sizeof(struct node));
			        	printf("\n Enter the co for the new node ==>");
			        	scanf("%d",&nw->co);
			        	printf("\n Enter the exp for the new node ==>");
			        	scanf("%d",&nw->exp);
			        	nw->nxt=NULL;
			        	if (poly1==NULL)
			        	{
			        		poly1=nw;
			        		t1=nw;
					}
					else
					{
						t1->nxt=nw;
						t1=nw;
					}
					printf("\n Press 1 to create the node of the poly1");
					printf("\n Press 0 to stop creating ploy1==>");
					scanf("%d",&p1);
					}
				
					t1=poly1;
					while(t1!=NULL)
					{
						printf("| %d | %d |--> ",t1->co,t1->exp);
						t1=t1->nxt;
					}
				   break;
			case 2:
					p2=1;
					poly2=NULL;
			        while (p2!=0)
			        {
			        	nw=(struct node *)malloc(sizeof(struct node));
			        	printf("\n Enter the co for the new node ==>");
			        	scanf("%d",&nw->co);
			        	printf("\n Enter the exp for the new node ==>");
			        	scanf("%d",&nw->exp);
			        	nw->nxt=NULL;
			        	if (poly2==NULL)
			        	{
			        		poly2=nw;
			        		t2=nw;
						}
						else
						{
							t2->nxt=nw;
							t2=nw;
						}
						printf("\n Press 1 to create the node of the poly2");
						printf("\n Press 0 to stop creating ploy2==>");
						scanf("%d",&p2);
					}
					t2=poly2;
					while(t2!=NULL)
					{
						printf("| %d | %d |--> ",t2->co,t2->exp);
						t2=t2->nxt;
					}
				   getch();
				   break;
			case 3:
				   t1=poly1;
				   t2=poly2;
				   res=NULL;
				   t3=NULL;
				   if ((poly1==NULL) && (poly2==NULL))
				   {
				   	res=NULL;
					}
					else
					{				
				   		if ((poly1!=NULL) && (poly2==NULL))
				   			{
				   				res=poly1;
				   			}
				   		else
				   			{	
				   				if ((poly1==NULL) && (poly2!=NULL))
				   					{
				   						res=poly2;
				   					}
				   				else
								   {
								   	  while ((t1!=NULL) && (t2!=NULL))
								   	  {
								   	  		if (t1->exp>t2->exp)
												 {
													nw=(struct node*)malloc(sizeof(struct node));
													nw->co=t1->co;
													nw->exp=t1->exp;
													nw->nxt=NULL;
													if(res==NULL)
													{
														res=nw;
														t3=nw;
														t1=t1->nxt;
													}
													else
													{
														t3->nxt=nw;
														t3=nw;
														t1=t1->nxt;
													}
												 }	
											if (t1->exp<t2->exp)
											{
													nw=(struct node*)malloc(sizeof(struct node));
													nw->co=t2->co;
													nw->exp=t2->exp;
													nw->nxt=NULL;
													if(res==NULL)
													{
														res=nw;
														t3=nw;
														t2=t2->nxt;
													}
													else
													{
														t3->nxt=nw;
														t3=nw;
														t2=t2->nxt;
													}
											}
											if (t1->exp==t2->exp)
											{
													nw=(struct node*)malloc(sizeof(struct node));
													nw->co=t1->co+t2->co;
													nw->exp=t2->exp;
													nw->nxt=NULL;
													if(res==NULL)
													{
														res=nw;
														t3=nw;
														t1=t1->nxt;
														t2=t2->nxt;
													}
													else
													{
														t3->nxt=nw;
														t3=nw;
														t1=t1->nxt;
														t2=t2->nxt;
													}
											}
											
									  }
									  
									  if ((t1==NULL) && (t2!=NULL))
									  {
									  	while(t2!=NULL)
									  	{
									  				nw=(struct node*)malloc(sizeof(struct node));
													nw->co=t2->co;
													nw->exp=t2->exp;
													nw->nxt=NULL;
													t3->nxt=nw;
													t3=nw;
													t2=t2->nxt;
										}
									  }
									  if ((t1!=NULL) && (t2==NULL))
									  {
									  	while(t1!=NULL)
									  	{
									  				nw=(struct node*)malloc(sizeof(struct node));
													nw->co=t1->co;
													nw->exp=t1->exp;
													nw->nxt=NULL;
													t3->nxt=nw;
													t3=nw;
													t1=t1->nxt;
										}
									  } 
									  
									  
								   }	
							}
					}
				   
				if (res==NULL)
				{
					printf("\n The resulted list is NULL")	;
				}
				else
				{
					t3=res;
					while(t3!=NULL)
					{
						printf("| %d | %d |--> ",t3->co,t3->exp);
						t3=t3->nxt;
					}
				}
				   
				   
				   break;
			default:
				   break;
		}
	printf("\n Press 1 to re-do again the polynomial addition");
	printf("\n Press 0 to exit ==>");
	scanf("%d",&c);
	}
}
