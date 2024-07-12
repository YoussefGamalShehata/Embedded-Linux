# Task4
## Section 1 :
### Thinking Then Scripting:

The thinking of this script was about dividing it into three stages as follows:
![Untitled](https://github.com/user-attachments/assets/cedef38e-3626-4d6f-abba-2d5d7afbd1ad)

1- First Stage **(Creating User)**:

was about get the **Username** from the user then check if this **Username** is already exist on the system or Not
In case that the user entered a repeated **Username** on the system we need to warning him and ask him to enter new **Username**
In case that the user entered a non-repeated **Username** we will go to the next Stage

2- Second Stage **(Creating Group)**:

The user also here is responsible to enter the **Groupn_NAme** and apply the same behaviour as i did in the **Creating User** Stage
In Case we pass from this stage Now we can go to the next stage

3- Adding the new **User** to the new **Group**:
In this stage we are gonna to add the created user to be a member inside the new group

#### Here is the script after applying the above stages

![Screenshot from 2024-07-12 03-10-39](https://github.com/user-attachments/assets/321eb2a4-b00f-456c-b1b6-2bccfbe88667)

## -------------------------------------------------------------------------------------------------------------------------------------
### Testing The Script :
1-

The image below shows that when i tried to enter an exist **Username** the script refuesd to create it and print a warning message to indicate the user that there is a user with the same **Username**
Askin him to enter new **Username**

![Screenshot from 2024-07-12 03-11-27](https://github.com/user-attachments/assets/95f9df04-f77c-47ab-95f9-df9d65875278)

2-

The image below show the full process in success way or creating the user and the group 

![Screenshot from 2024-07-12 03-14-54](https://github.com/user-attachments/assets/926ebe5a-d404-4904-a787-481c40352295)

3-
Check the **/etc/passwd** to see my new user exist or not

![Screenshot from 2024-07-12 03-15-18](https://github.com/user-attachments/assets/f1398471-1426-4534-9c2b-e3a9dfcacaca)

4-

Check the **/etc/group** to see my new group exist or not and also the adding of the new user happened or not 

![Screenshot from 2024-07-12 03-15-43](https://github.com/user-attachments/assets/b86cc13a-5ad6-4447-ba7a-7b2f27388d5c)


