#include <stdio.h>
#include <stdlib.h>

#define WIDTH 3
#define HEIGHT 4
#define SIZE WIDTH*HEIGHT

void test(int** arr)
{
	for(int i=0; i<WIDTH; i++)
		for(int j=0; j<HEIGHT; j++)
			arr[i][j] = j+i;

	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int* grid[WIDTH];

	int* row = malloc(sizeof(int)*SIZE);	
	for(int i=0; i<WIDTH; i++)
	{
		grid[i] = &row[i*HEIGHT];
	}

	test(grid);

	return 0;
}
