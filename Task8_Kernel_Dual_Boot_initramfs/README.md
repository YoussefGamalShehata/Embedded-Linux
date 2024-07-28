# Dual Booting our Kernel from 2 diffrenet Root File System using initramfs

## Thinking:
1- We have made our kernel to starts on a **Root file system** From RAM using initramfs methos and this method increase the speed of the booting over the other method booting from Sd-card **RFS**

2- Now we have to add an great option to our kernel which is to select one of two **Root File Systems** exist on the machine based on the user selection 

3- This new option increases the reliability of the system and also the comfort of the user it is like a **boot manager** who manage which **RFS** will be launced

## Process:
1- We need to add a new partition to our **Virtual Sd-card** using **cfdisk** command but first please dont forget to detach the current loop for your sd-card as follows:
- in my labtop the loop is 24
  
```
sudo losetup -d /dev/loop24
```
```
cfdisk sd.img
```

![image](https://github.com/user-attachments/assets/f1770232-2a5d-49da-b7b3-2fad0f716d65)


2- Quit and do the following command to give a loop to the sd-card:

```
sudo losetup -f --show --partscan sd.img
```

3- Apply the **ext4** algorithm using the following command: 

```
sudo mkfs.ext4 -L rootfs1 /dev/loop24p3
```

4- Now go to the new partition and create the RFS inside it but we are goning to copy the root file system from the old root file system partition which is **rootfs1** to be clear see this photo


![image](https://github.com/user-attachments/assets/e720b619-3fd8-4cc8-84a0-8aa444663546)

5- Now we need to create a script that manages the booring selection as follows:

```
#!/bin/bash
echo "Select an option:"
echo "1) rootfs1"
echo "2) rootfs1"
read -p "Enter choice: " choice

case $choice in
    1)
        mkdir -p /mnt/rootfs1
        mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs1
        chroot /mnt/rootfs1/rootfs1
        ;;
    2)
        mkdir -p /mnt/rootfs2
        mount -t ext4 /dev/mmcblk0p3 /mnt/rootfs2
        chroot /mnt/rootfs2/rootfs2
        ;;
    *)
        echo "Wrong selection"
        ;;
esac
```

- **Boot manager script**:

![image](https://github.com/user-attachments/assets/b4c9d62b-da4d-4bdd-b3b6-19abaa8c7c83)



6- You just need to indetifiy which rootfs has lunched to do this i have created a directory inside the rootfs1 called **Hello_From_rootfs1**
   and same one in the second partition **Hello_From_rootfs2**

**rootfs1**

![image](https://github.com/user-attachments/assets/e0819c32-594c-495e-8dea-19fc9d0ab554)


**rootfs2**

![image](https://github.com/user-attachments/assets/9e98a146-5074-4f7b-98aa-aa81f9df4d9e).


7- Now we need to archive out Roof File System as follows:

```
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
```

```
gzip initramfs.cpio
```

```
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```
- The uRamdisk file will be exist in your **rootfs1**, just copy it to the **boot** partition

8- You need to edit the **rcS** script to make the boot_manager script runs automatically as follows

![image](https://github.com/user-attachments/assets/8d14d1fe-b422-4508-b97f-19ebc1358bef)


9- **Open QEMUUU**

```
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic  -kernel u-boot -sd ~/Desktop/Myblock/sd.img
```

![WhatsApp Image 2024-07-28 at 5 54 24 PM](https://github.com/user-attachments/assets/305c091a-9d85-46db-98a8-bf28d3ad05ae)


9- The has been started and the script also launched as follows:


![image](https://github.com/user-attachments/assets/3fdb1e9b-e6be-425d-b7de-eee0c9af5552)


10- As the above image we have selected **2** which means that the kernel uses the **RFS** From the **rootfs2** partition to check this just use:

```
ls
```

![image](https://github.com/user-attachments/assets/05a01fbb-3631-4d65-b724-f22493631533)









