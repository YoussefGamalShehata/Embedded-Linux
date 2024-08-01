# Creating an application to be run under a certain Run Level as a daemon app (background)

## Thinking:

1- As we know that SystemV is working with the Run Levels concept, we need to create a dummy application that gets run once the Run Level is initiated 

2- To do this mission we have to follow the SystemV thinking way which will be mentioned in the process section below

## Process:
1- Create the **daemon application** you want as following:

```
mkdir ~/Desktop/MyApplication
```
```
cd ~/Desktop/MyApplication
```
touch MyApplication.c
```
nano MyApplication.c
```

- Now you need to implement your application as follows:

![WhatsApp Image 2024-08-01 at 10 33 17 AM](https://github.com/user-attachments/assets/729b7d26-d668-4ff6-9394-5b1ea1a3863e)


2- Copy the binary of your application into **bin** (we are simulating everything so we need to do this step)


![WhatsApp Image 2024-08-01 at 10 33 18 AM](https://github.com/user-attachments/assets/b3bd202c-e16a-441f-8887-e2017725338e)


3- Go to /etc/init.d and create the script which invokes the binary in the **/bin** :
```
cd /etc/init.d/
```
```
sudo touch myinitialization
```
```
sudo nano myinitialization
```
- As we know that this type of script uses **start-stop-daemon** command as follows
```
#! /bin/sh
case "$1" in
      start)
           echo "Starting deamonapp........."
           start-stop-daemon -S -n deamonapp -a /bin/deamonapp &
           ;;
     stop)
           echo "Stopping deamonapp........."
           start-stop-daemon -K -n deamonapp
           ;;
     *)
           echo "Usage: $0 {start|stop}"
           exit 1
esac
exit 0
```

![WhatsApp Image 2024-08-01 at 10 33 34 AM](https://github.com/user-attachments/assets/ae7dc219-22c6-436a-b71b-7f4b2899b5bb)


4- Now you want to select a certian **Run Level** which invokes the script in **/etc/init.d/myinitialization**, for me i selected **rc5.d** as follows:

- First, go inside **rc5.d**
```
cd rc5.d
```

- Then create the soft link to **/etc/init.d/myinitialization**
  
```
sudo ls -s ../init.d/myinitialization S01myinitialization
```

![WhatsApp Image 2024-08-01 at 10 54 51 AM](https://github.com/user-attachments/assets/aefb08ac-7d0b-4a2d-9e95-346d44f2be5b)


5- Test the application using:

```
/etc/init.d/myinitialization start
```

![WhatsApp Image 2024-08-01 at 10 33 35 AM](https://github.com/user-attachments/assets/775a6293-90c9-4bf6-a975-af5e2bb7bfde)



