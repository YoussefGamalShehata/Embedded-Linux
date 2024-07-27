#Starting the kernel with root file system located in the RAM **[initramfs]**

# Thinking:

1- Utilizing RAM for executing applications offers significant performance advantages over SD cards, primarily due to its much higher data transfer speeds. RAM provides faster read and write operations,
   resulting in quicker access to application data and smoother performance
   
2- So we decided to load our **Root file system** into RAM and force the kernel to start up on this RFS

# Process:
1- Due to we have limited resources such as low RAM size we dont need to transfer all the **Root file system** in the RAM,just only the neccessary and critcal needed to the kernel will be load into RAM

2- To achieve this we need to Archieve the **Root file system** we will use **cpio** archieve method with **initramfs**

```
cd rootfs/
```

```
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
```

- The above command generates an archieved file **initramfs.cpio** in the main directory using the **cpio** archieve method then refer the owner of the file to the **root**


![image](https://github.com/user-attachments/assets/3aac7c28-f5be-44b4-b0d5-3c7e775d3d7c)


3- After Archieveing the **Root file system** we will compress the generated file to reduse its size using **gzip** command as follows:

```
gzip initramfs.cpio
```

4- Apllying **mkimage** command to the compressed file to generate the binary to be loaded by u-boot then CPU executes it during booting

```
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```

- The line generates a binary file called **uRamdisk** from **initramfs.cpio.gz** and its type is ram which means it will be loaded into RAM also the arch is arm and OS is linux
  

5-Now you can find in the **rootfs** partition the **uRamdisk** file as shown:


![image](https://github.com/user-attachments/assets/e8cc1149-06e4-46ca-8f99-8474179d4b30)


6- Copy the **uRamdisk** file becaues you are going to load it and the bootable partition here is **boot** partition so we need this file in the **boot** partition

```
 sudo cp uRamdisk /media/youssef/boot
```

7- **QEMU TIME** .... open Qemu now

```
qemu-system-arm –M vexpress-a9 –m 128M –nographic –kernel u-boot –sd sd.img
```

8- At this step you have to change some variables 

**bootcmd** variable:

- we need to load the **uRamdisk** file so we are goning to add fatload command for this file but wait a second !!! where can you load this file ?? as we know the kernel has a recommended address and also FDT but uRamdisk
has no recommended address you can decide the address of uRamdisk based on your system ... just use command **bdinfo** in u-boot and look at start address and size and take care to select an address suitable for uRamdisk
away from $kernel_addr_r and $fdt_addr_r.....Based on my System i selected **0x67000000**
So i have created a variable called **initramfs** and set it with **0x67000000**

```
setenv initramfs 0x67000000
```

```
editenv bootcmd
```

**bootargs**

- Due to the kernel starts based on the root file system in the ram we need to edit the **init** inside bootargs to be **rdinit**
  
```
editenv bootargs
```

```
saveenv
```

![image](https://github.com/user-attachments/assets/d3aabb9d-e4b2-459c-8ace-dfd8dce499fb)


9- Now Testttt

```
reset
```

## C O N G A R T Z, you did itttttt with initramfs!! 🔥


![WhatsApp Image 2024-07-27 at 6 22 15 PM](https://github.com/user-attachments/assets/9fecfa59-0962-4a27-9043-ceb1aa8a2a98)



