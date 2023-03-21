// Q4. Write interactive C programs to perform the following on strings:
// (a) To check if two strings are Anagram.
// (b) To check whether the given alphabet is a vowel or consonant.
// (c) To convert the given string from lower case to upper case without using the inbuilt
// function in <string.h>

// (a)
#include <stdio.h>
#include <string.h>

int anagram(char a[], char b[])
{
	if (strlen(a) != strlen(b))
		return 0;
	int i = 0;
	int freq_a[26] = {0};
	int freq_b[26] = {0};
	for (i = 0; a[i] && b[i]; i++) {
		freq_a[a[i] - 97]++;
		freq_b[b[i] - 97]++;
	}
	for (i = 0; i < 26; i++) {
		if (freq_a[i] != freq_b[i])
			return 0;
	}
	return 1;
}

int main()
{
	char a[50], b[50];
	printf("Enter first string: ");
	scanf("%s", a);
	printf("Enter second string: ");
	scanf("%s", b);
	if (anagram(a, b)) {
		printf("Two strings are an anagram to each other\n");
	} else {
		printf("Two strings are not an anagram to each other\n");
	}
	return 0;
}
