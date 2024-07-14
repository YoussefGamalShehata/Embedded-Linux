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
        2- File system Algorithm is FAT16
        3- Bootable Partition
  
  **The Second one** has the following proporties :
  
        1- Its name is rootfs
        2- File system Algorithm is ext4
        3- Not Bootable Partition



















