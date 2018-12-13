#include <stdio.h>
#include"myerror.h"

void Error(char *s)
{
	printf("error: %s\n", s);
}
void FatalError(char *s)
{
	printf("fatal error: %s\n", s);
}