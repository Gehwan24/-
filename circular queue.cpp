/************************************
*
*   This is Circular Queue Data Structure
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*   고고싱 2019 - 10 - 31
*
*   개발환경은 C 입니다
*************************************/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>

//size가 100인 큐를 초기화하고 시작
int queue[SIZE] = { 0 };
int front = -1;
int rear = -1;

//큐가 꽉 찼을 때, 오류 반환
void enqueue(int data)
{
	if (front == -1)
	{
		rear = 0;
		queue[++front] = data;
	}
	else if((front+1)%SIZE == rear%SIZE)
		printf("THIS QUEUE IS FULL! DO NOT PUSH\n");
	else
		queue[++front] = data;
}
//큐가 비었을 때, 오류 반환
int dequeue(void)
{
	if (rear > front)
	{
		printf("THIS QUEUE IS EMPTY! DO NOT POP\n");
		rear = front = -1;
		return NULL;
	}
	else
		return queue[rear++%SIZE];
}

int main(void)
{
	printf("-----------------CIRCULAR QUEUE START!-------------------\n");
	int input = 0;
	int input_value;
	int temp;
	while (1) {
		printf("%d %d\n", front, rear);
		printf("1. PUSH   2. POP    3. EXIT : ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ENQUEUE DATA : ");
			scanf("%d", &input_value);
			enqueue(input_value);
			break;
		case 2:
			temp = dequeue();
			if (temp != NULL) {
				printf("DEQUEUE DATA : %d\n", temp);
				temp = NULL;
			}
			break;
		case 3:
			break;
		}
		if (input == 3)
			break;
	}
	printf("Program Exit\n");
	return 0;
}
