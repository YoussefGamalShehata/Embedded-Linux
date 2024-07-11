#Task_1

##Scripting

- As the above script (File_organizer.sh) and the image below here is the script by which we can organize a desired directory in our file system

![Screenshot from 2024-07-11 14-14-17](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/ffaabae2-fa8d-441f-ad73-8f0f99fd2311)

##Steps of Thinking
1-
The First step is how we can take a directory from the user ? to achieve this we can ask him to enter the path of the desired directory using read command as following
```
read -p "Please Enter Your Directory Path: " D_Path
```
through this line i will print to the user **Please Enter Your Directory Path** waiting him to enter the path and store it in **D_Path** Variable

2- 
The second step is to check on the user input we don't know the user behaviour so we must take care of that i did that through a simple check using one of the file conditions **-d** on the directory path given by the user
in case the user enters an existing real directory the script will go through its functionality which is organizing the files into a servel subdirectories
in case the user enters a file path or non existing directory the script will ask him to enter new right path of a directory

3-
about the script right behaviour in case entering true condition first changing directory to be in the desired directory using **cd** command
```
cd ${D_Path}
```
Then creating the 3 required directories to handle the organization process using **mkdir** command
```
mkdir -p images documents others
```
Now we can move the files into the created subdirectories but to achieve this point we need to filter the files to move the documentation files into the document directory and photos into image directory and any other files 
will be stored into others directory so the wild card symbol **\*** will make it so easy as following lines
```
mv *.jpg *.png *.gif ${D_Path}/images/
mv *.txt *.doc *.pdf ${D_Path}/documents/
```
now we moved some of the files to its directory but there are other files how can we stored it into others directory ??
first we can find a problem if i write the next line
```
mv *.* ${file} ${D_Path}/others/
```
that means that everything inside the main directory will be moved into others directory including **images** and **documents** and this behavior is not consistent with our goal
To solve this problem we need to check on everything remaining in the main directory **is it a file or no ?**
by using the following for loop inside the main directory i could to catch only the files exist regardless the directories
```
for file in ./*
do
        if [ -f ${file} ]
        then
                mv ${file} ${D_Path}/others/
        fi
done
```
in the first line **for file in ./\***
I'm trying to loop in the current directory using **.** with everthing exist in it using **\***





















