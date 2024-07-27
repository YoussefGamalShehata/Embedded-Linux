# Starting up and loading the kernel by inittab

## Thinking:
1- We have faced an issue in the pervious task that the kernel had a panic which was **Not Sync with Root file system** and it was logic panic there was no any RFS the kernel can use to start up
2- So we need to Create our RFS that helps the kernel to start up
## Process:
1- Creating a root file system is not easy we need to create all the directories needed to the system which are **[bin - sbin - usr - dev - etc - proc - mnt - home - sys - boot - root - srv]** under the **ext4** partition
   in the SD-card
2- Filling these Directories with the sutiabl files such as the system utilities need to the user-space and system configurations 

3- There is a tool called **BusyBox** helps us to create the system utilites and the init process which the kernel invokes at the beginning so **BusyBox** creates 3 Directories of our **RFS** >>> **[bin - sbin - usr]**

4- Clone the **busybox** Repo 
    ```
    git clone https://github.com/mirror/busybox.git
    ```
    ```
    cd busybox
    ```
5- Need to build the busybox to generate the 3 Directories but we need to set a group of general configurations first
      ```
      export CROSS_COMILE= <Path of Vexpress_ca9 Tool-chain>
      ```
      ```
      export ARCH=arm
      ```
      ```
      make menuconfig
      ```
      - we are gonning to build it statically which prevent the busybox to create dynamic libraries in the /usr directory so we need to force this in the menuconfig as follows:
      
      ![image](https://github.com/user-attachments/assets/598e1fdc-05ef-4372-af6e-a5e26f83465f)
 6- Now you are ready to build **Busybox**
     ```
     make
     ```
 7- Make sure that the generated **busybox** file is **ARM** archetecture and **Statically** using the following command:
     ```
     file busybox
     ```
 8- Where is the 3 Directories ???
 
     Not generated yet !! you need to do the following command which is generates a directory called **_install** contains the 3 Directories
     ```
     make install
     ```
     ```
     ls
     ```
     
     ![image](https://github.com/user-attachments/assets/345a845f-c9e5-4796-b486-018355d64262)

     ```
     cd _install/
     ```
     
     **Here is your 3 Directories**
     
     ![image](https://github.com/user-attachments/assets/8f163dc0-ec01-460c-977e-350c4cc2e055)

  9- Now copy all the content inside **_install** directory into your root file system which is the rootfs partition inside the sd card
      ```
      rsync -a ~/Desktop/BusyBox/busybox/_install/* /media/youssef/rootfs
      ```
      ![image](https://github.com/user-attachments/assets/0b218c09-3eec-4d65-99da-6ca8af04e373)

  10- Now need to create the init.d directory which contains the rcS script will be invoked by the inittab to mount the **devtmpfs** , **sysfs** and **proc**
      ```
      cd etc/
      ```
      ```
      mkdir init.d
      ```
      ```
      touch rcS
      ```
      ```
      #!/bin/sh
      # mount a filesystem of type proc to /proc
      mount -t proc nodev /proc
      # mount a filesystem of type sysfs to /sys
      mount -t sysfs nodev /sys
      # mount devtmpfs if you forget to configure it in Kernel menuconfig
      #there is two options uncomment one of them  
      mount -t devtmpfs devtempfs /dev
      ```
      - **You need to add the execution permission to the rcS Script**
      ```
      chmod +x rcS
      ```

      - **Create inittab file in the /etc**
      ```
      cd etc/
      ```
      ```
      nano inittab
      ```
      ```
      #When system startup,will execute "rcS" script
      ::sysinit:/etc/init.d/rcS
      #Start"askfirst" shell on the console (Ask the user firslty to press any key) 
      ttyAMA0::askfirst:-/bin/sh
      #when restarting the init process,will execute "init" 
      ::restart:/sbin/init
      ```
  11- Open **QEMU** Now and you have to edit the **bootcmd** and **bootargs** variables as follows:

      **For bootcmd**
      
      ```
      editenv bootcmd
      edid: fatload mmc 0:1 $kernel_addr_r zImage; fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb; bootz ${kernel_addr_r} - ${fdt_addr_r}
      ```
      
      **For bootargs**
      
      ```
      editenv bootargs
      edid: console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init 
      ```
      
      ![image](https://github.com/user-attachments/assets/6bd6be4f-96ad-4ddb-a465-165efbc49891)

      ```
      saveenv
      ```
      
      ```
      reset
      ```

      ### Congratulations !! , You started you kerneeeeeeeel yoyoyoyoyo

      
      ![WhatsApp Image 2024-07-27 at 3 06 10 PM (1)](https://github.com/user-attachments/assets/2f20bd45-8d9f-4085-a1f6-f3901670a2bc)

      
      
    

      

