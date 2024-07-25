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


  





  
