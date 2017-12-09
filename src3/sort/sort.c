//选择排序(升序排列)
void select_sort(int *array, int len)
{
	int i, j;
	int min = 0;	// 指向最小的元素的位置
	
	// 外层循环
	for (i = 0; i < len-1; ++i)
	{
		min = i;
		// 内存循环
		for (j = i + 1; j < len; ++j)
		{
			// 判断
			if (array[min] > array[j])
			{
				// 保存最小的元素的位置
				min = j;
			}
		}
		
		// 判断是否需要交换
		if (min != i)
		{
			// 找到了新的最小值
			// 交换
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}
}
