/************************************
*
*   This is Linked List Data Structure
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*   고고싱 2019 - 11-01
*
*   개발환경은 C 입니다
*************************************/
#include <stdio.h>
#include <stdlib.h>

//정수형 자료형 및 다음 노드를 향한 포인터를 가지고 있는 구조체 Node

typedef struct Node {
	int data;
	Node* next;
}Node;

Node* start_head;

Node* Create_Node(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data; //데이터 입력
	new_node->next = NULL;
	return new_node;
}

void InsertNode(int data) {
	Node* new_node = Create_Node(data);
	Node* temp_node;
	if (start_head == NULL) 
		start_head = new_node;
	else if (start_head->next == NULL)
		start_head->next = new_node;
	else
	{
		temp_node = start_head;
		while (temp_node->next != NULL)
		{
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
}

void SearchNode(int data) {
	Node* temp_node = start_head;
	if (start_head == NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		do {
			if (temp_node->data == data)
			{
				printf("Linked List has %d\n", data);
				return;
			}
			else
				temp_node = temp_node->next;
		} while (temp_node != NULL);
		printf("There is no data %d\n", data);
	}
}

void DeleteNode(int data)
{
	Node* temp_node = start_head;
	Node* before_node = temp_node;
	if (start_head == NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		while (temp_node != NULL)
		{
			if (temp_node->data == data)
				break;
			else
			{
				before_node = temp_node;
				temp_node = temp_node->next;
			}
		}
		if (temp_node == NULL)
			printf("There is no data %d\n", data);
		else
		{
			if (before_node == start_head)
			{
				if (start_head->next == NULL)
					start_head = NULL;
				else
					start_head = start_head->next;
				free(before_node);
			}
			else
			{
				printf("Delete %d\n", temp_node->data);
				before_node->next = temp_node->next;
				free(temp_node);
			}
		}	
	}
}
void Print_data(void)
{
	Node* temp_node = start_head;
	if (start_head == NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		while (temp_node != NULL)
		{
			printf("%d ", temp_node->data);
			temp_node = temp_node->next;
		}
		printf("\n");
	}
}
int main(void)
{
	printf("---------------------------------Linked List-----------------------------------\n");
	int input,data;
	while (1) {
		printf("1.Insert      2. Search       3. Delete       4. Print       5.Exit\n");
		scanf("%d", &input);
		if (input == 5)
		{
			printf("Program Exit\n");
			break;
		}
		switch (input)
		{
		case 1:
			printf("Insert. Please input data : ");
			scanf("%d", &data);
			InsertNode(data);
			break;
		case 2:
			printf("Search. Please input data : ");
			scanf("%d", &data);
			SearchNode(data);
			break;
		case 3:
			printf("Delete. Please input data : ");
			scanf("%d", &data);
			DeleteNode(data);
			break;
		case 4:
			printf("--------------Print data-----------\n");
			Print_data();
			printf("--------------Print data-----------\n");
			break;
		default :
			printf("Wrong Input!! Please select again \n");
		}
	}
	return 0;
}