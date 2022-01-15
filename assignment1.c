#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *right,*left;
};
typedef struct node *Node;
Node createnode(Node nw)
{
	nw = (Node)malloc(sizeof(struct node));
	nw->right = nw->left = nw;
	printf("Enter the info\n");
		scanf("%d",&nw->info);
	return nw;
}

void Insertrear(Node Header)
{
	Node nw;
	nw = createnode(nw);

		Header->left->right = nw;
		nw->left = Header->left;
		nw->right = Header;
		Header->left = nw;
	
		Header->info++;
}

void Disp(Node Header)
{
	Node temp;
	if(Header->info==0)
	{
		printf("The list is empty\n");
		return;
	}
	temp = Header->right;
	while(temp!=Header)
	{
		printf("%d-> ",temp->info);
		temp = temp->right;
	}
	printf("\n");
}

void Insert(Node Header,int k)
{
	Node nw,temp;
	int count = 1;
	nw = createnode(nw);
	temp = Header->right;
	
	while(temp!=Header->left && count!=k)
	{
		temp = temp->right;
		count++;
	}
	if(count!=k)
	{
		printf("Invalid position\n");
		return;
	}
	nw->right = temp;
	nw->left = temp->left;
	temp->left->right = nw;
	temp->left = nw;
	Header->info++;
}

void Delete1(Node Header,int k)
{
	Node temp;
	int count = 1;
	if(Header->info == 0)
	{
		printf("Empty list\n");
		return;
	}
	temp = Header;
	while(temp!=Header->left && count!=k)
	{
		temp = temp->right;
		count++;
	}
	if(count!=k || k==1 || Header->info == 1)
	{
		printf("Invalid pos\n");
		return;
	}
	temp->left->right = temp->right;
	temp->right->left = temp->left;
	printf("Deleting the node with info %d\n",temp->info);
	free(temp);
	Header->info--;
	
}

void Delete2(Node Header,int k)
{
	Node temp;
	int count=1;
	if(Header->info==0)
	{
		printf("The list is empty\n");
		return;
	}
	temp = Header->right;
	while(temp!=Header->left && count!=k)
	{
		temp = temp->right;
		count++;
	}
	if(temp==Header->left || count!=k)
	{
		printf("Invalid position\n");
		return;
	}
	temp = temp->right;
	temp->left->right = temp->right;
	temp->right->left = temp->left;
	printf("Deleting the node with info %d\n",temp->info);
	free(temp);
	Header->info--;

}

void swap(Node Header,Node N1,Node N2)
{
	Node s1,s2,p1,p2,temp;
	if(N1->left == N2)
	{
		temp = N1;
		N1 = N2;
		N2 = temp;
	}
	p1 = N1->left;
	p2 = N2->left;
	s1 = N1->right;
	s2 = N2->right;
	if(N1->right == N2)
	{
		p1->right = N2;
		N2->left = p1;
		N2->right = N1;
		N1->left = N2;
		s2->left = N1;
		N1->right = s2;
	}
	else
	{
		N1->right = s2;
		s2->left = N1;
		N1->left = p2;
		p2->right = N1;
		N2->right = s1;
		s1->left = N2;
		N2->left = p1;
		p1->right = N2;
	}
}

Node searchkey(Node Header,int k)
{
	Node temp = Header->right;

	while(temp!=Header)
	{
		if(temp->info == k)
			return temp;
		temp = temp->right;
	}
	return NULL;
}

void Removeinsert(Node Header)
{
	Node last;
	last = Header->left;
	last->left->right = Header;
	Header->left = last->left;
	last->right = Header->right;
	last->left =  Header;
	Header->right->left = last;
	Header->right = last;
}

void RevDisp(Node Header)
{
	Node temp = Header->left;
	if(Header->info==0)
	{
		printf("The list is empty\n");
		return;
	}
	while(temp!=Header)
	{
		printf("<-%d",temp->info);
		temp = temp->left;
	}
	printf("\n");
}



