#include "student.h"

/*
Student: Student Class Constructor
Input: void
Output: Void
*/
Student::Student()
    : Person()
{
    theoric_er = nullptr;
    lab_er = nullptr;
    this->n_theo = 0;
    this->n_lab = 0;
}

/*
Student: Student Class Constructor
Input: first_name->Student first_name,
       last_name->Student last_name,
       id->Student id
Output: Void
*/
Student::Student(std::string first_name, std::string last_name, int id, float mean_score, int passed)
    : Person()
{
    theoric_er = nullptr;
    lab_er = nullptr;
    this->n_theo = 0;
    this->n_lab = 0;
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = id;
    this->mean_score = mean_score;
    this->passed = passed;
}

/*
~Student: Student Class Destructor
Input: void
Output: Void
*/
Student::~Student()
{
    delete[] theoric_er;
    delete[] lab_er;
    delete[] courses;
    this->~Person();
}

/*
get_mean: Return MeanScore
Input: void
Output: Returns MeanScore
*/
float Student::get_mean()
{
    return this->mean_score;
}

/*
operator++: It adds a unit to student's semestes
Input: void
Output: No of semesters
*/
void Student::operator++()
{
    this->semesters++;
}

/*
operator!=: Check if students id match
Input: Second_Student-> Second Student Object
Output: Match Result
*/
bool Student::operator!=(const Student& Second_Student)
{
    return (this->id != Second_Student.id);
}