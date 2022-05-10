/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:52:42 by glychest          #+#    #+#             */
/*   Updated: 2020/11/24 18:55:28 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 12288

# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft.h"

int get_next_line(const int fd, char **line);

#endif
