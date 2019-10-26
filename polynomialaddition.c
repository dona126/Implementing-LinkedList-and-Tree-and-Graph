
//POLYNOMIAL ADDITION

#include<stdio.h>
#include<stdlib.h>
struct node

     {

        int coef;
	int exp;
	struct node *addr;

     };
struct node *createterm(int coeff, int expp);
struct node *createpoly(int n);
struct node *addpoly(struct node *h1,struct node *h2);
void traversal(struct node *head);

void main()
	{
		struct node *h1=NULL,*h2=NULL,*R;
		int n,m;
		printf("Enter number of terms of first polynomial:");
		scanf("%d",&n);
		printf("Enter number of terms of second polynomial:");
		scanf("%d",&m);
		h1=createpoly(n);
		h2=createpoly(m);
		printf("First polynomial:\n");
		traversal(h1);
		printf("Second polynomial:\n");
		traversal(h2);
		printf("Resultant polynomial:\n");
		R=addpoly(h1,h2);
		traversal(R);

	}
struct node *createterm(int coeff, int expp)
	{
		struct node *p;
		p=(struct node *)malloc(sizeof(struct node ));
		p->coef=coeff;
		p->exp=expp;
		p->addr=NULL;
		return p;

	}



struct node *createpoly(int n)
	{
		int i=1,coeff,expp;

		struct node *nt,*head=NULL,*last;

		for(i=1;i<=n;i++)
			{
				printf("Enter coefficient and exponent of %d th terms",i);
				scanf("%d",&coeff);
				scanf("%d",&expp);
				nt=createterm(coeff,expp);
				if(head==NULL)
					{
						head=nt;
						last=nt;
					}
				else
       					{
       						last->addr=nt;
       						last=nt;
					}
			}
		return head;
	}



void traversal(struct node *head)
	{
		struct node *p;
		p=head;
		while(p!=NULL)
           		{
				printf("%dx%d+",p->coef,p->exp);
				p=p->addr;
			}
		printf("\n");

	}


struct node *addpoly(struct node *h1,struct node *h2)
	{
		struct node *R=NULL,*p1,*p2,*last,*n;
		p1=h1;
		p2=h2;
		while(p1!=NULL && p2!=NULL)
			{
				if(p1->exp>p2->exp)
					{
						n=createterm(p1->coef,p1->exp);
						p1=p1->addr;
					}
				else if(p1->exp<p2->exp)
					{
						n=createterm(p2->coef,p2->exp);
						p2=p2->addr;
					}
				else
					{
						n=createterm(p1->coef + p2->coef,p1->exp);
						p1=p1->addr;
						p2=p2->addr;
					}

				if(R==NULL)
					{
						R=n;
						last=n;
     				        }
				else
					{
						last->addr=n;
						last=n;
					}
			}
		while(p1!=NULL)
			{
				n=createterm(p1->coef,p1->exp);
				p1=p1->addr;
			        if(R==NULL)
					{
					        R=n;
						last=n;
       					}
				else
					{
						last->addr=n;
						last=n;
					}
			}
		while(p2!=NULL)
			{
				n=createterm(p2->coef,p2->exp);
				p2=p2->addr;
			        if(R==NULL)
					{
						R=n;
						last=n;
					}
				else
					{
						last->addr=n;
						last=n;
					}
			}
		return R;
	}




