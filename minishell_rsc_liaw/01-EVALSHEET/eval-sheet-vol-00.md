# EVAL-SHEET-VOL-00
## SECTION-1-COMPILE
-	test-1				:	use 'make -n' check '-Wall -Wextra -Werror'
-	test-2				:	relink tests

## SECTION-2-SIMPLE-COMMAND-&-GLOBAL-VAR
-	test-1				:	absolute-path command ex '/bin/ls' without any options
-	code-review-1		:	explain the usage of global variables in this minishell project
-	test-2				:	empty command on minishell
-	test-3				:	only spaces or tab on minishell

## SECTION-3-ARGUMENTS
-	test-1				:	absolute-path command ex '/bin/ls' with args but no quotes
-	test-2				:	repeat test-1 multiple times with diff commands & args

## SECTION-4-ECHO
-	test-1				:	echo with args
-	test-2				:	echo without args
-	test-3				:	echo with/without args and -n option