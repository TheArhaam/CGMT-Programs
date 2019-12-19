//LAB EXAM - 04
//POLYGON SCALE AND ROTATE
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

//Variable declaration
int gd=DETECT,gm;
int arr[20][3],res[20][3],s[3][3];
int edges,degree,sx,sy,xp,yp,i,j,k,choice;
float radian;

//Function declaration
void degreetoradian();
void drawpolygon(int [20][3]);
void scalepolygon();
void rotatepolygon();

void main()
{
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"SCALE AND ROTATE A POLYGON\n";

	//Taking input
	cout<<"Enter the number of edges: ";
	cin>>edges;
	for(i=0;i<edges;i++)
	{
		cout<<"Enter coordinate [x y]: ";
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2]=1;
	}

	//MENU
	cout<<"1)Scale\n";
	cout<<"2)Rotate\n";
	cout<<"Enter your choice [1/2]: ";
	cin>>choice;

	switch(choice)
	{
		case 1:	//SCALE
			scalepolygon();
			break;
		case 2:	//ROTATE
			rotatepolygon();
			break;
		default:cout<<"Invalid choice.";
			break;
	}
	getch();
}

//function to scale polygon
void scalepolygon()
{
	cout<<"Enter the scaling factor [sx sy]: ";
	cin>>sx>>sy;
	cleardevice();

	//Scaling Matrix
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				s[i][j]=1;
			}
			else
			{
				s[i][j]=0;
			}
		}
	}
	s[0][0]=sx;
	s[1][1]=sy;

	//Scaling
	for(i=0;i<edges;i++)
	{
		for(j=0;j<3;j++)
		{
			res[i][j]=0;
			for(k=0;k<3;k++)
			{
				res[i][j]=res[i][j]+arr[i][k]*s[k][j];
			}
		}
	}
	setcolor(WHITE);
	drawpolygon(arr);
	setcolor(RED);
	drawpolygon(res);
}

//function to rotate a polygon
void rotatepolygon()
{
	int t,v;
	cout<<"Enter the angle: ";
	cin>>degree;
	cout<<"Enter pivot point [xp yp]: ";
	cin>>xp>>yp;
	cleardevice();
	degreetoradian();
	for(i=0;i<edges;i++)
	{
		t=arr[i][0]-xp;
		v=arr[i][1]-yp;
		res[i][0]=xp+floor(t*cos(radian)-v*sin(radian));
		res[i][1]=yp+floor(v*cos(radian)+t*sin(radian));
	}
	setcolor(WHITE);
	drawpolygon(arr);
	setcolor(RED);
	drawpolygon(res);
}

//function to draw a polygon
void drawpolygon(int arr[20][3])
{
	for(i=0;i<(edges-1);i++)
	{
		line(arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
	}
	line(arr[edges-1][0],arr[edges-1][1],arr[0][0],arr[0][1]);
}

//function to convert degree to radian
void degreetoradian()
{
	radian = (float) degree*3.14/180;
}
