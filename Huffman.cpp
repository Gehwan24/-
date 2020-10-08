#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAX_TREE_HT 100 
#define MAX  100000
int total_compreesion = 0;
struct MinHeapNode { // ��� ��Ʈ����

    char data;        // ����� ����   
    unsigned freq;    // �󵵼�  
    int compress; // ���� ��Ʈ
    char compress_bit[MAX_TREE_HT] = { NULL };
    int size;
    struct MinHeapNode* left, * right; // ���� ������ ������
};

struct MinHeap { // Heap�� �����ϴ� ����ü

    unsigned size; // heap ������
    unsigned capacity; // ���밡������
    struct MinHeapNode** array; // �迭
};

int isLeaf(struct MinHeapNode* root) // �� ��尡 �����ִ� ������� Ȯ���ϴ� �Լ�
{
    return !(root->left) && !(root->right); //�Ѵ� ������ 1
}

struct MinHeapNode* newNode(char data, unsigned freq) // ��� �����ϴ� �Լ�
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
        (sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    temp->compress = 0;
    for (int i = 0; i < MAX_TREE_HT; i++)
        temp->compress_bit[i] = '\0';
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) // ���� ���� HEAP�� ����� ����
{
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap)); // �� �����Ҵ�

    minHeap->size = 0; // �� ������� 0���� ����

    minHeap->capacity = capacity; // ���� ���ڿ� ũ�⸸ŭ�� �ش� ���� ����ɷ�

    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
            capacity * sizeof(struct MinHeapNode*)); // 15 * �� ��常ŭ�� �����Ҵ�
    return minHeap; // �ش� ���� ��ȯ�Ѵ�.
}

void swapMinHeapNode(struct MinHeapNode** a,
    struct MinHeapNode** b)//���� ��ġ�� �ٲ��ִ� �Լ� (���� �� ������ ��ȯ�Ǿ��� ����ɶ� �̿�)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// min heap �����ϴ� ��� 
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx; // ���� ������ ����
    int left = 2 * idx + 1; // ����
    int right = 2 * idx + 2; // ������

    if (left < minHeap->size && minHeap->array[left]->
        freq < minHeap->array[smallest]->freq) // ���� ���� ���� ���� ������ Ŭ �� smallest�� ���� ���� �ȴ�.
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
        freq < minHeap->array[smallest]->freq)// ���� ���� ���� ������ ������ Ŭ �� smallest�� ������ ���� �ȴ�.
        smallest = right;

    if (smallest != idx) {// idx���� smallest���� �ٸ���� �ش� ����� ��ġ�� ��ȯ���ش�
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest); // �ٽ� heapify�� ���� minheap�� �����Ѵ�
    }
}

int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1); // heap�� ũ�Ⱑ 1�ϋ� 1�� ��ȯ, ������ 0
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1]; // minheap�� ���� �����Ҷ� , ���� ���� ���� �����ǰ� ������ ��Ʈ�� �µ� �ٽ� heapify�� ���� minheap ����

    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{

    ++minHeap->size; // heap�� �����ϴ� �� ����
    int i = minHeap->size - 1; //insert�� ����忡 �Ѵ�

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { // �θ������ ũ�� �� 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode; // �ڱⰡ �ö� �� �ִ� ���� ���� ������ �ö󰣴�
}

void buildMinHeap(struct MinHeap* minHeap) // min heap �����
{

    int n = minHeap->size - 1; //�������� ������ �ݾ� ���̸� minheap������ Ȯ��
    int i;
    for (int i = 0; i < minHeap->size; i++)
    {
        printf("%c ", minHeap->array[i]->data);
    }
    printf("\n");

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

}

void printArr(int arr[], int n) // ������ �ڵ带 ����ϴ� �κ�
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

void inorder(struct MinHeap* root,int idx)
{
    if (idx * 2 + 1 < root->size)
        inorder(root, idx * 2+1);
    printf("%c ", root->array[idx]->data);
    if (idx * 2 + 2 < root->size)
        inorder(root, idx * 2+2);
}
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) // minheap�� ����� ����
{
    struct MinHeap* minHeap = createMinHeap(size);
    
    printf("�ּ� ������ ��Ʈ���� �ڼձ��� ������ �ѹ����� ������ȸ ������� ����ϸ�...\n");
    for (int i = 0; i < size; ++i) {
        minHeap->size = i+1;
        minHeap->array[i] = newNode(data[i], freq[i]);
        for(int j = i/2+1; j >= 0; j--)
            minHeapify(minHeap, j);
        for (int j = 0; j <= i; j++)
            printf("%c ", minHeap->array[j]->data);
        printf("\n");
        inorder(minHeap, 0);
        printf("\n");
    }

    minHeap->size = size;

    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode* left, * right, * top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {

        root->compress = top;
        total_compreesion += top * root->freq;
        printf("                    %c: ", root->data);
        for (int i = 0; i < root->size; ++i)
            printf("%c", root->compress_bit[i]);
        printf("\n");
    }
}

