#ifndef STORE_H
#define STORE_H

#include <stdio.h>
#include <string.h>
#include "input.h"

typedef struct {
	char *title;
	char *categories;
	char *author;
} MetaData;

//MetaData *createMetaData(char *title, char *categories, char *author);
int storeToFile(char *filepath, MetaData *m);
MetaData *setMetaData();
void deleteMetaData(MetaData *m);

#endif
