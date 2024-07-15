# Session Task **[Emulation of SD-CARK(1GB) usin simple File]**

## Thinking Procedure :

- To go through our task  we need to know what is Emulation and what is the difference between
   **Emulation** & **Simulation**?

  **Emulation** :
  
   It is the concept of seeing **performance** and **behavior** that affects **real hardware resources** by your          software
   When you say you are doing simulation, you should keep in mind that your program will be taken into account along      with how you build its behavior with the hardware resources you are emulating.

  **Simulation** :

  It is the concept of just testing your software on a hardware with regerdless how the real hardware you are testing
  on will behaves with this software.
  Just seeing that the software is runable on this hardware only.
  
- **What do we need ?**

  We need to create virtual block storage on my device acting like **SD-Card** of total size **1GB** with
  **2 Partitions**
  **The First one** has the following proporties :
  
        1- Its name is boot
        2- The file system Algorithm is FAT16
        3- Bootable Partition
  
  **The Second one** has the following proporties :
  
        1- Its name is rootfs
        2- The file system Algorithm is ext4
        3- Not Bootable Partition

  **Optional** : mount the created block storage to our root 

## -------------------------------------------------------------------------------------------------------------
1- 
Creating a simple file named **sd.img** 

2- 
How can we resize the file **sd.img** to be **1GB** ?
Using an existing file in our file system called zero, you can find a zero file at the following path :
**/dev/zero**
we need to inject zeros from **/dev/zero** to **sd.img** until the size reaches **1GB**
Using the **dd** command as following:
```
dd if=/dev/zero of=sd.img bs=1M count=1024
```
The above command says :
Copy Zeros from **/dev/zero** To **sd.img** with 1Mbytes of Zeros each time for 1024 times so after 1024 times we will have 1024Mbytes of zeros inside **sd.img** 
and now we have 1GB file as Raw memory **(^@)**

![88db4c63-0cd2-4a01-b8e0-4f8800a04678](https://github.com/user-attachments/assets/1efe7b15-9140-4f9a-b88c-943b04e3a425)

3-
Now we need to create our Partitions inside **sd.img** with the specifications for each one i had mentioned above
using the following command:
```
cfdisk sd.img
```
result in a selection on the monitor you need to select the following :
**For boot Partition**:
    1- dos
    2- new
    3- Configure size to be **200M**
    4- bootable
    5- select type then **FAT16**
    6- Select write then reply **yes**

**For rootfs Partition**:
    1- new
    2- configure size to be **500M**
    3- **Don't select bootable**
    4- Select type then **Linux** represents ext4
    5- Select write then reply **yes**

**After you finish Select Quit** that take you into terminal 

Now we want to force the loop device to deal with the **sd.img** as it is a block storage we can do that through the following command :
```
losetup -f --show --partscan sd.img
```
As you see in the image below **loop13** is selected to be the loop device that represents our file **sd.img** and in the path of **/dev/** we see that **loop13**
became has 2 partitions **loop19p1** and **loop13p2**
![62c9137a-8cc8-47d2-b6d2-d576421c0d67](https://github.com/user-attachments/assets/33183223-446c-415d-846f-915cca55aed3)













