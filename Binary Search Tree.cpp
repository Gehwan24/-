#define _CRT_SECURE_NO_WARNINGS
/************************************
*
*   This is Binary Search Tree Data Structure(추가 및 검색만 됨, 삭제되는 건 BST HEAP 부터 갑니다)
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*   고고싱 2019 - 11-01
*
*   개발환경은 C 입니다
**************************************/
#include <stdio.h>
#include <stdlib.h>

//트리에 들어갈 Node
typedef struct Node {
	int data;
	Node* left;
	Node* right;
}Node;

Node* start = NULL;
bool check = false;

//Node 생성하는 부분
Node* CreateNode(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

//Tree 에 노드 삽입
Node* InsertNode(int data, Node* root) {
	if (root == NULL)
	{
		root = CreateNode(data);
		return root;
	}
	else
	{
		if (root->data > data)
			root->left = InsertNode(data, root->left);
		else
			root->right = InsertNode(data, root->right);
		return root;
	}
}

//트리에 노드가 있는지 존재 유무를 확인해주는 함수 
void SearchNode(int data, Node* root) {
	if (root->data == data)
		check = true;
	else
	{
		if (root == NULL)
			return;
		else if (root->data > data)
			SearchNode(data, root->left);
		else
			SearchNode(data, root->right);
	}
}

//최소 노드를 구하는 함수 (나중에 Delete 함수에서 활용 예정)
Node* findMinNode(Node* root) {
	if (root->left == NULL)
		return root;
	else
	{
		while (root->left != NULL)
		{
			root = root->left;
		}
		return root;
	}
}

/*
데이터를 트리에서 지워주는 함수
현재 코드는 지워지는 데이터 오른쪽 노드에서 가장 작은값을 윗대가리로 올리는 작업
만약 다른 방법으로 하고 싶다면 왼쪽 노드에서 가장 큰값을 찾아서 올려도 된다.
*/
Node* DeleteNode(int data, Node* root) {
	Node* temp_node = NULL;
	if (root == NULL)
		return root;
	else
	{
		if (root->data > data)
			root->left = DeleteNode(data, root->left);
		else if (root->data == data)
		{
			if (root->left == NULL)
			{
				temp_node = root->right;
				free(root);
				return temp_node;
			}
			else if (root->right == NULL)
			{
				temp_node = root->left;
				free(root);
				return temp_node;
			}
			temp_node = findMinNode(root->right);// 이부분이 오른쪽 최대 작은값 구하는 부분
			root->data = temp_node->data;
			root->right = DeleteNode(temp_node->data, root->right);
		}
		else
			root->right = DeleteNode(data, root->right);
	}
	return root;
}

void PrintData(Node* root)//Preorder 형식 출력
{
	if (root == NULL)
		return;
	{
		printf(" %d ", root->data);
		PrintData(root->left);
		PrintData(root->right);
	}
}
int main(void)
{
	Node* temp;
	printf("---------------------------------Binary Search Tree(No Delete)-----------------------------------\n");
	int input, data;
	while (1) {
		printf("1.Insert      2. Search      3. Delete      4.Pirnt        4.Exit\n");
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
			start = InsertNode(data, start);
			break;
		case 2:
			printf("Search. Please input data : ");
			scanf("%d", &data);
			SearchNode(data, start);
			if (check)
				printf("Data exists!\n");
			else
				printf("Data doesn't exists!\n");
			check = false;
			break;
		case 3:
			printf("Delete. Please input data : ");
			scanf("%d", &data);
			temp = DeleteNode(data, start);
			if (temp == NULL)
				printf("There is no data!\n");
			break;
		case 4:
			PrintData(start);
			printf("\n");
			break;
		default:
			printf("Wrong Input!! Please select again \n");
		}
	}
	return 0;
}
