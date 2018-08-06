/*

 快速排序的基本思想:	
   通过一趟排序将待排序记录分割成独立的俩部分，其中一部分记录的关键字均
   比另一部分记录的关键字小，则可分别对着俩部分记录继续进行排序，以达到
   整个序列有序的目的、

*/


void QuickSort(Sqlist *L)
{
	Qsort(L, 1, L->length);
}

void Qsort(Sqlist *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); // 将L->r[low...high]一分为二, 算出枢轴值pivot
		Qsort(L, low, pivot-1);
		Qsort(L, pivot+1, high);
	}
}

int Partition(Sqlist *L, int low, int high)
{
	int pivotKey;
	pivotKey = L->r[low];
	while (low < high)
	{
		while (low < high && r[high] >= pivotKey)
			high--;
		swap(L, low, high);
		while (low <high  && r[low] <= pivotKey)
			low++;
		swap(L, low, high);
	}
	return low;
}

/*
时间复杂度分析：
	最好情况是 O(n)
	最差情况是 O(n^2)
*/