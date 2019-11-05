//LAB EXAM - 07
//3D Rotation
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

void main()
{
	//Variable declaration
	int gd=DETECT,gm;
	int x1,y1,x2,y2,i,j,k,choice;
	int arr[4][8]={1};
	double par[4][4]={0},r[4][4]={0},p[4][8]={0},res[4][8]={0},phi;
	float F;

	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	//CUBE COORDINATES
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

	phi= (double) (30*0.0175); //Cabinet
	F=0.5;

	//MENU
	cout<<"3D ROTATION\n";
	cout<<"1)X-axis rotation\n";
	cout<<"2)Y-axis rotation\n";
	cout<<"3)Z-axis rotation\n";
	cout<<"Enter your choice [1/2/3]: ";
	cin>>choice;
	switch(choice)
	{
		case 1:	//X-axis rotation
/*X*/	r[0][0]=1; r[0][1]=0;		r[0][2]=0;		r[0][3]=0;
/*Y*/	r[1][0]=0; r[1][1]=cos(phi);	r[1][2]=(-1)*sin(phi);	r[1][3]=0;
/*Z*/	r[2][0]=0; r[2][1]=sin(phi);	r[2][2]=cos(phi);	r[2][3]=0;
	r[3][0]=0; r[3][1]=0;		r[3][2]=0;		r[3][3]=1;
			break;

		case 2:	//Y-axis rotation
/*X*/	r[0][0]=cos(phi);	r[0][1]=0; r[0][2]=sin(phi);	r[0][3]=0;
/*Y*/	r[1][0]=0; 		r[1][1]=1; r[1][2]=0;		r[1][3]=0;
/*Z*/	r[2][0]=(-1)*sin(phi);	r[2][1]=0; r[2][2]=cos(phi);	r[2][3]=0;
	r[3][0]=0;		r[3][1]=0; r[3][2]=0;		r[3][3]=1;
			break;

		case 3:	//Z-axis rotation
/*X*/	r[0][0]=cos(phi); r[0][1]=(-1)*sin(phi); r[0][2]=0; r[0][3]=0;
/*Y*/	r[1][0]=sin(phi); r[1][1]=cos(phi); 	 r[1][2]=0; r[1][3]=0;
/*Z*/	r[2][0]=0;	  r[2][1]=0; 		 r[2][2]=1; r[2][3]=0;
	r[3][0]=0;	  r[3][1]=0; 		 r[3][2]=0; r[3][3]=1;
			break;

		default:cout<<"Invalid input.";
			getch();
			exit(0);
			break;
	}

	//FILLING par[][]
	par[0][0]=1;	par[0][1]=0;	par[0][2]=F*cos(phi);	par[0][3]=0;
	par[1][0]=0;	par[1][1]=1;	par[1][2]=F*sin(phi);	par[1][3]=0;
	par[2][0]=0;	par[2][1]=0;	par[2][2]=0;		par[2][3]=0;
	par[2][0]=0;	par[3][1]=0;	par[3][2]=0;		par[3][3]=1;

	//Cabinet Projection
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<4;k++)
			{
				p[i][j]=p[i][j]+par[i][k]*arr[k][j];
			}
		}
	}

	//ROTATION
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<4;k++)
			{
				res[i][j]=res[i][j]+r[i][k]*p[k][j];
			}
		}
	}

	//DRAWING THE CUBE
	//FRONT FACE
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
	//BACK FACE
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
	//Connecting the remaining points
	setcolor(YELLOW);
	for(i=0;i<4;i++)
	{
		x1=res[0][i];	y1=res[1][i];
		x2=res[0][i+4];	y2=res[1][i+4];
		line(x1,y1,x2,y2);
	}

	getch();
}