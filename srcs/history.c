#include "minishell.h"

void	ms_addhistory(t_ms *ms)
{
	if (ms->input != NULL && ms->input[0] != '\0')
	{
		if (ms->previous_input == NULL || ft_strcmp(ms->input,
				ms->previous_input) != 0)
		{
			add_history(ms->input);
			if (ms->previous_input != NULL)
			{
				free(ms->previous_input);
				ms->previous_input = NULL;
			}
			ms->previous_input = ft_strdup(ms->input);
		}
	}
}
