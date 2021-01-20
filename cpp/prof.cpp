#include "prof.h"

/*
Prof: Prof Class Constructor
Input: void
Output: Void
*/
Prof::Prof()
    : Person()
{
}

/*
Prof: Prof Class Constructor
Input: first_name->Prof first_name,
       last_name->Prof last_name,
       id->Prof id
Output: Void
*/
Prof::Prof(std::string first_name, std::string last_name, int id)
    : Person()
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = id;
}

/*
~Prof: Prof Class Destructor
Input: void
Output: Void
*/
Prof::~Prof()
{
    delete[] courses;
    this->~Person();
}

/*
get_mean: Return MeanScore
Input: void
Output: Returns MeanScore
*/
float Prof::get_mean()
{
    float sum_score_of_all {};
    for (int i = 0; i < this->n_classes; i++)
        sum_score_of_all += this->courses[i]->average();

    return sum_score_of_all / this->n_classes;
}