#define _CRT_SECURE_NO_WARNINGS
/************************************
*
*   This is Merge/Quick Sort Algorithm Structure
*
*   Gehwan Gehwan
*
*   �б����� ��� ���� ��� �� �ȳ��� �ٽ� �����ϴ� ����
*
*   Sort (���� ��) ������ ���� ���ͳ� ���� ��
*
*   ���� 2019 - 10 - 31
*
*   ����ȯ���� C �Դϴ�
*************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
/*
MERGE SORT
�ε����� ��� �ɰ��� �� �� ���Ŀ� �ϳ��� ������ ����°�
*/
void merge(int arr[], int start, int middle, int end)
{
	int temp[SIZE];
	int low = start;
	int high = middle + 1;
	int k = 0;
	while (low <= middle && high <= end)
	{
		if (arr[low] <= arr[high])
			temp[k++] = arr[high++];
		else
			temp[k++] = arr[low++];
	}
	while(low <= middle) 
		temp[k++] = arr[low++];
	while(high <= end)
		temp[k++] = arr[high++];
	for (int i = 0; i < SIZE; i++)
		arr[i] = temp[i];
}
void MergeSort(int arr[], int start, int end)
{
	int middle;
	if (start < end)
	{
		middle = (start + end) / 2;
		MergeSort(arr, start, middle);
		MergeSort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
	
}
int Partition(int arr[], int start, int end)
{
	int temp;
	int pivot = arr[start];
	int low = start+1;
	int high = end;
	while (pivot <= arr[low] && low <= end)
	{
		while (pivot <= arr[low] && low <= end)
			low++;
		while (pivot >= arr[high] && high >= (start + 1))
			high--;
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[start];
	arr[start] = arr[high];
	arr[high] = temp;
	return high;
}
void QuickSort(int arr[], int start, int end)
{
	int pivot;
	if (start < end)
	{
		pivot = Partition(arr, start, end);
		QuickSort(arr, start, pivot - 1);
		QuickSort(arr, pivot + 1,end);
	}
}
void PrintArray(int arr[])
{
	for (int i = 0; i < SIZE;i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

int main(void)
{
	printf("===================This is Merge/Quick Sort=======================\n");
	int input;
	int arr[SIZE] = { 0 };
	PrintArray(arr);
	printf("1. Merge       2.Quick :");
	scanf("%d", &input);
	if (input == 1)
	{
		MergeSort(arr, 0, SIZE - 1);
		PrintArray(arr);
	}
	else if (input == 2)
	{
		QuickSort(arr, 0, SIZE - 1);
		PrintArray(arr);
	}
	else {
		printf("Wrong Input. Program exit.\n");
	}
}