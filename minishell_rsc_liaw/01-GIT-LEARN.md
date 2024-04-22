# git-learning-material
-	content-table				-
								:	[1. resources](#resources)
								:	[2. configurations](#git-configuration)
								:	[3. branching](#branching)
								:	[4. pull-request](#pull-request)
								:	[5. merge-conflicts](#merge-conflicts)
								:	[6 merge-and-rebase](#merge-vs-rebase)
## resources
-	free-code-camp youtube		:	git for professionals tutorial - tools & concepts...
-	free-code-camp youtube		:	git branches tutorial
-	cbea.ms						:	how to write a git commit message

## git-configuration
-	developer name 				:	git config --global user.name "New name"
-	developer email				:	git config --global user.email "New email"
-	change default branch name	:	git config --global init.defaultBranch main
-	enable colorful output		:	git config --global color.ui auto
-	default branch merge		:	git config --global pull.rebase false
-	verification and checking	-
								:	git config --get user.name
								:	git config --get user.email
-	git text editor				:	git confit --global core.editor "vim"

## commit
-	git diff 'filename'			:	show differences of a specific files / whole repository
-	git add -p					:	add selective chunk of code within a file
-	good commit message			-
								:	1.	separate title from body with a blank line
								:	2.	limit the title to 50 characters
								:	3.	capitalize the title
								:	4.	do not end the title with a period
								:	5.	use the impreative mood in the subject-line
								:	6.	wrap the body at 72 characters (line break)
								:	7.	use the body to explain (what & why) instead of how

## branching
-	use short git log syntax	:	git log --oneline (-n 5) (optional)
-	create new branch			:	git branch 'name' (commit-code) (optional)
-	switch branches				:	git checkout/switch 'name'
-	rename branch				:	git branch -m 'new name'
-	rename not-checkout branch	:	git branch -m 'branch-name' 'new name'
-	publish branch				:	git push -u origin feature
-	check ALL branches
	includin remote branches	:	git branch -a
-	tracking branches			:	git checkout --track -origin/'bash-branch'
-	track remote-git commits
	show (ahead/behind)			:	git fetch > git branch -v
-	push ALL branches' changes	:	git push --all
-	delete local branch
	(you can't del cur-active)	:	git switch (whatever not a del branch) > git branch -d 'name'
-	delete remote branch		:	git push origin --delete 'name'
-	merging branch				:	git merge 'name'
-	compare branches progress	:	git log 'b1'..'b2'
-	compare main to remote/main	:	git log 'origin/main..main'
-	grab file from other branch	:	git checkout 'target branch' -- 'file/dir name'

## pull-request
-	pull-request explain		-
								:	1.	you create a pull request from a branch on GitHub
								:	2.	you submit the pull request to the repository's maintainers
								:	3.	the maintainers review your pull request
								:	4.	the maintainers merge your pull request
-	how to create a pull request-
								:	1.	create a new branch
								:	2.	make changes on the new branch
								:	3.	push the new branch to the remote repository
								:	4.	create a pull request on GitHub

## merge-conflicts
-	merge vs rebase				:	merge = merge commit
								:	rebase = linear history
-	merge conflicts				-
								:	1.	merge the main branch into the feature branch
								:	2.	manually fix the conflicts
								:	3.	commit the changes
								:	4.	push the merge commit to the remote repository
-	merge conflicts				:	git merge main

## merge vs rebase
-	explain						:	while merge is a non-destructive operation, rebase is destructive
-	rebase conflicts			-
								:	1.	merge the main branch into the feature branch
								:	2.	manually fix the conflicts
								:	3.	commit the changes
								:	4.	rebase the feature branch onto the main branch
								:	5.	push the changes to the remote repository
-	rebase conflicts			:	git rebase main

# temp and others
-	git reset head pointer 		:	git symbolic-ref HEAD refs/heads/'name'
