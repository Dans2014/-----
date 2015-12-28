#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	//方法声明
	void one(int *a,int l);
	int two(int *a,int l,int *b);
	void three(int *a,int l,int m,int n);
	int i,count,a[60],b[60];
	//初始化数组
	srand((unsigned int)time(NULL));
	for(i=0;i<60;i++)
		*(a+i)=rand();
	printf("原数组为：\n");
	three(a,60,7,8);//调用函数输出原数组
	printf("\n");
	printf("素数数组为：\n");
	count=two(a,60,b);//调用函数求数组中素数
	three(b,count,7,8);//调用函数输出素数数组
	printf("\n");
	printf("变换后的数组为：\n");
	one(a,60);//调用函数对数组排序
	three(a,60,5,12);//调用函数输出变换后数组
}
//方法实现数组排序
void one(int *a,int l)
{
	int i,j,temp;
	//冒泡法
	for(i=0;i<60;i++)
		for(j=i;j<60;j++)
			if(*(a+i)>*(a+j))
			{
				temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;
			}
}
//方法实现找出数组中素数并存入另一个数组
int two(int *a,int l,int *b)
{
	int i,j,count=0;
	for(i=0;i<60;i++)
	{
		for(j=2;j<*(a+i);j++)
		{
			if(*(a+i)%j==0)
				break;
		}
		if(j==*(a+i))
		{
			*(b+count)=*(a+i);
			count++;
		}
	}
	return count;//返回素数个数，即数组b有用长度
}
//方法实现输出数组
void three(int *a,int l,int m,int n)
{
	int i,count=0;
	for(i=0;i<l;i++)
	{
		printf("%*d",n,*(a+i));
		count++;
		if(count%m==0)
			printf("\n");
	}
}