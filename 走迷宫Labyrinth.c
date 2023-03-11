#include <stdio.h>
#include <getch.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//定义地图二位数组
char arr[10][10]={
{'#','#','#','#','#','#','#','#','#','#'},
{'#','@',' ','#','#','#','#','#','#','#'},
{'#','#',' ','#','#','#','#','#','#','#'},
{'#','#',' ','#','#',' ',' ','#','#','#'},
{'#',' ',' ',' ',' ',' ','#','#','#','#'},
{'#',' ','#','#',' ','#','#','#','#','#'},
{'#',' ','#','#',' ',' ',' ','#','#','#'},
{'#',' ',' ','#',' ','#',' ',' ',' ','#'},
{'#','#','#','#','#','#','#','#',' ',' '},
{'#','#','#','#','#','#','#','#','#',' '}
};
//定义记录角色位置变量
int x = 1,y = 1;
//显示
void show(void);
//移动
void up(void);
void down(void);
void left(void);
void right(void);
//结束判断
bool end(void);

//主函数
int main()
{
	int dir=0,count,t;
		count=time(NULL);
	while(1)
	{	
		//显示地图
		show();
		//获取方向键
		dir = getch();
		switch(dir)
		{
			//up
			case 183:up();break;
			//down
			case 184:down();break;
			//left
			case 186:left();break;
			//right
			case 185:right();break;
		}
		//判断是否到达终点
		if(end())
		{
			t=time(NULL);
			show();
			printf("共计时长：%d s\n",t-count);
			break;
		}
	}
}

//显示
void show(void)
{
	//清屏
	system("clear");
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

//移动
//上
void up(void)
{
	if(x-1>=0 && arr[x-1][y]==' ')
	{
		arr[x][y]=' ';
		arr[x-1][y]='@';
		x=x-1;
	}
}
//下
void down(void)
{
	if(x+1<10 && arr[x+1][y]==' ')
	{
		arr[x][y]=' ';
		arr[x+1][y]='@';
		x=x+1;
	}
}
//左
void left(void)
{
	if(y-1>=0 && arr[x][y-1]==' ')
	{
		arr[x][y]=' ';
		arr[x][y-1]='@';
		y=y-1;
	}
}
//右
void right(void)
{
	if(y+1<10 && arr[x][y+1]==' ')
	{
		arr[x][y]=' ';
		arr[x][y+1]='@';
		y=y+1;
	}
}
//结束判断
bool end(void)
{
	if(x==9 && y==9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
