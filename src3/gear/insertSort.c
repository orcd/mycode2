#include <stdio.h>

//��������
void InsertSort(int *arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}

//ϣ������
void ShellSort(int *arr, int len)
{
	int increment = len;

	while (increment > 1)
	{
		increment = increment / 3 + 1;
		//����������������飬Ȼ�����ÿһ��
		for (int i = 0; i < increment; ++i)
		{
			//��ÿ��ִ�в�������
			for (int j = i + increment; j < len; j += increment)
			{
				int temp = arr[j];
				int k = j - increment;
				while (k >= 0 && temp < arr[k])
				{
					arr[k + increment] = arr[k];
					k -= increment;
				}
				arr[k + increment] = temp;
			}
		}
	}
}

//��������
void QuickSort(int *arr, int start, int end)
{
	int i = start;
	int j = end;

	if (i >= j)
		return;

	int temp = arr[i];

	while (i < j)
	{

		//���ұ��ҵ�һ���Ȼ�׼ֵС�ķŵ����
		while (i < j && arr[j] >= temp)
		{
			--j;
		}

		if (i < j && arr[j] < temp)
		{
			arr[i] = arr[j];
			++i;
		}

		//������ҵ�һ���Ȼ�׼ֵ��ķŵ��ұ�
		while (i < j && arr[i] < temp)
		{
			++i;
		}

		if (i < j && arr[i] >= temp)
		{
			arr[j] = arr[i];
			--j;
		}
	}

	arr[i] = temp;

	QuickSort(arr, start, i - 1);
	QuickSort(arr, i + 1, end);
}

//�ϲ�������������
//void Merge(int *arr1, int start1, int end1, int *arr2, int start2, int end2, int *arr3)
//{
//	int i = start1;
//	int j = start2;
//
//	int length = 0;
//
//	while (i <= end1 && j <= end2)
//	{
//		if (arr1[i] < arr2[j])
//		{
//			arr3[length] = arr1[i];
//			++i;
//		}
//		else
//		{
//			arr3[length] = arr2[j];
//			++j;
//		}
//		length++;
//	}
//
//	while (i <= end1)
//	{
//		arr3[length++] = arr1[i++];
//	}
//
//	while (j <= end2)
//	{
//		arr3[length++] = arr2[j++];
//	}
//}

void Merge(int *arr, int start, int mid, int end, int *temp)
{
	int i = start;
	int j = mid + 1;

	int length = 0;

	while (i <= mid &&j <= end)
	{
		if (arr[i] < arr[j])
		{
			temp[length++] = arr[i++];
		}
		else
		{
			temp[length++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[length++] = arr[i++];
	}

	while (j <= end)
	{
		temp[length++] = arr[j++];
	}

	for (int i = 0; i < length; ++i)
	{
		arr[start + i] = temp[i];
	}
}

void MergeSort(int *arr, int start, int end, int *temp)
{
	if (start == end)
		return;
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid,temp);
	MergeSort(arr, mid + 1, end,temp);
	//�ϲ�������������
	Merge(arr, start, mid, end, temp);
}

int main()
{
	int arr[10] = { 2, 7, 4, 8, 6, 5, 1, 9, 0, 3 };
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	//QuickSort(arr, 0, 9);
	int temp[10];
	MergeSort(arr, 0, 9, temp);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}


	/*int arr1[3] = { 1, 3, 5 };
	int arr2[5] = { 0, 2, 4, 6, 7 };
	int arr3[8];
	Merge(arr1, 0, 2, arr2, 0, 4, arr3);
	for (int i = 0; i < 8; ++i)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");*/
	return 0;
}