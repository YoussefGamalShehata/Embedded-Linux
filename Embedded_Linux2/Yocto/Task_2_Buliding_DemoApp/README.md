# Building a recipe of DemoApp using CMake

## Thinking:

1- We need to get the Application's Repo link.

2- Creating the Hireachy of the recipe in the layer.

3- Start the implementation of the recipe.

4- Run bitbake.

5- Run the Application.

## Process:
1- Our DemoApp exists at the following link:
```
https://github.com/FadyKhalil/DemoApp.git
```
2- Creating the Hireachy Environment for our Recipe **demoapp.bb** as follows:

![image](https://github.com/user-attachments/assets/a8042a24-f830-47a4-b933-d67c2f224613)

3- Implementing the **demoapp.bb**
- **Header Section** which consists of general information about the recipe 
```
SUMMARY="This recipe should clone a DemoApp CALCULATOR Package"
DESCRIPTION = "Calculator Application Package needed to be part of the final image so we have to create a recipe that processes the application."
```
- License Type and License Check Sum :
```
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
```
- Now time of **Development Section** Implementation:
**Using git scheme for SRC_URI variable to get the demoapp from github**
**Removing https:// from the repo link and set the protocol and branch** as follows:
```
SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
```
**As you have to use git scheme you need to set the SRCREV variable with the last commit hash of your Demoapp repo** as follows

```
SRCREV="720c663c5fd7246b4b42c5205d74db7d9784b5b2"
```

- As we know the default building setting in **bitbake** is **make** which leads to reconfiguring this setting due to we need to build using **CMake** not **Make** we can do this through the following line:
  
```
inherit cmake
```

- Overwrite the **do_configure** task to define the building method which is **CMake** as follows:
  
```
do_configure() {
    #staticlly build
    cmake -S ${WORKDIR}/git -B ${B} -DCMAKE_EXE_LINKER_FLAGS="-static" -DCMAKE_SHARED_LINKER_FLAGS="-static"
}
```

- Overwrite the **do_compile** task to **make** the result of the building which is a **Makefile** :

```
do_compile() {
    cd ${B}
    oe_runmake || die "make failed"
}
```

- Installing the Build results which are my Application's binaries in the **D** Directory as follows:

```
do_install() {
    mkdir -p ${D}${bindir}
    cp ${B}/calculator ${D}${bindir}
}
```
  
![image](https://github.com/user-attachments/assets/2d4e9a17-c543-4537-9633-5712f611ca51)


4- Run bitbake :
**Go to the build environment then run bitbake**

```
bitbake demoapp
```

![image](https://github.com/user-attachments/assets/d15d7dbe-29d7-4bdc-9067-261bcda090d9)

5- To run your Application you need to go to your **WORKDIR** (work directory) and then to the **image** Directory which contains **/usr/bin/demoapp** as follows:

![image](https://github.com/user-attachments/assets/5046a697-8450-4b36-b0b4-208036c8901b)

- In the above image we tested our **dempapp** which is a **calculator** and it ran successfully also the **file type** which is **statically linked**















