#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;

Node createnode(Node nn);
Node attach(Node n,Node h);
void read(Node h);
void disp(Node h);
Node add(Node h1,Node h2,Node h3);
void disp1(Node h);

int main()
{
	Node h1,h2,h3;
	h1 = (Node)malloc(sizeof(struct node));
	h2 = (Node)malloc(sizeof(struct node));
	h3 = (Node)malloc(sizeof(struct node));
	h1->info=0;
	h2->info=0;
	h3->info=0;
	h1->link=NULL;
	h2->link=NULL;
	h3->link=NULL;

	int ch;
	while(1)
	{
		printf("Implementation of long integer values\n");
		printf("1.Enter the number\n");
		printf("2.Display the number\n");
		printf("3.Add two long int\n");
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
				if(h1->link==NULL)
				{
					printf("Enter the first number\n");
					read(h1);
				}
				printf("Enter the 2nd number\n");
				read(h2);
				//disp(h2);
				h3 = add(h1,h2,h3);
				disp1(h3);

				break;
			default:
				exit(1);
		}
	}
}


Node createnode(Node nn)
{
	nn = (Node)malloc(sizeof(struct node));
	nn->link = NULL;
	return nn;

}

Node attach(Node n,Node h)
{
	Node temp;
	temp = h->link;
	if(h->link==NULL)
		h->link = n;
	else
	{
		n->link = temp;
		h->link = n;
	}
	h->info++;
	return h;
}

void read(Node h)
{
	Node nn,temp;
	int digit;
	printf("Enter the number (Enter -111 to stop)\n");

	for(;;)
	{
		nn = createnode(nn);
		scanf("%d",&digit);
		if(digit==-111)
			break;
		nn->info = digit;
		h = attach(nn,h);
	}

}

void disp(Node h)
{
	Node temp;
	int *array,i;
	array = (int *)malloc(sizeof(int)*h->info);
	temp = h->link;
	//printf("%d\n",temp->info);
	if(h->link==NULL)
	{
		printf("You have not entered the number\n");
		return;
	}
	for(i=h->info-1;i>=0 && temp!=NULL;i--)
	{
		*(array+i) = temp->info;
		temp = temp->link;
	}

	for(i=0;i<h->info;i++)
		printf("%d",*(array+i));
	printf("\n");
	free(array);
	array=NULL;

}

void disp1(Node h)
{
	Node temp;
	int *array,i;
	//array = (int *)malloc(sizeof(int)*h->info);
	temp = h->link;
	//printf("%d\n",temp->info);
	if(h->link==NULL)
	{
		printf("You have not entered the number\n");
		return;
	}
	for(;temp!=NULL;)
	{
		printf("%d",temp->info);
		temp = temp->link;
	}
	printf("\n");

}
Node add(Node h1,Node h2,Node h3)
{
	Node t1,t2,nn,tp=NULL;
	int sum=0,carry=0,digit=0;
	t1 = h1->link;
	t2 = h2->link;
	while(t1!=NULL && t2!=NULL)
	{
		sum = t1->info+t2->info+carry;
		digit = sum%10;
		carry = sum/10;
		nn = createnode(nn);
		nn->info = digit;
		h3 = attach(nn,h3);
		t1 = t1->link;
		t2 = t2->link;
	}

	if(t1!=NULL)
		tp = t1;
	else if(t2!=NULL)
		tp = t2;
	while(tp!=NULL)
	{
		sum = tp->info+carry;
		digit = sum%10;
		carry = sum/10;
		nn = createnode(nn);
		nn->info = digit;
		h3 = attach(nn,h3);
		tp = tp->link;
	}

	if(carry!=0)
	{
		nn=createnode(nn);
		nn->info = carry;
		h3 = attach(nn,h3);
	}
	return h3;
}