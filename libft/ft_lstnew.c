#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		lst->content = NULL;
	}
	else
	{
		lst->content = malloc(content_size);
		if (lst->content == NULL)
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
	}
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
