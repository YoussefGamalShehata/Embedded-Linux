# Booting The Vexpress Kernel using extlinux method

## Thinking:
1- We want to boot the generated kernel 
2- we need to take the **zImage** and **vexpress_dtb** files and put them into the **boot** partition
3- Opening Qemu 

## Process:

1- First we need to take our kernel and dtb and put them in the **boot** partition

![image](https://github.com/user-attachments/assets/9f4019c1-0f1e-4d22-adb0-210cd72046fb)

2- Don't forget to edit the **FDT** part in the **extlinux.conf** to be **vexpress-v2p-ca9.dtb**

3- Open Qemu:
```
qemu-system-arm –M vexpress-a9 –m 128M –nographic –kernel u-boot –sd sd.img
```

4- The Result:

  #### Our Kernel has been loaded successfully 

![image](https://github.com/user-attachments/assets/026d576e-28f5-4f52-ac16-399fd771c684)


5- You will see the following **Kernel Panic**:

![image](https://github.com/user-attachments/assets/9c854b67-2717-4790-b398-fc0716fa4a27)

- **Note**: Our **Problem** is about that the kernel can't find a **Root filesystem** to sync with it so your kernel will not continue
            The **Solution** of this problem is to create a **Root filesystem** and this solution will be provided in the next task **Task6**

