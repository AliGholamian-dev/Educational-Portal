#ifndef PROF_H
#define PROF_H

#include "course.h"
#include "person.h"

class Prof : public Person {
public:
    Prof();
    Prof(std::string first_name, std::string last_name, int id);
    ~Prof();
    float get_mean() override; // Each of professor's courses has mean. This function returns mean of those means.
};

#endif