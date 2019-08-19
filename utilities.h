#ifndef UTILITIES_H
#define UTILITIES_H

#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "store.h"

void timestamp(char **str, size_t maxSize);
char *readLine();
int setString(char **str);
int setString2(char **str);
void replaceSpaces(char *str, char substitution);

#endif

