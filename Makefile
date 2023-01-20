CC = gcc
OBJECT = main.c
all:main.c gradeCalculator.c
	$(CC) -o main main.c gradeCalculator.c
Main_Program: main.c
	$(CC) -o main main.c 
	echo " Main file Compiled!"
Student_Program: gradeCalculator.c
	$(CC) -o gradeCalculator gradeCalculator.c
	echo " Second file Compiled!"