#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *link;
}Node;

void disp(Node *pf);
Node *insertfront(Node *pf);
Node *createnode(Node *nw);
Node *delete1(Node *pf);
Node *delete2(Node *pf);

Node *delete3(Node *pf);
Node *searchneg(Node *pf);

Node *insertrightk(Node *pf,int k);

Node *insertleftk(Node *pf,int k);
Node *destroy(Node *pf);
Node *searchkey(Node *pf,int k);
Node *swap(Node *pf,Node *N1,Node *N2);


int main()
{
	Node *root = NULL;
	int ch;
	int k;
	Node *n1,*n2;
	int k1,k2;

	while(1)
	{
		printf("1.Insertfront\n");
		printf("2.Delete neg\n");
		printf("3.Delete 2\n");
		printf("4.Delete 3\n");
		printf("5.Disp\n");
		printf("6.Insert right of k\n");
		printf("7.Insert left of k\n");
		printf("8.Destroy\n");
		printf("9.Swap 2 nodes\n");
			scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				root = insertfront(root);
				break;
			case 2:
				root = delete1(root);
				break;
			case 3:
				root = delete2(root);
				break;
			case 4:
				root = delete3(root);
				break;
			case 5:
				disp(root);
				break;
			case 6:
				printf("Enter the value of k\n");
					scanf("%d",&k);
				root = insertrightk(root,k);
				break;
			case 7:
				printf("Enter the value of k\n");
					scanf("%d",&k);
				root = insertleftk(root,k);
				break;
			case 8:
				root = destroy(root);
				break;

			case 9:
				printf("Enter the value of first node key\n");
					scanf("%d",&k1);
				n1 = searchkey(root,k1);
				printf("Enter the value of second node key\n");
					scanf("%d",&k2);
				n2 = searchkey(root,k2);

				if(n1!=NULL && n2!=NULL)
					root = swap(root,n1,n2);
				disp(root);
				break;


			default:
				exit(1);
		}
	}
	
	return 0;
}

Node *createnode(Node *nw)
{
	nw = (Node *)malloc(sizeof(Node));
	nw->link = NULL;
	return nw;
}

Node *insertfront(Node *pf)
{
	Node *nw;
	nw = createnode(nw);
	printf("Enter the value\n");
		scanf("%d",&nw->info);
	if(pf==NULL)
		pf = nw;
	else
	{
		nw->link = pf;
		pf = nw;
	}

	return pf;
}

void disp(Node *pf)
{
	if(pf==NULL)
	{
		printf("Empty");
		return;
	}
	while(pf != NULL)
	{
		printf("%d ",pf->info);
		pf = pf->link;
	}
	printf("\n");
}



Node *delete2(Node *pf)//delete node next to neg
{
	Node *tn,*pn;
	tn = pf;
	pn = tn;
	tn = tn->link;

	while(tn!=NULL)
	{
		if(pn->link != NULL && pn->info < 0 )
		{
			pn->link = tn->link;
			free(tn);
			tn = pn->link;
		}
		if(tn!=NULL)
		{
			pn = tn;
			tn = tn->link;
		}

	}
	return pf;
}


Node *swap(Node *pf,Node *N1,Node *N2)//swap 2 nodes
{
	Node *p1,*p2,*T;
	p1 = pf;
	while(p1 != N1 && p1->link != N1)
		p1 = p1->link;

	p2 = N1->link;

	while(p2 != N2 && p2->link != N2)
		p2 = p2->link;

	T = N2->link;
	N2->link = N1->link;
	p1->link = N2;
	p2->link = N1;
	N1->link = T;

	printf("N2 = %d N1 = %d\n",N2->info,N1->info);

	if(N1==pf)
	{
		
		pf = N2;
		printf("NULL\n");
	}
		//return N2;
	return pf;
}

Node *delete3(Node *pf)//delete the node previous to node having a negetive key value
{
	Node *tn,*pn,*qn;
	qn=pn=NULL;
	tn = pf;

	while(tn!=NULL)
	{
		if(tn->info >= 0)
		{
			qn = pn;
			pn = tn;
			tn = tn->link;
		}
		else if(pn==NULL)
		{
			if(pn==NULL)
			{
				qn = pn;
				pn = tn;
				tn = tn->link;
			}

			else
			{
				pf = tn;
				free(pn);
				pn=NULL;
			}
		}
		else
		{
			qn->link = tn;
			free(pn);
			pn = tn;
			tn = tn->link;
		}
			
		

	}
	return pf;
}




Node *delete1(Node *pf)//delete all nodes containing a negative value
{
	Node *temp,*pos,*prev=NULL;
	temp = pf;
	while(temp!=NULL)
	{
		pos = searchneg(temp);
		if(pos != NULL)
		{
			if(prev == NULL)
			{
				pf = pf->link;
				free(temp);
				temp = pf;
			}
			else
			{
				while(temp!=pos)
				{
					prev = temp;
					temp = temp->link;
				}
				prev->link = temp->link;
				free(temp);
				temp = pf;
				prev = NULL;
			}	
		}
		else
		{
			prev = temp;
			temp = temp->link;
		}
	}
	return pf;
}

Node *searchneg(Node *pf)
{
	if(pf->info<0)
		return pf;
	else
		return NULL;
}


Node *insertrightk(Node *pf,int k)//insert element to the right of kth node
{
	Node *temp,*nw,*prev=NULL;
	int count=1;
	temp = pf;

	while(temp != NULL && count!=k)
	{
		prev = temp;
		temp = temp->link;
		count++;
	}
	if(temp == NULL)
	{
		printf("Entered position is invalid\n");
		return pf;
	}
	nw = createnode(nw);
	printf("Enter the info\n");
		scanf("%d",&nw->info);
	nw->link = temp->link;
	temp->link = nw;

	printf("check\n");
	return pf;
}

Node *insertleftk(Node *pf,int k)//insert node to the left of kth node
{
	Node *temp,*nw,*prev=NULL;
	int count=1;
	temp = pf;

	while(temp != NULL && count != k)
	{
		prev = temp;
		temp = temp->link;
		count++;
	}
	if(temp == NULL)
	{
		printf("Entered position is invalid\n");
		return pf;
	}
	nw = createnode(nw);
	printf("Enter the info\n");
		scanf("%d",&nw->info);

	if(prev == NULL)
		pf = nw;
	else
		prev->link = nw;
	nw->link = temp;
	printf("check\n");
	return pf;
}




Node *destroy(Node *pf)//destroy all nodes
{
	Node *temp;
	temp = pf;
	while(pf!=NULL)
	{
		pf = pf->link;
		free(temp);
		temp = pf;
	}
	return NULL;
}

Node *searchkey(Node *pf,int k)
{
	Node *temp = pf;

	while(temp!=NULL)
	{
		if(temp->info == k)
			return temp;
		temp = temp->link;
	}
	return NULL;
}
