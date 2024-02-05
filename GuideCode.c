#include <stdio.h>

void ChoiceActivity();
void FuncDef();

int main() {
	int choice;

	printf("C언어로 학습한 자료구조입니다.");
	printf("\n각각의 학습 내용들은 BRANCHE에 저장되어 있습니다.");
	while (1) {
		printf("\n\n--------BRANCHE 위치 보기 --------");
		printf("\n1. TREE");
		printf("\n2. GRAPH");
		printf("\n3. SORT");
		printf("\n4. EXIT");
		printf("\n번호를 입력하세요: ");
		scanf("%d", &choice);
		if (choice == 4) { printf("종료하겠습니다."); break; }
		ChoiceActivity(choice);
	}
}

void FuncDef() {
	void PrintTreeMention();
	void PrintGraphMention();
	void PrintSortMention();
}

void ChoiceActivity(int choice) {
	switch (choice) {
	case 1:
		PrintTreeMention();
		break;
	case 2:
		PrintGraphMention();
		break;
	case 3:
		PrintSortMention();
		break;
	default:
		printf("잘못된 값을 입력하셨습니다.");
	}
}

void PrintTreeMention() {
	printf("Tree는 계층적 관계를 표현하는 비선형 자료구조입니다.");
	printf("\n노드로 구성되며, 하나의 루트 노드에서 시작해 여러 자식 노드가 분기되는 구조를 가집니다.");
	printf("\n각 노드는 자식 노드를 가질 수 있으며, 노드 간에는 부모-자식 관계가 성립합니다.");
	printf("\n트리 구조에서는 사이클이 존재할 수 없으며, 어떤 두 노드 간에도 정확히 하나의 경로만 존재합니다.");
}

void PrintGraphMention() {
	printf("Graph는 정점들과 이들을 연결하는 간선의 집합으로 구성된 추상 자료형입니다.");
	printf("\n그래프는 방향성이 있는 방향 그래프와 방향성이 없는 무방향 그래프로 나뉩니다.");
	printf("\n그래프는 사이클을 포함할 수 있으며, 노드 간에 다수의 경로가 존재할 수 있습니다.");
}

void PrintSortMention() {
	printf("Sort는 데이터 요소들을 특정 순서대로 나열하는 처리 과정입니다.");
	printf("\n정렬 방식에 따라 여러 알고리즘이 있으며 각각은 다른 장단점을 가집니다.");
}
