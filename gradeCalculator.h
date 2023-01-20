#ifndef GRADESCALCULATOR_H_
#define GRADESCALCULATOR_H_

#include "students.h"
float GetAverage(info_t students[], int n, int k);
float GetAvgMin(info_t s[], int numStudents);
float GetAvgMax(info_t s[], int numStudents);
float GetLowestGrade(info_t s[], int numStudents, int numGrades);
float GetHighestGrade(info_t s[], int numStudents, int numGrades);
void gradeAverageModify(info_t s[],int numStudents);
#endif /*GRADESCALCULATOR_H_*/