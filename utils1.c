#include "so_long.h"

int	ft_strlen2(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	print_walls_error(void)
{
	ft_putstr("MAP BOUNDARY WALLS PROBLEM");
	exit(1);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	str = ptr;
	i = 0;
	while (i < num)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *ptr1, char *ptr2)
{
	int i;

	i = 0;
	while (ptr1[i] == ptr2[i] && ptr1[i] != '\0' && ptr2[i] != '\0')
		i++;
	return (ptr1[i] - ptr2[i]);
}
