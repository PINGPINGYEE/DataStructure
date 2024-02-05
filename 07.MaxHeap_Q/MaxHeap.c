#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200

int cnt = 0;

typedef struct Element
{
	int key;
} element;

typedef struct heapType
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// heap 제작
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// heap 초기화
void init(HeapType* h)
{
	h->heap_size = 0;
}

// heap가 비었는지 확인
int is_empty(HeapType* h)
{
	return (h->heap_size == 0);
}

// heap가 꽉 찼는지 확인
int is_full(HeapType* h)
{
	return(h->heap_size == (MAX_ELEMENT - 1));
}

// 레벨 출력 함수
int print_level_heap(HeapType* h) {
	int k = 1;
	for (int i = 1; i < h->heap_size + 1; i++)
	{

		if (k > h->heap_size) break;
		printf("[%d] ", i);
		for (int j = 0; j < pow(2, i - 1); j++)
		{
			if (k > h->heap_size) break;
			printf("%d ", h->heap[k]);
			k++;
		}

		printf("\n");
	}
}

// 출력 함수
int print_heap(HeapType* h) {
	for (int i = 1; i < h->heap_size + 1; i++)
	{
		printf("%d ", h->heap[i]);
	}
}

// 기본 구성
void basic_insert_heap(HeapType* h, element item)
{
	int i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

// 입력 함수
void insert_heap(HeapType* h, element item) {
	if (is_full(&h))
	{
		printf("heap가 꽉 찼습니다.");
		return;
	}
	int i = ++(h->heap_size);
	cnt = 0;

	while ((i > 1) && item.key > h->heap[i / 2].key) {
		cnt++;
		h->heap[i] = item;
		print_heap(h);
		printf("\n");
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

// 삭제 함수
element delete_heap(HeapType* h)
{
	cnt = 0;
	int parent, child;
	element item, temp;
	if (is_empty(h))
	{
		printf("heap가 비었습니다.");
		return;
	}
	item = h->heap[1]; // 첫 노드로 item 설정
	temp = h->heap[(h->heap_size)--]; // temp를 마지막 노드로 설정
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		cnt++;
		print_heap(h);
		printf("\n");
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++;
		// 자식 노드가 하나일 때 ++안되게, 자식 노드가 두개일 때는 큰 수 인덱스로 child 설정
		if (temp.key >= h->heap[child].key) break; // temp값이 현재 heap값보다 크거나 같으면 break
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 메인 함수
int main()
{
	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 }, e5 = { 75 }, e6 = { 63 },
		e7 = { 65 }, e8 = { 21 }, e9 = { 18 }, e10 = { 15 }, e11 = { 100 };
	HeapType* heap;


	heap = create();
	init(heap);

	basic_insert_heap(heap, e1);
	basic_insert_heap(heap, e2);
	basic_insert_heap(heap, e3);
	basic_insert_heap(heap, e4);
	basic_insert_heap(heap, e5);
	basic_insert_heap(heap, e6);
	basic_insert_heap(heap, e7);
	basic_insert_heap(heap, e8);
	basic_insert_heap(heap, e9);
	basic_insert_heap(heap, e10);

	printf(" ---------------------------------------\n");
	printf("| i : 노드 추가                         | \n");
	printf("| d : 노드 삭제                         | \n");
	printf("| p : 레벨별 출력                       | \n");
	printf("| c : 종료                              | \n");
	printf(" ---------------------------------------\n");

	char choice = ' ';
	element item;

	while(choice != 'q')
	{
		printf("\n메뉴 입력: ");
		scanf_s(" %c", &choice);

		switch (choice)
		{
		case 'i':
			printf("추가할 값 입력: ");
			scanf_s("%d", &item);
			insert_heap(heap, item);
			print_heap(heap);
			printf("\n노드가 이동한 횟수 %d\n", cnt); 
			break;
		case 'd':
			delete_heap(heap);
			print_heap(heap);
			printf("\n노드가 이동한 횟수 %d\n", cnt);
			break;
		case 'p':
			printf("트리 레벨별 출력\n");
			print_level_heap(heap);
			break;
		case 'q':
			break;
		default:
			printf("다시 입력하세요\n");
			continue;
		}
	}

	printf("프로그램을 종료합니다.\n");
	free(heap);
	return 0;
}
