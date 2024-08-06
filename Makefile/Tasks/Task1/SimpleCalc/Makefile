#using the CC variable to be gcc compiler
CC=gcc
#i will create a variable for each directory to easy use them
SRC_DIR=src
INC_DIR=include
BIN_DIR=bin
BUILD_DIR=build
#using the INC VAriable
INCS= -I ./$(INC_DIR)

#i want to build 2 files which are Calc.o and main.o
#to get them i want to compile using gcc -c %.c
#i want the first Rule to be the final exeutable one to for it at starting
#create the End rule to execute the App.out in the build directory
#Save the source files in a VAriable
SOURCES=$(wildcard $(SRC_DIR)/*.c)
#create a variable which include .o file 
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SOURCES))
#The Rule which will be called once we write make
$(BUILD_DIR)/App.out:$(OBJS)
#gcc will call all the prerequistes and name them as the target name
	@$(CC) $^ -o $@
	@echo Application file has been created
$(BIN_DIR)/%.o:$(SRC_DIR)/%.c
#create .o files in the current directory
	@$(CC) $(INC) -c $<
#move the created .o file to the bin directory
	@mv ./*.o ./$(BIN_DIR)/
.PHONY:clean
clean:
	@rm $(BIN_DIR)/*.o $(BUILD_DIR)/*.out
	@echo Files have been deleted
