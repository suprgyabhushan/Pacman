#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(int argc, char *argv[])
	{
	int size,i,no1,no2;
	size=argc-2;
	char **fname=(char**)malloc(sizeof(char*)*size);
	for(i=0;i<size;i++)
		fname[i]=(char*)malloc(sizeof(char)*10);
	int *count=(int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++)
		{
		strcpy(fname[i],argv[i+2]);
		printf("%s\n",fname[i]);
		}
	char firstline[100];
	FILE *in=fopen(argv[1],"r");
	fgets(firstline,100,in);
	FILE *ret;
	while(*firstline != '%')
		{
			for(i=0;i<size;i++)
				{
				ret=fopen(fname[i],"a+w");
				fprintf(ret,"%s",firstline);
				//fgets(firstline,100,in);
				fclose(ret);
				}
			
			fgets(firstline,100,in);
		}  
	for(i=0;i<size;i++)
		{
		ret=fopen(fname[i],"a+w");
		fprintf(ret,"%s",firstline);
		fclose(ret);
		}
	FILE *in1;
	while(!feof(in))
		{
		fscanf(in,"%d %d\n",&no1,&no2);
		//printf("%d %d\n",no1,no2);
		in1=fopen(fname[no1-1],"a+w");
		count[no1-1]++;
		printf("%d ",count[no1-1]);
		fprintf(in1,"%d",no2);
		fprintf(in1,"\n");
		fclose(in1);		
		}
	
	fclose(in);
	/*char b[100];
	for(i=0;i<size;i++)
		{
		in1=fopen(fname[i],"w");
		fscanf(in1,"%s",b);
			
		while(strcmp(b,"samples:")!=0)
			{
			fscanf(in1,"%s",b);
			}
		fprintf(in1,"%d",count[i]);
		fclose(in1);
		}*/

	return 0;
	}
