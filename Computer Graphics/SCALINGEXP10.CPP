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

void mat_mul(int array1[][3],float array2[][3],float array3[][3],int size)
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

	float sx,sy;
	cout<<"Enter the scale factor for x and y:-\n";
	cin>>sx>>sy;
	//clrscr();
	setcolor(YELLOW);
	matrix_translate[0][0]=sx;
	matrix_translate[0][1]=0.0;
	matrix_translate[0][2]=0.0;
	matrix_translate[1][0]=0.0;
	matrix_translate[1][1]=sy;
	matrix_translate[1][2]=0.0;
	matrix_translate[2][0]=0.0;
	matrix_translate[2][1]=0.0;
	matrix_translate[2][2]=1.0;

	float result[3][3];
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			result[i][j]=0.0;
			for(int k=0;k<3;k++)
			{
				result[i][j]+=matrix_translate[i][k]*input_matrix[k][j];
			}
		}
	}*/
	matrix_mul(matrix_translate,input_matrix,result,3);
	cout<<"After scaling about origin, triangle shown in YELLOW colour\n";
	int r[3][3];
	for(int p=0;p<3;p++)
	{
		for(int q=0;q<3;q++)
			r[p][q]=ROUND(result[p][q]);
	}
	line(x+r[0][0],y-r[1][0],x+r[0][1],y-r[1][1]);
	line(x+r[0][1],y-r[1][1],x+r[0][2],y-r[1][2]);
	line(x+r[0][0],y-r[1][0],x+r[0][2],y-r[1][2]);

	//rotation about point (xA,yA)
	int a,b;
	cout<<"Enter the coordinates about which to scale:-\n";
	cin>>a>>b;
	int mat_trans[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	int mat_trans_inv[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	float inter1[3][3];   //mat_trans with matrix_translate
	float inter2[3][3];   //mat_trans_inv with inter1
	float res[3][3];
	mat_trans[0][2]=-a;
	mat_trans[1][2]=-b;
	mat_trans_inv[0][2]=a;
	mat_trans_inv[1][2]=b;
	setcolor(MAGENTA);
	cout<<"After scaling about fixed point, triangle shown in magenta colour\n";
	matrix_mul(matrix_translate,mat_trans,inter1,3);
	mat_mul(mat_trans_inv,inter1,inter2,3);
	matrix_mul(inter2,input_matrix,res,3);
	int pt[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			pt[i][j]=ROUND(res[i][j]);
	}
	line(x+pt[0][0],y-pt[1][0],x+pt[0][1],y-pt[1][1]);
	line(x+pt[0][1],y-pt[1][1],x+pt[0][2],y-pt[1][2]);
	line(x+pt[0][2],y-pt[1][2],x+pt[0][0],y-pt[1][0]);

	getch();
	closegraph();
	return 0;
}