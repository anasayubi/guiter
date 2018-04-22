#!/bin/bash

# Format:
# op.sh [PROGRAM] [FILE]
# op.sh -l -> lists the current screen sessions
# otherwise shows help

## Prereqs:
# ensure that screen is preinstalled on your system

## For debugging purposes
echo \$1: $1
echo \$2: $2

BOLD=$(tput bold)
NORMAL=$(tput sgr0)

# list the current processes running background
if [[ $1 == -l ]]
then
  screen -ls
# list help
elif [[ $1 == -h ]]
then
  echo ${BOLD}Parameters allowed:${NORMAL}
  echo op.sh \[FILE\] : open FILE with the default program
  echo op.sh \[PROGRAM\] \[FILE\] : to open FILE with PROGRAM
  echo op.sh -l : return all the detached sessions
  echo op.sh -h : return help
  echo Run any invalid command to output this help
# output the default application of program($2)
elif [[ $1 == -d ]] && [[ $2 ]]
then
  FILE_MIME=$(xdg-mime query filetype $2)
  APPLICATION=$(xdg-mime query default $FILE_MIME)
  if [[ ! $APPLICATION ]]
  then
    echo No default application exists for the mimetype $FILE_MIME
  else
    echo $APPLICATION
  fi
# open file($1) with default application 
elif [[ $1 ]] && [[ !$2 ]]
then 
  FILE_MIME=$(xdg-mime query filetype $1)
  APPLICATION=$(xdg-mime query default $FILE_MIME)
  # now run application
  gtk-launch $APPLICATION $1
# run program($1) with file($2)
elif [[ $1 ]] && [[ $2 ]]
then
  screen -d -m $1 $2
# show help on invalid usage
else
  echo ${BOLD}Incorrect usage of op.sh! 
  echo The following parameters are allowed:${NORMAL}
  echo op.sh \[FILE\] : open FILE with the default program
  echo op.sh \[PROGRAM\] \[FILE\] : to open FILE with PROGRAM
  echo op.sh -l : return all the detached sessions
  echo op.sh -h : return help
  echo Run any invalid command to output this help
fi
