#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Vector {
	int size, capacity;
	int* data;
};

void init(struct Vector* vector) {
	vector->size = 0;
	vector->capacity = 1;
	vector->data = malloc(sizeof(int));
}

void append(struct Vector* vector, int toAdd) {
	if (vector->size == vector->capacity) {
		int* newData = malloc(2 * vector->capacity * sizeof(int));
		memcpy(newData, vector->data, vector->size * sizeof(int));
		free(vector->data);
		vector->data = newData;
		vector->capacity *= 2;
	}
	vector->data[vector->size++] = toAdd;
}


int main() {
	
	int N, Q, i, j, x;
	int T;


	static struct Vector vectors[100000];
	scanf("%d", &N);

	for (int i = 0; i<N; i++) {
		int l;
		scanf("%d", &l);

		init(&vectors[i]);
		for (int j = 0; j<l; j++) {
			int x;
			scanf("%d", &x);
			append(&vectors[i], x);
		}
	}

	scanf("%d", &Q);

	for (int var = 0; var < Q; var++) {
		scanf("%d", &T);

		if (T == 1) {
			scanf("%d %d", &i, &j);
			printf("%d\n", vectors[i - 1].data[j - 1]);
		}
		else {
			scanf("%d %d", &i, &x);
			append(&vectors[i - 1], x);
		}
	}

	return 0;
}