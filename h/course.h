#ifndef COURSE_H
#define COURSE_H

#include <string>

#include "er.h"
#include "lab.h"
#include "prof.h"
#include "student.h"
#include "theorical.h"

class Course {
public:
    Course();
    ~Course();
    Course(std::string name, int weight, bool theorical);
    Course(Prof* profesor, std::string name, int weight, bool theorical);
    Course(Prof* profesor, Student* student, std::string name, int weight, bool theorical);
    bool operator<(const Course&); // comparing population of two course
    bool operator=(const Course&); // comparing population of two course
    void operator()(Student&, Theorical&, int); // Add or Remove Student
    void operator()(Student&, Lab&, int); // Add or Remove Student
    float max(); // returm max score in this course
    float average(); // return average of class
    std::string name; // name of course
    int weight; // weight of course
    bool theorical; // this course is lab or theorical?
    Student** students; // a set of pointers which point to course students
    Prof* professor; // points to course professor
    int population { 0 }; // number of class students
    ER** educational_reports; // a set of pointers which point to students ERs.
};

#endif