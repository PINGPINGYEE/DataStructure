#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;
} QueType;

void init_que(QueType* q)
{
	q->front = q->rear = 0;
}

element is_empty(QueType* q)
{
	return (q->front == q->rear);
}

element is_full(QueType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

void que_print(QueType* q)
{
	printf("QUE(front=%d rear =%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


void enque(QueType* q, element item)
{
	if (is_full(q))
	{
		fprintf(stderr, "FULL!");
		return;

	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;

}

element deque(QueType* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "EMPTY!");
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

int main(void)

{
	QueType que;

	init_que(&que);

	int n;
	int qVal;
	int dqVal;

	while (1)
	{
		printf("==MENU==\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Select : ");
		scanf_s("%d", &n);

		if (n == 1)
		{
			if (!is_full(&que))
			{
				printf("Input data : ");
				scanf_s("%d", &qVal);
				enque(&que, qVal);
				printf("Data : %d\n", qVal);
			}
			else
			{
				printf("FULL!\n");
			}
		}
		else if (n == 2)
		{
			if (!is_empty(&que))
			{
				dqVal = deque(&que);
				printf("Data : %d\n", dqVal);
			}
			else
			{
				printf("EMPTY!\n");
			}
		}
		else if (n == 3)
		{
			que_print(&que);
		}
		else if (n == 4)
		{
			printf("Exit!");
			exit(1);
		}
		else
		{
			printf("WRONG NUMBER!\n");
		}
	}
}
