#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAX_TREE_HT 100 
#define MAX  100000
int total_compreesion = 0;
struct MinHeapNode { // 노드 스트럭쳐

    char data;        // 노드의 문자   
    unsigned freq;    // 빈도수  
    int compress; // 압축 비트
    char compress_bit[MAX_TREE_HT] = { NULL };
    int size;
    struct MinHeapNode* left, * right; // 왼쪽 오른쪽 포인터
};

struct MinHeap { // Heap을 구성하는 구조체

    unsigned size; // heap 사이즈
    unsigned capacity; // 수용가능한지
    struct MinHeapNode** array; // 배열
};

int isLeaf(struct MinHeapNode* root) // 이 노드가 끝에있는 노드인지 확인하는 함수
{
    return !(root->left) && !(root->right); //둘다 없으면 1
}

struct MinHeapNode* newNode(char data, unsigned freq) // 노드 생성하는 함수
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

struct MinHeap* createMinHeap(unsigned capacity) // 가장 작은 HEAP을 만드는 과정
{
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap)); // 힙 동적할당

    minHeap->size = 0; // 힙 사이즈는 0으로 시작

    minHeap->capacity = capacity; // 받은 문자열 크기만큼이 해당 힙의 수용능력

    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
            capacity * sizeof(struct MinHeapNode*)); // 15 * 힙 노드만큼을 동적할당
    return minHeap; // 해당 힙을 반환한다.
}

void swapMinHeapNode(struct MinHeapNode** a,
    struct MinHeapNode** b)//힙의 위치를 바꿔주는 함수 (서로 힙 구성간 교환되어져 변경될때 이용)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// min heap 구성하는 방법 
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx; // 가장 작은값 설정
    int left = 2 * idx + 1; // 왼쪽
    int right = 2 * idx + 2; // 오른쪽

    if (left < minHeap->size && minHeap->array[left]->
        freq < minHeap->array[smallest]->freq) // 기존 시작 값이 왼쪽 값보다 클 때 smallest는 왼쪽 값이 된다.
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
        freq < minHeap->array[smallest]->freq)// 기존 시작 값이 오른쪽 값보다 클 때 smallest는 오른쪽 값이 된다.
        smallest = right;

    if (smallest != idx) {// idx값과 smallest값이 다를경우 해당 노드의 위치를 교환해준다
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest); // 다시 heapify를 통해 minheap을 구성한다
    }
}

int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1); // heap의 크기가 1일떄 1을 반환, 나머지 0
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1]; // minheap의 값을 제거할때 , 가장 작은 값이 삭제되고 끝값이 루트로 온뒤 다시 heapify를 통해 minheap 유지

    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{

    ++minHeap->size; // heap에 존재하는 값 증가
    int i = minHeap->size - 1; //insert는 끝노드에 한다

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { // 부모노드와의 크기 비교 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode; // 자기가 올라갈 수 있는 가장 작은 값까지 올라간다
}

void buildMinHeap(struct MinHeap* minHeap) // min heap 만들기
{

    int n = minHeap->size - 1; //끝값부터 시작해 반씩 줄이며 minheap인지를 확인
    int i;
    for (int i = 0; i < minHeap->size; i++)
    {
        printf("%c ", minHeap->array[i]->data);
    }
    printf("\n");

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

}

void printArr(int arr[], int n) // 허프만 코드를 출력하는 부분
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
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) // minheap을 만드는 과정
{
    struct MinHeap* minHeap = createMinHeap(size);
    
    printf("최소 히프를 루트부터 자손까지 순차적 넘버링과 중위순회 방식으로 출력하면...\n");
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
//디코드함수(디코딩 하고 싶은 문자열, 트리 루트 노드)
void decode(char* str, struct MinHeapNode* root)
{
    int i = 0;
    struct MinHeapNode* j = root;
    while (str[i] != '\0') //문자의 끝이 아닌 경우
    {
        if (str[i] == '0') //문자가 0인 경우
            j = j->left; //왼쪽 자식으로 이동
        else if (str[i] == '1') //문자가 1인 경우
            j = j->right; //오른쪽 자식으로 이동
        if (j->left == NULL && j->right == NULL) //단 노드인 경우
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
    printf("             허프만 트리\n");
    printtrees(root, arr, top, data, freq, size);
    printf("***********************************************\n");
    printf("***********************************************\n");
    printf("             허프만(가변길이) 코드\n");
    printCodes(root, arr, top);
    printf("***********************************************\n\n");

    printf("고정 Bit 표현 저장공간     -> %d Bits\n", total * 4);
    printf("Huffman (가변 Bit) 표현 저장공간 -> %d Bits\n\n", total_compreesion);
    printf("허프만 코드를 출력하고 싶은 문장을 쓰시오.\n");
    char want[MAX] = { NULL };
    scanf("%s", want);
    encode(want, root, encode_arr,0);
    printf("\ndecode : (NULL입력시 종료)");
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
    printf("입력할 문자 개수 : ");
    scanf("%d", &n);
    char* ch = (char*)malloc(sizeof(char) * n);
    int* freq = (int*)malloc(sizeof(int) * n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        printf("문자정보 (end = 0) -> ");
        scanf(" %c", &ch[i]);
        printf("빈도수 정보 -> ");
        scanf("%d",&freq[i]);
        printf("\n");
        total += freq[i];
    }
    printf("문자 개수: %d     문자 빈도수 합: %d\n", n, total);

    HuffmanCodes(ch, freq,n,total);


    return 0;
}
