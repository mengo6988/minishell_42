# EVAL-SHEET-VOL-02
## SECTION-1-ENV
-	test-1				:	env & export

## SECTION-2-EXPORT
-	test-1				:	export test, check env & export 
-	test-2				:	create a new environment variable (export new=133)
-	test-3				:	replace an existing environment variable (export new=444)

## SECTION-3-UNSET
-	test-1				:	repeats section-2 tests 
-	test-2				:	unset the new variables, check env & export
-	test-3				:	unset an old variable, check env & export
-	test-4				:	unset a non-existing variable, check env & export

## SECTION-4-CD
-	test-1				:	navigate a few directions & check with /bin/ls
-	test-2				:	navigate to non-existing directory
-	test-3				:	add '.' and '..' to the arguments

## SECTION-5-PWD
-	test-1				:	pwd with no args
-	test-2				:	repeat multiples times in different directories