#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
typedef struct Node {
	int value;
	struct Node* next;
} Node;
Node* create(int data)
{
	// Выделение памяти под корень списка
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
	return(tmp);
}
Node* pushStart(int data, Node* head)
{

	Node* tmp = create(data);
	// Присваивание указателю на следующий элемент значения указателя на «голову» 
	// первоначального списка
	tmp->next = head;
	return(tmp);
}
int main() {
	srand(22341);
	int size = 0;
	int w;
	int max = 0;
	int min = 0;
	scanf("%d", &size);
	w = size;
	int** mas;
	int** nas;
	mas = (int**)malloc(sizeof(int*) * size);
	nas = (int**)malloc(sizeof(int*) * size);
	Node** sps;
	Node** last;
	Node** deleted;
	Node* tmp;
	deleted = (Node**)malloc(sizeof(Node*) * size);
	sps = (Node**)malloc(sizeof(Node*) * size);
	last = (Node**)malloc(sizeof(Node*) * size);
	int size1 = size;
	int i = 0;
	int j = 0;
	int s = 0;
	setlocale(LC_ALL, "");

	while (size1 > i) {
		j = 0;
		sps[i] = create(i);
		last[i] = sps[i];
		mas[i] = (int*)malloc(sizeof(int) * w);
		nas[i] = (int*)malloc(sizeof(int) * w);
		while (w > j) {

			mas[i][j] = 0;
			nas[i][j] = 0;
			j++;
		}



		i++;
	}
	i = 0;
	j = 0;
	bool fl = true;
	int h = 0;
	while (size1 > i) {
		j = i;
		while (w > j) {
			if (i == j) {
				mas[i][j] = 0;
				nas[i][j] = 0;
			}
			else {
				mas[i][j] = rand() % 2;
				nas[i][j] = rand() % 2;
				mas[j][i] = mas[i][j];
				nas[j][i] = nas[i][j];
			}
			j++;

		}
		i++;

	}
	i = 0;
	j = 0;
	while (size1 > i) {
		j = 0;
		while (w > j) {
			if (mas[i][j] == 1) {
				if (fl) {
					last[i] = pushStart(j + 1, NULL);
					fl = false;
				}
				else {
					last[i] = pushStart(j + 1, last[i]);
				}
			}
			j++;
		}
		i++;
		fl = true;
	}


	for (int i = 0; i < size1; i++) {
		sps[i] = last[i];
	}
	for (int i = 0; i < size1; i++) {
		printf("%d\t", i + 1);
		while (last[i] != NULL) {
			printf("%d\t", last[i]->value);
			last[i] = last[i]->next;
		}
		printf("\n");
	}



	printf("\t");
	for (int o = 0; o < size; o++) {
		printf("%d\t", o + 1);
	}
	printf("\n");
	for (int o = 0; o < size; o++) {
		printf("%d\t", o + 1);
		for (int n = 0; n < w; n++) {
			printf("%d\t", mas[o][n]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\t");

	for (int o = 0; o < size; o++) {
		printf("%d\t", o + 1);
	}
	printf("\n");
	for (int o = 0; o < size; o++) {
		printf("%d\t", o + 1);
		for (int n = 0; n < w; n++) {
			printf("%d\t", nas[o][n]);
		}
		printf("\n");
	}
	//матричное представление
	printf("Отождествление вершины юху\n");
	int a;
	int b;

	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b) {
		min = b - 1;
		max = a - 1;
	}
	else {
		min = a - 1;
		max = b - 1;
	}
	bool flag = false;
	if (mas[min][max] == 1) {
		flag = true;
	}

	for (int n = 0; n < w; n++) {
		mas[min][n] = mas[min][n] | mas[max][n];

	}
	while (max + 1 < size - 1) {
		for (int o = min; o < size; o++) {
			mas[o][max] = mas[o][max + 1];
		}
		max++;
	}
	for (int o = 0; o < size; o++) {
		for (int n = 0; n < w; n++) {
			mas[n][o] = mas[o][n];
			if (n == o) {
				mas[o][n] = 0;
			}
		}
	}
	if (flag) {
		mas[min][min] = 1;
	}
	int g = 1;
	printf("\t");
	for (int o = 0; o < size - g; o++) {
		printf("%d\t", o + 1);
	}
	printf("\n");
	for (int o = 0; o < size - g; o++) {
		printf("%d\t", o + 1);
		for (int n = 0; n < w - g; n++) {
			printf("%d\t", mas[o][n]);
		}
		printf("\n");
	}
	printf("Стягивание ребра юху\n");


	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b) {
		min = b - 1;
		max = a - 1;
	}
	else {
		min = a - 1;
		max = b - 1;
	}
	if (mas[min][max] == 1) {

		for (int n = 0; n < w; n++) {
			mas[min][n] = mas[min][n] | mas[max][n];
		}
		while (max + 1 < size) {
			for (int o = 0; o < size; o++) {
				mas[max][o] = mas[max + 1][o];
			}
			max++;
		}
		for (int o = 0; o < size; o++) {
			for (int n = 0; n < w; n++) {
				mas[o][n] = mas[n][o];
				if (n == o) {
					mas[o][n] = 0;
				}
			}
		}
		g++;
		printf("\t");
		for (int o = 0; o < size - g; o++) {
			printf("%d\t", o + 1);
		}
		printf("\n");
		for (int o = 0; o < size - g; o++) {
			printf("%d\t", o + 1);
			for (int n = 0; n < w - g; n++) {
				printf("%d\t", mas[o][n]);
			}
			printf("\n");
		}
	}
	else {
		printf("Операция невозможна\n");
	}
	printf("Расщепление вершины юху\n");
	scanf("%d", &a);
	a--;
	for (int n = 0; n < w; n++) {
		mas[size - g][n] = mas[a][n];
	}

	mas[size - g][a] = 1;
	for (int o = 0; o < size; o++) {
		for (int n = 0; n < w; n++) {
			mas[o][n] = mas[n][o];
		}
	}
	mas[size - g][size - g] = 0;
	printf("\t");
	g--;
	for (int o = 0; o < size - g; o++) {
		printf("%d\t", o + 1);
	}
	printf("\n");
	for (int o = 0; o < size - g; o++) {
		printf("%d\t", o + 1);
		for (int n = 0; n < w - g; n++) {
			printf("%d\t", mas[o][n]);
		}
		printf("\n");
	}
	//списковое представление
	printf("Отождествление вершины юху feat. spiski\n");
	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b) {
		min = b - 1;
		max = a - 1;
	}
	else {
		min = a - 1;
		max = b - 1;
	}
	int del = 0;
	deleted[del] = sps[max];
	last[min] = sps[min];
	last[max] = sps[max];
	flag = false;
	while (last[min] != NULL) {
		
		if ((last[max]->next)->value == last[min]->value) {
			tmp = last[max]->next;
			last[max]->next = last[max]->next->next;
			free(tmp);
			break;
		}
		last[min] = last[min]->next;
	}

		last[min]->next = last[max];


	for (int i = 0; i < size1; i++) {
		last[i] = sps[i];
	}
	for (int i = 0; i < size1; i++) {
		if (last[i] != deleted[del]) {
			printf("%d\t", i + 1);
			while (last[i] != NULL) {

				printf("%d\t", last[i]->value);

				last[i] = last[i]->next;
			}
			printf("\n");
		}
	}

	printf("Расщепление вершины юху feat. spiski\n");
	scanf("%d", &a);
	a--;
	tmp = create(1);
	last[a]=sps[a];
	while (last[a]->next != NULL) {
		last[a] = last[a]->next;
	}
	last[a]->next=tmp;
	sps[a+1]=sps[a];

	printf("\n");
	
	

	for (int i = 0; i < size1; i++) {
		last[i] = sps[i];
	}
	for (int i = 0; i < size1; i++) {

		printf("%d\t", i + 1);
		while (last[i] != NULL) {
			if(last[i]->value==i+1){
				printf("%d\t", last[i]->value+1);
			}else{
			printf("%d\t", last[i]->value);
			}
			last[i] = last[i]->next;
		}
		printf("\n");

	}
}