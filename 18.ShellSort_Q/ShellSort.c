#include <stdio.h>
#include <stdlib.h> // srand 및 rand 함수를 위한 헤더
#include <time.h>   // time 함수를 위한 헤더
#define MAX_SIZE 20

int total_comparisons = 0;  // 총 비교 횟수
int total_moves = 0;        // 총 이동 횟수
int run_count = 0;          // 실행 횟수

// gap만큼 떨어진 요소들을 삽입 정렬
void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        int moved = 0; // 값의 이동 여부를 확인하기 위한 변수
        for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
            list[j + gap] = list[j];
            total_comparisons++; // 비교 횟수 증가
            moved = 1;        // 값이 이동했음을 표시
            total_moves++;   // 값이 실제로 이동했다면 이동 횟수 증가
        }
        list[j + gap] = key;
        if (moved) {
            total_moves++;   // 값이 실제로 이동했다면 이동 횟수 증가
        }
    }
}


// 셸 정렬
void shell_sort(int list[], int n) {
    int i, gap;
    if(run_count == 1) {
      printf("Original List\n");
      for (i = 0; i < n; i++) {
          printf("%d ", list[i]);
      }
      printf("\n\n");
      printf("Shell Sort\n");
    }
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        if (run_count == 1) {
            printf("When gap is %d: ", gap);
            for (i = 0; i < n; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
        }
        for (i = 0; i < gap; i++) {
            inc_insertion_sort(list, i, n - 1, gap);
        }
    }
}


int main() {
    int i, n = MAX_SIZE;
    int list[MAX_SIZE];

    // srand를 사용하여 랜덤 시드 초기화
    srand(time(NULL));

    // 20번의 셸 정렬 실행
    for (run_count = 1; run_count <= 20; run_count++) {
        // 리스트를 랜덤 값으로 초기화
        for (i = 0; i < MAX_SIZE; i++) {
            list[i] = rand() % 100;
        }

        // 셸 정렬 수행
        shell_sort(list, n);

        // 첫 번째 실행의 결과만 출력
        if (run_count == 1) {
            printf("Shell sort:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", list[i]);
            }
        }
    }

    // 평균 비교 및 이동 횟수 출력
    printf("\n\n");
    printf("Average Move Count: %d\n", total_moves / 20);
    printf("Average Compare Count: %d\n", total_comparisons / 20);

    return 0;
}
