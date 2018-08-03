/*
简单选择排序的思想：
假设排序表为L[1...n],第i趟排序从L[i...n]中选择关键字最小的元素与L[i]交换，
每一趟排序可以确定一个元素的最终位置，这样经过n-1次排序皆可以使得整个序列有序
*/


//来自王道2018数据结构与算法 P297
void SelectSort(ElementType A[], int n)
{
	int i, j, min;
	for (i = 0; i < n-1; i++) 
	{
		min = i;
		for (j = i+1; j < n-1; j++)
		{
			if (A[j] < A[min]) min = j;
		}
		if (min != i) swap(A[i], A[min]);
	}
}

//来自大话数据结构 P384
void SelectSort(Sqlist *L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;
		for (j = i+1; j < L->length; j++)
		{
			if (L->r[min] > L->r[j])
			{
				min = j;
			}
		}

		if (i != min)
		{
			swap(L, i, min);
		}
	}
}