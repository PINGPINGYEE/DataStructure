#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX];
int n;
int comparePlus = 0;
int movePlus = 0;

void printArray(int list[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", list[i]);
}

void printStep(int step, int compareCount, int moveCount) {
  printf("Step %d:\n", step);
  printf("첫번째 경우에 대한 비교 횟수: %d\n", compareCount);
  printf("첫번째 경우에 대한 이동 횟수: %d\n", moveCount);
  printf("현재 배열: ");
  printArray(list, n);
  printf("\n");
}

// 선택정렬렬
void selectionSort(int list[], int n, int turnTime) {
  int i, j, least, temp;
  int compareCount = 0;
  int moveCount = 0;

  for (i = 0; i < n - 1; i++) {
    least = i;
    for (j = i + 1; j < n; j++) {
      compareCount++; // 비교 횟수 증가
      if (list[j] < list[least]) {
        least = j;
      }
    }

    if (least != i) // 최솟값이 현재 위치와 다른 경우에만 이동 횟수 증가
    {
      SWAP(list[i], list[least], temp);
      moveCount++; // 이동 횟수 증가
    }

    if (turnTime == 1)
      printStep(i + 1, compareCount, moveCount);
  }

  comparePlus += compareCount;
  movePlus += moveCount;
}

//삽입정렬
void insertionSort(int list[], int n, int turnTime) {
  int i, j, key;
  int compareCount = 0;
  int moveCount = 0;

  for (i = 1; i < n; i++) {
    key = list[i];
    for (j = i - 1; j >= 0 && list[j] > key; j--) {
      compareCount++; // 비교 횟수 증가
      list[j + 1] = list[j];
      moveCount++; // 이동 횟수 증가
    }
    list[j + 1] = key;
    moveCount++; // 이동 횟수 증가

    if (turnTime == 1)
      printStep(i, compareCount, moveCount);
  }

  comparePlus += compareCount;
  movePlus += moveCount;
}

//버블 정렬렬
void bubbleSort(int list[], int n, int turnTime) {
  int i, j, temp;
  int compareCount = 0;
  int moveCount = 0;

  for (i = n - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      compareCount++; // 비교 횟수 증가
      if (list[j] > list[j + 1]) {
        SWAP(list[j], list[j + 1], temp);
        moveCount++; // 이동 횟수 증가
      }
    }

    if (turnTime == 1)
      printStep(n - i, compareCount, moveCount);
  }

  comparePlus += compareCount;
  movePlus += moveCount;
}

int main(void) {
  int i, j, choice, turnTime = 0; // turnTime은 첫번째만 출력하기 위함
  n = MAX;
  for (int i = 0; i < n; i++) {
    srand(time(NULL));
    for (i = 0; i < n; i++)
      list[i] = rand() % 100;

    printf("정렬 방법을 선택하세요.\n");
    printf("1. 선택 정렬\n");
    printf("2. 삽입 정렬\n");
    printf("3. 버블 정렬\n");
    printf("선택: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      turnTime = 0;
      comparePlus = 0;
      movePlus = 0;
      for (i = 0; i < 20; i++) {
        turnTime++;
        for (j = 0; j < n; j++)
          list[j] = rand() % 100;
        if (turnTime == 1) {
          printf("Original Array : ");
          printArray(list, n);
          printf("\n");
        }
        selectionSort(list, n, turnTime);
      }
      printf("Selection Sort 평균 비교 횟수: %d\n", comparePlus / 20);
      printf("Selection Sort 평균 이동 횟수: %d\n", movePlus / 20);
      break;
    case 2:
      turnTime = 0;
      comparePlus = 0;
      movePlus = 0;
      for (i = 0; i < 20; i++) {
        turnTime++;
        for (int j = 0; j < n; j++)
          list[j] = rand() % 100;
        if (turnTime == 1) {
          printf("Original Array : ");
          printArray(list, n);
          printf("\n");
        }
        insertionSort(list, n, turnTime);
      }
      printf("평균 비교 횟수 %d", comparePlus / 20);
      printf("\n평균 비교 횟수 %d", movePlus / 20);
      break;
    case 3:
      turnTime = 0;
      comparePlus = 0;
      movePlus = 0;
      for (i = 0; i < 20; i++) {
        turnTime++;
        for (int j = 0; j < n; j++)
          list[j] = rand() % 100;
        if (turnTime == 1) {
          printf("Original Array : ");
          printArray(list, n);
          printf("\n");
        }
        bubbleSort(list, n, turnTime);
      }
      printf("평균 비교 횟수 %d", comparePlus / 20);
      printf("\n평균 비교 횟수 %d", movePlus / 20);
      break;
    default:
      printf("잘못된 선택입니다.\n");
      break;
    }
  }

  return 0;
}
