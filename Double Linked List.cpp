/************************************
*
*   This is Double Linked List Data Structure
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

int list_count = 0;
typedef struct Node {
	int data;
	Node* before;
	Node* next;
}Node;

Node* start_head;

Node* Create_Node(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data; //데이터 입력
	new_node->before = NULL;
	new_node->next = NULL;
	return new_node;
}

void InsertNode(int data) {
	Node* new_node = Create_Node(data);
	Node* temp_node;
	if (start_head == NULL)
	{
		start_head = new_node;
		new_node->before = start_head;
		new_node->next = start_head;
	}
	else if (start_head->next == start_head)
	{
		start_head->next = new_node;
		start_head->before = new_node;
		new_node->before = start_head;
		new_node->next = start_head;
	}
	else
	{
		temp_node = start_head;
		while (temp_node->next != start_head)
		{
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
		start_head->before = new_node;
		new_node->before = temp_node;
		new_node->next = start_head;
	}
	list_count++;
}

void SearchNode_Next(int data) {
	int count = 0;
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
		} while (count++<list_count);
		printf("There is no data %d\n", data);
	}
}
void SearchNode_Before(int data) {
	int count = 0;
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
				temp_node = temp_node->before;
		} while (count++<list_count);
		printf("There is no data %d\n", data);
	}
}
void DeleteNode(int data)
{
	int count = 0;
	Node* before_node;
	Node* next_node;
	Node* temp_node = start_head;
	if (start_head == NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		while (count < list_count)
		{
			if (temp_node->data == data)
				break;
			else
			{
				temp_node = temp_node->next;
				count++;
			}
		}
		if (count>=list_count)
			printf("There is no data %d\n", data);
		else
		{
			printf("Delete Data : %d\n", temp_node->data);
			if (temp_node==start_head&&temp_node->next == start_head)
			{
				start_head = NULL;
			}
			else
			{
				if (temp_node == start_head)
				{
					before_node = temp_node->before;
					next_node = temp_node->next;
					before_node->next = temp_node->next;
					next_node->before = temp_node->before;
					start_head = next_node;
				}
				else
				{
					before_node = temp_node->before;
					next_node = temp_node->next;
					before_node->next = temp_node->next;
					next_node->before = temp_node->before;
				}
			}
			free(temp_node);
			list_count--;
		}
	}
}
void Print_data(void)
{
	int count = 0;
	Node* temp_node = start_head;
	if (start_head == NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		while (count<list_count)
		{
			printf("%d ", temp_node->data);
			temp_node = temp_node->next;
			count++;
		}
		printf("\n");
	}
}
int main(void)
{
	printf("---------------------------------Linked List-----------------------------------\n");
	int input, data;
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
			SearchNode_Next(data);
			printf("\n");
			SearchNode_Before(data);
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
		default:
			printf("Wrong Input!! Please select again \n");
		}
	}
	return 0;
}