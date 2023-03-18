#include "secure_data.h"

char *parse(char *str)
{
	char *ret = strtok(str, " ");
	if (ret == NULL)
		return NULL;
	int len = strlen(ret);
	if (len > 0 && ret[len - 1] == '\n')
	{
		ret[len - 1] = '\0';
	}
	return ret;
}
