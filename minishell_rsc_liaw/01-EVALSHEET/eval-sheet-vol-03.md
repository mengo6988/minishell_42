# EVAL-SHEET-VOL-03
## SECTION-1-RELATIVE-PATH
-	test-1				:	execute some previous commands with relative path
-	test-2				:	execute command with argument with a lot of '..' involved

## SECTION-2-ENVIRONMENT-PATH
-	test-1				:	execute command without any absolute path (ex: ls, wc))
-	test-2				:	unset $PATH and ensure above command not working anymore
-	test-3				:	export $PATH to (dir1:dir2) & make sure it 
							check in accordance to 'left to right' orders

## SECTION-3-REDIRECTIONS
-	test-1				:	any command with redirections '<' or '>'
-	test-2				:	repeat few times with different commands & '<', '>', '>>'
-	test-3				:	test '<<' here document (it doesn't have to update the history)

## SECTION-4-PIPES
-	test-1				:	cat file | grep bla | more
-	test-2				:	repeat few times with different commands & args
-	test-3				:	wrong commands "ls filedoesntexist | grep bla | more"
-	test-4				:	mix pipes and redirections

## SECTION-5-HISTORY-AND-EXTRA-TESTING
-	test-1				:	type command then ctrl+c and enter (should not execute anything)
-	test-2				:	navigate through history with up and down arrows & retry commands
-	test-3				:	invalid command (ex: 'blablabla')
-	test-4				:	cat | cat | ls
-	test-5				:	execute a long command with ton of args

## SECTION-6-ENVIRONMENT-VARIABLES
-	test-1				:	execute echo with some environment variables ($variable) as args
-	test-2				:	check that $ is interpreted as an environment variable
-	test-3				:	check that double quotes interpolate $
-	test-4				:	check that USER exists. Otherwise, set it
-	test-5				:	echo "$USER" should print the value of the USER variable