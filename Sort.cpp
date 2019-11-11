#define _CRT_SECURE_NO_WARNINGS
/************************************
*
*   This is Sort Algorithm Structure
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*   Sort (전부 다) 머지랑 퀵은 인터넷 보고 함
*
*   고고싱 2019 - 10 - 31
*
*   개발환경은 C 입니다
*************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX -1

void BubbleSort(int arr[]) {
	int temp;
	for (int i = 0; i < SIZE;i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

void InsertSort(int arr[]) {
	int temp;
	for (int i = 1; i < SIZE; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

void SelectSort(int arr[]) {
	int max_index, max;
	for (int i = 0; i < SIZE; i++)
	{
		max = MAX;
		for (int j = i; j < SIZE; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				max_index = j;
			}
		}
		arr[max_index] = arr[i];
		arr[i] = max;
	}

	for (int i = 0; i < SIZE; i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int start, int middle, int end)
{
	int i = start, j = middle + 1, k = start;
	int temp[SIZE];
	while (i <= middle && j <= end) {
		if (arr[i] >= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= middle) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];
	for (int a = start; a <= end; a++) arr[a] = temp[a];
}

void MergeSort(int arr[],int start,int end) {
	int middle;
	middle = (start + end) / 2;
	if (start < end)
	{
		MergeSort(arr, start, middle);
		MergeSort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
}


int Partition(int arr[], int left, int right)
{
	int temp;
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot <= arr[low] && low <= right)
			low++;
		while (pivot >= arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;
	return high;
}


void QuickSort(int arr[],int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot+1,right);
	}
}

int main(void) {
	printf("=================================Sort===================================\n");
	int arr[SIZE] = { 4,2,6,7,57,564,53,42,23,56 };
	int input;

	for (int i = 0; i < SIZE; i++)
		printf(" %d ", arr[i]);
	printf("\n");

	printf(" 1. Bubble    2.Insert    3. Select   4. Merge    5. Split :");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		BubbleSort(arr);
		break;
	case 2:
		InsertSort(arr);
		break;
	case 3:
		SelectSort(arr);
		break;
	case 4:
		MergeSort(arr,0,SIZE-1);
		for (int i = 0; i < SIZE; i++)
			printf(" %d ", arr[i]);
		printf("\n");
		break;
	case 5:
		QuickSort(arr,0,SIZE-1);
		for (int i = 0; i < SIZE; i++)
			printf(" %d ", arr[i]);
		printf("\n");
		break;
	}

	return 0;
}