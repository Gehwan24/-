#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

//문자일 때는 alpha에 저장, 숫자일 때는 digit에 저장하는 구조체 stack
typedef struct stack {
	char alpha = NULL;
	int digit = NULL;
}stack;

int main(void) {
	stack arr[SIZE];
	int count = 0;//stack 에 입력되는 수 카운트해주는 변수
	int sum = 0;
	char* input = (char*)malloc(sizeof(char));
	scanf("%[^\n]", input);//개행 포함 입력받기

	char* temp = strtok(input, " ");//문자열 공백을 기준으로 구분하기

	while (temp != NULL)//문자가 없을 때 까지 반복
	{
		//부호일 경우, alpha에 저장
		if (temp[0] == '+' || temp[0] == '*' || temp[0] == '-' || temp[0] == '/')
			arr[count++].alpha = temp[0];
		else
		{
			//숫자는 digit 저장
			arr[count++].digit = atoi(temp);
			//숫자를 연산하려면 최소 3 + 3 , 3개의 연산자가 필요하기 때문에 다음과 같이 3개가 안되면 연산이 안되게 함
			if (count < 3)
				;
			else
			{
				//기호 숫자 숫자 순이면 연산이 반복해서 가능하도록 다음과 같이 정의
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
					//연산한 부분 전체 초기화
					for (int i = count - 3; i < count; i++)
					{
						arr[i].alpha = NULL;
						arr[i].digit = NULL;
					}
					count = count - 3;
					//연산값 다시 넣기
					arr[count++].digit = sum;
					if (count < 3)
						break;
				}
			}
		}
		//구분자를 통해 다음 개행까지 확인하기
		temp = strtok(NULL, " ");
	}
	if (count != 0)
		printf("Wrong input\n");
	else
		printf("total is %d : %d", count - 1,arr[count - 1].digit);
	return 0;
}