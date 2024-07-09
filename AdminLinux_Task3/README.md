#Task3

##Section 1 :

As the above Script we got the next Results :
   1- due to the .bashrc exist in the Home Directory my script passed with true condition
   2- open new terminal to be a new process in the background 
   3- Testing the new added variables in the new terminal as shown below
   
   a-
![Screenshot from 2024-07-09 22-27-47](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/b039b3bc-9a04-4460-842c-928f9a78a70d)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------

   b- 
   
![Screenshot from 2024-07-09 22-29-35](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/a9d2a3eb-790a-441a-a295-48de5930e62e)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
##Section 2:

1-
we can make sure listing the user commands through the directory /usr/bin so using the following command :

```
ls /usr/bin
```

![Screenshot from 2024-07-09 23-01-10](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/9401e11c-ac0a-434f-b7b2-6a5f3f80e7ac)


Then redirect them to /tmp/commands.list using the following command:

```
ls /usr/bin >> /tmp/commands.list
```

to make sure that they had been redirected we can use command more to scroll and see as following:

![Screenshot from 2024-07-09 23-10-03](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/d7cf0599-9bd9-48b9-8b4f-f6c1e73f0de3)

![Screenshot from 2024-07-09 23-02-47](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/64ebe157-1dde-412b-b648-79e244145f5c)

2-
we can edit our general .bashrc file to insert an statement that display the date once we open the terminal as following:

![Screenshot from 2024-07-09 23-19-52](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/03087f42-3c1b-4934-84b6-fd30a8526a15)

To tes it we can open new terminal as following :

![Screenshot from 2024-07-09 23-20-56](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/18c05c17-88d9-4f5f-96de-d21535629d49)


3-
To Count the Number of words in a file we can use the following command:
```
ws -w filename
```
but in our case we need to coung the number of user commands which can be done with samt concept but according to directories and files as following:
```
ls /usr/bin | wc -w
```
![Screenshot from 2024-07-10 00-09-42](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/3c91ab2a-8125-4f23-8029-8bc2b444d100)

4-
The output of :
```
cat f1 | cat f2
```
will display the content of f2 only as following 

![Screenshot from 2024-07-10 00-29-33](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/7f3dee7b-13d3-48d7-88d5-cc0741e584d0)

![Screenshot from 2024-07-10 00-29-45](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/1fb679e2-9547-4b9e-bb68-ca78134b4a98)

The output :

![Screenshot from 2024-07-10 00-32-02](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/3aa480f7-7ea7-4233-9a81-b84399caa1eb)

5-

using locate command i searched on .profile on the whole system as following :
```
locate .profile
```
![Screenshot from 2024-07-10 00-54-46](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/cbd7284c-a7ce-4ff0-b10d-6f2096c8eb9c)

6-

To prind id of each file in a directory we use
ls -i <filename>
or
ls --inode <filename>
in our case :
a- for /
```
ls -i /
```
```
ls --inode /
```
![Screenshot from 2024-07-10 01-14-01](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/48d2e2ca-fef6-42d2-a5e7-3fdc4d98cc56)

b- for /etc 
```
ls -i /etc
```
```
ls --inode /etc
```

![Screenshot from 2024-07-10 01-12-04](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/a1d6e78f-d8ee-4403-b8e2-8fd7f6d9b529)

c- for /etc/hosts

```
ls -i /etc/hosts
```
```
ls --inode /etc/hosts
```
![Screenshot from 2024-07-10 01-17-18](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/fe74a34c-9cab-41b8-9f95-3b6939848e48)


7-

![Screenshot from 2024-07-10 01-34-01](https://github.com/YoussefGamalShehata/Embedded-Linux/assets/152656762/ad52e92f-760d-4d15-8d4d-aee3cef96f7a)

8-

We can't generate a hard link in this case due to passwd is a directory not a file and this conlicts with the concpet

9-
echo \ command prints > which means that the shell is wating an input from the user
to change > to be : 
we can use Environment variable PS1 as following


