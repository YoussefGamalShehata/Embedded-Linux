# Adding a Special Package to the Buildroot's menuConfig (Multi-Threading Application)

## Thinking:

1- Imagine to add a package in the menuconfig of the buildroot !! ....

2- You can add whatever you want in the **menuconfig** but first you need to understand the sequence to do this mission

3- You need to find out which is the directory contains all the packages

4- Discover one or two packages inside the packages directory to what is the main componets to add a new packaged in the menuconfig

5- Statr to create your package directory and also the specific files which you discovered 


## Process:

1- If you use **ls** command inside the buildroot directory you will fine the following:
```
cd ~/Desktop/BuildRoot/buildroot
```
```
ls
```

![image](https://github.com/user-attachments/assets/64ae0c4a-c01b-463a-b58c-556097163c2e)


2- Go to the **package** directory which is the directory contains all the packages supported by buildroot tool:
```
cd package
```

```
ls
```

![WhatsApp Image 2024-08-04 at 9 52 23 AM](https://github.com/user-attachments/assets/d465a149-fe8c-47ef-a49b-ad572d27e98c)


3- As you see in the above image there are many directories each one is the directory of a certian package

4- Let's go inside one of them to see what are the needed files to create a package directory
```
cd
```
- As you see there are 2 main files in each package directory
  
    1- Config.in
    2- Package.mk
  
![image](https://github.com/user-attachments/assets/921b917a-8f19-4f71-b83a-02cdf8515140)


5- **Now what is required?** >>>> Just creating a Multi-Threading Application to the package directory of the buildroot to be selected from **Target Packages** from the **menuconfig**

6- Go to the main package directory then create your special package directory which contain 
    - Source code of your Multi-threading Application
    - Makefile to automate the building of the source code by buildroot
    - Config.in file
    - Myapp.mk (as we saw above)

7- Follow the steps:
```
cd ~/Desktop/BuildRoot/buildroot/package
```
```
mkdir MyApp
```
```
cd MyApp
```
```
touch MyApp.cpp MyApp.mk Makefile Config.in

```

![image](https://github.com/user-attachments/assets/3db1024e-1e84-4154-bcce-7c00f64a2de1)



8- At first we want to write our application in **MyApp.cpp**:

```
#include <iostream>
#include <thread>

void printMessage1() {
    std::cout << "hello Youssef Gamal" << std::endl;
}

void printMessage2() {
    std::cout << "Welcome to Luxoft Community" << std::endl;
}

void printMessage3() {
    std::cout << "Let's Start" << std::endl;
}

int main() {
    // Create three threads
    std::thread t1(printMessage1);
    std::thread t2(printMessage2);
    std::thread t3(printMessage3);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
```

9- Write the **Makefile**:

```
nano Makefile
```

```
.PHONY: clean
.PHONY: MyApp

MyApp: MyApp.cpp
    $(CC) -o '$@' '$<'

clean:
    -rm MyApp
```

10- Write **MyApp.mk**:

```
nano MyApp.mk
```

```
################################################################################
#
# Multi-Threading Package Added by Youssef Gamal
#
################################################################################

MyApp_VERSION = 1.0
MyApp_SITE = package/MyApp/src
MyApp_SITE_METHOD = local# Other methods like git,wget,scp,file etc. are also available.

define MyApp_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define MyApp_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/MyApp  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
```

11- Write **Config.in**:

```
nano Config.in
```

```
config BR2_PACKAGE_MYAPP
    bool "MyApp"
    help
        MyApp package.
```

12- There is only one step left: you need to go to the main package directory and edit the main **Config.in** file to include inside it the *Config.in** file you have created in you package as follows:

```
cd ~/Desktop/BuildRoot/buildroot/package
```

```
vim Config.in
```

 - You will see the following:
   

![WhatsApp Image 2024-08-04 at 10 56 46 AM](https://github.com/user-attachments/assets/8c0aa2c0-6fce-47e1-ab0a-a63bf2f88dc5)


13- In this step you have 2 options to add your Package in the **menuconfig**

- **Option 1:** You can add it under **Target Packgaes** by adding the following line under the **Target Packgaes** menu :
    
```
 source "package/MyApp/Config.in"
```
    
![image](https://github.com/user-attachments/assets/d1e0c25e-d76b-4217-b1a4-2a655afe4c4d)

**In this Case go to the main directory of the buildroot and run the menuconfig command**

```
cd ..
```

```

make menuconfig
```

**Go under Target Packages and you will find your new package as follows:**


![WhatsApp Image 2024-08-04 at 10 47 20 AM](https://github.com/user-attachments/assets/9cc27ea8-cb0e-42e7-ae8e-2c2e77ac6fab)


- **Option 2:** You can add it in the main menu by creating a new menu in the main **Config.in** file as follows :
  

  ![image](https://github.com/user-attachments/assets/c81fe8c2-0740-404e-897b-48cf77b09849)
  
  
**In this case go to the main directory of the buildroot and run the menuconfig command you will see the new package added in the main menu**

```
cd ..
```

```
make menuconfig
```

![WhatsApp Image 2024-08-04 at 10 47 19 AM](https://github.com/user-attachments/assets/e6577b8a-acff-46fd-8461-6847c33e2d65)





