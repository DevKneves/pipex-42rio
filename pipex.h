/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneves <kneves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:44:47 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 11:43:20 by kneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	conflict(void);
void	ft_putstr(char *str);

#endif
