#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;

	if (lst != NULL)
	{
		newlst = (t_list*)malloc(sizeof(f(lst)));
		if (newlst == NULL)
			return (NULL);
		newlst = f(lst);
		newlst->next = ft_lstmap(lst->next, f);
		return (newlst);
	}
	return (NULL);
}
