/*
    Made by Christopher A. Mendoza
    Last modified on 3/09/2023
*/
#include <stdio.h>
#include <stdlib.h>
/*Custom Header Files*/
#include "students.h"
#include "gradeCalculator.h"



/*Setting the size of the students*/
#define STUDENT_MAX_SIZE 25
#define GRADE_MAX_SIZE   10

int main()
{
    /*Declared varibles*/
    int totalGrades;
    int totalStudents;
    int totalArrSize;
    int maxGrade;
    int minGrade;
    int avgMin; 
    int avgMax;
    int storeSize = 0;
    /*This first portions will take in the input of the user*/
    printf("Welcome to the Student Info Organizer!!!!\n");
    //Asking how many students the user will input
    printf("How many students will you grade (1 - 25): ");
    scanf("%d", &totalStudents);
    if(totalStudents >= 0 && totalStudents <= STUDENT_MAX_SIZE)
    {
        /*Here we ask the user to input the number of grades for each student*/
        printf("Enter how many grades each student has (1 - 10): ");
        scanf("%d", &totalGrades);

        if(totalGrades >= 0 && totalGrades <= GRADE_MAX_SIZE)
        {
            /*Calculate the size of the total array*/
            totalArrSize = totalGrades*totalStudents;
            /*Here we define the size of the array of structs*/
            info_t *student  = malloc(totalArrSize * sizeof *student);
            printf("|==============================================================|\n");
            for(int i = 0; i < totalStudents; i++)
            {
                student[i].firstName = (char*)malloc(sizeof(char*));                        
                printf("\nEnter the Firstname for Student %d: " ,i + 1);
                scanf("%s",student[i].firstName);

                student[i].lastName = (char*)malloc(sizeof(char*));
                printf("Enter the Last Name for Student %d: " ,i + 1);
                scanf("%s", student[i].lastName);

                printf("Enter the Age for Student %d: " ,i + 1);
                scanf("%d",&student[i].age);
                for(int k = 0; k < totalGrades; k++)
                {
                    printf("Enter Grade %d for Student %d: " ,k+1,i+1);
                    scanf("%f",&student[storeSize].grades);
                    
                    if(storeSize < totalStudents*totalGrades)
                    {
                        storeSize = storeSize + 1; 
                    }   
                }
                /*Here all the grades are sent to the gradeCalculator to calculate the highest/lowest grades*/
                float avg = GetAverage(student, totalGrades, i);
                student[i].Average = avg;
                /*Note: These fucntions dont return any actual grades, rather they return the address of the grade in the struct*/
                maxGrade = GetHighestGrade(student, totalStudents,totalGrades);
                minGrade = GetLowestGrade(student, totalStudents, totalGrades);
            }
            int choice;
            do
            { 
                printf("|==============================================================|\n");
                for(int g = 0; g < totalStudents; g++)
                {
                    printf("The average for %s %s -> %0.2f\n", student[g].firstName,student[g].lastName, student[g].Average);
                    avgMin = GetAvgMin(student, totalStudents);
                    //printf("avgMin = %i\n", avgMin);
                    avgMax = GetAvgMax(student, totalStudents);
                    //printf("avgMax = %i\n", avgMax);
                }
                printf("\n|==============================================================|\n");
                printf("Do you wish to continue with the program??\n");
                printf("Press 1 -> To exit the program\n");
                printf("Press 2 -> To change the grades of the students\n");
                printf("] ");
                scanf("%i", &choice);
                switch(choice)
                {
                    case 1:
                        printf("|==============================================================|\n");
                        for(int h = 0; h < totalStudents; h++)
                        {
                            printf("The average for %s %s -> %0.2f\n", student[h].firstName,student[h].lastName, student[h].Average);
                        }
                        printf("The student with the highest grade is %s %s with a %f\n", student[maxGrade/totalGrades].firstName, student[maxGrade/totalGrades].lastName,student[maxGrade].grades);
                        printf("The student with the lowest grade is %s %s with a %f\n", student[minGrade/totalGrades].firstName, student[minGrade/totalGrades].lastName,student[minGrade].grades);
                        printf("The student with the highest lowset average is %s %s with a %f\n", student[avgMin].firstName,student[avgMin].lastName, student[avgMin].Average);
                        printf("The student with the lowset average is %s %s with a %f\n", student[avgMax].firstName,student[avgMax].lastName, student[avgMax].Average);
                        free(student);
                        printf("Thank you for using the program ty!!!\n");
                        break;
                    case 2:
                        gradeAverageModify(student, totalStudents);
                        break;
                    default:printf("Inavlid Selection\n");
                        
                }
            }while(choice != 1);
        }
        else
        {
            printf("Input not valid\n");
        }
    }
    else
    {
        printf("Input not valid\n");
        
    }
    return 0;
}