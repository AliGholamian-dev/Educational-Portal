#ifndef LAB_H
#define LAB_H

#include "er.h"

class Lab : public ER {
public:
    Lab();
    ~Lab();
    Lab(Course*, Student*, Prof*, int wight);
    float calculate_final() override; // Function which calculate final score
    void scoring(float report, float activities, float final_exam, int absences) override; // Function which score parameters
    float report; // Report Score
    float activities; // Activities Score
    float final_exam; // Final Exam Score
};

#endif