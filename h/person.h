#ifndef PERSON_H
#define PERSON_H

#include <string>
class Course;

class Person {
public:
    Person();
    ~Person() = default;
    virtual float get_mean() = 0; // Return MeanScore
    std::string first_name;
    std::string last_name;
    int id; // id of person
    Course** courses; // a set of pointers to person's courses
    int n_classes {}; // number of person's courses
};

#endif