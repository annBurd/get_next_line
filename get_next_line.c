/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:06:10 by aburdeni          #+#    #+#             */
/*   Updated: 2018/02/15 18:14:13 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	fill_the_buf(const int fd, char **buf, int *rb)
{
	*buf = ft_memalloc(BUFF_SIZE + 1);
	*rb = read(fd, *buf, BUFF_SIZE);
	buf[0][BUFF_SIZE] = 0;
}

static char	*check_fd(const int fd, t_fd **head, int *rb)
{
	t_fd	*tmp;

	(void)*rb;
	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->s);
		tmp = tmp->next;
	}
	tmp = (t_fd*)malloc(sizeof(t_fd));
	tmp->fd = fd;
	tmp->s = ft_strnew(0);
	tmp->next = (*head);
	(*head) = tmp;
	return (tmp->s);
}

static int	read_to_nl(const int fd, char **buf)
{
	char	*buf_tmp;
	char	*fresh;
	int		rb;

	fill_the_buf(fd, &buf_tmp, &rb);
	if (rb == 0 && (ft_strlen(buf_tmp) == 0))
	{
		free(buf_tmp);
		return (-2);
	}
	fresh = ft_strjoin(*buf, buf_tmp);
	free(buf_tmp);
	free(*buf);
	*buf = fresh;
	return (rb);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*head;
	char		*buf;
	char		*rebuf;
	char		*end;
	int			rb;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, "", 0) < 0)
		return (-1);
	buf = check_fd(fd, &head, &rb);
	end = ft_strchr(buf, '\n');
	while (end == NULL)
	{
		rb = read_to_nl(fd, &buf);
		end = (rb > 0) ? ft_strchr(buf, '\n') : ft_strchr(buf, 0);
		if (rb == -2 && end == buf)
			return (0);
	}
	*line = ft_strsub(buf, 0, end - buf);
	rebuf = (buf[end - buf] == 0) ? ft_strnew(0) :
		ft_strsub(buf, end - buf + 1, ft_strlen(buf + (end - buf + 1)));
	free(buf);
	head->s = rebuf;
	return (1);
}
