#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "input.h"
#include "utilities.h"
#include "store.h"

int main()
{
	MetaData *m = setMetaData(); 
	char timestring[11];
	char *t = timestring;
	timestamp(&t, 11);
	
	size_t nameLen = strlen(timestring) + strlen(m->title) + 5;
	char *fileName = malloc(nameLen);
	snprintf(fileName, nameLen, "%s-%s.md", timestring, m->title);
	replaceSpaces(&fileName, '-');
	printf("slugified fileName: %s\n", fileName);

	storeToFile(fileName, m);
	
	deleteMetaData(m);
	free(fileName);

	return 0;
}
