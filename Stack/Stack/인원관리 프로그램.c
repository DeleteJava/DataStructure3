#include <stdio.h>
#include <string.h>

int main(void)
{

	char str1[100] = "Abcd", str2[100];
	strcpy(str2, str1);
	printf("%s\n", str2);


	return 0;
}