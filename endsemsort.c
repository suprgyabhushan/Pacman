#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
	{
	int size,i,j;
	char **name;int *count;
	size=argc-1;
	count=(int*)malloc(sizeof(int)*size);
	name=(char**)malloc(sizeof(char*)*size);
	for(i=0;i<size;i++)
		name[i]=(char*)malloc(sizeof(char)*120);	
	for(i=0;i<size;i++)
		{		
		strcpy(name[i],argv[i+1]);		
		}
	int min,pos;
	char *temp = (char*)malloc(sizeof(char)*size);
	for(i=1;i<size;i++)
		{	
		for(j=0;j<size-1;j++)
			{
			if(strlen(name[j])>=strlen(name[j+1]))
				{
				strcpy(temp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temp);
				}
			}
		}
	for(i=0;i<size;i++)
		{
		printf("%s ",name[i]);
		}
	printf("\n");
	return 0;
	}	
