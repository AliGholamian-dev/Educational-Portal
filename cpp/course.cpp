#include "course.h"

/*
Course: Course Class Constructor
Input: void
Output: Void
*/
Course::Course()
{
    this->students = nullptr;
    this->professor = nullptr;
    this->educational_reports = nullptr;
}

/*
~Course: Course Class Destructor
Input: void
Output: Void
*/
Course::~Course()
{
    delete[] students;
    delete[] educational_reports;
}

/*
Course: Course Class Constructor
Input: name->Course Name,
       weight->Course Weight,
       theorical-> this course is lab or theorical
Output: Void
*/
Course::Course(std::string name, int weight, bool theorical)
{
    this->students = nullptr;
    this->professor = nullptr;
    this->educational_reports = nullptr;
    this->name = name;
    this->weight = weight;
    this->theorical = theorical;
}

/*
Course: Course Class Constructor
Input: profesor->Course Prof,
       name->Course Name,
       weight->Course Weight,
       theorical-> this course is lab or theorical
Output: Void
*/
Course::Course(Prof* profesor, std::string name, int weight, bool theorical)
{
    this->students = nullptr;
    this->educational_reports = nullptr;

    this->name = name;
    this->weight = weight;
    this->theorical = theorical;
    this->professor = profesor;

    //Add this course to Prof's Courses
    Course** Backup_Course { new Course* [this->professor->n_classes + 1] {} }; //Backup Courses
    Backup_Course[this->professor->n_classes] = this;
    for (int i = 0; i < this->professor->n_classes; i++)
        Backup_Course[i] = this->professor->courses[i];
    delete[] this->professor->courses;
    this->professor->courses = Backup_Course;
    this->professor->n_classes++;
}

/*
Course: Course Class Constructor
Input: profesor->Course Prof,
       student->Course Student,
       name->Course Name,
       weight->Course Weight,
       theorical-> this course is lab or theorical
Output: Void
*/
Course::Course(Prof* profesor, Student* student, std::string name, int weight, bool theorical)
{
    this->educational_reports = nullptr;

    this->name = name;
    this->weight = weight;
    this->theorical = theorical;
    this->professor = profesor;

    //Add this course to Prof's Courses
    Course** Backup_Course { new Course* [this->professor->n_classes + 1] {} };
    Backup_Course[this->professor->n_classes] = this;
    for (int i = 0; i < this->professor->n_classes; i++)
        Backup_Course[i] = this->professor->courses[i];
    delete[] this->professor->courses;
    this->professor->courses = Backup_Course;
    this->professor->n_classes++;

    //Add Student to Course
    this->population++;
    this->students = new Student* [1] { student };

    //Add this course to Students's Courses
    Course** Student_Backup_Course { new Course* [student->n_classes + 1] {} };
    Student_Backup_Course[student->n_classes] = this;
    for (int i = 0; i < student->n_classes; i++)
        Student_Backup_Course[i] = student->courses[i];
    delete[] student->courses;
    student->courses = Student_Backup_Course;
    student->n_classes++;
}

/*
operator<: comparing population of two course
Input: Second_Course
Output: Result of comparing population of two course
*/
bool Course::operator<(const Course& Second_Course)
{
    return (this->population < Second_Course.population);
}

/*
operator=: comparing population of two course
Input: Second_Course
Output: Result of comparing population of two course
*/
bool Course::operator=(const Course& Second_Course)
{
    return (this->population == Second_Course.population);
}

/*
operator(): comparing population of two course
            Input: Added_Student->Student to Add or Remove,
            Added_Theorical->ER to Add or Remove,
            Add_or_Remove->Whether to Add or Remove Student
Output: void
*/
void Course::operator()(Student& Added_Student, Theorical& Added_Theorical, int Add_or_Remove)
{
    if (Add_or_Remove == 1) {
        //Add Student to Course
        Student** Backup_Student { new Student* [this->population + 1] {} };
        Backup_Student[this->population] = &Added_Student;
        for (int i = 1; i < this->population; i++)
            Backup_Student[i] = this->students[i];
        delete[] this->students;
        this->students = Backup_Student;

        //Complete ER Data
        Added_Theorical.weight = this->weight;
        Added_Theorical.course = this;
        Added_Theorical.professor = this->professor;
        Added_Theorical.student = &Added_Student;

        //Add ER to Course
        ER** Backup_ER { new ER* [this->population + 1] {} };
        Backup_ER[this->population] = &Added_Theorical;
        for (int i = 0; i < this->population; i++)
            Backup_ER[i] = this->educational_reports[i];
        delete[] this->educational_reports;
        this->educational_reports = Backup_ER;
        this->population++;

        //Add this course to Students's Courses
        Course** Student_Backup_Course { new Course* [Added_Student.n_classes + 1] {} };
        Student_Backup_Course[Added_Student.n_classes] = this;
        for (int i = 0; i < Added_Student.n_classes; i++)
            Student_Backup_Course[i] = Added_Student.courses[i];
        delete[] Added_Student.courses;
        Added_Student.courses = Student_Backup_Course;
        Added_Student.n_classes++;

        //Add Theorical to Student's theorical
        Theorical** Student_Backup_Theorical { new Theorical* [Added_Student.n_theo + 1] {} };
        Student_Backup_Theorical[Added_Student.n_theo] = &Added_Theorical;
        for (int i = 0; i < Added_Student.n_theo; i++)
            Student_Backup_Theorical[i] = Added_Student.theoric_er[i];
        delete[] Added_Student.theoric_er;
        Added_Student.theoric_er = Student_Backup_Theorical;
        Added_Student.n_theo++;
    } else {
        //Remove Student From Course
        Student** Backup_Student { new Student* [this->population - 1] {} };
        for (int i = 0, j = 0; i < this->population; i++) {
            if (Added_Student.operator!=(*this->students[i])) {
                Backup_Student[j] = this->students[i];
                j++;
            }
        }
        delete[] this->students;
        this->students = Backup_Student;

        //Set er.final = 0
        //Set er.passed = false
        Added_Theorical.final = 0;
        Added_Theorical.passed = false;

        //Remove ER From Course
        ER** Backup_ER { new ER* [this->population - 1] {} };
        for (int i = 0, j = 0; i < this->population; i++) {
            if (&Added_Theorical != this->educational_reports[i]) {
                Backup_ER[j] = this->educational_reports[i];
                j++;
            }
        }
        delete[] this->educational_reports;
        this->educational_reports = Backup_ER;
        this->population--;

        //Removing course from student’s courses
        Course** Student_Backup_Course { new Course* [Added_Student.n_classes - 1] {} };
        for (int i = 0, j = 0; i < Added_Student.n_classes; i++) {
            if (this != Added_Student.courses[i]) {
                Student_Backup_Course[j] = Added_Student.courses[i];
                j++;
            }
        }
        delete[] Added_Student.courses;
        Added_Student.courses = Student_Backup_Course;
        Added_Student.n_classes--;
    }
}

