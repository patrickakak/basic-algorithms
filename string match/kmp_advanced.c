/**
 * A variation of KMP algorithm, faster and better
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int Position;
#define NotFound -1
void BuildMatch(char *pattern, int *match);
Position KMP(char *string, char *pattern);
int main() {
	char string[] = "This is a simple example.";
	char pattern[] = "simple";
	Position p = KMP(string, pattern);
	if (p == NotFound) printf("Not Found.\n");
	else printf("%s\n", p+string);
	return 0;
}
/* Improve next[] to be nextVal[] */
void BuildNextVal(char *pattern, int *nextVal, int *next) {
	Position i, j;
	int m = strlen(pattern);
	nextVal[0] = 0;
	for (i = 1; i < m; i++) {
		j = next[i-1];
		while (j>0 && pattern[j]==pattern[i])
			j = next[j-1];
		if (j == 0) nextVal[i] = 0;
		else if (j == next[i-1]) nextVal[i] = next[i];
		else nextVal[i] = j;
	}
}
void BuildMatch(char *pattern, int *match) {
	Position i, j;
	int m = strlen(pattern);
	match[0] = 0;
	for (i=1, j=0; i < m; i++)
		if (pattern[i] == pattern[j]) {
			match[i] = j+1;
			j++;
		} else {
			while ((j>0) && (pattern[j]!=pattern[i]))
				j = match[j-1];
			if (pattern[j] == pattern[i]) {
				match[i] = j+1;
				j++;
			} else match[i] = 0;
		}
}
Position KMP(char *string, char *pattern) {
	int n = strlen(string);
	int m = strlen(pattern);
	Position s, p, *match, *nextVal;
	if (n < m)
		return NotFound;
	match = (Position *) malloc(sizeof(Position) * m);
	BuildMatch(pattern, match);
	nextVal = (Position *) malloc(sizeof(Position) * m);
	BuildNextVal(pattern, nextVal, match);
	s = p = 0;
	while (s<n && p<m)
		if (string[s] == pattern[p]) {
			s++;
			p++;
		} else if (p > 0) p = nextVal[p];
		else s++;
	free(match);
	free(nextVal);
	return (p == m) ? (s-m) : NotFound;
}
