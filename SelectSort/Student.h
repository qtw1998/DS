//
// Created by qtw1998 on 2018/6/7.
//

#ifndef UNTITLED3_STUDENT_H
#define UNTITLED3_STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        return score < otherStudent.score;
    }

    friend ostream& operator<< (ostream &out,const Student &student){
        out<<"Student: "<<student.name<<" "<<student.score<<endl;
        return out;
    }
};
#endif //UNTITLED3_STUDENT_H
