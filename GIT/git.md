# Git

Version Control System is a tool that helps to track changes in code.

> Git is a Version Control System

# Github

Website that allows developers to store and manage their code using Git

# Clone

Cloning a repository on our local machine

# init Command

init - used to create a new git repo

```
git init
git remote add origin <_link->
git remote -v           (to varify remote)
git branch              (to check branch)
git branch -M main      (to rename branch)
git push origin main
git push -u origin main
```

# Branch Commands

```
git branch                                 (to check branch)
git branch -M main                         (to rename branch)
git checkout <-branch name->               (to navigate)
git checkout -b <-new branch name->        (to create new branch)
git checkout -d <-branch name->            (to delete branch)

```

# Merging Code

### Way 1

```
git diff <-branch name->      (to campare commits ,branches,files & more)
git merge <-branch name->     (to merge 2 branches)
```

### Way 2

> #### Create a PR (Pull Request)
>
> It lets you tell others about changes you've pushed to a branch in a repository on GitHub

# Pull Command

used to fetch and download content from a remote repo and immediately update the local repo to match that content

```
git pull origin main
```

# Resolving Merge Conflicts

An event that takes place when Git is unable to automatically resolve difference in code between two commits.

# Undoing Changes

### Case 1 : Staged changes

The command used to stage any change in Git is git add.

```
git reset <-file name->
git reset
```

### Case 2 : Commited changes (for one commits)

In Git, HEAD points to the tip of the current branch, which is the commit where you last updated the current branch. So, HEAD is a reference to the most recent commit in the current branch.

> git log

When you create a new commit, Git automatically updates HEAD to point to the new commit. You can use the `git log --oneline` command to view the commit history of the current branch, and the commit at the top of the list is the one that HEAD is currently pointing

git reset changes where the current branch is pointing to (HEAD).
`HEAD` is a pointer or a reference to the last commit in the current branch. `HEAD~3` would mean behind three commits from `HEAD`.

```
git reset HEAD~1
```

### Case 3 : Commited changes (for many commits)

```
git reset <-commit hash->
git reset --hard <-commit hash->
```

Be aware that the git reset –hard HEAD or git reset –hard HEAD@{n} command would remove your uncommitted changes, even if you staged them. If you don’t want your unstaged changes to be removed, you can use the --soft flag instead of the --hard flag.

# Fork

- A fork is a new repository that shares code and visibility settings with the original "upstream" repository
- Fork is a rough copy
