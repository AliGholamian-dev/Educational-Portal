#include "theorical.h"

/*
Theorical: Theorical Class Constructor
Input: void
Output: Void
*/
Theorical::Theorical()
    : ER()
{
}

/*
~Theorical: Theorical Class Destructor
Input: void
Output: Void
*/
Theorical::~Theorical()
{
    this->~ER();
}

/*
Theorical: Theorical Class Constructor
Input: course->Pointer to the Course,
       student->Pointer to the Student,
       professor->Pointer to the Professor,
       wight->weight of Course
Output: Void
*/
Theorical::Theorical(Course* course, Student* student, Prof* professor, int wight)
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
float Theorical::calculate_final()
{
    this->final = ((this->mid_term * 8) + (this->final_exam * 8) + (this->homeWorks * 4)) / 20.000;
    this->passed = (this->final >= 10);
    return this->final;
}

/*
scoring: Function which score parameters
Input: mid_term ->mid_term  Score,
       final_exam->final_exam Score,
       homeWorks->homeWorks Score,
       absences->No of absences
Output: void
*/
void Theorical::scoring(float mid_term, float final_exam, float homeWorks, int absences)
{
    this->mid_term = mid_term;
    this->final_exam = final_exam;
    this->homeWorks = homeWorks;
    this->absences = absences;
}