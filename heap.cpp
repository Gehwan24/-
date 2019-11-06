/************************************
*
*   This is Heap Data Structure
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*	MAX HEAP
*
*   고고싱 2019 - 10 - 31
*
*   개발환경은 C 입니다
*************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

typedef struct HEAP {
	int data;
}HEAP;

typedef struct HEAP_TYPE {
	HEAP heap[100];
	int size;
}HEAP_TYPE;

void InsertHeap(int data, HEAP_TYPE* h)
{
	int temp = h->size++;
	int temp_value;
	h->heap[temp].data = data;
	if (temp == 1)
		return;
	else
	{
		while (temp != 1)
		{
			if (h->heap[temp].data > h->heap[temp / 2].data)
			{
				temp_value = h->heap[temp].data;
				h->heap[temp].data = h->heap[temp / 2].data;
				h->heap[temp / 2].data = temp_value;
				temp = temp / 2;
			}
			else
				break;
		}
	}
}

void SearchHeap(int data, HEAP_TYPE* h)
{
	int count = 1;
	for (int i = 1; i < h->size; i++)
	{
		if (data == h->heap[i].data)
		{
			printf("%d index : data exists!\n", count);
			break;
		}
		count++;
	}
	if (count == h->size)
		printf("Data doesn't exist\n");
}

int DeleteMAXHeap(HEAP_TYPE* h)
{
	int max;
	int count = 1;
	int last;
	if (h->size == 1)
	{
		printf("There is no data\n");
		return NULL;
	}
	else
	{
		max = h->heap[1].data;
		if (h->size == 2)
		{
			h->heap[--h->size].data = 0;
		}
		else
		{
			last = h->heap[--h->size].data;
			h->heap[h->size].data = 0;
			h->heap[count].data = last;
			while (1)
			{
				if (count * 2+1 <= h->size)
					break;
				if (h->heap[count].data < h->heap[count * 2].data || h->heap[count].data < h->heap[count * 2 + 1].data)
				{
					if (h->heap[count * 2].data > h->heap[count * 2 + 1].data)
					{
						last = h->heap[count].data;
						h->heap[count].data = h->heap[count * 2].data;
						h->heap[count * 2].data = last;
						count = 2 * count;
					}
					else
					{
						last = h->heap[count].data;
						h->heap[count].data = h->heap[count * 2 +1].data;
						h->heap[count * 2 + 1].data = last;
						count = 2 * count + 1;
					}
				}
				else
					break;
			}
		}
	}
	return max;
}

void PrintHeap(HEAP_TYPE heap)
{
	printf("-------------------------------------------------------------------------\n");
	for (int i = 1; i < heap.size;i++)
	{
		printf(" %d ", heap.heap[i].data);
	}
	printf("\n");
	printf("-------------------------------------------------------------------------\n");
}
int main(void)
{
	HEAP_TYPE h;
	int input,value,max;
	h.size = 1;
	printf("-------------------------MAX HEAP---------------------------\n");
	while (1)
	{
		printf("1. Insert   2. Search     3.Delete MAX    4.Print      5.Exit\n");
		scanf("%d", &input);
		if (input == 5)
		{
			printf("Program Exit\n");
			break;
		}
		else
		{
			switch (input)
			{
			case 1:
				printf("Insert  value : ");
				scanf("%d", &value);
				InsertHeap(value, &h);
				break;
			case 2:
				printf("Search  value : ");
				scanf("%d", &value);
				SearchHeap(value, &h);
				break;
			case 3:
				max = DeleteMAXHeap(&h);
				if (max == NULL)
					;
				else
					printf("MAX VALUE IS %d \n", max);
				break;
			case 4:
				PrintHeap(h);
				break;
			default:
				printf("Wrong Input\n");
				break;
			}
		}
	}
	return 0;
}



