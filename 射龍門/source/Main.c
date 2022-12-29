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

void play(int wDeck[][13], int people,int count) {
	printf("------------------------\n");
	int left,right;
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
	int mode = check(left,right, wDeck[count 
		% 4][count % 13] % 13 + 1);
	int *co = calloc(people, sizeof(int));
	printf("0:門外 1:撞柱 2:門內\n");
	for (int input,i = 0; i < people; i++) {
		printf("%d:", i + 1);
		scanf("%d", &input);
		while (input < 0 || input>2) {
			printf("不符合請重新輸入:", i + 1);
			scanf("%d", &input);
		}
		co[i] = input;
	}

	for (int i = 0; i < people; i++) {
		if (co[i] == mode)printf("玩家%d贏\n", i + 1);
		else printf("玩家%d輸\n", i + 1);
	}

}
int main() {

	srand(time(NULL));
	int deck[4][13] = { 0 }, people;
	shuffle(deck);
	printf("幾人?");
	scanf("%d", &people);
	for (int i = 0; i < 5; i++) play(deck, people, -1 + i * 3);
}