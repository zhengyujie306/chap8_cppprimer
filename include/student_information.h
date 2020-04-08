#ifndef STUDENT_INFORMATION_H
#define STUDENT_INFORMATION_H
#include <string>
using namespace std;

class student_information
{
public:
    student_information(string id = "", string name = "", int age = 0, int sex = 0) :
        id_stu(id), name_stu(name), age_stu(age), sex_stu(sex) {};
    string getid() const {return id_stu;}
    string getname() const {return name_stu;}
    int getage() const {return age_stu;}
    int getsex() const {return sex_stu;}

    virtual ~student_information();

protected:

private:
    string id_stu;
    string name_stu;
    int age_stu;
    int sex_stu;
};



#endif // STUDENT_INFORMATION_H
