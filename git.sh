#!/bin/bash

# collect commit message
read -p 'commit msg: ' msg

# checks if an arg is passed or not
if [[ -z $1 ]];
then
	git add .
else
	git add $1
fi

git commit \-m "$msg"

git push

# Pushes all files in the current directory
