#include "utilities.h"

void timestamp(char **str, size_t maxSize)
{
	time_t now = time(0);
	struct tm *gtm = gmtime(&now);
	snprintf(*str, maxSize, "%d-%02d-%02d",
			gtm->tm_year + 1900,
			gtm->tm_mon + 1,
			gtm->tm_mday
			);
}

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


void replaceSpaces(char *str, char substitution)
{
	while (*str) {
		if (*str == ' ') {
			*str = substitution;
		}
		str++;
	}
}


