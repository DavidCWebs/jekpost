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
