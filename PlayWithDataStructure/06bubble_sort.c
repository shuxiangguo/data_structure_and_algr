#define MAXSIZE 10  //用于要排序数组个数最大值
typedef struct 
{
	int r[MAXSIZE+1]; //用于存储要排序的数组，r[0]用作哨兵或临时变量
	int length; //用于记录顺序表长度
} Sqlist;


void swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}


//最简单的冒泡排序
//
//每个关键字和它后面的每一个关键字比较，如果大则交换
void BubbleSort0(Sqlist *L)
{
	int i,j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i+1; j <= L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L,i,j);
			}
		}
	}
}


//改进后的冒泡排序
//
//每次循环从最后一个开始，依次向第一递进，如果后面比前一个大，则交换
void BubbleSort(Sqlist *L)
{
	int i,j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length-1, j >= i; j--)
		{
			if (L->r[j+1] < L->r[j])
			{
				swap(L, j, j+1);
			}
		}
	}
}

//优化冒泡排序
//增加一个是否交换的标记

void BubbleSort2(Sqlist *L)
{

	int i,j;
	int flag = 1;
	for (i = 1; i < L->length && flag; i++)
	{
		flag = 0;
		for (j = l->length-1; j >= i; j--)
		{
			if (L->r[j] > L->r[j+1])
			{
				swap(L, j, j+1);
				flag = 1;
			}
		}
	}
}


时间复杂度分析：
最好的情况，即已排好序，比较n-1次，没有数据交换
最差的额情况，即逆序，比较1+2+3+...+n-1 = n(n-1)/2，时间复杂度为O(n^2)