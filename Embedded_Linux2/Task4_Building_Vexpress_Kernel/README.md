# Building the kernel for Vexpress_ca9 Development board

## Thinkin:
1- we want to build a kernel for our borad

2- So we need to clone the kernel and configure to be a kernel on our sepcific archeitecure 

3- Adding some configurations we want to our kernel

## Process:
1- You need to Clone the kernel
```
git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
```
```
cd linux
```
2- You need to apply the configurations for our development board
```
cd arch/
```
```
cd arm/
```
```
cd configs/
```
```
ls grep | vexpress
```

![image](https://github.com/user-attachments/assets/0d3f44f5-e144-4251-928b-c1b579d13549)


3- You need to apply the configurations so go to the main directory and use the following:
```
make vexpress_defconfig
```
4- Now we need to add more configurations we want so we can do that through **menuconfig** and we need mainly to add 3 configurations
    - Enable the automount for **devtemps**
    - Select the compression method to be **XZ**
    - Name the kernel version

5- You may some problems during the building of the kernel so before you start building please do the following:
```
sudo apt-get install libgmp-dev
```
```
sudo apt-get install libmpc-dev
```

6- Now you are ready to build your kernel 
```
make -j4 zImage modules dtbs
```
  - Explanation:
      - **-j4** speed up the building time by increase the power of CPU
      - **zImage** which is the compressed image to be generated
      - **modules** indicate to build all the needed modules
      - **dtbs** indicate to generate all the need dtbs files

** Here is your kernel has been generated **

    ![image](https://github.com/user-attachments/assets/287b50f1-ee44-4802-ba39-f317e305cffe)

7- You can reach your zImage and dtb files as follows:
```
cd arch/
```
```
cd arm/
```
```
cd boot/
```
```
ls
```
#### Here is you **zImage**

![image](https://github.com/user-attachments/assets/6ea00949-72d9-41bc-a837-d6baf47a481e)

```
cd dts/
```
```
cd arm/
```
```
ls | grep vexpress
```
#### Here is your dtb file [vexpress-v2p-ca9.dtb]

![image](https://github.com/user-attachments/assets/16934f56-a769-41fc-83a6-af5844902171)


    
