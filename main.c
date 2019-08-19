#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "utilities.h"	// timestamp()
#include "store.h"	// setMetaData()

int main()
{
	MetaData *m = setMetaData(); 
	char timestring[11];
	char *t = timestring;
	timestamp(&t, 11);
	
	size_t nameLen = strlen(timestring) + strlen(m->title) + 5;
	char *fileName = malloc(nameLen);
	snprintf(fileName, nameLen, "%s-%s.md", timestring, m->title);
	replaceSpaces(fileName, '-');
	storeToFile(fileName, m);
	printf("%s\n", fileName);
	
	deleteMetaData(m);
	free(fileName);

	return 0;
}
