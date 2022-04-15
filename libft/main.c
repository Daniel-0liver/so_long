#include "libft.h"

int main() {
	char s1[] = "aHere is a very big test but noa";
	char s2 = ' ';
	char **s3;
	int i = 0;
	int j = 0;
	s3 = ft_split(s1, s2);
	while (s3[i])
	{
		printf("%s\n", s3[i]);	
		i++;
	}
	
	return (0);
}