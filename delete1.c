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


int main()
{
	Node *root = NULL;
	int ch;

	while(1)
	{
		printf("1.Insertfront\n");
		printf("2.Delete neg\n");
		printf("3.Delete 2\n");
		printf("4.Delete 3\n");
		printf("5.Disp\n");
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
			default:
				exit(1);
		}
	}
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

// Node *delete2(Node *pf)
// {
// 	Node *pn,*tn;
// 	pn = NULL;
// 	tn = pf;

	
// 	while(tn != NULL)
// 	{
// 		while(tn->info<0)
// 		{
// 			pn = tn;
// 			tn = tn->link;
// 		}
// 		if(pn == NULL)
// 		{
// 			pn = tn;
// 			tn = tn->link;
// 		}
// 		else
// 		{
// 			pn->link = tn->link;
// 			free(tn);
// 			tn = pn->link;
// 			if(tn != NULL)
// 			{
				
// 				pn = tn;
// 				tn = tn->link;
// 			}
// 		}
// 		// pn = tn;
// 		// tn = tn->link;
// 	}

// 	return pf;
	

// }

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

// Node *delete3(Node *pf)//prev neg
// {
// 	Node *tn,*pn,*qn;
// 	qn=pn=NULL;
// 	tn = pf;

// 	while(tn!=NULL)
// 	{
// 		if(tn->info >= 0 && tn!=NULL)
// 		{
// 			qn = pn;
// 			pn = tn;
// 			tn = tn->link;
// 		}
// 		else if(tn->info < 0)
// 		{
// 			if(pn==NULL && qn==NULL)
// 			{
// 				qn = pn;
// 				pn = tn;
// 				tn = tn->link;
// 			}
// 			else
// 			{
// 				if(qn==NULL)
// 				{
// 					pf = tn;
// 					free(pn);
// 					pn=NULL;
// 				}
// 				else
// 				{
// 					qn->link = tn;
// 					free(pn);
// 					pn = tn;
// 					tn = tn->link;
// 				}
// 			}
// 		}

// 	}
// 	return pf;
// }


// Node *delete1(Node *pf)
// {
// 	Node *p,*q,*r;
// 	p = pf;
// 	q = NULL;
// 	r = NULL;

// 	while(p!=NULL)
// 	{
// 		if(q==NULL)
// 		{
// 			if(p->info < 0)
// 			{
// 				pf = pf->link;
// 				free(p);
// 				p = pf;
// 			}
// 			else
// 			{
// 				r = q;
// 				q = p;
// 				p = p->link;
// 			}
// 		}
// 		else if( q->info < 0)
// 		{
// 				r->link = p;
// 				free(q);
// 				q = p;
// 				p = p->link;
// 		}
// 		else
// 		{
// 			if(p->info < 0)
// 			{
// 				q->link = p->link;
// 				free(p);
// 				p = q->link;
// 			}
// 			else
// 			{
// 				r = q;
// 				q = p;
// 				p = p->link;
// 			}
// 		}
// 	}
// 	return pf;
// }

// Node *swap(Node *pf,Node *N1,Node *N2)
// {
// 	Node *p1,*p2,*T;
// 	p1 = pf;
// 	while(p1 != N1 && p1->link != N1)
// 		p1 = p1->link;

// 	p2 = N1->link;

// 	while(p2 != N2 && p2->link != N2)
// 		p2 = p2->link;

// 	T = N2->link;
// 	p1->link = N2;
// 	N2->link = N1->link;
// 	p2->link = N1;
// 	N1->link = T;

// }

Node *delete3(Node *pf)//prev neg
{
	Node *tn,*pn,*qn;
	qn=pn=NULL;
	tn = pf;

	while(tn!=NULL)
	{
		if(tn->info >= 0 && tn!=NULL)
		{
			qn = pn;
			pn = tn;
			tn = tn->link;
		}
		else if(qn==NULL)
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


// Node *delete1(Node *pf)
// {
// 	Node *p,*q,*r;
// 	p = pf;
// 	q = r = NULL;

// 	while(p!=NULL)
// 	{
// 		if(q==NULL)
// 		{
// 			if(p->info<0)
// 			{
// 				pf = pf->link;
// 				free(p);
// 				p = pf;
// 			}
// 			else
// 			{
// 				r = q;
// 				q = p;
// 				p = p->link;
// 			}
// 		}
// 		else if(q->info<0)
// 		{
// 			r->link = p;
// 			free(q);
// 			q = p;
// 			p = p->link;
// 		}
// 		else
// 		{
// 			if(p->info<0)
// 			{
// 				q->link = p->link;
// 				free(p);
// 				p = q->link;
// 			}
// 			else{
// 				r = q;
// 				q = p;
// 				p = p->link;
// 			}
// 		}
// 	}
// 	return pf;
// }

Node *delete1(Node *pf)
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
			{while(temp!=pos)
			{
				prev = temp;
				temp = temp->link;
			}
			prev->link = temp->link;
			free(temp);
			temp = pf;
			prev = NULL;}	
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
