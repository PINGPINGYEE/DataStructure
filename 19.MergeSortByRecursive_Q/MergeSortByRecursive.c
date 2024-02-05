#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y) =(t))
int total_comparisons = 0;  // 총 비교 횟수
int total_moves = 0;        // 총 이동 횟수
int run_count = 0;          // 실행 횟수

int sorted[MAX_SIZE]; // 추가적인 공간이 필요
void merge(int list[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, l;

    while (i <= mid && j <= right) {
        total_comparisons++; // 비교 횟수 증가
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
        total_moves++; // 이동 횟수 증가
    }

    if (i > mid) {
        for (l = j; l <= right; l++, k++) {
            sorted[k] = list[l];
            total_moves++; // 이동 횟수 증가
        }
    }
    else {
        for (l = i; l <= mid; l++, k++) {
            sorted[k] = list[l];
            total_moves++; // 이동 횟수 증가
        }
    }

    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }

    if (run_count == 1) { // 첫 번째 실행에서만 전체 배열 출력
        printf("Current Array: ");
        for (int i = 0; i < MAX_SIZE; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

void merge_sort(int list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    int cycleCount = 0;
    int i, n = MAX_SIZE;
    int list[MAX_SIZE];

    srand(time(NULL)); // 랜덤 시드 설정

    for (run_count = 1; run_count <= 20; run_count++) {
        cycleCount++;
        for (i = 0; i < MAX_SIZE; i++) {
            list[i] = rand() % 100;
        }
        if (cycleCount == 1) {
            printf("Origin list : ");
            for (i = 0; i < MAX_SIZE; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
        }

        merge_sort(list, 0, n - 1);
    }
    printf("Average Move Count: %d\n", total_moves / 20);
    printf("Average Comparison Count: %d\n", total_comparisons / 20);


    return 0;
}
