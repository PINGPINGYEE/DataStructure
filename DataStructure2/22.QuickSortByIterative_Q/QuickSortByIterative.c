#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define STACK_SIZE 1000

int move_count = 0;
int compare_count = 0;

#define SWAP(x, y, t) (move_count++, (t)=(x), (x)=(y), (y)=(t))

typedef struct {
    int left;
    int right;
} Range;

int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do { low++; compare_count++; } while (low <= right && list[low] < pivot);
        do { high--; compare_count++; } while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}

// stack을 이용하여 반복적으로 quicksort 구현
void iterative_quick_sort(int list[], int left, int right, int isFirst) {
    Range stack[STACK_SIZE];
    int top = -1;
    Range r;

    stack[++top] = (Range){ left, right };

    while (top >= 0) {
        r = stack[top--];

        if (r.left < r.right) {
            int q = partition(list, r.left, r.right);

            // 각 파티션 작업 후 배열 상태 출력
            if (isFirst) {
                printf("Partitioning : ");
                for (int i = 0; i < MAX_SIZE; i++) {
                    printf("%d ", list[i]);
                }
                printf("\n");
            }

            // 오른쪽 파티션을 먼저 스택에 푸시
            if (q + 1 < r.right) stack[++top] = (Range){ q + 1, r.right };
            // 왼쪽 파티션을 스택에 푸시
            if (r.left < q - 1) stack[++top] = (Range){ r.left, q - 1 };
        }
    }
}


// main 함수
int main(void) {
    int list[MAX_SIZE];
    int n = MAX_SIZE;
    srand(time(NULL));
    int total_move_count = 0;
    int total_compare_count = 0;

    for (int j = 0; j < 20; j++) {
        move_count = compare_count = 0;

        for (int i = 0; i < n; i++) {
            list[i] = rand() % 100;
        }

        if (j == 0) {
            printf("Original : ");
            for (int i = 0; i < n; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
        }

        iterative_quick_sort(list, 0, n - 1, j == 0);


        total_move_count += move_count;
        total_compare_count += compare_count;
    }

    printf("평균 이동 횟수: %.0f\n", (double)total_move_count / 20);
    printf("평균 비교 횟수: %.0f\n", (double)total_compare_count / 20);

    return 0;
}
