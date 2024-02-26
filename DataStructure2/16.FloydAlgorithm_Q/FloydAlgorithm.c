#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define INF 5000

// 그래프 선언
typedef struct graphType {
  int n;
  int weight[MAX_VERTICES][MAX_VERTICES]
} GraphType;


int A[MAX_VERTICES][MAX_VERTICES]; // D[i][j]는 최소 거리를 저장
int P[MAX_VERTICES][MAX_VERTICES]; // P[i][j]는 거치는 최고 차수 정점을 저장

// 플로이드 알고리즘
void Floyd(GraphType *g) {
  int i, j, k;
  for (i = 0; i < g->n; i++) // 배열 초기화
    for (j = 0; j < g->n; j++) {
      P[i][j] = -1;
      A[i][j] = g->weight[i][j];
    }
  for (k = 0; k < g->n; k++)
    for (i = 0; i < g->n; i++)
      for (j = 0; j < g->n; j++)
        if (A[i][j] > A[i][k] + A[k][j]) {
          A[i][j] = A[i][k] + A[k][j];
          P[i][j] = k;
        }
}

// 경로 출력
void Print_Path(int a, int b) {
  if (P[a][b] != -1) { // a에서 바로 b로 가는 것이 최단거리
    Print_Path(a, P[a][b]);
    int value = P[a][b];
    printf("%d ", value+1);
    Print_Path(P[a][b], b);
  }
}

int main() {
  int number;


  while (1) {
    printf("종료 하시려면 1을 누르세요. 계속 하시려면 아무 숫자나 누르세요.");
    scanf("%d", &number);
    if(number == 1) break;

    // 그래프 제작
    GraphType g = {
      10, {
      { 0, 3, INF, INF, INF, 11, 12, INF, INF, INF }, // 1
      { 3, 0, 5, 4, 1, 7, 8, INF, INF, INF }, // 2
      { INF, 5, 0, 2, INF, INF, 6, 5, INF, INF }, // 3
      { INF, 4, 2, 0, 13, INF, INF, 14, INF, 16 }, // 4
      { INF, 1, INF, 13, 0, 9, INF, INF, 18, 17 }, // 5
      { 11, 7, INF, INF, 9, 0, INF, INF, INF, INF }, // 6
      { 12, 8, 6, INF, INF, INF, 0, 13, INF, INF }, // 7
      { INF, INF, 5, 14, INF, INF, 13, 0, INF, 15 }, // 8
      { INF, INF, INF, INF, 18, INF, INF, INF, 0, 10 }, // 9
      { INF, INF, INF, 16, 17, INF, INF, 15, 10, 0 } // 10
      }
    };

    Floyd(&g);
    int a, b;


    printf("출발점을 입력하세오. (1 ~ %d)\n", MAX_VERTICES);
    scanf("%d", &a);
    printf("도착점을 입력하세오. (1 ~ %d)\n", MAX_VERTICES);
    scanf("%d", &b);
    printf("최단거리 : %d\n", A[a - 1][b - 1]);
    printf("최단경로 : ");
    printf("%d ", a); Print_Path(a-1, b-1);
    if (A[a][b] != 0) printf("%d", b);
    printf("\n\n");
    }
  return 0;
}
