#include "students.h"
#include <stdio.h>
/*
    Here is the library that contains all the
    Functions necessary to determine which was
    of the following:
    ->Get the average of each student
    ->Determine
*/

float GetAverage(info_t students[], int n, int k)
{
    int j = 0;     //This initialize that value at 0
    float result;  //This variable will return the result of every average of each student 
    float sum = 0; //Sets the value at 0
    //printf("n = %i, k = %i\n", n,k); debugging measure
    for(int i = 0; i < n; i++)
    {
        j = (k*n)+i;//The k*n is to figure which grade number it is, the plus i to add the previous number to the j
        sum = sum + students[j].grades; //This sets sum equal to the previous sum plus the new values
    }
    result = sum / n; //This takes all the values of the exams and divides the number of exams
    return result;
}
/*This function deals with taking lowest average of the student*/
float GetAvgMin(info_t s[], int numStudents)
{
    float min = s[0].Average;     
    float location = 0;   
    for(int i = 0; i < numStudents; i++) 
    {
        if(s[i].Average < min)  
        {
            min = s[i].Average; 
            location = i;       
        }
    }
    return location; 
}
/*This function deals with highest average of the student*/
float GetAvgMax(info_t s[], int numStudents)
{

    float max = s[0].Average;            
    float location = 0;    
     
    for(int i = 0; i < numStudents; i++)  
    {
        if(s[i].Average > max) 
        {
            max = s[i].Average;  
            location = i;        
        }
    }
    return location;            
}
/*This function deals with taking the lowest exam of the student*/
float GetLowestGrade(info_t s[], int numStudents, int numGrades)
{

    float lowest;  
    float location = 0;
    lowest = s[0].grades;  
    for(int i = 0; i < numStudents*numGrades; i++) 
    {
        if(s[i].grades < lowest) 
        {
            lowest = s[i].grades; 
            location = i;      
        }
    }
    return location;          
}
/*This function deals with taking the highest exam of the student*/
float GetHighestGrade(info_t s[], int numStudents, int numGrades)
{
    float highest= s[0].grades;
    float location = 0; 
    for(int i = 0; i < numStudents*numGrades; i++)
    {
        if(s[i].grades> highest)
        {
            highest = s[i].grades; 
            location = i;       
        }
    }
    return location;           
}
void gradeAverageModify(info_t s[],int numStudents)
{
    int modify;
    int *gradeAdder;
    float addPoints;
    for(int i = 0; i < numStudents; i++)
    {
        printf("%i => %s %s\n", i+1, s[i].firstName,s[i].lastName);
    }
    printf("Which students grade will your like to modify?\n");
    printf("->");
    scanf("%i", &modify);
    modify-=modify;
    printf("How many points will you like to add to %s %s\n", s[modify].firstName, s[modify].lastName);
    printf("]] ");
    scanf("%f", &addPoints);
    s[modify].Average += addPoints;
    printf("%s %s now has an average of %0.2f\n", s[modify].firstName,s[modify].lastName,s[modify].Average);
}