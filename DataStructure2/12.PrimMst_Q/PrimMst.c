#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
  int n;	// 정점의 개수
  int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치에 대한 이중배열 생성 -> 인접행렬
} GraphType;

int selected[MAX_VERTICES]; // 선택되엇는지 확인할 배열
int distance[MAX_VERTICES]; // 가중치를 기록할 배열


// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
  int v, i;
  for (i = 0; i < n; i++)
    if (!selected[i]) {
      v = i;
      break;
    }
  for (i = 0; i < n; i++)
    if (!selected[i] && (distance[i] < distance[v])) v = i; // v가 최솟값을 가짐
  return (v);
}

// prim 알고리즘
void prim(GraphType* g, int s)
{
  int i, u, v;

  for (u = 0; u < g->n; u++)
    distance[u] = INF;
  distance[s] = 0;
  for (i = 0; i < g->n; i++) {
    u = get_min_vertex(g->n); // 배열에서 최솟값 찾기
    selected[u] = TRUE;
    if (distance[u] == INF) return;
    printf("정점 %d 추가\n", u+1); // 출력
    for (v = 0; v < g->n; v++)
      if (g->weight[u][v] != INF)
        if (!selected[v] && g->weight[u][v] < distance[v])
          distance[v] = g->weight[u][v];
  }
}


int main(void)
{
  // 그래프 선언 및 제작
  GraphType g = { 10, // 노드의 개수
    { 
      { 0, 3, INF, INF, INF, 11, 12, INF, INF, INF }, // 1
      { 3, 0, 5, 4, 1, 7, 8, INF, INF, INF }, // 2
      { INF, 5, 0, 2, INF, INF, 6, 5, INF, INF }, // 3
      { INF, 4, 2, 0, 13, INF, INF, 14, INF, INF }, // 4
      { INF, 1, INF, 13, 0, 9, INF, INF, INF, 17 }, // 5
      { 11, 7, INF, INF, 9, 0, INF, INF, INF, INF }, // 6
      { 12, 8, 6, INF, INF, INF, 0, 13, INF, INF }, // 7
      { INF, INF, 5, 14, INF, INF, 13, 0, INF, 15 }, // 8
      { INF, INF, INF, INF, INF, INF, INF, INF, 0, 10 }, // 9
      { INF, INF, INF, INF, 17, INF, INF, 15, 10, 0 } // 10
    }
  };

  prim(&g, 0);
  return 0;
}
