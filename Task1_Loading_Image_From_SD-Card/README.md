# Loading fake zImage and file.dtb from virtual SD_Card on vexpress_ca9 Development Board using QEMU

## Thinking:

1- make sure you set the configurations of the u-boot with vexpress_ca9 Board then build it

2- Create fake **zImage** file and **file.dtb**  in the **boot** partition as following 


![WhatsApp Image 2024-07-24 at 11 10 02 PM](https://github.com/user-attachments/assets/351eff08-bd45-4422-81ca-b8c7fe901ebe)

![WhatsApp Image 2024-07-24 at 11 09 37 PM](https://github.com/user-attachments/assets/15cbb7e9-551e-49f9-80af-f92ac2869793)


## Process:
1- Writing a **u-boot script** that loads the **zImage** and **file.dtb** from the **boot** partition and save the script also in the **boot** partition

![image](https://github.com/user-attachments/assets/56b0eb42-1a62-4af7-bb14-42a6914e55fc)

2- Generate the Binary file for the above script using **mkimage** command to load and execute the script by u-boot causing the loading of **zImage** and **file.dtb**

```
sudo mkimage -A arm -T script -C none -a 0x60003000 -e 0x60003000 -n 'ubootScript' -d /home/youssef/boot/ubootScript.txt   /media/youssef/boot/ubootScript
```

![image](https://github.com/user-attachments/assets/b6b6bc64-a6ea-400b-bb8c-eac0907717a7)

- At this point we have the binary file of the script in the **boot** partition

3- Setting up the Qemu depending on **[u-boot - virtual sd_card]** and editing the **bootcmd** variable to load the binary file of the script and start executing it using **source** command as following
```
editenv bootcmd
edit: fatload mmc 0:1 0x60003000 ubootScript; soruce 0x60003000
```

![image](https://github.com/user-attachments/assets/d71a1f0b-1405-4a33-a811-0e170321a163)


4-using command **saveenv** and reboot Qemu


5-Now the Script has been loaded causing the loading of **zImage** and **file.dtb**

![WhatsApp Image 2024-07-24 at 11 26 20 PM](https://github.com/user-attachments/assets/9826964c-edcb-429d-aafb-01be636feef6)

6- Using **md** command with the addresses inside the script **0x60002000** , **0x60002500** and **0x60003000** to ensure that everthing alright

```
md 0x60002000
```
```
md 0x60002500
```
```
md 0x60003000
```

![image](https://github.com/user-attachments/assets/31520b56-7500-4f2f-8515-31aff694409d)