void printtrees(struct MinHeapNode* root, int arr[], int top, char data[], int freq[], int size)
{
    if (root->left) {
        arr[top] = 0;
        printtrees(root->left, arr, top + 1,data, freq, size);
    }

    if (root->right) {
        arr[top] = 1;
        printtrees(root->right, arr, top + 1, data, freq, size);
    }

    if (isLeaf(root)) {
        for(int i = 0; i < size; i++)
            if (data[i] == root->data)
            {
                printf(" data -> %c  count ->  %3d    newcode -> ", root->data, freq[i]);
            }
        printArr(arr, top);
        for (int i = 0; i < top; ++i)
            root->compress_bit[i] = arr[i] + '0';
        root->size = top;
    }
}
char decode_code[MAX] = { NULL };
int decode_index = 0;
//���ڵ��Լ�(���ڵ� �ϰ� ���� ���ڿ�, Ʈ�� ��Ʈ ���)
void decode(char* str, struct MinHeapNode* root)
{
    int i = 0;
    struct MinHeapNode* j = root;
    while (str[i] != '\0') //������ ���� �ƴ� ���
    {
        if (str[i] == '0') //���ڰ� 0�� ���
            j = j->left; //���� �ڽ����� �̵�
        else if (str[i] == '1') //���ڰ� 1�� ���
            j = j->right; //������ �ڽ����� �̵�
        if (j->left == NULL && j->right == NULL) //�� ����� ���
        {
            decode_code[decode_index++] = j->data;
            j = root;
            break;
        }
        i++;
    }
}
void find(struct MinHeapNode* root, char target)
{
    if (root->left) {
        find(root->left, target);
    }

    if (root->right) {
        find(root->right,target);
    }

    if (isLeaf(root)) {
        if(root->data == target)
            printf("%s ", root->compress_bit);
        return;
    }
}
char* encode(char* str, struct MinHeapNode* root, char arr[], int top)
{
    char* answer = NULL;
    int i = 0;
    char temp[] = " ";
    while (str[i] != '\0')
    {
        find(root,str[i]);
        i++;
    }
    return answer;
}

void HuffmanCodes(char data[], int freq[], int size,int total)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    
    int arr[MAX_TREE_HT], top = 0;
    char encode_arr[MAX_TREE_HT] = { NULL };
    char* ch = (char*)malloc(sizeof(char) * size);

    printf("***********************************************\n");
    printf("             ������ Ʈ��\n");
    printtrees(root, arr, top, data, freq, size);
    printf("***********************************************\n");
    printf("***********************************************\n");
    printf("             ������(��������) �ڵ�\n");
    printCodes(root, arr, top);
    printf("***********************************************\n\n");

    printf("���� Bit ǥ�� �������     -> %d Bits\n", total * 4);
    printf("Huffman (���� Bit) ǥ�� ������� -> %d Bits\n\n", total_compreesion);
    printf("������ �ڵ带 ����ϰ� ���� ������ ���ÿ�.\n");
    char want[MAX] = { NULL };
    scanf("%s", want);
    encode(want, root, encode_arr,0);
    printf("\ndecode : (NULL�Է½� ����)");
    while (1) {
        memset(want, 0x00, sizeof(want));
        scanf("%s", want);
        if (!strcmp(want, "NULL"))
            break;
        decode(want, root);
    }
    printf("%s", decode_code);
}


int main()
{

    int n;
    printf("�Է��� ���� ���� : ");
    scanf("%d", &n);
    char* ch = (char*)malloc(sizeof(char) * n);
    int* freq = (int*)malloc(sizeof(int) * n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        printf("�������� (end = 0) -> ");
        scanf(" %c", &ch[i]);
        printf("�󵵼� ���� -> ");
        scanf("%d",&freq[i]);
        printf("\n");
        total += freq[i];
    }
    printf("���� ����: %d     ���� �󵵼� ��: %d\n", n, total);

    HuffmanCodes(ch, freq,n,total);


    return 0;
}
