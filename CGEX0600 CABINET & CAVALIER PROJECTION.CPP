//LAB EXAM - 06
//OBLIQUE PROJECTION (Cabinet & Cavalier)
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

void main()
{
	//Variable declarations
	int gd=DETECT,gm;
	int arr[4][8]={1};
	int x1,y1,x2,y2,i,j,k,choice;
	float F;
	double par[4][4],res[4][8]={0},phi;

	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	//COORDINATES FOR CUBE
	//X		//Y		//Z
	//FRONT FACE
	arr[0][0]=100;	arr[1][0]=100;	arr[2][0]=100;
	arr[0][1]=200;	arr[1][1]=100;	arr[2][1]=100;
	arr[0][2]=200;	arr[1][2]=200;	arr[2][2]=100;
	arr[0][3]=100;	arr[1][3]=200;	arr[2][3]=100;

	//BACK FACE
	arr[0][4]=100;	arr[1][4]=100;	arr[2][4]=200;
	arr[0][5]=200;	arr[1][5]=100;	arr[2][5]=200;
	arr[0][6]=200;	arr[1][6]=200;	arr[2][6]=200;
	arr[0][7]=100;	arr[1][7]=200;	arr[2][7]=200;

	cout<<"OBLIQUE PROJECTION\n";
	cout<<"1)Cabinet Projection\n";
	cout<<"2)Cavalier Projection\n";
	cout<<"Enter your choice [1/2]: ";
	cin>>choice;
	switch(choice)
	{
		case 1:	//Cabinet Projection
			phi= (double) (30*0.0175);
			F=0.5;
			break;
		case 2:	//Cavalier Projection
			phi= (double) (45*0.0175);
			F=1;
			break;
		default:cout<<"Invalid choice.";
			exit(0);
			break;
	}

	//Filling par[][]
	par[0][0]=1;	par[0][1]=0;	par[0][2]=F*cos(phi);	par[0][3]=0;
	par[1][0]=0;	par[1][1]=1;	par[1][2]=F*sin(phi);	par[1][3]=0;
	par[2][0]=0;	par[2][1]=0;	par[2][2]=0;		par[2][3]=0;
	par[3][0]=0;	par[3][1]=0;	par[3][2]=0;		par[3][3]=1;

	//Calculating coordinates
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<4;k++)
			{
				res[i][j]=res[i][j]+par[i][k]*arr[k][j];
			}
		}
	}

	//DRAWING FRONT FACE
	setcolor(WHITE);
	for(i=0;i<3;i++)
	{
		x1=res[0][i];	y1=res[1][i];
		x2=res[0][i+1];	y2=res[1][i+1];
		line(x1,y1,x2,y2);
	}
	x1=res[0][3];	y1=res[1][3];
	x2=res[0][0];	y2=res[1][0];
	line(x1,y1,x2,y2);

	//DRAWING BACK FACE
	setcolor(WHITE);
	for(i=4;i<7;i++)
	{
		x1=res[0][i];	y1=res[1][i];
		x2=res[0][i+1];	y2=res[1][i+1];
		line(x1,y1,x2,y2);
	}
	x1=res[0][7];	y1=res[1][7];
	x2=res[0][4];	y2=res[1][4];
	line(x1,y1,x2,y2);

	//CONNECTING THE REMAINING POINTS
	setcolor(WHITE);
	for(i=0;i<4;i++)
	{
		x1=res[0][i];	y1=res[1][i];
		x2=res[0][i+4];	y2=res[1][i+4];
		line(x1,y1,x2,y2);
	}
	getch();
}
