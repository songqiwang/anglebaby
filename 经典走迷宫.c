#include <stdio.h>
void go(int (*p)[10] ,int i,int x,int y,int q,int *e,int (*P)[10],int *b);
int load[1000]={0};//在全局变量中定义路径数组与步法映射数组
int M[10][10]={0};
   //寻找路径函数(*p)[]   x,y分别表示路径坐标 load[] ：是把路径坐标输入在数组中。q来记录步数。e是t的指针变量,P用来映射的指针变量，b用来代替第几步的指针变量
int main()
{
	int maze[10][10] =    //定义迷宫数组,u,h分别打印示例中用于循环的行列变量,t用来表示第几条路，v来表示每一步
	{
	{2,3,2,2,2,2,2,2,2,2},
	{2,0,0,2,0,0,0,0,0,2},
	{2,2,0,2,0,2,2,2,0,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,0,2,2,0,2,0,2,0,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,2,0,2,0,0,2,0,0,2},
	{2,0,0,0,0,0,2,0,2,2},
	{2,0,2,0,2,0,2,0,0,2},
	{2,2,2,2,2,2,2,2,4,2}
	},u,h,g=0,t=1,v=1;
	char f;//f用来跳过示例输出路径的媒介
	load[0]=1;load[1]=1;
	printf("Now convert the digital maze into a labyrinth of the wall:\n");//为了好看，把数字迷宫改为墙体迷宫,2代表墙，0代表空白可以走
	printf("The corresponging coordinates are (x,y):(row,col)\n\n\n");//x代表数组的行，从0行开始，col代表列。
	printf("xy0 1 2 3 4 5 6 7 8 9\n");
	for(u=0;u<=9;u++)
    {
        printf("%d",g);
        for(h=0;h<=9;h++)
        {
            if(maze[u][h]==2) printf("■");
            else if(maze[u][h]==0) printf("  ");
            else if(maze[u][h]==3) printf("▼");
			else printf("  ");
        }
        printf("\n");
        g++;
    }
    printf("\nPlease input ENTER to continue :");
    scanf("%c",&f);
	printf("\n\n\n\n");

	go(&maze[1],1,1,1,2,&t,&M[1],&v);
   
	return 0;
}

void go(int (*p)[10],int i,int x,int y, int q,int *e,int (*P)[10],int *b)
{
	    int (*array)[10],m,n,(*A)[10];  //函数内部控制循环变量,m控制打印图形的列，n控制路径数组的下标
	    (*p)[i]=6;
		(*P)[i]=(*b)++;

		//用6记录走过路程的标识

		if((*p)[i-1] == 0) {y=y-1;load[q]=x;load[q+1]=y;go(p,i-1,x,y,q+2,e,P,b);}//左

        if((*p)[i+1] == 0) {y=y+1;load[q]=x;load[q+1]=y;go(p,i+1,x,y,q+2,e,P,b);}//右

		if((*(p+1))[i] == 0) {x=x+1;load[q]=x;load[q+1]=y;go(p+1,i,x,y,q+2,e,P+1,b);}//下

		if((*(p-1))[i] == 0) {x=x-1;load[q]=x;load[q+1]=y;go(p-1,i,x,y,q+2,e,P-1,b);}//上





		if((*(p+1))[i]==4)//打印走过的路劲并判断是否走入死胡同或者其他已经结束
		{
            (*(P+1))[i]=(*b);
			array=p-8;A=P-8;
		
           
			printf("The %d way is :\n",*e);
			for(;array<=p+1;array++)
			{
				for(m=0;m<=9;m++)
				{
				  if  ((*array)[m] == 3) printf("▼");
				  else if ((*array)[m] == 2||(*array)[m]  == 0)  printf("%d ",(*array)[m] );
                  else printf("■");
				}
				printf("\n");
			}
			printf("\n");
			printf("Change the digital maze to wall maze : \n\n");
			array=p-8;
            (*(p+1))[i]=6;

			for(;array<=p+1;array++)//打印墙体式迷宫，并显示第几步
			{
				for(m=0;m<=9;m++)
				{
					if ((*array)[m] == 2)   printf("■");

					else  if ((*array)[m]  == 0)  printf("  ");

					else  if ((*array)[m]  == 3)  printf("▼");
					else  printf("%2d",(*A)[m]) ;
				}
			    A++;
				printf("\n");
			}

            (*(p+1))[i]=4;
	

			printf("The path coordinates are :\n");
            printf("(0,1)->");
			for(n=0;load[n]!=0&&load[n+1]!=0;n=n+2)//打印路径坐标
			{
			   printf("(%d,%d)->",load[n],load[n+1]);
			   if(n%20==0&&n!=0) printf("\n");
			}

			printf("(9,8)");
            printf("\n\n");
			(*e)++;
		}
		(*p)[i]=0;//返回
		load[q]=0;
		load[q+1]=0;
		--(*b);
}
