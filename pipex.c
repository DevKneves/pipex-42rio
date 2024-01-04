/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneves <kneves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:40:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 03:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
    int filein;

    filein = open(argv[1], O_RDONLY, 0777);
    if(filein == -1)
        conflict();
    dup2(fd[1], STDOUT_FILENO);
    dup2(filein, STDIN_FILENO);
    close(fd[0]);
    execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		conflict();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int     fd[2];
    pid_t   pid;

    if(argc == 5)
    {
        if(pipe(fd) == -1)
            conflict();
        pid = fork();
        if(pid == -1)
            conflict();
        if(pid == 0)
            child_process(argv, envp, fd);
        waitpid(pid, NULL, 0);
        parent_process(argv, envp, fd);
    }
    else
    {
        ft_putstr("invalid arguments\n")
        ft_putstr("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n")
    }
    return (0);
}