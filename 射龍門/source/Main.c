#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
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

void gamble(int *gam, int *bal, int people, int *money) {
	for (int input, i = 0; i < people; i++) {
		printf("��%d�쪱�a\n��k:", i + 1);
		scanf("%d", &input);
		while (input < 0 || input>2) {
			printf("���ŦX�W�h�Э��s��J��k:", i + 1);
			scanf("%d", &input);
		}
		gam[i] = input;
		printf("���B(�̦h%d):", money[i]);
		scanf("%d", &input);
		while (input > money[i] || input <= 0) {
			printf("���ŦX�W�h�Э��s��J���B:", i + 1);
			scanf("%d", &input);
		}
		bal[i] = input;
	}
}

void play(int wDeck[][13], int people, int *money) {
	printf("-----------------------------\n");
	int left, right, count = 0;
	left = wDeck[(++count) % 4][(++count) % 13] % 13 + 1;
	right = wDeck[(++count) % 4][(++count) % 13] % 13 + 1;
	while (abs(right - left) <= 1)
	{
		left = wDeck[count % 4][count % 13] % 13 + 1;
		right = wDeck[(++count) % 4][(++count) % 13] % 13 + 1;
	}
	if (left > right) swap(&left, &right);
	printf("*%d %d*\n", left, right);

	int mode = check(left, right, wDeck[(++count) % 4][(++count) % 13] % 13 + 1);
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

	printf(">>>>>�U���a�Ѿl���B<<<<<\n");
	for (int i = 0; i < people; i++) printf("��%d�쪱�a�Ѿl:%d\n", i + 1, money[i]);
}
int main() {
	srand(time(NULL));
	int people;
	printf("                         -----------------------------------------------------------------\n");
	printf("                        |                        �w��Ө�g�s���C��                       |\n");
	printf("                         -----------------------------------------------------------------\n");
	printf("���a���X�H?");
	scanf("%d", &people);
	int *money = calloc(people, sizeof(int));
	for (int z = 0; z < people; z++) money[z] = 1000;
	for (int i = 0; i < 5; i++) {
		int deck[4][13] = { 0 };
		shuffle(deck);
		play(deck, people, money);
		for (int j = 0; j < people; j++) {
			if (money[j] <= 0) {
				i = 10000;
				j = 10000;
				break;
			}
		}
	}
	printf("-----------------------------\n�C������");
}
