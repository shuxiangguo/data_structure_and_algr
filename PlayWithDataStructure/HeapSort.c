// 还未掌握 后面继续学习

//堆排序
void HeapSort(Sqlist *L)
{
	int i;
	for (i = L->length / 2; i > 0; i--)//把L中的r构建成一个大根堆
	{
		HeapAdjust(L, i, L->length);
	}

	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);//将堆顶记录和当前未经排序子序列的最有一个记录交换
		HeapAdjust(L, 1, i-1);//将L->r[1...i-1]重新调整为大根堆
	}
}


// 已知L->r[s...m]中记录的关键字除了L->r[s]之外均满足堆的定义
// 该函数调整L->r[s]的关键字， 使L->r[s..m]称为一个大根堆
void HeapAdjust(Sqlist *L, int s, int m)
{
	int temp j;
	temp = L->r[s];
	for (j = 2*s; j <= m; j *= 2)
	{
		if (j < m && L->r[j] < L->r[j+1])
			++j; //j为关键字较大的孩子向下筛选
		if (temp >= L->r[j])
			break; //rc应该插入在位置s上
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp; //插入
}