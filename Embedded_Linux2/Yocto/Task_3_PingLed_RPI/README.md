# Creating a simple RPI Image which has a special Recipe to Ping a Led

## Thinking:
1- Building Up the meta-layer which contains the recipe.
2- Using a ready image recipe to build like **core-minimal-image** or **core-minimal-sato**.
3- Writing a script using bash to access /sys/class/gpio to ping a led on the desired rpi.
4- Adding a recipe-pingled to the meta-layer.
5- Adding some dependencies to our image.

## Process:
1- We need to clone Poky Repo to build up our **Build Environment** for RPI:

```
git clone -b kirkstone https://github.com/yoctoproject/poky.git
```

2- Using **oe-init-build-env** script to create my Build Env:

```
source oe-init-build-env
```

![image](https://github.com/user-attachments/assets/0d8a026e-5a0c-409d-8cf9-cb7299a407f3)

3- Before anything we need to decide the layers on which my image depends on through **bblayers.conf** file


![image](https://github.com/user-attachments/assets/0aa4f076-4753-4e7c-adb7-e4157fddc7c7)


4- My meta-layer is called **meta-iti** which has the following tree:

![image](https://github.com/user-attachments/assets/9a82423b-4b1d-4d1a-869d-99d90cbfbbeb)


5- I'm going to create my distro 
