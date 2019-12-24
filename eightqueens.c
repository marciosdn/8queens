#include <stdio.h>

#define SIZE 8

int t[SIZE] = {0,0,0,0,0,0,0,0};
int q=1;
int a=1;

int test(int queen,int col) {
	a++;
	for (int i=1;i<queen;i++) {
		if (t[queen-i-1]==col) return 0;
		if (t[queen-i-1]==col-i) return 0;
		if (t[queen-i-1]==col+i) return 0;
	}
	return 1;
}

void play(int queen) {
	for (int col=1;col<SIZE+1;col++) {
		if (test(queen,col)) {
			t[queen-1]=col;
			if(queen==SIZE) printf("%d,%d,%d%d%d%d%d%d%d%d\n",q++,a,t[0],t[1],t[2],t[3],t[4],t[5],t[6],t[7]);
			else play(queen+1);
			t[queen-1]=0;
		}
	}
}

void main(void) {
	play(1);
	printf("%d",a);
}
