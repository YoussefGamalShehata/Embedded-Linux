# Building The default Recipe and appending it with a Python script depending on Global variable

## Thinking:

1- We want to build a recipe

2- First of all we need to create a new **meta-Layer** outside of anything related to poky or open-embedded

3- Not only building a recipe we need to use Python logic that depends on a global variable 

5- So we need to define our Global variable and initialize it with a value

6- Creating the Python logic which depends on the global variable

7- Build all of this


## Process:

1- Clone the **kirkstone** release of the Poky :

```
git clone -b kirkstone git://git.yoctoproject.org/poky.git
```

2- Creating a recipe requires Creating a new **Meta-Layer** that contains all the **Meta-data** of which the **recipe** is one of them, So we can say that the first step is to create a new **meta-Layer**:

- To create a new **meta-layer** you need to follow the following steps:
  
  1- Source the **oe-init-build-env** to create your build environement
```
source oe-init-build-env
```
  2- You need to use the following command to create the **template** of the **meta-layer**
  
```
bitbake-layers create-layer ~/Desktop/Yocto/meta-iti
```

3- Now you have the **template** of the **meta-layer** you want to create as follows :

![image](https://github.com/user-attachments/assets/e2ba56ad-bdd4-4797-b401-ee8832767e74)

4- Now if you open **conf** directoy you will find **local.conf** what you need now is to create a variable in this file as follows:

```
cd conf
```

```
nano local.conf
```

```
MY_CUSTOM_VAR = "1"
```

![image](https://github.com/user-attachments/assets/c10b59a3-69ed-4173-92ac-15f38d6243f8)

5- Go to the directory of the recipes and start now to create you recipe, but in the default directory there is an example or default recipe you can test using it as follows:

```
cd recipes-example
```

```
cd example
```

```
ls
```

```
nano example_0.1.bb
```

![image](https://github.com/user-attachments/assets/84ac4017-8722-4d62-97ae-73fedaf8765b)


6- We need to add to this recipe the Python logic which depends on **MY_CUSTOM_VAR** Variable which I created to do this we have to create **.bbappened** file as follows:

![image](https://github.com/user-attachments/assets/5d3af156-82fe-48cb-ad95-5bd4deafc5cb)


7- You have to add the following logic to your **.bbappend** file
```
# example_0.1.bbappend

python __anonymous() {
    var_value = d.getVar('MY_CUSTOM_VAR')
    if var_value == "0":
        d.appendVar('do_display_banner', '\n    bb.plain("hi Joeeeeee")\n')
    elif var_value == "1":
        d.appendVar('do_display_banner', '\n    bb.plain("hi my friend")\n')
}
```

8- before building you have to include your new **meta-layer** in the building environment of the poky, you can do that by adding the absolute path of your **meta-layer** in the **bblayers.conf** file of the build directory in the **Poky** as follows:

```
cd ~/Desktop/Yocto/poky/build/conf
```

```
nano bblayers.conf
```

![image](https://github.com/user-attachments/assets/d38d9ea7-dde8-4a81-a15a-d5ad1fab7a31)

9- Now you can build

```
bitbake example
```

![image](https://github.com/user-attachments/assets/bc6bd29e-f17e-4f85-8d9a-685d574a4b47)


![image](https://github.com/user-attachments/assets/83ed0e11-026d-4011-b980-70d07f7bf5f5)

 




