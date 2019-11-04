/************************************
*
*   This is Binary Tree Data Structure(�߰� �� �˻��� ��, �����Ǵ� �� BST HEAP ���� ���ϴ�)
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

Node* root;
bool check = false;

Node* CreateNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->right = NULL;
	new_node->left = NULL;
	return new_node;
}

void Find_and_Insert(Node* node, Node* position)
{
	if (position->left == NULL)
	{
		position->left = node;
		return;
	}
	else if (position->right == NULL)
	{
		position->right = node;
		return;
	}
	if (position->left != NULL)
		Find_and_Insert(node, position->left);
	else if (position->right != NULL)
		Find_and_Insert(node, position->right);
	else
		return;
}

void Insert_Node(int data)
{
	Node* new_node = CreateNode(data);
	if (root == NULL)
		root = new_node;
	else
		Find_and_Insert(new_node, root);
}

void Search_Node(int data,Node* node) {
	if (node->data == data)
		check = true;
	else
	{
		if (node->left != NULL)
			Search_Node(data, node->left);
		if(node ->right != NULL)
			Search_Node(data, node->right);
	}
}

int main(void)
{
	printf("---------------------------------Binary Tree(No Delete)-----------------------------------\n");
	int input, data;
	while (1) {
		printf("1.Insert      2. Search   3.Exit\n");
		scanf("%d", &input);
		if (input == 3)
		{
			printf("Program Exit\n");
			break;
		}
		switch (input)
		{
		case 1:
			printf("Insert. Please input data : ");
			scanf("%d", &data);
			Insert_Node(data);
			break;
		case 2:
			printf("Search. Please input data : ");
			scanf("%d", &data);
			Search_Node(data, root);
			if (check)
				printf("Data exists!\n");
			else
				printf("Data doesn't exists!\n");
			check = false;
			break;
		default:
			printf("Wrong Input!! Please select again \n");
		}
	}
	return 0;
}
