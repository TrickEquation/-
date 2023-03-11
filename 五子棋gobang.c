#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getch.h>
//定义棋盘
char arr[15][15];
//定义角色变量
char num='@';
//定义落子位置
int x=0,y=0;
int flag=-1; //换人下棋标志位
//显示棋盘
void show(void);
//是否成功落子
bool is_down(void);
//是否五子连珠
bool is_end(void);
//横向连珠
bool x_row(void);
//纵向连珠
bool y_row(void);
//左斜连珠
bool l_xy(void);
//右斜连珠
bool r_xy(void);

int main()
{
	//初始化棋盘
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			arr[i][j]='*';
		}
	}
	//显示棋盘
	show();
	//下棋循环
	while(1)
	{
		//开始下棋
		printf("\33[%d;%dH",x+1,(y+1)*2);
		switch(getch())
		{
			case 183:x>0 && x--;break;
			case 184:x<14 && x++;break;
			case 186:y>0 && y--;break;
			case 185:y<14 && y++;break;
			case 10:
					printf("%c",num);
					arr[x][y]=num;
		//五子连珠
		if(is_end())
		{
		//	show();
		printf("\33[16;0H");
			printf("恭喜%c获胜!\n",num);
			return 0;
		}
		flag=-flag;
		//换人下棋
		if(flag>0)
		{
			num='$';
		}
		else
		{
			num='@';
		}
		}
	}
}

//显示棋盘
void show(void)
{
	system("clear");
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			printf(" %c",arr[i][j]);
		}
		printf("\n");
	}
}
	
//是否成功落子
bool is_down(void)
{
	if(x<0||x>=15||y<0||y>=15)
	{
		return false;
	}
	if(arr[x][y]!='*')
	{
		return false;
	}
	return true;
}
bool is_end(void)
{	
	if(x_row()||y_row()||l_xy()||r_xy())
	{
		return true;
	}
	else
	{
		return false;
	}

}
//横向连珠
bool x_row(void)
{
	int sum=0;
	for(int i=0;i<15;i++)
	{
		if(arr[x][i]==num)
		{
			sum++;
			if(sum==5)
			{
				return true;
			}
		}
		else
		{
			sum=0;
		}
	}
	return false;
}
//纵向连珠
bool y_row(void)
{
	int sum=0;
	for(int i=0;i<15;i++)
	{
		if(arr[i][y]==num)
		{
			sum++;
			if(sum==5)
			{
				return true;
			}
		}
		else
		{
			sum=0;
		}
	}
	return false;
}
//左斜连珠
bool l_xy(void)
{
	int sum=0;
	int x_i=x>y?x-y:0;
	int y_i=x<y?y-x:0;
	for(int i=x_i,j=y_i;i<15&&j<15;)
	{
		if(arr[i][j]==num)
		{
			sum++;
			if(sum==5)
			{
				return true;
			}
		}
		else
		{
			sum=0;
		}
		i++;
		j++;
	}
	return false;

}
//右斜连珠
bool r_xy(void)
{
	int sum=0;
	int x_i=14-x>=y?x+y:14;
	int y_i=14-x<=y?y-14+x:0;
	for(int i=x_i,j=y_i;i<15&&j<15;)
	{
		if(arr[i][j]==num)
		{
			sum++;
			if(sum==5)
			{
				return true;
			}
		}
		else
		{
			sum=0;
		}
		i--;j++;
	}
	return false;
}
