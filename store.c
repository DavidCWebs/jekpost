#include "store.h"
//#include "utilities.h"

int storeToFile(char *filepath, MetaData *m)
{
	int rc = 0;
	FILE *fOut = fopen(filepath, "a+");
	if(fOut != NULL) {
		if(fputs("---\n", fOut) != EOF) {
			rc = 1;
		}
		if(fputs("title: ", fOut) != EOF) {
			rc = 1;
		}
		if(fputs(m->title, fOut) != EOF) {
			rc = 1;
		}
		fputc('\n', fOut);
		if(fputs("author: ", fOut) != EOF) {
			rc = 1;
		}
		if(fputs(m->author, fOut) != EOF) {
			rc = 1;
		}
		fputc('\n', fOut);

		if(fputs("categories: ", fOut) != EOF) {
			rc = 1;
		}
		if(fputs(m->categories, fOut) != EOF) {
			rc = 1;
		}
		fputc('\n', fOut);
		if(fputs("layout: post", fOut) != EOF) {
			rc = 1;
		}
		fputc('\n', fOut);
		fputs("---", fOut);
		fclose(fOut);
	}
	return rc;
}

MetaData *setMetaData()
{
	char *title;
	char *categories;
	char *author;

	puts("Enter title:");
	setString(&title);
	puts("Enter categories:");
	setString(&categories);
	puts("Enter author name:");
	setString(&author);
	
	MetaData *m = malloc(sizeof(MetaData));
	m->title = malloc(strlen(title) + 1);
	strcpy(m->title, title);
	m->categories = malloc(strlen(categories) + 1);
	strcpy(m->categories, categories);
	m->author = malloc(strlen(author) + 1);
	strcpy(m->author, author);
	
	free(title);
	free(categories);
	free(author);
	return m;
}

void deleteMetaData(MetaData *m)
{
	free(m->title);
	free(m->categories);
	free(m->author);
	free(m);
}
