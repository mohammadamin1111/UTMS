#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "generalfunctions.hpp"
#include "IO.hpp"

using namespace std;
class CourseOffering;
class Course
{

public:
    Course(string cid, string name, int credit, int prerequisite, vector<int> major_ids)
        : cid(cid), name(name), credit(credit), prerequisite(prerequisite), major_ids(major_ids) {}

    string get_cid() { return cid; };
    CourseOffering *offer(int id_, int capacity_, string time, string exam_date_, int class_number_,string professor_name);

protected:
    string name;
    string cid;
    int credit;
    int prerequisite;
    vector<int> major_ids;
};
class CourseOffering : public Course
{
public:
    CourseOffering(string cid, string name, int credit, int prerequisite, vector<int> major_ids, int id_, int capacity_, string time, string exam_date_, int class_number_,string professor_name_);
    void has_interference(string new_week_day, int new_start_time, int new_end_time);
    void check_major_id(int id);
    void show_information();
    int get_id();
    void show_full_information();
    string get_time(){ return time;};
     string get_name(){ return name;};
    void check_prerequisite(int semester);
    string get_exam_date(){ return exam_date;};

private:
    int id;
    int capacity;
    int class_number;
    string time;
    string exam_date;
    string week_day;
    int start_time;
    int end_time;
    string professor_name;
    StandardIO io;
};

#endif