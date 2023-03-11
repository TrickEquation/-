#include <stdio.h>
#include <stdbool.h>
#include <getch.h>
#include <stdlib.h>

//定义整张游戏地图二维数组
int arr[8][8]={
	{0,0,1,1,1,1,0,0},
	{0,0,1,4,4,1,0,0},
	{0,1,1,0,4,1,1,0},
	{0,1,0,0,3,4,1,0},
	{1,1,0,3,0,0,1,1},
	{1,0,0,1,3,3,0,1},
	{1,0,0,2,0,0,0,1},
	{1,1,1,1,1,1,1,1}
	};
//定义记录人位置变量
int x=6,y=3;
//定义记录步数变量
int cnt=0;

//显示地图
void show(void);
//移动
void up(void);
void down(void);
void left(void);
void right(void);
//判断游戏结束
bool end(void);

int main()
{
	while(1)
	{
		int dir=0;
		//显示地图
		show();
		//移动
		dir=getch();
		switch(dir)
		{
			case 183:up();break;
			case 184:down();break;
			case 186:left();break;
			case 185:right();break;
		}
		//判断游戏结束
		if(end())
		{
			show();
			printf("恭喜通关!\n一共走了%d步\n",cnt);
			return 0;
		}
	}
}

//显示地图
void show(void)
{
	//清屏
	system("clear");
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch(arr[i][j])
			{
				case 0:printf("  ");break;
				case 1:printf("# ");break;
				case 2:printf("@ ");break;
				case 3:printf("$ ");break;
				case 4:printf("o ");break;
				case 6:printf("@ ");break;
				case 7:printf("$ ");break;
			}
		}
		printf("\n");
	}
}
//移动
void up(void)
{
	if(arr[x-1][y]==0||arr[x-1][y]==4)
	{
		arr[x-1][y]+=2;
		arr[x][y]-=2;
		x=x-1;
		cnt++;
	}
	else if(arr[x-1][y]==3||arr[x-1][y]==7)
	{
		if(arr[x-2][y]==0||arr[x-2][y]==4)
		{
			arr[x-2][y]+=3;
			arr[x-1][y]=arr[x-1][y]-1;
			arr[x][y]-=2;
			x=x-1;
			cnt++;
		}
	}
}
void down(void)
{
	if(arr[x+1][y]==0||arr[x+1][y]==4)
	{
		arr[x+1][y]+=2;
		arr[x][y]-=2;
		x=x+1;
		cnt++;
	}
	else if(arr[x+1][y]==3||arr[x+1][y]==7)
	{
		if(arr[x+2][y]==0||arr[x+2][y]==4)
		{
			arr[x+2][y]+=3;
			arr[x+1][y]=arr[x+1][y]-1;
			arr[x][y]-=2;
			x=x+1;
			cnt++;
		}
	}
}
void left(void)
{
	if(arr[x][y-1]==0||arr[x][y-1]==4)
	{
		arr[x][y-1]+=2;
		arr[x][y]-=2;
		y=y-1;
		cnt++;
	}
	else if(arr[x][y-1]==3||arr[x][y-1]==7)
	{
		if(arr[x][y-2]==0||arr[x][y-2]==4)
		{
			arr[x][y-2]+=3;
			arr[x][y-1]=arr[x][y-1]-1;
			arr[x][y]-=2;
			y=y-1;
			cnt++;
		}
	}
}
void right(void)
{
	if(arr[x][y+1]==0||arr[x][y+1]==4)
	{
		arr[x][y+1]+=2;
		arr[x][y]-=2;
		y=y+1;
		cnt++;
	}
	else if(arr[x][y+1]==3||arr[x][y+1]==7)
	{
		if(arr[x][y+2]==0||arr[x][y+2]==4)
		{
			arr[x][y+2]+=3;
			arr[x][y+1]=arr[x][y+1]-1;
			arr[x][y]-=2;
			y=y+1;
			cnt++;
		}
	}
}
//判断游戏结束
bool end(void)
{
	int sum=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(arr[i][j]==7)
			{
				sum++;
			}
		}
	}
	if(sum==4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

