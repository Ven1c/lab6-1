#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main() {
srand(353415);
int size = 0;
int sizeO = 0;
int w;
int max = 0;
int min = 0;
scanf("%d", &size);
scanf("%d", &sizeO);
w = size;
int** mas;
int** nas;
int** pas;
int** ob;
int** per;
int** col;
int** dec;
mas = (int**)malloc(sizeof(int*) * size);
nas = (int**)malloc(sizeof(int*) * size);
pas = (int**)malloc(sizeof(int*) * sizeO);
ob = (int**)malloc(sizeof(int*) * size);
per = (int**)malloc(sizeof(int*) * size);
col = (int**)malloc(sizeof(int*) * size);
dec = (int**)malloc(sizeof(int*) * size * sizeO);

int size1 = size;
int size2 = size*sizeO;
int i = 0;
int j = 0;
int s = 0;
setlocale(LC_ALL, "");

for(int i=0;size2>i;i++){
	j = 0;
	dec[i] = (int*)malloc(sizeof(int) * size2);
	for(int j=0;size2>j;j++){
		dec[i][j]=0;
}
}
while (sizeO > i) {
j = 0;
pas[i] = (int*)malloc(sizeof(int) * sizeO);

while (sizeO > j) {

pas[i][j] = 0;

j++;
}
i++;
}
i = 0;
j = 0;
int h = 0;
while (sizeO > i) {
j = i;
while (sizeO > j) {
if (i == j) {
pas[i][j] = 0;
}
else {
pas[i][j] = rand() % 2;
pas[j][i] = pas[i][j];
}
j++;
}
i++;
}
i=0;
while (size1 > i) {
j = 0;
mas[i] = (int*)malloc(sizeof(int) * w);
nas[i] = (int*)malloc(sizeof(int) * w);
ob[i] = (int*)malloc(sizeof(int) * w);
per[i] = (int*)malloc(sizeof(int) * w);
col[i] = (int*)malloc(sizeof(int) * w);

while (w > j) {

mas[i][j] = 0;
nas[i][j] = 0;
ob[i][j] = 0;
per[i][j] = 0;
col[i][j] = 0;
j++;
}
i++;
}
i = 0;
j = 0;
while (size1 > i) {
j = i;
while (w > j) {
if (i == j) {
mas[i][j] = 0;
nas[i][j] = 0;
}
else {
mas[i][j] = rand() % 2;
mas[j][i] = mas[i][j];
nas[i][j] = rand() % 2;
nas[j][i] = nas[i][j];

}
j++;
}
i++;
}
for (int i=0;size1 > i;i++) {
for (int j = 0;w > j;j++) {
if (mas[i][j] == 0 && nas[i][j] == 0) {
ob[i][j] = 0;
}
else { ob[i][j] = 1;
}
}
}

for (int i = 0;size1 > i;i++) {
for (int j = 0;w > j;j++) {
if (mas[i][j] == 1 && nas[i][j] == 1) {
per[i][j] = 1;
}
else {
per[i][j] = 0;
}
}
}
for (int i = 0;size1 > i;i++) {
for (int j = 0;w > j;j++) {
if ((mas[i][j]==1 && nas[i][j]==1)||(mas[i][j] == 0 && nas[i][j] == 0)) {
col[i][j] = 0;
}
else {
col[i][j] = 1;
}
}
}
int v1=0;
int v2=0;
for(int i=0;size>i;i++){
	for(int j=0;sizeO>j;j++){
		for(int k=0;size>k;k++){
			for(int l=0;sizeO>l;l++){
				if (i==k){
				dec[v1][v2]=pas[j][l];
				}
				if(j==l){
				dec[v1][v2]=mas[i][k];
				}
				v2++;
}
			
}
		v2=0;
		v1++;
}
	
}


printf("Первая матирца\n");
for (int o = 0; o < size; o++) {
for (int n = 0; n < w; n++) {
printf("%d\t", mas[o][n]);
}
printf("\n");
}
printf("\n");
printf("Вторая матирца\n");
for (int o = 0; o < size; o++) {
for (int n = 0; n < w; n++) {
printf("%d\t", nas[o][n]);
}
printf("\n");
}
printf("Третья матирца\n");
for (int o = 0; o < sizeO; o++) {
for (int n = 0; n < sizeO; n++) {
printf("%d\t", pas[o][n]);
}
printf("\n");
}
printf("\n");
printf("Матирца объединения \n");
for (int o = 0; o < size; o++) {
for (int n = 0; n < w; n++) {
printf("%d\t", ob[o][n]);
}
printf("\n");
}
printf("Матирца пересечения \n");
for (int o = 0; o < size; o++) {
for (int n = 0; n < w; n++) {
printf("%d\t", per[o][n]);
}
printf("\n");
}
printf("Матирца кольцевой суммы \n");
for (int o = 0; o < size; o++) {
for (int n = 0; n < w; n++) {
printf("%d\t", col[o][n]);
}
printf("\n");
}
printf("\n");
printf("Матирца декартового произведения \n");
for (int o = 0; o < size2; o++) {
for (int n = 0; n < size2; n++) {
printf("%d\t", dec[o][n]);
}
printf("\n");
}
}
