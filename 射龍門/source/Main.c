#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

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
	printf("0:���~ 1:���W 2:����\n");
	for (int input,i = 0; i < people; i++) {
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



}
int main() {
	srand(time(NULL));
	int deck[4][13] = { 0 }, people;
}