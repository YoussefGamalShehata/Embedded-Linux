#!/bin/bash
while true
do
	read -p "Please Enter Your User Name : " user_name
	if  grep "^${user_name}"  /etc/passwd
	then
		echo "Failed to create User...Already Exist!!"
		continue
	else
		sudo useradd -m ${user_name}
		echo "Successfully User : ${user_name} Created"
		read -p "Please Enter Your Group Name : " group_name
	fi
	if  grep "^${group_name}"  /etc/group
        then
        	echo "Failed to create Group...Already Exist!!"
        	continue
	else
		sudo groupadd ${group_name}
		echo "Successfully Group : ${group_name} Created"
		sudo usermod -aG ${group_name} ${user_name}
		echo "User ${user_name} has been added to Group ${group_name}"
		break
	fi
done
