#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct
{
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
	{
		printf("error!");
		return -1;
	}
	else return L->array[pos];
}

void insert(ArrayListType* L, int pos, element item)
{

	int cnt = 0;

	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
			cnt++;
		}
		L->array[pos] = item;
		L->size++;
	}
	printf("\nMOVE : %d\n\n", cnt);
}

element deleting(ArrayListType* L, int pos)
{
	element item;
	int dcnt = 0;
	
	if (is_empty(L) || pos < 0 || pos >= L->size)
	{
		printf("error");
		return -1;
	}
	else
	{
		item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++)
		{
			L->array[i] = L->array[i + 1];
			dcnt++;
		}
		L->size--;
		printf("\nMOVE : %d\n", dcnt);
		printf("DELETE : %d\n\n", item);
		return item;
		
	}
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
	{
		printf("%d->", L->array[i]);
		
	}
	printf("\n");
}

int main()
{
	int menubar, value, position;
	ArrayListType L;
	init(&L);



	while (1)
	{
		printf("\nMenu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &menubar);
		if (menubar == 1)
		{
			resetgoto:
				printf("Enter the number and position: ");
				scanf_s("%d %d", &value, &position);
			if (is_empty(&L) && position != 0)
			{
				printf("List Size is Zero. Please enter again\n");
				goto resetgoto;
			}
			else
			{
				insert(&L, position, value);
			}
			
		}
		else if (menubar == 2)
		{
			if (is_empty(&L))
			{
				printf("List is empty\n");
	
			}
			else
			{
				printf("Enter the position: ");
				scanf_s("%d", &position);
				deleting(&L, position);
			}
		}
		else if (menubar == 3)
		{
			print_list(&L);
		}
		else if (menubar == 0)
		{
			printf("Exit the program.\n");
			break;
		}
		else
		{
			printf("Wrong Number.\n");
		}
	}
}
