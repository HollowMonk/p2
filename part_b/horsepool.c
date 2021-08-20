#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 1024

int shift_table[MAX];

void shifttable(char pattern[])
{
	int i, j, m = strlen(pattern);
	for (i = 0; i < MAX; i++)
		shift_table[i] = m;//Initialise shift table to pattern_length
	for (j = 0; j < m - 1; j++)
		shift_table[pattern[j]] = m - 1 - j;//pattern[j] will give a char that will be converted to ASCII m-1-j  give the 
											//no of chars in front of current char
}

int horspool(char src[], char pattern[])
{
	int i, j, text_length, pattern_length;
	text_length = strlen(src);
	pattern_length = strlen(pattern);
	printf("\nLength of text = %d", text_length);
	printf("\nLength of pattern = %d", pattern_length);
	i = pattern_length - 1;
	while (i < text_length)
	{
		j = 0;
		while ((j < pattern_length) && (pattern[pattern_length - 1 - j] == src[i - j]))
			j++;

		if (j == pattern_length)
			return (i - pattern_length + 1);
		else
			i += shift_table[src[i]];
	}

	return -1;
}

int main()
{
	char src[MAX], pattern[MAX];
	int pos;

	printf("Enter the text in which pattern is to be searched: ");
	scanf("%s",src);

	printf("Enter the pattern to be searched: ");
	scanf("%s",pattern);

	clock_t st = clock();
	shifttable(pattern);
	pos = horspool(src, pattern);
	clock_t et = clock();

	if (pos >= 0)
		printf("\n\nThe desired pattern was found starting from position %d", pos + 1);
	else
		printf("\n\nThe pattern was not found in the given text");

	double time_taken = (double)(et - st) / CLOCKS_PER_SEC;
	printf("\nTime taken to execute is %lf\n", time_taken);
	return 0;
}