/*
operator(): comparing population of two course
            Input: Added_Student->Student to Add or Remove,
            Added_Lab->ER to Add or Remove,
            Add_or_Remove->Whether to Add or Remove Student
Output: void
*/
void Course::operator()(Student& Added_Student, Lab& Added_Lab, int Add_or_Remove)
{
    if (Add_or_Remove == 1) {
        //Add Student to Course
        Student** Backup_Student { new Student* [this->population + 1] {} };
        Backup_Student[this->population] = &Added_Student;
        for (int i = 0; i < this->population; i++)
            Backup_Student[i] = this->students[i];
        delete[] this->students;
        this->students = Backup_Student;

        //Add ER to Course
        ER** Backup_ER { new ER* [this->population + 1] {} };
        Backup_ER[this->population] = &Added_Lab;
        for (int i = 0; i < this->population; i++)
            Backup_ER[i] = this->educational_reports[i];
        delete[] this->educational_reports;
        this->educational_reports = Backup_ER;
        this->population++;

        //Add this course to Students's Courses
        Course** Student_Backup_Course { new Course* [Added_Student.n_classes + 1] {} };
        Student_Backup_Course[Added_Student.n_classes] = this;
        for (int i = 0; i < Added_Student.n_classes; i++)
            Student_Backup_Course[i] = Added_Student.courses[i];
        delete[] Added_Student.courses;
        Added_Student.courses = Student_Backup_Course;
        Added_Student.n_classes++;
        delete[] Student_Backup_Course;

        //Add Lab to Student's Lab
        Lab** Student_Backup_Lab { new Lab* [Added_Student.n_lab + 1] {} };
        Student_Backup_Lab[Added_Student.n_lab] = &Added_Lab;
        for (int i = 0; i < Added_Student.n_lab; i++)
            Student_Backup_Lab[i] = Added_Student.lab_er[i];
        delete[] Added_Student.courses;
        Added_Student.lab_er = Student_Backup_Lab;
        Added_Student.n_lab++;
        delete[] Student_Backup_Lab;

        //Complete ER Data
        Added_Lab.weight = this->weight;
        Added_Lab.course = this;
        Added_Lab.professor = this->professor;
        Added_Lab.student = &Added_Student;
    } else {
        //Remove Student From Course
        Student** Backup_Student { new Student* [this->population - 1] {} };
        for (int i = 0, j = 0; i < this->population; i++) {
            if (Added_Student.id != this->students[i]->id) {
                Backup_Student[j] = students[i];
                j++;
            }
        }
        delete[] this->students;
        this->students = Backup_Student;

        //Set er.final = 0
        //Set er.passed = false
        Added_Lab.final = 0;
        Added_Lab.passed = false;

        //Remove ER From Course
        ER** Backup_ER { new ER* [this->population - 1] {} };
        for (int i = 0, j = 0; i < this->population; i++) {
            if (&Added_Lab != this->educational_reports[i]) {
                Backup_ER[j] = this->educational_reports[i];
                j++;
            }
        }
        delete[] this->educational_reports;
        this->educational_reports = Backup_ER;
        this->population--;

        //Removing course from student’s courses
        Course** Student_Backup_Course { new Course* [Added_Student.n_classes - 1] {} };
        for (int i = 0, j = 0; i < Added_Student.n_classes; i++) {
            if (this != Added_Student.courses[i]) {
                Student_Backup_Course[j] = Added_Student.courses[i];
                j++;
            }
        }
        delete[] Added_Student.courses;
        Added_Student.courses = Student_Backup_Course;
        Added_Student.n_classes--;
    }
}

/*
max: returm max score in this course
Input: void
Output: Max_Value->max score in this course
*/
float Course::max()
{
    float Max_Value { 0 };
    for (int i = 0; i < this->population; i++)
        if (this->educational_reports[i]->final > Max_Value)
            Max_Value = this->educational_reports[i]->final;
    return Max_Value;
}

/*
average: return average of class
Input: void
Output: return average of class
*/
float Course::average()
{
    float Sum_Value { 0 };
    for (int i = 0; i < this->population; i++)
        Sum_Value += this->educational_reports[i]->final;
    return Sum_Value / population;
}