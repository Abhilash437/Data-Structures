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

// Node *delete2(Node *pf) //following a negetive element
// {
// 	Node *pn,*tn;
// 	tn = pf;
// 	pn = NULL;

// 	while(tn != NULL)
// 	{
// 		if(pn!=NULL && pn->info < 0)
// 		{
// 				pn->link = tn->link;
// 				printf("Deleting node %d\n",tn->info);
// 				free(tn);
// 				return pf;
// 		}
// 			pn = tn;
// 			tn = tn->link;
// 	}
// 	return pf;
// }

// Node *delete3(Node *pf) //following a negetive element
// {
// 	Node *pn,*tn,*qn;
// 	tn = pf;
// 	pn = qn = NULL;

// 	while(tn != NULL)
// 	{
// 		if(pn != NULL && tn->info < 0)
// 		{
// 			if(qn==NULL)
// 			{
// 				pf = pn;
// 				printf("Deleting node %d\n",pf->info);
// 				free(pn);
// 			}
// 			else
// 			{
// 				qn->link = tn;
// 				printf("Deleting node %d\n",pn->info);
// 				free(pn);
// 			}
// 		}
// 			qn = pn;
// 			pn = tn;
// 			tn = tn->link;
// 	}
// 	return pf;
// }


