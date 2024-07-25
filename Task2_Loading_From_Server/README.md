# Loading Fake zImage and file.dtb from Server Using tftp network protocol

## Thinking:
1- We need to connect the Server which is **X86** in this case to the **vexpress development board** on QEMU

2- This type of connection called **Virtual Network Connection** which means that we need to connect our **X86** to **QEMU** Virtually

3- From the **X86** Side the **TAP** which is virtual network interface avaliable on **X86** 

4- From the **QEMU** Side it is so easy to emulate a **network interface card (nic)** using flag **-net**

## So what should we do ???
- Install TAP network interface using the following command
  ```
  sudo apt-get install tftpd-hpa
  ```
- Creating a TAP on **X86** side giving it a random **IP Address** to give us the chance to connect to it then check if it works or not **the above script [TapScript.sh] for creating the TAP]
  To check it works or not use the following command
  
  ```
  sudo systemctl status tftpd-hpa.service
  ```
  
  ![image](https://github.com/user-attachments/assets/22f57680-8a9a-40da-862e-fbbd3cdcca14)


  **Note**: you need to edit the configurtaion of accessing **/srv/tftp** which is the directoy acting like **server** and loading fils will be from this directory
            you need to do the following:
  ```
  cd /etc/default
  ```
  ```
  sudo nano tftpd-hpa
  ```
    - Edit the **TFTP_OPTIONS**   to be as the following :
      
 
  ![image](https://github.com/user-attachments/assets/a0d8dfc7-47b3-4712-80c9-e07428ed8383)

    - Also you want to go to **/srv/tftp** to create the fake files **zImage** and **file.dtb** but first you need to change the owner as follows:
      **Before**

      ![image](https://github.com/user-attachments/assets/d952adf6-1e1e-4594-9d08-f361ac084acf)

      ```
      chown tftp:tftp tftp
      ```
      
      **After**
      
      ![image](https://github.com/user-attachments/assets/4d85a0fc-6675-4804-9c8b-9e64c64e710e)

  - Now Create the fake files
    
    ![image](https://github.com/user-attachments/assets/95c13b60-78a4-4917-9eed-0471edb03441)

  - Run the **TapScript.sh** to create TAP
    ```
    sudo chmod +x TapScript.sh
    ```
    ```
    ./TapScript.sh
    ```
    ```
    ifconfig
    ```
    
    ![image](https://github.com/user-attachments/assets/9adf6606-f43b-4edc-a25e-fa442d13e4cf)

  
  - Now you did well on the **X86** side you can now run **QEMU** Using the following command
    
    ```
    sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/Myblock/sd.img
    ```
  - You may face the following problem which is everything is good but can load due to **serverip** variable is not set as follows:
    
    ![image](https://github.com/user-attachments/assets/bb82e985-ab64-4227-b533-1ca36bf97ec9)

  - To solve this problem all you need to do
    ```
    setenv serverip <Your TAP_IP>
    ```
    ```
    saveenv
    ```
    Then **Exit** QEMU and open it again
  - The Final Result will be as follows :
    
    ![image](https://github.com/user-attachments/assets/18e63aff-017e-49ae-adcb-8682883874f6)
    

    ![image](https://github.com/user-attachments/assets/c1016465-2d69-4c42-9f10-d33a9d8c71a0)



  ## To make the Loading more generic you can use a uboot script that gives 2 different options for Loading as follows:
  **You can see it in the above script [ubootScript_Both.txt]**

  ![image](https://github.com/user-attachments/assets/b65c7915-a703-44d7-9b64-544a0d247d68)




  
