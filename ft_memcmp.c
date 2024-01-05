#include "so_long.h"

int	ft_memcmp(char *ptr1, char *ptr2)
{
	int i;

	i = 0;
	while (ptr1[i] == ptr2[i] && ptr1[i] != '\0' && ptr2[i] != '\0')
		i++;
	return (ptr1[i] - ptr2[i]);
}