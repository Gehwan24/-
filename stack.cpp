/************************************
*
*   This is Stack Data Structure 
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

//size가 100인 스택을 초기화하고 시작
int stack[SIZE] = { 0 };
int position = -1;

//스택이 꽉 찼을 때, 오류 반환
void push(int data)
{
	if (position+1 == SIZE - 1)
		printf("THIS STACK IS FULL! DO NOT PUSH\n");
	else
		stack[++position] = data;
}
//스택이 비었을 때, 오류 반환
int pop(void) 
{
	if (position == -1)
	{
		printf("THIS STACK IS EMPTY! DO NOT POP\n");
		return NULL;
	}
	else
		return stack[position--];
}

int main(void)
{
	printf("-----------------STACK START!-------------------\n");
	int input = 0;
	int input_value;
	int temp;
	while (1) {
		printf("1. PUSH   2. POP    3. EXIT : ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("PUSH DATA : ");
			scanf("%d", &input_value);
			push(input_value);
			break;
		case 2:
			temp = pop();
			if (temp != NULL) {
				printf("POP DATA : %d\n", temp);
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