#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define INPUT_FILE "day1.input"

int comparei(const void *va, const void *vb) {
	int a = *(int *)va;
	int b = *(int *)vb;

	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int main(void) {
	struct stat file_info = {0};
	stat(INPUT_FILE, &file_info);

	size_t file_size = file_info.st_size;
	size_t nlines = file_size / 14;
	// size_t nlines = file_size / 6;

	FILE *file = fopen(INPUT_FILE, "r");

	int *left = malloc(nlines * sizeof(int));
	int *right = malloc(nlines * sizeof(int));

	int *pleft = left;
	int *pright = right;
	while (fscanf(file, "%d  %d\n", pleft++, pright++) == 2)
		;

	qsort(left, nlines, sizeof(int), comparei);
	qsort(right, nlines, sizeof(int), comparei);

	int diff = 0;
	for (size_t i = 0; i < nlines; i++) {
		int d = abs(left[i] - right[i]);
		// printf("%d, %d, %d\n", d, left[i], right[i]);
		diff += d;
	}

	printf("Part 1: %d\n", diff);
}
