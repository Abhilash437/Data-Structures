#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void deletechar(char *,char );
int main()
{
	char name[20],ch;

		printf("Enter the string\n");
			scanf("%s",name);
			fflush(stdin);
		printf("Enter the character\n");
			scanf("%c",&ch);

		deletechar(name,ch);

		printf("displaying the updated string %s\n",name);
}

void deletechar(char *ps,char c)
{
	int len=0;
	int i,j;
	char *temp=ps;
	while(*(temp) != '\0')
	{
		len++;
		temp++;
	}
	//len = strlen(ps);
	for(i=0;i<len;i++)
	{
		if(*(ps+i) == c)
		{
			for(j=i;j<len;j++)
				*(ps+j) = *(ps+j+1);
			len--;
			i--;
		}

	}
	

}