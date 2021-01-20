#include "er.h"

/*
ER: ER Class Constructor
Input: void
Output: Void
*/
ER::ER()
{
    course = nullptr;
    professor = nullptr;
    student = nullptr;
}

/*
calculate_final: Function which calculate final score
Input: void
Output: final -> final score 
*/
float ER::calculate_final()
{
    return this->final;
}

/*
scoring: Function which score parameters
Input: absences->No of absences
Output: void
*/
void ER::scoring(float first_dummy_input, float second_dummy_input, float third_dummy_input, int absences)
{
    this->absences = absences;
}