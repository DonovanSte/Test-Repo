#include "main.h"

char **split_string(char *string, int *count)
{
	int i, j, len = 0;
	*count = 1;

	/* count the number of words in the string */
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == ' ') {
			(*count)++;
		}
	}

	/* allocate memory for the array of words */
	char **words = malloc(*count * sizeof(char *));

	/* split the string into words */
	j = 0;
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == ' ') {
			words[j] = malloc(len + 1);
			memcpy(words[j], &string[i - len], len);
			words[j][len] = '\0';
			len = 0;
			j++;
		} else {
			len++;
		}
	}

	/* handle the last word */
	words[j] = malloc(len + 1);
	memcpy(words[j], &string[i - len], len);
	words[j][len] = '\0';

	return words;
}