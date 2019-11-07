/************************************
*
*   This is Graph Data Structure
*
*   Gehwan Gehwan
*
*   학교에서 배운 내용 기억 잘 안나서 다시 시작하는 슬픔
*
*	Undirected Graph
*
*   고고싱 2019 - 10 - 31
*
*   개발환경은 C 입니다
*************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct graph {
	int vertex;
	int** matrix;
}graph;

graph* CreateGraph(int number) {
	graph *g = (graph*)malloc(sizeof(graph));
	g->vertex = number;
	g->matrix = (int**)malloc(sizeof(int *)*number);
	for (int i = 0; i < number;i++)
	{
		g->matrix[i] = (int*)malloc(sizeof(int)*number);
		memset(g->matrix[i], 0x00, sizeof(int)*number);
	}
	return g;
}
void ClearGraph(graph* g)
{
	for (int i = 0; i < g->vertex;i++)
	{
		free(g->matrix[i]);
	}
	free(g->matrix);
	free(g);
}
void AddGraph(graph* g) {
	int a, b;
	printf("Insert two vertex : ");
	scanf("%d%d", &a, &b);
	if (a<0 || a>g->vertex || b<0 || b>g->vertex)
		printf("Wrong Input\n");
	else
	{
		g->matrix[a][b] = 1;
		g->matrix[b][a] = 1;
	}
}
void PrintMatrix(graph* g)
{
	for (int i = 0; i < g->vertex; i++)
	{
		for (int j = 0; j < g->vertex; j++)
			printf(" %d ", g->matrix[i][j]);
		printf("\n");
	}
}
int main(void)
{
	printf("------------------------------------------Graph-----------------------------------------\n");
	int input;
	int option;
	printf("vertex : ");
	scanf("%d", &input);
	graph* g = CreateGraph(input);
	while (1) {
		printf("1. ADD EDGE       2.PRINT        3.EXIT\n");
		scanf("%d", &option);
		if (option == 3)
		{
			printf("Program Exit.\n");
			break;
		}
		else
		{
			switch(option)
			{
			case 1:
				AddGraph(g);
				break;
			case 2:
				PrintMatrix(g);
				break;
			}
		}
	}
	ClearGraph(g);
	return 0;
}