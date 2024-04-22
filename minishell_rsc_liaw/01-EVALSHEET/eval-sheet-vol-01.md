# EVAL-SHEET-VOL-01
## SECTION-1-EXIT
-	test-1				:	exit with args
-	test-2				:	exit without args

## SECTION-2-RETURN-VALUE-OF-A-PROCESS
-	note				:	followin tests-result should be same as bash	
-	test-1				:	absolute-path command ex '/bin/ls' with args but no quotes
-	test-2				:	execute echo $? after test-1
-	test-3				:	repeat test-1 and test-2 multiple times with diff commands & args
-	test-4				:	wrong command ex '/bin/ls/ filedoesnexist'
-	test-5				:	expr $? + $?

## SECTION-3-SIGNALS
-	test-1				:	ctrl-c on empty prompt 
-	test-2				:	ctrl-\ on empty prompt
-	test-3				:	ctrl-d on empty prompt
-	test-4				:	ctrl-c on non-empty prompt
-	test-5				:	press enter
-	test-6				:	ctrl-\ on non-empty prompt
-	test-7				:	ctrl-d on non-empty prompt
-	test-8				:	run cat then control-c
-	test-9				:	run cat then control-\
-	test-10				:	run cat then control-d
-	test-11				:	repeat test-8,9,10 multiple times with diff commands & args

## SECTION-4-DOUBLE-QUOTES
-	test-1				:	any command with args that uses double quotes
-	test-2				:	echo "cat lol.c | cat > lol.c"
-	test-3				:	try anything without dollar sign

## SECTION-5-SINGLE-QUOTES
-	test-1				:	any command with args that uses single quotes
-	test-2				:	empty arguments ex echo ''
-	test-3				:	try env-var, whitespaces, pipes, redirections in single quotes
-	test-4				:	echo '$USER'
-	NOTE				:	nothing should be interpreted (expand) in single quotes