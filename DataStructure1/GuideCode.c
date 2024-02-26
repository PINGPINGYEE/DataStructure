#include <stdio.h>

void ChoiceActivity();
void FuncDef();

int main() {
	int choice;

	printf("C언어로 학습한 자료구조입니다.");
	printf("\n각각의 학습 내용들은 BRANCHE에 저장되어 있습니다.");
	while (1) {
		printf("\n\n--------BRANCHE 위치 보기 --------");
		printf("\n1. STACK");
		printf("\n2. QUEUE");
		printf("\n3. LIST");
		printf("\n4. EXIT");
		printf("\n번호를 입력하세요: ");
		scanf("%d", &choice);
		if (choice == 4) { printf("종료하겠습니다."); break; }
		ChoiceActivity(choice);
	}
}

void FuncDef() {
	void PrintStackMention();
	void PrintQueueMention();
	void PrintListMention();
}

void ChoiceActivity(int choice) {
	switch (choice) {
	case 1:
		PrintStackMention();
		break;
	case 2:
		PrintQueueMention();
		break;
	case 3:
		PrintListMention();
		break;
	default:
		printf("잘못된 값을 입력하셨습니다.");
	}
}

void PrintStackMention() {
	printf("Stack은 마지막에 들어온 데이터가 가장 먼저 나가는 FILO(First In, Last Out) 원칙을 따릅니다.");
	printf("\n값을 삽입하는 \'push\', 삭제하는 \'pop\', 마지막 데이터의 index를 나타내는 \'top\' 등의 변수가 사용됩니다.");
}

void PrintQueueMention() {
	printf("Queue는 첫 번째로 들어온 데이터가 가장 먼저 나가는 FIFO(First In, First Out) 원칙을 따릅니다.");
	printf("\n값을 삽입하는 \'enqueue\', 삭제하는 \'dequeue\', 첫 데이터의 index를 나타내는 \'front\', 마지막 데이터의 index를 나타내는 \'rear\' 등의 변수가 사용됩니다.");
}

void PrintListMention() {
	printf("List, 그 중에서도 LinkedList는 데이터 노드의 집합에서 각 요소가 다음 요소를 가리키는 참조를 포함하여 선형적으로 연결된 구조를 뜻합니다.");
	printf("\n이러한 방식으로 데이터를 저장함으로써, 배열과는 동적으로 데이터를 관리할 수 있습니다.");
}