void sort(Node H)
{
	Node tn=H->right,pn;
	int i,j,temp;

	if(H->info==0)
	{
		printf("The list is empty\n");
		return;
	}
	pn = tn;

	for(i=0;i<H->info-1;i++)
	{
		tn = pn;
		for(j=0;j< H->info-1-i ;j++)
		{
			if(tn->info > tn->right->info)
			{
				temp = tn->info;
				tn->info = tn->right->info;
				tn->right->info = temp;
			}
			tn = tn->right;
		}
	}
}

void Insertbyorder(Node H)
{
	
	Insertrear(H);
	sort(H);
}

void Merge(Node H1,Node H2)
{
	Node temp;
	temp = H1->left;
	temp->right = H2->right;
	H2->right->left = temp;
	temp = H2->left;
	temp->right = H1;
	H1->left = temp;
	H1->info += H2->info;
	free(H2);
	H2=NULL;
	sort(H1);
}

void Merge1(Node H1,Node H2)
{
	Node p1,p2,temp;
	int k=0;
	p1 = H1->right;
	p2 = H2->right;
	while(k < H2->info)
	{
			temp = p2;
			p2 = p2->right;
			while(p1!=H1->left && p1->info<temp->info)
				p1 = p1->right;
			if(p1->info<temp->info)
			{
				p1->right = temp;
				temp->left = p1;
				temp->right = H1;
				H1->left = temp;
				p1 = p1->right;
			}
			else
			{
				temp->right = p1;
				temp->left = p1->left;
				p1->left->right = temp;
				p1->left = temp;
			}
			k++;
	}
	H1->info = H1->info+H2->info;

}

int main()
{
	Node Header,n1,n2,H1,H2;
	Header = (Node)malloc(sizeof(struct node));
	Header->info = 0;
	Header->right = Header->left = Header;
	int k,k1,k2;
	H1 = (Node)malloc(sizeof(struct node));
	H1->info = 0;
	H1->right = H1->left = H1;

	H2 = (Node)malloc(sizeof(struct node));
	H2->info = 0;
	H2->right = H2->left = H2;

	int ch;
	while(1)
	{
		printf("Assignment questions 1 to 6\n");
		printf("1.Insert rear\n");
		printf("2.Display\n");
		printf("3.Insert\n");
		printf("4.Delete the node which is predecessor of kth node\n");
		printf("5.Delete the node which is the successor of kth node\n");
		printf("6.Remove the last node and insert it to the front\n");
		printf("7.Swap\n");
		printf("8.Display list in reverse\n");
		printf("9.Merge 2 sorted lists into a single sorted list\n");
			scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				Insertrear(Header);
				Disp(Header);
				break;
			case 2:
				Disp(Header);
				break;
			case 3:
				printf("Enter the value of the pos\n");
					scanf("%d",&k);
				Insert(Header,k);
				break;
			case 4:
				printf("Enter the value of the pos\n");
					scanf("%d",&k);
				Delete1(Header,k);
				break;
			case 5:
				printf("Enter the value of the pos\n");
					scanf("%d",&k);
				Delete2(Header,k);
			case 6:
				Removeinsert(Header);
				Disp(Header);
				break;
			case 7:
				printf("Enter the value of first node key\n");
					scanf("%d",&k1);
				n1 = searchkey(Header,k1);
				printf("Enter the value of second node key\n");
					scanf("%d",&k2);
				n2 = searchkey(Header,k2);

				if(n1!=NULL && n2!=NULL)
					swap(Header,n1,n2);
				Disp(Header);
				break;
			case 8:
				RevDisp(Header);
				break;
			case 9:
				printf("Enter the values for the first LL (Enter -111 to stop and 0 to continue)\n");
				while(1)
				{
					scanf("%d",&ch);
					if(ch==-111)
						break;
					Insertbyorder(H1);
				}
				printf("Enter the values for the second LL (Enter -111 to stop and 0 to continue)\n");
				while(1)
				{
					scanf("%d",&ch);
					if(ch==-111)
						break;
					Insertbyorder(H2);
					//Disp(H2);
				}
				printf("After merging details of 2 LL the final sorted LL is\n");
				Merge1(H1,H2);
				Disp(H1);

			default:
				exit(1);
		}
	}
	return 0;
}

