#include<stdio.h>
#include<string.h>

struct Student
{
int studentID;
char studentName[20];
int marks_1,marks_2;
float average;
};

int main(void)
{
int counter;
struct Student studentRecord[6];

printf("Database of six students");

for(counter=0; counter<6; counter++)
{
printf("\nStudent ID:");
scanf("%d",&studentRecord[counter].studentID);
printf("Student Name:");
scanf("%s",&studentRecord[counter].studentName);
printf("Marks 1:");
scanf("%d",&studentRecord[counter].marks_1);
printf("Marks 2:");
scanf("%d",&studentRecord[counter].marks_2);
printf("Average:");
scanf("%f",&studentRecord[counter].average);
}

printf("\nStudent Information List:");

for(counter=0; counter<6; counter++)
{
printf("\nStudent ID:%d\t Student Name:%s\t Marks 1:%d\t Marks 2:%d\t Average :%f\n",studentRecord[counter].studentID,studentRecord[counter].studentName,studentRecord[counter].marks_1,studentRecord[counter].marks_2,studentRecord[counter].average);}
return 0;
}