#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

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
	int matrix_translate[3][3];
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
	input_matrix[0][0]=x1;
	input_matrix[0][1]=x2;
	input_matrix[0][2]=x3;
	input_matrix[1][0]=y1;
	input_matrix[1][1]=y2;
	input_matrix[1][2]=y3;
	input_matrix[2][0]=h;
	input_matrix[2][1]=h;
	input_matrix[2][2]=h;

	int tx,ty;
	cout<<"Enter the translation factor for x and y:-\n";
	cin>>tx>>ty;
	//clrscr();
	setcolor(YELLOW);
	matrix_translate[0][0]=1;
	matrix_translate[0][1]=0;
	matrix_translate[0][2]=tx;
	matrix_translate[1][0]=0;
	matrix_translate[1][1]=1;
	matrix_translate[1][2]=ty;
	matrix_translate[2][0]=0;
	matrix_translate[2][1]=0;
	matrix_translate[2][2]=1;

	int result[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			result[i][j]=0;
			for(int k=0;k<3;k++)
			{
				result[i][j]+=matrix_translate[i][k]*input_matrix[k][j];
			}
		}
	}
	cout<<"After translation, triangle shown in YELLOW colour\n";
	line(result[0][0],result[1][0],result[0][1],result[1][1]);
	line(result[0][1],result[1][1],result[0][2],result[1][2]);
	line(result[0][0],result[1][0],result[0][2],result[1][2]);

	getch();
	closegraph();
	return 0;
}