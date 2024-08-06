#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char * FirstName;
  char * SecondName;
  char * ThirdName;
}Name;
typedef struct
{
  int Day;
  int month;
  int year;
}DOB;
typedef struct
{
  char * Street;
  char * City;
  char * Country;
}Address;
typedef struct
{
  char * TelePhone;
  char * Mobile;
  char * Email;
}Contacts;
typedef struct
{
    int basic;
    int additinal;
    int reductions;
    int taxes;
}Salary;
typedef struct
{
   Name     Emp_Name;
   DOB      Emp_DOB;
   Address  Emp_Address;
   Contacts Emp_Contacts;
   char * Job;
   Salary   Emp_Salary;
}Employee;
int main(void)
{
    //One Line Intialization
    Employee Youssef=
    {
      {"Youssef","Gamal","Shehata"},
      {9,9,1998},
      {"Hadayek-El Zaytoun","Cairo","Egypt"},
      {"0222562646","01066333797","youssefgamalshehata@gmail.com"},
      {"Android Automotive Developer"},
      {45000,5000,2000,1500}
    };
    //Printing Employee Information
    printf("Employee Name is : %s %s %s \n",Youssef.Emp_Name.FirstName,Youssef.Emp_Name.SecondName,Youssef.Emp_Name.ThirdName);
    printf("Employee Date of Birth is : %d/%d/%d \n",Youssef.Emp_DOB.Day,Youssef.Emp_DOB.month,Youssef.Emp_DOB.year);
    printf("Employee Address is : %s - %s - %s \n",Youssef.Emp_Address.Street,Youssef.Emp_Address.City,Youssef.Emp_Address.Country);
    printf("Employee Job is :%s\n",Youssef.Job);
    printf("Employee Salary is basic :%d - additinal :%d - reductions:%d - taxes:%d \n",Youssef.Emp_Salary.basic,Youssef.Emp_Salary.additinal,Youssef.Emp_Salary.reductions,Youssef.Emp_Salary.taxes);


}
