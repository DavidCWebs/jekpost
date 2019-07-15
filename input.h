#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include "store.h"

char *readLine();
int setString(char **str);
int setString2(char **str);
void replaceSpaces(char **str, char substitution);

#endif
