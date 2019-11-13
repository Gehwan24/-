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
void merge(int arr[], int start,int middle, int end)
{
	//��ġ�� �Լ�
	int temp[SIZE];
	int i = start;
	int j = middle+1;
	int k = 0;
	while (i <= middle && j <= end) //���߿� �ѳ� ���������� �� �ؼ� ū����� �־��ֱ�
	{
		if (arr[i] >= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= middle) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];
	for (int i = 0; i < SIZE;i++)
		arr[i] = temp[i];
}
void MergeSort(int arr[], int start, int end)
{
	int middle;
	//������ �ɰ��� ������ �����ؾߴ�
	if (start < end)
	{
		middle = (start + end) / 2;
		MergeSort(arr, start, middle); //���� - �߰� �κ�
		MergeSort(arr, middle+1,end); // �߰� - �� �κ�
		merge(arr, start, middle, end); // �ٽ� ��ġ��;
	}
}
int Partition(int arr[], int start, int end)
{
	int temp;
	int pivot = arr[start]; //������ �� ���� ���� (����)
	int low = start + 1;
	int high = end;
	//low <= high �϶� ���� �ݺ���
	while (low <= high)
	{
		//pivot�� ������ ������ üũ
		while (pivot <= arr[low] && low <= end)
			low++;
		//pivot�� ������ ������ üũ
		while (pivot >= arr[high] && high >= (start + 1))
			high--;
		//���ؼ� �ΰ� �� ��ȯ
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	//�������� pivot (�� ����)�� �� ��� ��ġ�� ����������.
	temp = arr[start];
	arr[start] = arr[high];
	arr[high] = temp;
	return high;
}
void QuickSort(int arr[], int start, int end)
{
	//���� �������� ���� ����
	int pivot;
	if (start < end)
	{
		pivot = Partition(arr, start, end);
	}
}
void PrintArray(int arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf(" %d ", arr[i]);
	}
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