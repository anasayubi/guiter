#!/bin/bash

# Format:
# op.sh [PROGRAM] [FILE]
# op.sh -l -> lists the current screen sessions
# otherwise shows help

# ensure that screen is preinstalled on your system

BOLD=$(tput bold)
NORMAL=$(tput sgr0)

# run program($1) with file($2)
if [[ $1 ]] && [[ $2 ]]
then
  screen -d -m $1 $2
# list the current processes running background
elif [[ $1 == -l ]]
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
  echo $FILE_MIME
  xdg-mime query default $FILE_MIME
# open file($1) with default application 
elif [[ $1 ]]
then 
  FILE_MIME=$(xdg-mime query filetype $1)
  APPLICATION=$(xdg-mime query default $FILE_MIME)
  # now run application
  gtk-launch $APPLICATION $1
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
