#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int power;
	struct node *link;
};
typedef struct node *poly;

poly createh(poly h)
{
	h = (poly)malloc(sizeof(struct node));
	h->link = h;
	h->coeff=0;
	h->power=0;
	return h;
}
void createpoly(int coeff,int exp,poly h)
{
	poly nn,temp,prev;
	nn = (poly)malloc(sizeof(struct node));
	nn->coeff = coeff;
	nn->power = exp;
	nn->link = nn;

	if(h->link==h)
	{
		h->link = nn;
	}
	else
	{
		temp=h->link->link;
		prev = h->link;
		while(temp!=h->link && temp->power > nn->power)
		{
			prev = temp;
			temp = temp->link;
		}
		if(temp==h->link)
		{

			if(temp->power > nn->power)
			{
				nn->link=temp->link;
				temp->link=nn;
				h->link=nn;
			}
			else
			{
				prev->link = nn;
				nn->link = temp;
			}
		}
		else
		{
			nn->link = temp;
			h->link->link = nn;
		}
	}
	h->coeff++;

}
void read(poly h)
{
	int coeff,exp;
	poly nn,temp;
	for(;;)
	{
		printf("Enter the value for the coeff (Enter -111 to stop)\n");
			scanf("%d",&coeff);
		if(coeff==-111)
			break;
		printf("Enter the value for the power of x\n");
			scanf("%d",&exp);
		createpoly(coeff,exp,h);
	}
}



void disp(poly h)
{
	poly temp;
	temp = h->link->link;
	if(h->link==h)
	{
		printf("You haven't entered the polynomial\n");
		return;
	}
	do
	{
		if(temp->coeff > 0)
			printf("+ ");
		printf("%d X^%d ",temp->coeff,temp->power);
		temp = temp->link;
	}while(temp!=h->link->link);
	printf("\n");
}

int expo(int e,int x)
{
	if(e==0)
		return 1;
	return x*expo(e-1,x);
}
void evaluate(poly h)
{
	poly temp;
	int sum=0,x=0;
	if(h->link==h)
	{
		printf("You have not entered the polynomial\n");
		return;
	}
	printf("Enter the value for x\n");
		scanf("%d",&x);
	temp = h->link->link;
	do
	{
		sum += temp->coeff * expo(temp->power,x);
		temp = temp->link;
	}while(temp!=h->link->link);
	printf("The result of evaluation for the value of x %d is %d\n",x,sum);
}

int greater(int a,int b)
{
	if(a>b)
		return 1;
	else if(a==b)
		return 0;
	else
		return -1;
}

void add(poly h1,poly h2,poly h3)
{
	int expo,coeff,result,count1=0,count2=0;
	poly t1,t2,tp;
	t1 = h1->link->link;
	t2 = h2->link->link;
	
	do
	{
		result = greater(t1->power,t2->power);
		switch(result)
		{
			case 1:
				createpoly(t1->coeff,t1->power,h3);
				t1 = t1->link;
				count1++;
				break;
			case 0:
				coeff = t1->coeff+t2->coeff;
				expo = t1->power;
				//printf("%d %d\n",coeff,expo);
				if(coeff!=0)
					createpoly(coeff,expo,h3);
				t1 = t1->link;
				t2 = t2->link;
				count1++;
				count2++;
				break;
			case -1:
				createpoly(t2->coeff,t2->power,h3);
				
				t2 = t2->link;
				count2++;
				break;
		}	
		
	}while(count1 < h1->coeff && count2 < h2->coeff);

	while(count1<h1->coeff)
	{
		createpoly(t1->coeff,t1->power,h3);
		t1 = t1->link;
		count1++;
	}
	while(count2 < h2->coeff)
	{
		createpoly(t2->coeff,t2->power,h3);
		t2 = t2->link;
		count2++;
	}

}

int main()
{
	poly h1,h2,h3;
	int ch;

	createheader:
		h1 = createh(h1);
		h2 = createh(h2);
		h3 = createh(h3);
	while(1)
	{
		printf("-----Polynomial-----\n");
		printf("1.Enter the polynomial\n");
		printf("2.Display the polynomial\n");
		printf("3.Evaluate the polynomial\n");
		printf("4.Add 2 polynomials\n");
			scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				read(h1);
				break;
			case 2:
				disp(h1);
				break;
			case 3:
				evaluate(h1);
				break;
			case 4:
				if(h1->link==h1)
				{
					printf("Enter the first polynomial\n");
					read(h1);
					disp(h1);
				}
				printf("Enter the second equation\n");
				read(h2);
				disp(h2);
				add(h1,h2,h3);
				//printf("%d\n",h3->link->coeff);
				disp(h3);

				goto createheader;
				// h1 = createh(h1);
				// h2 = createh(h2);
				// h3 = createh(h3);
				// h1->link = h1;
				// h2->link = h2;
				break;
			default:
				exit(1);
		}
	}
}