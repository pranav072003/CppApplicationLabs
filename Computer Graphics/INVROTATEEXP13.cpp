#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int ROUND(float num)
{
	if(num<=0)
	{
		return (int)(num-0.5);
	}
	else
	{
		return (int)(num+0.5);
	}
}

void matrix_mul(float array1[][3],int array2[][3],float array3[][3],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			array3[i][j]=0.0;
			for(int k=0;k<size;k++)
			{
				array3[i][j]+=array1[i][k]*array2[k][j];
			}
		}
	}
}

void mat_mul(float array1[][3],float array2[][3],float array3[][3],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			array3[i][j]=0.0;
			for(int k=0;k<size;k++)
			{
				array3[i][j]+=array1[i][k]*array2[k][j];
			}
		}
	}
}

int main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	int xA,xB,xC,yA,yB,yC;
	cout<<"Enter the coordinate values:-\n";
	cin>>xA>>yA>>xB>>yB>>xC>>yC;
	int h=1;
	float matrix_translate[3][3];
	int input_matrix[3][3];
	int x1=x+xA;
	int x2=x+xB;
	int x3=x+xC;
	int y1=y-yA;
	int y2=y-yB;
	int y3=y-yC;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	int j;
	input_matrix[0][0]=xA;
	input_matrix[0][1]=xB;
	input_matrix[0][2]=xC;
	input_matrix[1][0]=yA;
	input_matrix[1][1]=yB;
	input_matrix[1][2]=yC;
	input_matrix[2][0]=h;
	input_matrix[2][1]=h;
	input_matrix[2][2]=h;

	int THETA;
	cout<<"Enter the rotation angle(counterclockwise) for x and y:-\n";
	cin>>THETA;
	//clrscr();
	float s=(float)sin((double)THETA);
	float c=(float)cos((double)THETA);
	setcolor(YELLOW);
	matrix_translate[0][0]=c;
	matrix_translate[0][1]=-s;
	matrix_translate[0][2]=0.0;
	matrix_translate[1][0]=s;
	matrix_translate[1][1]=c;
	matrix_translate[1][2]=0.0;
	matrix_translate[2][0]=0.0;
	matrix_translate[2][1]=0.0;
	matrix_translate[2][2]=1.0;

	float result[3][3];

	matrix_mul(matrix_translate,input_matrix,result,3);
	cout<<"After rotation about origin, triangle shown in YELLOW colour\n";
	int r[3][3];
	for(int p=0;p<3;p++)
	{
		for(int q=0;q<3;q++)
			r[p][q]=ROUND(result[p][q]);
	}
	line(x+r[0][0],y-r[1][0],x+r[0][1],y-r[1][1]);
	line(x+r[0][1],y-r[1][1],x+r[0][2],y-r[1][2]);
	line(x+r[0][0],y-r[1][0],x+r[0][2],y-r[1][2]);

	float mat_inv_rotate[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat_inv_rotate[i][j]=matrix_translate[i][j];
		}
	}
	mat_inv_rotate[0][1]=s;
	mat_inv_rotate[1][0]=-s;
	float res[3][3];
	mat_mul(mat_inv_rotate,result,res,3);
	setcolor(GREEN);
	cout<<"Triangle after inverse rotation shown in Green colour\n";
	int yu[3][3];
	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++)
		{
			yu[a][b]=ROUND(res[a][b]);
		}
	}
	line(x+yu[0][0],y-yu[1][0],x+yu[0][1],y-yu[1][1]);
	line(x+yu[0][1],y-yu[1][1],x+yu[0][2],y-yu[1][2]);
	line(x+yu[0][0],y-yu[1][0],x+yu[0][2],y-yu[1][2]);

	getch();
	closegraph();
	return 0;
}