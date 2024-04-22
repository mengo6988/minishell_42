#include "minishell.h"

void	ms_readline(t_ms *ms)
{
	ms->input = readline("minishell > ");
	ms_addhistory(ms);
	// TODO: Error Handling
	if (error != 0)
	{
		reset_things;
		set exit / return value
	}
	// TODO: Lexical Analysis:- tokenizing, analysis(add metadata)
	tokenize(ms);
	// TODO: Parsing
}

void	minishell_loop(t_ms *ms)
{
	while (ms->exit = false)
	{
		ms_readline(ms);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	for (int i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	while (1)
	{
		input = readline("minishell > ");
		add_history(input);
		printf("%s\n", input);
	}
	return (0);
}

// TODO: Parsing/tokenizing the input...
// TODO: Handling the pipes, open fd and closing the unnecasarry ones
// 	heredoc is a must as well...
//
// TODO: Checking the access/if function/cmd is available, then execve it
// TODO: Reset the arguments to wait for next input

// FIX: Handling the signals
// exit status has to be right

// WARN: echo with -n option
// cd with relative/absolute path
// pwd with no options
// export with no option
// unset with no options
// env with no options/arguments
// exit with no options
