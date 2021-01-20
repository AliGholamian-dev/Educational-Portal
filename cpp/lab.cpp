#include "lab.h"

/*
Lab: Lab Class Constructor
Input: void
Output: Void
*/
Lab::Lab()
    : ER()
{
}

/*
~Lab: Lab Class Destructor
Input: void
Output: Void
*/
Lab::~Lab()
{
    this->~ER();
}

/*
Lab: Lab Class Constructor
Input: course->Pointer to the Course,
       student->Pointer to the Student,
       professor->Pointer to the Professor,
       wight->weight of Course
Output: Void
*/
Lab::Lab(Course* course, Student* student, Prof* professor, int wight)
    : ER()
{
    this->course = course;
    this->professor = professor;
    this->student = student;
    this->weight = wight;
}

/*
calculate_final: Function which calculate final score
Input: void
Output: final -> final score 
*/
float Lab::calculate_final()
{
    this->final = ((this->report * 8) + (this->final * 10) + (this->activities * 2)) / 20.000;
    this->passed = (this->final >= 10);
    return this->final;
}

/*
scoring: Function which score parameters
Input: report->Report Score,
       activities->Activities Score,
       final_exam->Final Exam Score,
       absences->No of absences
Output: void
*/
void Lab::scoring(float report, float activities, float final_exam, int absences)
{
    this->report = report;
    this->activities = activities;
    this->final_exam = final_exam;
    this->absences = absences;
}