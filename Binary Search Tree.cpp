#define _CRT_SECURE_NO_WARNINGS
/************************************
*
*   This is Binary Search Tree Data Structure(�߰� �� �˻��� ��, �����Ǵ� �� BST HEAP ���� ���ϴ�)
*
*   Gehwan Gehwan
*
*   �б����� ��� ���� ��� �� �ȳ��� �ٽ� �����ϴ� ����
*
*   ���� 2019 - 11-01
*
*   ����ȯ���� C �Դϴ�
**************************************/
#include <stdio.h>
#include <stdlib.h>

//Ʈ���� �� Node
typedef struct Node {
	int data;
	Node* left;
	Node* right;
}Node;

Node* start = NULL;
bool check = false;

//Node �����ϴ� �κ�
Node* CreateNode(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

//Tree �� ��� ����
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

//Ʈ���� ��尡 �ִ��� ���� ������ Ȯ�����ִ� �Լ� 
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

//�ּ� ��带 ���ϴ� �Լ� (���߿� Delete �Լ����� Ȱ�� ����)
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
�����͸� Ʈ������ �����ִ� �Լ�
���� �ڵ�� �������� ������ ������ ��忡�� ���� �������� ���밡���� �ø��� �۾�
���� �ٸ� ������� �ϰ� �ʹٸ� ���� ��忡�� ���� ū���� ã�Ƽ� �÷��� �ȴ�.
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
			temp_node = findMinNode(root->right);// �̺κ��� ������ �ִ� ������ ���ϴ� �κ�
			root->data = temp_node->data;
			root->right = DeleteNode(temp_node->data, root->right);
		}
		else
			root->right = DeleteNode(data, root->right);
	}
	return root;
}

void PrintData(Node* root)//Preorder ���� ���
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
