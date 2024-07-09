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





