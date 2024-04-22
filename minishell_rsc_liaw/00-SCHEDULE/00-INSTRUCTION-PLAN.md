# MINISHELL INSTRUCTION AND PLAN
`
## MINISHELL-BASIC-REQUIREMENT
-	Norminette 						:	all project files should be able to pass the norminette test
-	Error-free						:	segmentation fault, bus-error, double-free, etc...
-	Heap-memories-free				:	heap allocated memory space must be properly freed; no leaks
-	If nakefile is involved			-
									:	output should compile with 'cc -Werror -Wextra -Wall'
									:	Makefile must not relink
									:	must contain at least '$(NAME), all, clean, fclean, & re'
									:	include a rule 'bonus' to makefile for bonus files
									:	bonuses must be in different file 'name_bonus.{c/h}'
									:	to include 'libft' one should include the whole libft-directory
-	Submission						-
									:	commit and push to intra-git-repository before confirm submission
									:	evaluation of mandatory and bonus part should be done separately

## MINISHELL-GENERAL
-	core-concept					:	build a mini-shell that mimics the bash
-	main-part-1						:	(front-end)	parsing		-	treat and filter user input
-	main-part-2						:	(back-end)	execution	-	execute what have been parsed

## MINISHELL-MANDATORY
-	program name					:	minishell
-	turn-in-files					:	Makefile, all .h and all .c
-	Makefile						:	NAME, all, clean, fclean, re
-	allowed function				-
									:	libft
									:	readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
									:	add_history
									:	printf, malloc, free, write, access, open, read, close, fork
									:	wait, waitpid, wait3, wait4
									:	signal, sigaction, sigemptyset, sigaddset, kill, exit
									:	getcwd, chdir, stat, lstat, fstat, unlink, execve
									:	dup, dup2, pipe, opendir, readdir, closedir, strerror, perror
									:	isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent
									:	tgetflag, tgetnum, tgetstr, tgoto, tputs
-	requirement-1					:	display a prompt when waiting for a new command
-	requirement-2					:	have a working history
-	requirement-3					:	search and launch the right executable (PATH variable / relative / absulute path)
-	requirement-4					:	maximum one global variable to receive signal purpose only.
-	requirement-4a					:	ensure signal handler not access main data structures.
-	requirement-5					:	don't have to handle unclosed quotes or special charactoer such as backslash or semicolon
-	requirement-6					:	handle single quote
-	requirement-7					:	handle double quote that can read dollar sign
-	requirement-8					:	implement redirections	-
																:	left-single-arrow	-	redirect input
																:	right-single-arrow	-	redirect output
																:	left-double-arrow	-	read until delimiter
																							(no need update history)
																:	right-double-arrw	-	redict output in append mode
-	requirement-9					:	implement pipe; each pipeline command's output is connected to next command's input via a pipe
-	requirement-10					:	environment variables; $HOME, $USR, and so on...
-	requirement-11					:	handle '$?'; expand to the exit status of the most recently executed foreground pipeline
-	requirement-12					:	handle ctrl-C, ctrl-D, ctrl-\ behaviour like the one in bash
-	requirement-12a					:	interactive mode; ctl-c dis new prompt on new line, ctl-d exits shell & ctl-\ does nothing
-	requirement-13					:	implement builtins - echo (-n), cd (ab/re path), pwd, export, unset, env, exit
-	requirement-14					:	readline() function cause memory leaks, your own code can't cause memory leaks.

## MINISHELL-BONUS
-	requirement-1					:	handle && and || with parenthesis for priorities
-	requirement-2					:	handle 'wildcards *' that should work for the current working directory

## MINISHELL-SCHEDULE
-	WEEK-1	(NOV-15-NOV-18)			:	preparation -	git & github, guide-studies, code-studies, function testing, detailed-roadmap
														,evaluation sheet prepare, basic project file structure.
-	WEEK-2	(NOV-19-NOV-25)			:	front-end	-	parsing related task
`------ WE ARE HERE : WEEK 3 ---------`
-	WEEK-3	(NOV-26-DEC-02)			:	back-end	-	environment variables, fork-process & execution & file-redirection
-	WEEK-4	(DEC-03-DEC-09)			:	touch-up	-	pipe-redirection, signal handling & execution related task
-	WEEK-5	(DEC-10-DEC-16)			:	touch-up	-	testing, refactor, fix-bug & eval-shet check;
-	WEEK-6	(DEC-17-DEC-23)			:	buffer (1)
-	WEEK-7	(DEC-24-DEC-29)			:	buffer (1)