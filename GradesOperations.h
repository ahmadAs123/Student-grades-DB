#ifndef GRADES_OPERATIONS_H
#define GRADES_OPERATIONS_H
#include "StudentList.h"





StudentList* InsertStudents();
double PersentOfFailE2(StudentList* );
double PersentOfFailE1(StudentList* );
int NumDidntDoExam(StudentList* );
int NumdidExamStudent(StudentList* );
int NumOfStudents(StudentList* );
int MinMark(StudentList* );
int MaxMark(StudentList* );
double AverageOfEx2(StudentList* );
double AverageOfEx1(StudentList* );
int NumStudentsDidE1(StudentList*);
int NumStudentsDidE2(StudentList*);
void MakeReport();











#endif