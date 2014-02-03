#include <stdio.h>
#include <stdlib.h>



/*
Takes a pointer to the square array *arr
of size [a, a], and prints its elements.
Even though it is a 2-dimensional array,
the type of the pointer is the same as for 
regular linear array.
That's not a bug, that's a feature.
*/
void printSquareArr(int *arr,int a){
	int i,j;
	int k = 0;
	for (i = 0; i < a; ++i){
		for (j = 0; j < a; ++j){
			k = *(arr+i*a+j);	// (arr + i * a) is an offset for the i-th row 
			printf("%4d ",k);
		}
		printf("\n");
	}

}

void fillSpiralArray(int *arr, int a){
	int i,j;
	int i_top,i_bottom,j_right,j_left;	// borders of the spiral
	int n;

	typedef enum DIRECTION {
		RIGHT,
		DOWN,
		LEFT,
		UP
	} DIRECTION;

	DIRECTION dir = RIGHT;

	for (n=1,
		i = j  = j_left = 0,
		i_top = 1,
		i_bottom = j_right = a-1; 

	n <= a*a;

	++n){
		arr[i*a + j] = n;
		if (dir == RIGHT)
			if (j < j_right)
				++j;
			else {
				dir = DOWN;
				--j_right; // right border "shrinks" towards the center
				++i;

			}
		else if (dir == DOWN)
			if (i < i_bottom)
				++i;
			else {
				dir = LEFT;
				--i_bottom;
				--j;

			}
		else if (dir == LEFT)
			if(j > j_left)
				--j;
			else {
				dir = UP;
				++j_left;
				--i;

			}
		else if (dir == UP)
			if (i > i_top)
				--i;
			else {
				dir = RIGHT;
				++i_top;
				++j;

			}

	}
}
#define SIZE 5

int main(){
	int a = SIZE;	// this variable will be needed in the future, for dynamically allocated array
	int arr[SIZE][SIZE];	// instead of this static array with fixed size
	
	fillSpiralArray((int *)arr,a);

	printf("\nHere you go:\n");
	printSquareArr((int*)arr,a);

	getchar();
}