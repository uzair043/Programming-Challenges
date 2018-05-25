#include<stdlib.h>
#include<stdio.h>

struct Node {
	struct Node *prev, *next;
	int value;
};

struct List {
	struct Node *first, *last;
};

struct Node* insert(struct List* list, struct Node* pos, int toAdd) {
	struct Node* cur = malloc(sizeof(struct Node));
	cur->prev = pos; cur->value = toAdd;
	if (cur->prev == 0) {
		cur->next = list->first;
		list->first = cur;
	}
	else {
		cur->next = cur->prev->next;
		cur->prev->next = cur;
	}
	if (cur->next == 0)
		list->last = cur;
	else
		cur->next->prev = cur;
	return cur;
}


int main() {

	int N, val;
	
	struct List list = { 0, 0 };
	static struct Node *element[200001];
	
	element[0] = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &val);
		element[i] = insert(&list, element[val], i);
	}

	for (struct Node* cur = list.first; cur != 0; cur = cur->next)
		printf("%d ", cur->value);
	printf("\n");

	return 0;
}

