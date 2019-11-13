#define _CRT_SECURE_NO_WARNINGS
/************************************
*
*   This is Merge/Quick Sort Algorithm Structure
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
#define SIZE 100
/*
MERGE SORT
인덱스를 계속 쪼개서 비교 한 이후에 하나의 놈으로 만드는거
*/
void merge(int arr[], int start,int middle, int end)
{
	//합치는 함수
	int temp[SIZE];
	int i = start;
	int j = middle+1;
	int k = 0;
	while (i <= middle && j <= end) //둘중에 한놈 끝날때까지 비교 해서 큰놈부터 넣어주기
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
	//반으로 쪼개는 역할을 수행해야댐
	if (start < end)
	{
		middle = (start + end) / 2;
		MergeSort(arr, start, middle); //시작 - 중간 부분
		MergeSort(arr, middle+1,end); // 중간 - 끝 부분
		merge(arr, start, middle, end); // 다시 합치기;
	}
}
int Partition(int arr[], int start, int end)
{
	int temp;
	int pivot = arr[start]; //기준은 맨 왼쪽 부터 (시작)
	int low = start + 1;
	int high = end;
	//low <= high 일때 무한 반복쓰
	while (low <= high)
	{
		//pivot이 어디까지 가는지 체크
		while (pivot <= arr[low] && low <= end)
			low++;
		//pivot이 어디까지 가는지 체크
		while (pivot >= arr[high] && high >= (start + 1))
			high--;
		//비교해서 두개 값 교환
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	//마지막에 pivot (비교 기준)을 비교 결과 위치로 보내버린다.
	temp = arr[start];
	arr[start] = arr[high];
	arr[high] = temp;
	return high;
}
void QuickSort(int arr[], int start, int end)
{
	//왼쪽 기준으로 나눌 예정
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