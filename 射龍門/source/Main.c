#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int *money; //�ȩw

void shuffle(int wDeck[][13]) {
	for (int i = 1; i <= 52; i++) {
		int r, c;
		do {
			r = rand() % 4;
			c = rand() % 13;
		} while (wDeck[r][c]);
		wDeck[r][c] = i;
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int check(int left, int right, int card) {
	if (card<left || card>right) return 0;
	else if (card == left || card == right) return 1;
	else return 2;
}

void play(int wDeck[][13], int people, int count) {
	printf("------------------------\n");
	int left, right;
	count++;
	left = wDeck[count % 4][count % 13] % 13 + 1;
	count++;
	right = wDeck[count % 4][count % 13] % 13 + 1;
	while (abs(right - left) <= 1)
	{
		count++;
		left = wDeck[count % 4][count % 13] % 13 + 1;
		count++;
		right = wDeck[count % 4][count % 13] % 13 + 1;
	}
	if (left > right) swap(&left, &right);
	printf("%d %d\n", left, right);
	count++;
	int mode = check(left, right, wDeck[count
		% 4][count % 13] % 13 + 1);
	int *co = calloc(people, sizeof(int));
	printf("0:���~ 1:���W 2:����\n");
	for (int input, i = 0; i < people; i++) {
		printf("%d:", i + 1);
		scanf("%d", &input);
		while (input < 0 || input>2) {
			printf("���ŦX�Э��s��J:", i + 1);
			scanf("%d", &input);
		}
		co[i] = input;
	}

	for (int i = 0; i < people; i++) {
		if (co[i] == mode)printf("���a%dĹ\n", i + 1);
		else printf("���a%d��\n", i + 1);
	}

	int *gam = calloc(people, sizeof(int)), mag[3] = { 3,7,3 }, *bal = calloc(people, sizeof(int));
	if (right - left == 2) mag[2] = 10;
	else if (right - left == 12) mag[0] = 10000;
	else if (right - left > 5) mag[0] = 5;
	else mag[2] = 5;

	printf("0:���~(�߲v:%d) 1:���W(�߲v:%d) 2:����(�߲v:%d)\n", mag[0], mag[1], mag[2]);
	gamble(gam, bal, people, money);

	printf(">>>>>�}�X�Ӫ��P�O:%d<<<<<\n", wDeck[count % 4][count % 13] % 13 + 1);
	for (int i = 0; i < people; i++) {
		if (gam[i] == mode) {
			money[i] += bal[i] * mag[gam[i]];
			printf("���a%dĹ�F%d��\n", i + 1, bal[i] * mag[gam[i]]);
		}
		else {
			money[i] -= bal[i];
			printf("���a%d��F%d��\n", i + 1, bal[i]);
		}
	}

}
int main() {
	srand(time(NULL));
	int deck[4][13] = { 0 }, people;
	shuffle(deck);
	printf("�X�H?");
	scanf("%d", &people);
	for (int i = 0; i < 5; i++) play(deck, people, -1 + i * 3);
}