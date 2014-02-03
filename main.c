#include <stdio.h>
#include <stdlib.h>



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
			k = *(arr +i*cols +j);	// (arr + i * cols) is an offset for the i-th row 
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

	for (n=1,
		i = j  = j_left = 0,
		i_top = 1,
		i_bottom = rows -1,
		j_right = cols - 1;

	n <= (rows * cols);

	++n){
		*(arr+i*cols + j) = n;
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

#define SIZE 50

int main(){
	int a=1,b=1;
	int *arr;
	printf("Input rectangular array dimensions, e.g. \"6 7\", then hit Enter.\n");
	scanf("%d %d",&a,&b);

	arr = (int *) malloc(sizeof(int)*a*b); // 2-dimensional array allocated as a simple 1-dimensional one

	if (arr != NULL)
	{
		fillRectArray(arr,a,b);
		
		printRectArr(arr,a,b);

		free(arr);
	}
	else {
		printf("Can't allocate space\n");
	}

	getchar();
}