# Booting our vexpress_ca9 Development Board using bootflow method especially "extlinux" using Fake zImage and dtb file

## Thinking:

1- We need to boot our system regardless of the script we used before to load

2- To load without the need for a script we can use the **bootflow** mechanism to achieve our goal

- **bootflow** explanation
  using the command
  ```
  bootflow scan
  ```
  leads to a search in all storage devices about boot configurations....in our case we use the **extlinux** method for boot configuration so once the **bootflow scan** reaches **extlinx** directory it boots from it.

## Process:

 1- Create in the **boot** partition a new directory called **extlinux**
 2- Create inside the **extlinux** directory a new file called **extlinux.conf** you can see what is inside this file from the above attached file **exlinux.conf**
 3- Don't forget to create the **zImage** and **file.dtb** in the **boot** partition so the boot partition contains the following :
     - Note: the script ubootScript.txt and the other files will not affect anything because we are going to change the **bootcmd** variable to **bootflow scan** as we will see in the next steps
     
   ![image](https://github.com/user-attachments/assets/8b43b431-90e4-4e93-8d93-f60b4666e104)

 4- Now we can Run **QEMU** from the u-boot directory using the following:

    Note: we will not use the **-net** flag in the **QEMU** command because this method of booting is available only with booting from SD-Card and can't be used with loading from server

 
    qemu-system-arm –M vexpress-a9 –m 128M –nographic –kernel u-boot –sd sd.img

  5- After Running QEMU you are about to face a problem that is loading using **fatload** not **extlinux** that's because you need to do the following:
  
        ```
        editenv bootcmd
        edit: bootflow scan
        ```
        
        ```
        saveenv
        ```
        
        Then Exit from QEMU and run it again


  6- Here is the final result
  
  ![image](https://github.com/user-attachments/assets/19d6d3c4-3011-44c6-81e3-d47ace865585)

  ![image](https://github.com/user-attachments/assets/ec0c5198-8d54-4c15-abd0-895db3c9a128)

 
    
