#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
	int info;
	struct node1 *link;
}Node;

typedef struct node2{
	struct node2 *left;
	Node *right;
}Head;

Node *createnode1(Node *nw);

Head *createnode2(Head *nw);

Head *Creatematrix(Head *Table,int r,int c);



int main()
{
	int r,c;
	Head *Table=NULL;
		printf("enter the number of rows and columns\n");
			scanf("%d%d",&r,&c);

		Table = Creatematrix(Table,r,c);
		


}

Node *createnode1(Node *nw)
{
	nw = (Node *)malloc(sizeof(Node));
	nw->link = NULL;
	return nw;
}

Head *createnode2(Head *nw)
{
	nw = (Head *)malloc(sizeof(Head));
	nw->right = NULL;
	nw->left = NULL;
	return nw;
}

Head *Creatematrix(Head *Table,int r,int c)
{
	Head *temp;
	Node *f1;
	Node *nw1;
	Head *nw2;
	int i,j;

		temp = Table;
		//creation of header nodes
		for(i = 0;i<r;i++)
		{

			nw2 = createnode2(nw2);
			if(temp == NULL)
				temp = Table = nw2 ;
			else
			{
				while(temp->left!=NULL)
					temp = temp->left;
				temp->left = nw2;
			}
		}

		temp = Table;

		//creating matrix
		for(i=0;i<r;i++)
		{

			for(j=0;j<c;j++)
			{
				nw1 = createnode1(nw1);
				printf("Enter the %d %d element\n",i,j);
					scanf("%d",&nw1->info);

				if(temp->right == NULL)
					temp->right = f1 = nw1;
				else
				{
					f1->link = nw1;
					f1 = f1->link;
				}
			}
			temp = temp->left;
		}

		printf("Displaying\n");
		temp = Table;

		for(i=0;i<r;i++)
		{
			f1 = temp->right;
			for(j=0;j<c;j++)
			{
				printf("%2d ",f1->info);
				f1 = f1->link;
			}
			temp = temp->left;
			printf("\n");
		}

		return Table;
 

}