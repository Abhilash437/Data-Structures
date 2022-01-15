#include<stdio.h>
#include<stdlib.h>
#define colsize 40
#define rowsize 500

struct matrix
{
	int reg;
	int cc;
	struct matrix *right,*left;
};
struct student
{
	int nocour;
	char name[20];
	int regno;
	struct student *left;
	struct matrix *right;
};
struct course
{
	int nostud;
	//char name[20];
	int cc;
	struct course *right;
	struct matrix *left;
};
struct table
{
	int cinfo;
	int sinfo;
	struct student *left;
	struct course *right;
};
typedef struct matrix *details;
typedef struct student *std;
typedef struct course *cour;
typedef struct table *Table;

std createstd(std nn);
cour createcour(cour nn);
Table createrow(Table t);
Table createcol(Table t);
details createmat(details nn);
cour search(int key,cour t);
Table readdetails(Table t);
void stddisp(Table t);
void courdisp(Table t);



int main()
{
	Table T=NULL;
	T = (Table)malloc(sizeof(struct table));
	T->cinfo = T->sinfo = 0;
	T->left = NULL;
	T->right = NULL;
	int ch;
	while(1)
	{
		printf("Student and course details\n");
		printf("1.Enter the details\n");
		printf("2.Display studentwise details\n");
		printf("3.Display coursewise display\n");
			scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				T = readdetails(T);
				break;
			case 2:
				stddisp(T);
				break;      
			case 3:
				courdisp(T);
				break;
			default:
				exit(1);
		}
	}
}

std createstd(std nn)
{
	nn = (std)malloc(sizeof(struct student));
	nn->left = NULL;
	nn->right = NULL;
	nn->nocour = 0;
	return nn;
}

cour createcour(cour nn)
{
	nn = (cour)malloc(sizeof(struct course));
	nn->left=NULL;
	nn->right = NULL;
	nn->nostud = 0;
	return nn;
}
Table createrow(Table t)
{
	std temp,nn;
	int i;

	//n = 4;
	temp = t->left;
	for(i=0;i<rowsize;i++)
	{
		nn = createstd(nn);
		if(temp == NULL)
		{
			t->left = nn;
			temp = nn;
		}
		else
		{
			//temp = t->left;
			temp->left = nn;
			temp = nn;
		}
		t->sinfo++;
	}
	return t;	
}

Table createcol(Table t)
{
	cour temp,nn;
	int i;
	//n = 6;
	temp = t->right;
	for(i=0;i<colsize;i++)
	{
		nn = createcour(nn);
		nn->cc = i+1;
		if(temp==NULL)
		{
			t->right = nn;
			temp = nn;
		}
		else
		{
			temp->right = nn;
			temp = nn;
		}
		t->cinfo++;
	}
	return t;
}

details createmat(details nn)
{
	nn = (details)malloc(sizeof(struct matrix));
	nn->left = NULL;
	nn->right = NULL;
	nn->reg = nn->cc = 0;
	return nn;
}

cour search(int key,cour t)
{
	cour temp;
	temp = t;
	while(temp!=NULL && temp->cc!=key)
		temp = temp->right;
	return temp;
}

Table readdetails(Table t)
{
	t = createrow(t);
	t = createcol(t);
	std t1,n;
	cour t2,m;
	Table temp;
	int row,col,code;
	details tn,pn,nn;
	temp = t;
	t1 = t->left;
	//t2 = t->right;

	for(row=0;row<t->sinfo;row++)
	{
		printf("Enter the details of student %d\n",row+1);
		printf("Name: ");
		scanf("%s",t1->name);
		printf("Reg no: ");
		scanf("%d",&t1->regno);
		printf("Enter the course codes of the courses (maximum 4, Enter -111 to exit) \n");
		m = t2;
		n = t1;
		t2 = t->right;
		//t1 = t->left;
		//tn = t1->right;
		for(col=0;col<4;col++)
		{
			printf("Enter the course code: ");
			scanf("%d",&code);
			if(code == -111)
				break;
			nn = createmat(nn);
			nn->reg = t1->regno;
			nn->cc = code;
			if(t1->right == NULL)
				t1->right = tn = nn;
			else
			{
				tn->right = nn;
				tn = nn;
			}
			m = search(code,t2);

			if(m!=NULL)
			{
				if(m->left == NULL)
					m->left = pn = nn;
				else
				{
					pn = m->left;
					while(pn->left != NULL)
						pn = pn->left;
					pn->left = nn;
					//printf("%d\n",pn->reg);
					//pn = nn;
				}
				//printf("%d\n",nn->reg);
				m->nostud++;
				t1->nocour++;
			}
			else
			{
				printf("The course doesnt exist\n");
				continue;
			}
		}
		t1 = t1->left;
	}
	return t;

}

void stddisp(Table t)
{
	 cour t1;
	 std t2;
	 details p;
	 t1 = t->right;
	 t2 = t->left;
	 char *sub;
	 sub = (char *)malloc(sizeof(char)*20);
	 printf("Displaying the student wise details\n");
	 printf("Name\t\tRegno\t\tCourses\n");
	 printf("==================================================\n");
	 while(t2!=NULL)
	 {
	 	p = t2->right;
	 	printf("%-10s\t%d\t",t2->name,t2->regno);
	 	//printf("The courses taken by the student are: \n");
	 	while(p!=NULL)
	 	{
	 		printf("%d, ",p->cc);
	 		// switch(p->cc)
	 		// {
	 		// 	case 1:
	 		// 		sub = "Maths";
	 		// 		printf("%s, ",sub);
	 		// 		break;
	 		// 	case 2:
	 		// 		sub = "DataStructure";
	 		// 		printf("%s, ",sub);
	 		// 		break;
	 		// 	case 3:
	 		// 		sub = "OOPS";
	 		// 		printf("%s, ",sub);
	 		// 		break;
	 		// 	case 4:
	 		// 		sub = "DSD";
	 		// 		printf("%s, ",sub);
	 		// 		break;
	 		// 	case 5:
	 		// 		sub = "CO";
	 		// 		printf("%s, ",sub);
	 		// 		break;

	 		// }
	 		p = p->right;
	 	}
	 	printf("\n==================================================\n");
	 	printf("\n");
	 	t2 = t2->left;
	 }
}

void courdisp(Table t)
{
	cour t1;
	std t2;
	int count;
	details p;
	char *sub;
	sub = (char *)malloc(sizeof(char)*20);
	t1 = t->right;
	printf("Courses\t\tStudents(Reg no)\n");
	printf("\n=====================================================\n");
	while(t1!=NULL)
	{
		p = t1->left;
		// switch(t1->cc)
	 // 		{
	 // 			case 1:
	 // 				sub = "Maths";
	 // 				printf("%-10s\t",sub);
	 // 				break;
	 // 			case 2:
	 // 				sub = "DataStructure";
	 // 				printf("%-10s\t",sub);
	 // 				break;
	 // 			case 3:
	 // 				sub = "OOPS";
	 // 				printf("%-10s\t",sub);
	 // 				break;
	 // 			case 4:
	 // 				sub = "DSD";
	 // 				printf("%-10s\t",sub);
	 // 				break;
	 // 			case 5:
	 // 				sub = "CO";
	 // 				printf("%-10s\t",sub);
	 // 				break;

	 // 		}
		printf("%d\t",t1->cc);
	 		while(p!=NULL)
	 		{
	 			printf("%d, ",p->reg);
	 			p = p->left;
	 		}
	 		printf("\n=====================================================\n");
	 		printf("\n");
	 		
	 	t1 = t1->right;

	}
}