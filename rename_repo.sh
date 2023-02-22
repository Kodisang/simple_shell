#!/bin/bash

git remote set-url origin https://github.com/Sean/Simple-shell.git
git pull
mv Simple-shell simple_shell
git add .
git commit -m 'Rename repository from Simple-shell to simple_shell'
git push
