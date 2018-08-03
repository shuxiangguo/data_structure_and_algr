/*
直接插入算法:
	将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表
 */



void InsertSort(Sqlist *L)
{
	int i, j;
	for (i = 2; i < L->length; i++)
	{
		if (L->r[i] < L->r[i-1])
		{
			L->r[0] = L->r[i];//设置哨兵
			for (j = i-1; L->r[j] > L->r[0]; j--)
			{
				L->r[j+1] = L->[j]; //记录后移
			}
			L->r[j+1] = L->r[0];//插入到正确位置
		}
	}
}

时间复杂度O(n*n)