#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	//��������
	void one(int *a,int l);
	int two(int *a,int l,int *b);
	void three(int *a,int l,int m,int n);
	int i,count,a[60],b[60];
	//��ʼ������
	srand((unsigned int)time(NULL));
	for(i=0;i<60;i++)
		*(a+i)=rand();
	printf("ԭ����Ϊ��\n");
	three(a,60,7,8);//���ú������ԭ����
	printf("\n");
	printf("��������Ϊ��\n");
	count=two(a,60,b);//���ú���������������
	three(b,count,7,8);//���ú��������������
	printf("\n");
	printf("�任�������Ϊ��\n");
	one(a,60);//���ú�������������
	three(a,60,5,12);//���ú�������任������
}
//����ʵ����������
void one(int *a,int l)
{
	int i,j,temp;
	//ð�ݷ�
	for(i=0;i<60;i++)
		for(j=i;j<60;j++)
			if(*(a+i)>*(a+j))
			{
				temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;
			}
}
//����ʵ���ҳ�������������������һ������
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
	return count;//��������������������b���ó���
}
//����ʵ���������
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