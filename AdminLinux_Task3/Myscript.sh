#!/bin/bash

#check on the .bashrc if exist or not using File condition "-f"
Required_Path=$HOME/.bashrc
if [ -f ${Required_Path} ]
then
#in case the file exist we need to append new Enviroment variable so i will use export in .bashrc
echo "export HELLO=${HOSTNAME}" >> ${Required_Path}
echo "LOCAL=$(whoami)" >> ${Required_Path}
#this command gnome is configered to open a terminal and using & that means that the process will be in the backgroung
gnome-terminal &
else
echo ".bashrc file doesn't exist in you $HOME"
fi
