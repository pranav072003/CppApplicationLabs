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

void matrix_mul(int array1[][3],int array2[][3],int array3[][3],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			array3[i][j]=0;
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

void mm(float array1[][3],int array2[][3],float array3[][3],int size)
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

void mul(float array1[][3],float array2[][3],float array3[][3],int size)
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
	int matrix_reflect[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
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

	input_matrix[0][0]=xA;
	input_matrix[0][1]=xB;
	input_matrix[0][2]=xC;
	input_matrix[1][0]=yA;
	input_matrix[1][1]=yB;
	input_matrix[1][2]=yC;
	input_matrix[2][0]=h;
	input_matrix[2][1]=h;
	input_matrix[2][2]=h;

	cout<<"Reflection about X-axis and Y-axis give triangles as shown in Magenta and Yellow colours\n";
	int result[3][3];
	matrix_mul(matrix_reflect,input_matrix,result,3);
	setcolor(MAGENTA);
	line(x+result[0][0],y-result[1][0],x+result[0][1],y-result[1][1]);
	line(x+result[0][1],y-result[1][1],x+result[0][2],y-result[1][2]);
	line(x+result[0][2],y-result[1][2],x+result[0][0],y-result[1][0]);

	matrix_reflect[0][0]=-1;
	matrix_reflect[1][1]=1;
	matrix_mul(matrix_reflect,input_matrix,result,3);
	setcolor(YELLOW);
	line(x+result[0][0],y-result[1][0],x+result[0][1],y-result[1][1]);
	line(x+result[0][1],y-result[1][1],x+result[0][2],y-result[1][2]);
	line(x+result[0][2],y-result[1][2],x+result[0][0],y-result[1][0]);

	int a,b,c,d;
	cout<<"Enter the coordinates of arbitrary axis\n";
	cin>>a>>b>>c>>d;
	float m=(float)(d-b)/(c-a);
	float f=m/sqrt(1+m*m);
	float e=1/sqrt(1+m*m);
	float matrix_rotate[3][3]={{e,f,0.0},{-f,e,0.0},{0.0,0.0,1.0}};     //rotate transform
	int matrix_ref[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
	int mat_translate[3][3]={{1,0,-a},{0,1,-b},{0,0,1}};      //translate transform
	int mat_trans_inv[3][3]={{1,0,a},{0,1,b},{0,0,1}};   //inverse rotate transform
	float mat_rotate_inv[3][3]={{e,-f,0.0},{f,e,0.0},{0.0,0.0,1.0}};     //inverse translate transform

	float inter1[3][3];  //mat_translate with matrix_rotate
	float inter2[3][3];  //inter1 with matrix_ref
	float inter3[3][3];  //inter2 with mat_rotate_inv
	float inter4[3][3];  //inter3 with mat_trans_inv
	float res[3][3];  //calculate final result

	mm(matrix_rotate,mat_translate,inter1,3);
	mat_mul(matrix_ref,inter1,inter2,3);
	mul(mat_rotate_inv,inter2,inter3,3);
	mat_mul(mat_trans_inv,inter3,inter4,3);
	mm(inter4,input_matrix,res,3);

	int t[3][3];

	for(int u=0;u<3;u++)
	{
		for(int v=0;v<3;v++)
		{
			t[u][v]=ROUND(res[u][v]);
		}
	}

	cout<<"After reflection about arbitrary axis, the triangle is shown in red colour\n";
	setcolor(RED);
	line(x+t[0][0],y-t[1][0],x+t[0][1],y-t[1][1]);
	line(x+t[0][1],y-t[1][1],x+t[0][2],y-t[1][2]);
	line(x+t[0][2],y-t[1][2],x+t[0][0],y-t[1][0]);

	getch();
	closegraph();
	return 0;
}