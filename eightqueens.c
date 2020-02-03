//marciosdn
//2020-01-14

#include <stdio.h>

/*
Array solution 15863724 means:
10000000
00005000
00000008
00000600
00300000
00000070
02000000
00040000
*/

#define SIZE 8

int A[SIZE] = {0,0,0,0,0,0,0,0};    //array solution
int s=0;    //solutions
int t=0;    //total tests

int test(int queen,int col) {
	t++;
	for (int i=1;i<queen;i++) {
		if (A[queen-i-1]==col) return 0;
		if (A[queen-i-1]==col-i) return 0;
		if (A[queen-i-1]==col+i) return 0;
	}
	return 1;
}

void play(int queen) {
	for (int col=1;col<SIZE+1;col++) {
		if (test(queen,col)) {
			A[queen-1]=col;
			if(queen==SIZE) printf("Solution: %d, %d, %d%d%d%d%d%d%d%d\n",++s,t,A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7]);
			else play(queen+1);
			A[queen-1]=0;
		}
	}
}

void main(void) {
	play(1);
	printf("Tests %d",t);
}
