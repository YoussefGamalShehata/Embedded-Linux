#!/bin/bash

#Asking the user to enter a source directory which will be organized
read -p "Please Enter Your Directory Path: " D_Path
while true
do
#we need to check if the D_Path is directory or file
	if [ -d "$D_Path" ]
	then
	echo "Directory exist and processing to be organized"
	cd ${D_Path}
	mkdir -p images documents others
	mv *.jpg *.png *.gif ${D_Path}/images/
	mv *.txt *.doc *.pdf ${D_Path}/documents/
	for file in ./*
	do
        	if [ -f ${file} ]
        	then
        		mv ${file} ${D_Path}/others/
        	fi
	done
	echo "Go Check your Directory Now"
	break
	else
	echo "Not found Directory!!"
#Ask to enter exist directory
	read -p "Please Enter Exist Directory Path Please" D_Path
	fi
done
