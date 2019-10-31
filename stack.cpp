/************************************
*
*   This is Stack Data Structure 
*   
*   Gehwan Gehwan
* 
*   �б����� ��� ���� ��� �� �ȳ��� �ٽ� �����ϴ� ����
*
*   ���� 2019 - 10 - 31
*
*   ����ȯ���� C �Դϴ�
*************************************/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>

//size�� 100�� ������ �ʱ�ȭ�ϰ� ����
int stack[SIZE] = { 0 };
int position = -1;

//������ �� á�� ��, ���� ��ȯ
void push(int data)
{
	if (position+1 == SIZE - 1)
		printf("THIS STACK IS FULL! DO NOT PUSH\n");
	else
		stack[++position] = data;
}
//������ ����� ��, ���� ��ȯ
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