#include<stdio.h>
#include<stdlib.h>
void print(int i,int j)
{	
	static int r=0;
	static int c=0;
	float x;
	if(r==i)
		return;
	if(c==j)
	{
		printf("\n");
		c=0;
		r++;
		return print(i,j);
	}
	x=atof(argv[3+r+c]);
	printf("%f ",x);
	c++;
	return print(i,j);
}

int main(int argc,char *argv[])
{
	float i,j;
	i=atof(argv[1]);
	j=atof(argv[2]);
	print(i,j);
}
