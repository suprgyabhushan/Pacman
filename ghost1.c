#include<stdio.h>
#include<stdlib.h>
void searchPosition(char ** arr,int row,int col,int  * i,int * j)
{
	int k,l;
	for(k=0;k<row;k++)
	{
		for(l=0;l<col;l++)
		{
			if(arr[k][l]=='G')
			{
				*i=k;
				*j=l;
				return;
			}
		}
	}	
}
int rowCount(char * FileName)
{
	int row=0;	
	char ch;
	FILE * input=fopen(FileName,"r");
	ch=fgetc(input);
	while(ch!=EOF)
	{
		ch=fgetc(input);
		if(ch==10)
			row++;

	}
	fclose(input);
	return row;
}
int colCount(char *file)
{
	FILE *data=fopen(file,"r");
        int x=getc(data),col=0;
	while(x!='\n')
	{
        	x=getc(data);		
		col=col+1;	
        }
	return col;
	fclose(data);
}
int newSpeed(char m)
{
	if(m=='B')
		return 0;
	else if(m=='M')
		return 1;
	else if(m=='O')
		return 2;
	else if(m=='A')
		return 3;
	else 
		return 4;
}
void moveLeft(int *i,int *j,int row,int col)
{
	if(*j-2<0)
		*j=0;
	else
		*j=*j-2;
}
void moveRight(int *i,int *j,int row,int col)
{
	if(*j+2>=col)
		*j=col-1;
	else
		*j=*j+2;
}
void moveUp(int *i,int *j,int row,int col)
{
	if(*i-2<0)
		*i=0;
	else
		*i=*i-2;
}
void moveDown(int *i,int *j,int row,int col)
{
	if(*i+1>=row)
		*i=row-1;
	else
		*i=*i+1;
}
int nextMove(char ** arr,int row,int col,char * dir)
{
	int y,speed;
	int i=0,j=0;
	searchPosition(arr,row,col,&i,&j);
	arr[i][j]='-';
	if(strcmp(dir,"right")==0)
	{
		if(j+2>=col)
			j=col-1;
		else
			j=j+2;
		speed =newSpeed(arr[i][j]);
		while(speed!=4)
		{
			arr[i][j]='-';
			if(speed==0)
				moveLeft(&i,&j,row,col);
			else if(speed==1)
				moveRight(&i,&j,row,col);
			else if(speed==2)
				moveUp(&i,&j,row,col);
			else if(speed==3)
				moveDown(&i,&j,row,col);
			speed=newSpeed(arr[i][j]);
		}		
		arr[i][j]='G';
		return speed;
	}
	else if(strcmp(dir,"left")==0)
        {
                y=-2;
		if(j+y<0)
			j=0;
		else
			j=j+y;
		speed =newSpeed(arr[i][j]);
		while(speed!=4)
		{
			arr[i][j]='-';
			if(speed==0)
				moveLeft(&i,&j,row,col);
			else if(speed==1)
				moveRight(&i,&j,row,col);
			else if(speed==2)
				moveUp(&i,&j,row,col);
			else if(speed==3)
				moveDown(&i,&j,row,col);
			arr[i][j]='-';
			speed=newSpeed(arr[i][j]);
		}		
		arr[i][j]='G';
		return speed;
        }
	else if(strcmp(dir,"up")==0)
        {
                y=-1;
		if(i+y<0)
			i=0;
		else
			i=i+y;
		speed =newSpeed(arr[i][j]);
		while(speed!=4)
		{
			arr[i][j]='-';
			if(speed==0)
				moveLeft(&i,&j,row,col);
			else if(speed==1)
				moveRight(&i,&j,row,col);
			else if(speed==2)
				moveUp(&i,&j,row,col);
			else if(speed==3)
				moveDown(&i,&j,row,col);

			arr[i][j]='-';
			speed=newSpeed(arr[i][j]);
		}		
		arr[i][j]='G';
		return speed;
        }
	else
	{
		if(i+1>=row)
			i=row-1;
		else
			i=i+1;
		speed =newSpeed(arr[i][j]);
		while(speed!=4)
		{
			arr[i][j]='-';
			if(speed==0)
				moveLeft(&i,&j,row,col);
			else if(speed==1)
				moveRight(&i,&j,row,col);
			else if(speed==2)
				moveUp(&i,&j,row,col);
			else if(speed==3)
				moveDown(&i,&j,row,col);

			arr[i][j]='-';
			speed=newSpeed(arr[i][j]);
		}		
		arr[i][j]='G';
		return speed;
	}
}
void printVal(char ** mat,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%c ",mat[i][j]);
		printf("\n");
	}
}
void scanVal(char *fileName,char **mat,int row,int col)
{
	FILE * input=fopen(fileName,"r");
	char c;
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			mat[i][j]=fgetc(input);	
		c=fgetc(input);
	}
	fclose(input);
}
char ** init(int row,int col)
{	
	char ** mat;
	int i;
	mat=(char**)malloc(sizeof(char*)*row);
	for(i=0;i<row;i++)
		mat[i]=(char*)malloc(sizeof(char)*col);
	return mat;
}
int main(int argc,char * argv[])
{
	int row=rowCount(argv[1]);
	int col=colCount(argv[1]);
	printf("%d %d\n",row,col);
	int speed;
	FILE * action=fopen(argv[2],"r");
	char * dir=(char*)malloc(sizeof(char)*100);
	char ** arr;
	arr=init(row,col);
	scanVal(argv[1],arr,row,col);
	while(!(feof(action)))
	{
		fscanf(action,"%s",dir);
		if(feof(action)) break;
		speed=nextMove(arr,row,col,dir);
	}
	printVal(arr,row,col);
	return 1;
}
