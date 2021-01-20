#ifndef THEORICAL_H
#define THEORICAL_H

#include "er.h"

class Theorical : public ER {
public:
    Theorical();
    ~Theorical();
    Theorical(Course*, Student*, Prof*, int wight);
    float calculate_final() override; // Function which calculate final score
    void scoring(float mid_term, float final_exam, float homeWorks, int absences) override; // Function which score parameters
    float mid_term; // Midterm Score
    float final_exam; //Final Exam Score
    float homeWorks; // HomeWorks Score
};

#endif