#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printRectArr(const int *const arr,const int rows,const int cols);
void fillRectArray(int *const arr, const int rows, const int cols);

int main(){
	int a=0,b=0;
	int *arr;
	printf("Input rectangular array dimensions, e.g. \"6 7\", then hit Enter.\n");
	scanf("%d %d",&a,&b);
	if (a > 0 && b > 0)
	{
		arr = (int *) calloc(a*b,sizeof(int)); // 2-dimensional array allocated as a simple 1-dimensional one, then initialized to zero

		if (arr != NULL)
		{

			fillRectArray(arr,a,b);

			printRectArr(arr,a,b);

			free(arr);
		}
		else
			printf("Can't allocate space\n");
	}
	else
		printf("Need two positive integers\n");

	getchar();
}

/*
Takes a pointer to the rectangular array *arr
of size [rows, cols], and prints its elements.
Even though it is a 2-dimensional array,
the type of the pointer is the same as for 
regular linear array.
That's not a bug, that's a feature.
*/
void printRectArr(const int *const arr,const int rows,const int cols){
	int i,j;
	int k = 0;
	for (i = 0; i < rows; ++i){
		for (j = 0; j < cols; ++j){
			k = arr[i*cols +j];	// arr[i*cols +j] == a[i][j]
			printf("%4d ",k);
		}
		printf("\n");
	}
}

void fillRectArray(int *const arr, const int rows, const int cols){
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

		i = j  = 0;
		j_left = 0,
		i_top = 1,
		i_bottom = rows -1,
		j_right = cols - 1;

	for (n=1; n <= (rows * cols);++n){
		arr[i*cols +j] = n;
		switch (dir) {
		case RIGHT:
			if (j < j_right)
				++j;
			else {
				dir = DOWN;
				--j_right; // right border "shrinks" towards the center
				++i;
			}
			break;
		case DOWN:
			if (i < i_bottom)
				++i;
			else {
				dir = LEFT;
				--i_bottom;
				--j;
			}
			break;
		case LEFT:
			if(j > j_left)
				--j;
			else {
				dir = UP;
				++j_left;
				--i;
			}
			break;
		case UP:
			if (i > i_top)
				--i;
			else {
				dir = RIGHT;
				++i_top;
				++j;
			}
			break;
		default:
			return;
			break;
		}
	}
}
