#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	FILE ** files=(FILE**)malloc(sizeof(FILE*)*(argc-2));
	int * count=(int*)malloc(sizeof(int*)*(argc-2));
	FILE  * input=fopen(argv[1],"r");
	int i=0;
	for(i=0;i<argc-2;i++)
		files[i]=fopen(argv[i+2],"w");
	char * check=(char*)malloc(sizeof(char)*100);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	int row=atoi(check);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	fscanf(input,"%s",check);
	int ** arr=(int**)malloc(sizeof(int*)*row);
	for(i=0;i<row;i++)
		arr[i]=(int*)malloc(sizeof(int)*2);
	int t=0;
	while(t<row)
	{
		fscanf(input,"%d",&arr[t][0]);
		fscanf(input,"%d",&arr[t][1]);
		count[arr[t][0]-1]++;
		t++;
	}
	fclose(input);
	input=fopen(argv[1],"r");
	fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
		fprintf(files[i],"%s\n",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%s",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%s\n",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%s",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%d\n",count[i]);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%s",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
                fprintf(files[i],"%s\n",check);
        fscanf(input,"%s",check);
	for(i=0;i<argc-2;i++)
               	fprintf(files[i],"%s\n",check);
	for(t=0;t<row;t++)
		fprintf(files[arr[t][0]-1],"%d\n",arr[t][1]);
	for(i=0;i<argc-2;i++)
		fclose(files[i]);
	fclose(input);	
}

