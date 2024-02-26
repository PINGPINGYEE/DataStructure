#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int thread;
}TreeNode;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;
	if (q == NULL || p->thread == 1)
		return q;

	while (q->left != NULL)
		q = q->left;
	return q;
}

// 중위 순회
void inorder_thread(TreeNode* t)
{
	TreeNode* q = t;
	while (q->left) q = q->left;
	do {
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}



// 선언
TreeNode n1 = { 4, NULL, NULL, 1 };
TreeNode n3 = { 5, NULL, NULL, 1 };
TreeNode n2 = { 3, &n1, &n3, 0 };
TreeNode n4 = { 6, NULL, NULL, 1 };
TreeNode n5 = { 2, &n2, &n4, 0 };
TreeNode n6 = { 10, NULL, NULL, 1 };
TreeNode n7 = { 11, NULL, NULL, 1 };
TreeNode n8 = { 9, &n6, &n7, 0 };
TreeNode n9 = { 8, NULL, NULL,1 };
TreeNode n10 = { 7, &n9, &n8, 0 };
TreeNode n11 = { 1, &n5, &n10, 0 };
TreeNode* ThreadTree = &n11;

// 부모 찾는 함수
TreeNode* parent(TreeNode* child) {
	TreeNode* q = child->right;
	TreeNode* qptr = q->left;
	if (ThreadTree == NULL || ThreadTree == child) {
		return NULL;
	}

	if (q == NULL)
		return;

	else if (q->left == child || q->right == child) {
		// printf("%d \n", q->data);
		return q;
	}

	else if (qptr->left == child || qptr->right == child) {
		// printf("%d \n", qptr->data);
		return qptr;
	}

	else {
		exit(1);
	}
}



int main()
{
	n1.right = &n2;
	n3.right = &n5;
	n4.right = &n11;
	n6.right = &n8;
	n9.right = &n10;
	// 중위순회
	printf("1. 중위 순회 결과\n");
	inorder_thread(ThreadTree);

	// 부모 찾는 순회
	int value4 = parent(&n1)->data;
	int value5 = parent(&n3)->data;
	int value6 = parent(&n4)->data;
	printf("\n\n2. Node 4의 부모: %d", value4);
	printf("\n3. Node 5의 부모: %d", value5);
	printf("\n4. Node 6의 부모: %d", value6);
	printf("\n");
	return 0;
}
