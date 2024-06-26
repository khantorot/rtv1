#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (little[temp])
		temp++;
	if (temp == 0)
		return ((char*)big);
	while (big[i])
	{
		while (little[j] == big[i + j] && little[j] && i + j < (int)len)
			j++;
		if (little[j] == '\0')
			return ((char*)big + i);
		j = 0;
		i++;
	}
	return (0);
}
