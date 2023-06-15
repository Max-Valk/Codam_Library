/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 14:26:05 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/07 15:12:01 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	char	**paths;
	int		path_f;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
}	t_pipex;

/**
 * this program replicates the `|` (pipe) operator on the terminal
*/
int		pipex(t_pipex *var_struct);

/**
 * frees the struct used in the pipex function
*/
void	free_pipex(t_pipex *s_pipex);
/**
 * dups the correct fds for the infile and executes first command
*/
void	child_cmd_1(t_pipex	*var_struct);
/**
 * dups the correct fds for the outfile and executes second command
*/
void	child_cmd_2(t_pipex	*var_struct);
/**
 * actually executes the command given as a parameter in the function
*/
void	exec_command_paths(t_pipex *s_pipex, int cmdn);
/**
 * finds the correct path for the command given in the function
*/
char	*cmd_path(char **envp, char *cmd, int path_f);
/**
 * exits the program if an error occurred 
*/
void	error_exit(char *function, int error_num);
/**
 * parses the envp variable so the paths can be extracted from it
*/
char	**parse_env(char **envp);

#endif
