#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define INF 5000L
int parent[MAX_VERTICES];



// 간선 구조체 정의
typedef struct edge {
    int start;
    int end;
    int weight;
} Edge;

// 그래프 구조체 정의
typedef struct graphType {
    int n; // 노드의 개수
    int numEdges; // 간선의 개수
    Edge edges[2 * MAX_VERTICES];
} GraphType;

// MinHeap 구조체 정의
typedef struct heapType {
    Edge heap[MAX_VERTICES];
    int heapsize;
} HeapType;

// Heap 생성 함수
HeapType* create() {
    return ((HeapType*)malloc(sizeof(HeapType)));
}

// 배열 초기화
void setInit(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

// 합집합의 대표 선정
int setFind(int current) {
    if (parent[current] == -1) return current;
    while (parent[current] != -1) {
        current = parent[current];
    }
    return current;
}

// Union으로 합집합 아니면 합체
void setUnion(int a, int b) {
    int root1 = setFind(a);
    int root2 = setFind(b);
    if (root1 != root2) {
        parent[root2] = root1;
    }
}

// 그래프 초기화
void initGraph(GraphType* g, int n) {
    g->n = n;
    g->numEdges = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

// 간선 관련
void insertEdge(GraphType* g, int start, int end, int weight) {
    int index = g->numEdges++;
    g->edges[index].start = start;
    g->edges[index].end = end;
    g->edges[index].weight = weight;
}

// 비교하는 함수
int compare(const void* a, const void* b) {
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    return (x->weight - y->weight);
}

// Kruskal MST 알고리즘
void kruskalMST(GraphType* g) {
    int edgeAccepted = 0;
    int uSet, vSet;
    Edge e;

    setInit(g->n);
    qsort(g->edges, g->numEdges, sizeof(Edge), compare);

    printf("Kruskal MST Algorithm\n");
    int i = 0;
    while (edgeAccepted < (g->n - 1)) {
        e = g->edges[i];
        uSet = setFind(e.start);
        vSet = setFind(e.end);
        if (uSet != vSet) {
            printf("Edge (%d, %d) Select %d\n", e.start, e.end, e.weight);
            edgeAccepted++;
            setUnion(uSet, vSet);
        }
        i++;
    }
}



// Heap 초기화 함수
void initHeap(HeapType* h) {
    h->heapsize = 0;
}

// Heap 삽입 함수
void insertHeap(HeapType* h, Edge* node) {
    int i = ++h->heapsize;
    while (i != 1 && node->weight < h->heap[i / 2].weight) {
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = *node;
}

// Heap 삭제 함수
Edge deleteHeap(HeapType* h) {
    Edge item, temp;
    int parent = 1, child = 2;
    item = h->heap[1];
    temp = h->heap[h->heapsize--];

    while (child < h->heapsize && temp.weight > h->heap[child].weight) {
        if (h->heap[child].weight > h->heap[child + 1].weight) {
            child++;
        }
        if (temp.weight < h->heap[child].weight) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// Qsort 대신 MinHeap 사용
void kruskalMinHeap(GraphType* g) {
    int edge_accepted = 0;
    int uset, vset;
    Edge e;

    HeapType* h = create();
    initHeap(h);

    setInit(g->n);

    for (int i = 0; i <= g->numEdges; i++) {
        insertHeap(h, &g->edges[i]);
    }

    printf("Kruskal MST Algorith With MinHeap\n");

    while (edge_accepted < (g->n - 1)) {
        e = deleteHeap(h);

        uset = setFind(e.start);
        vset = setFind(e.end);

        if (uset != vset) {
            printf("Edge (%d, %d) Select %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            setUnion(uset, vset);
        }
    }

    free(h);
}


int main() {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    initGraph(g, 10);

    // 그래프 선언
    insertEdge(g, 1, 2, 3);
    insertEdge(g, 1, 6, 11);
    insertEdge(g, 1, 7, 12);
    insertEdge(g, 2, 3, 5);
    insertEdge(g, 2, 4, 4);
    insertEdge(g, 2, 5, 1);
    insertEdge(g, 2, 6, 7);
    insertEdge(g, 2, 7, 8);
    insertEdge(g, 3, 4, 2);
    insertEdge(g, 3, 7, 6);
    insertEdge(g, 3, 8, 5);
    insertEdge(g, 4, 5, 13);
    insertEdge(g, 4, 8, 14);
    insertEdge(g, 4, 10, 16);
    insertEdge(g, 5, 6, 9);
    insertEdge(g, 5, 9, 18);
    insertEdge(g, 5, 10, 17);
    insertEdge(g, 7, 8, 13);
    insertEdge(g, 8, 10, 15);
    insertEdge(g, 9, 10, 10);

    kruskalMST(g);
    printf("\n");
    kruskalMinHeap(g);

    free(g);

    return 0;
}
