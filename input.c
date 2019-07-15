#include "input.h"

char *readLine()
{
	int ch = 0;
	size_t i = 0;
	size_t size = 5;
	char *str = malloc(size);
	while((ch = getchar()) != '\n' && ch != EOF) {
		if(i > size) {
			size += size;
			str = realloc(str, size);
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	printf("*str is: %s\n", str);
	return str;
}

int setString(char **str)
{
	int ch = 0;
	size_t i = 0;
	size_t size = 1;
	*str = malloc(size);
	while((ch = getchar()) != '\n' && ch != EOF) {
		if(i >= size) {
//			size += size;
			size++;
			*str = realloc(*str, size);
		}
		(*str)[i++] = ch;
	}
	*str = realloc(*str, size + 1);
	(*str)[i] = '\0';
	
	return 0;
}

int setString2(char **str)
{
	int ch = 0;
	size_t i = 0;
	size_t size = 1;
	*str = malloc(size);
	while((ch = getchar()) != '\n' && ch != EOF) {
		if(i > size) {
			size += size;
			*str = realloc(*str, size);
		}
		*((*str) + i++) = ch;
	}
	*((*str) + i) = '\0';
	
	return 0;
}


void replaceSpaces(char **str, char substitution)
{
	char *c;
	for(size_t i = 0; *(c = *str + i); i++) {
		if(*c == ' ')
			*c = substitution;
	}
}


