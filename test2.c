#include<stdio.h>
#include<stdlib.h>
void max(float **arr,int r,int c)
{	
	int maximum=0;
	static int i=0;
	static int j=0;
	f(i==r)
		return;
	else if(j==c)
	{
		printf("\n");
		j=0;
		i++;
		return print(arr,r,c);
	}
	
	printf("%f ",arr[i][j]);
	j++;
	return print(arr,r,c);
}

int main(int argc,char *argv[])
{
	int i,j;
	float **arr;
	i=atoi(argv[1]);
	j=atoi(argv[2]);
	arr=(float **)malloc(8*i);
	int z;
	void mal()
	{
		static int z=0;
		if(z==i)
			return;
		arr[z]=(float *)malloc(4*j);
		z++;
		return mal();
	}
		
	void store()
	{
		static int k=0;
		static int l=0;
		static int c=3;

		if(k==i)
			return;
		else if(l==j)
		{
			l=0;
			k++;
			return store();
		}
		arr[k][l]=atof(argv[c]);
		l++;
		c++;
		return store();
	}
	mal();
	store();
	print(arr,i,j);
}
