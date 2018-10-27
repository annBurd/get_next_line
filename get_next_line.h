/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:14:21 by aburdeni          #+#    #+#             */
/*   Updated: 2018/02/15 18:14:25 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_fd
{
	int			fd;
	char		*s;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
