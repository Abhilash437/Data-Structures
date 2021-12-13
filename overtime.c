#include<stdio.h>
#include<stdlib.h>
typedef struct time{
	int hr;
	int min;
	int sec;
}Time;

int main()
{
	Time *t,*q;
	int ch;
	t = (Time *)malloc(sizeof(Time));
	q = (Time *)malloc(sizeof(Time));
	printf("Enter the time\n");
		scanf("%d%d%d",&t->hr,&t->min,&t->sec);
	

		while(1)
		{
			printf("1.Update\n");
			printf("2.Add\n");
				scanf("%d",&ch);
			if(ch==1)
			{

				t->sec++;
				if(t->sec==60)
				{
					t->sec=0;
					t->min++;
					if(t->min==60)
					{
						t->min=0;
						t->hr++;
						if(t->hr==24)
							t->hr = t->hr%24;
					}
				}

				printf("%d::%d::%d\n",t->hr,t->min,t->sec);
			}
			else if(ch==2)
			{
				printf("Enter the time\n");
				scanf("%d%d%d",&t->hr,&t->min,&t->sec);

				printf("Enter the time\n");
				scanf("%d%d%d",&q->hr,&q->min,&q->sec);

				t->hr = t->hr+q->hr;
				t->min = t->min + q->min;
				t->sec = t->sec+q->sec;

				if(t->sec>60)
				{
					t->sec = t->sec%60;
					t->min++;
				}
				if(t->min>60)
				{
					t->min = t->min%60;
					t->hr++;
				}
				if(t->hr>24)
				{
					t->hr = t->hr%24;
				}

				printf("%d::%d::%d\n",t->hr,t->min,t->sec);
			}
			else
				exit(1);
		}

}