#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

//������ ���� alpha�� ����, ������ ���� digit�� �����ϴ� ����ü stack
typedef struct stack {
	char alpha = NULL;
	int digit = NULL;
}stack;

int main(void) {
	stack arr[SIZE];
	int count = 0;//stack �� �ԷµǴ� �� ī��Ʈ���ִ� ����
	int sum = 0;
	char* input = (char*)malloc(sizeof(char));
	scanf("%[^\n]", input);//���� ���� �Է¹ޱ�

	char* temp = strtok(input, " ");//���ڿ� ������ �������� �����ϱ�

	while (temp != NULL)//���ڰ� ���� �� ���� �ݺ�
	{
		//��ȣ�� ���, alpha�� ����
		if (temp[0] == '+' || temp[0] == '*' || temp[0] == '-' || temp[0] == '/')
			arr[count++].alpha = temp[0];
		else
		{
			//���ڴ� digit ����
			arr[count++].digit = atoi(temp);
			//���ڸ� �����Ϸ��� �ּ� 3 + 3 , 3���� �����ڰ� �ʿ��ϱ� ������ ������ ���� 3���� �ȵǸ� ������ �ȵǰ� ��
			if (count < 3)
				;
			else
			{
				//��ȣ ���� ���� ���̸� ������ �ݺ��ؼ� �����ϵ��� ������ ���� ����
				while (arr[count - 1].digit != NULL && arr[count - 2].digit != NULL && arr[count - 3].alpha != NULL)
				{
					switch (arr[count - 3].alpha)
					{
					case '+':
						sum = arr[count - 2].digit + arr[count - 1].digit;
						printf("%d + %d = %d\n", arr[count - 2].digit, arr[count - 1].digit, sum);
						break;
					case '-':
						sum = arr[count - 2].digit - arr[count - 1].digit;
						printf("%d - %d = %d\n", arr[count - 2].digit, arr[count - 1].digit, sum);
						break;
					case '*':
						sum = arr[count - 2].digit * arr[count - 1].digit;
						printf("%d * %d = %d\n", arr[count - 2].digit, arr[count - 1].digit, sum);
						break;
					case '/':
						if (arr[count - 1].digit == 0)
						{
							printf("Wrong Input\n");
							return 0;
						}
						else
						{
							sum = arr[count - 2].digit / arr[count - 1].digit;
							printf("%d / %d = %d\n", arr[count - 2].digit, arr[count - 1].digit, sum);
						}
						break;
					}
					//������ �κ� ��ü �ʱ�ȭ
					for (int i = count - 3; i < count; i++)
					{
						arr[i].alpha = NULL;
						arr[i].digit = NULL;
					}
					count = count - 3;
					//���갪 �ٽ� �ֱ�
					arr[count++].digit = sum;
					if (count < 3)
						break;
				}
			}
		}
		//�����ڸ� ���� ���� ������� Ȯ���ϱ�
		temp = strtok(NULL, " ");
	}
	if (count != 0)
		printf("Wrong input\n");
	else
		printf("total is %d : %d", count - 1,arr[count - 1].digit);
	return 0;
}