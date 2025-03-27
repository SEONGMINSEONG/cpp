#include <stdio.h>
#include <string.h>
void main()
{
	char s1[] = "game", s2[20], s3[20];

	strcpy(s2, "over");
	sprintf(s3, "%s %s !", s1, s2);
	printf("strlen(%s) = %d\n", s1, strlen(s1));
	printf("strlen(%s) = %d\n", s2, strlen(s2));
	printf("strlen(%s) = %d\n", s3, strlen(s3));
	printf("strcmp(%s,%s) = %d\n", s1, s2, strcmp(s1, s2));
	printf("strcmp(%s,game) = %d\n", s1, strcmp(s1, "game"));
}