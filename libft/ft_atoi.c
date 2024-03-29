int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int negative;

	i = 0;
	nb = 0;
	negative = 0;
	while ((str[i] == '\f') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (negative)
		return (-nb);
	else
		return (nb);
}
