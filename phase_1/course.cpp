#include "course.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

CourseOffering *Course::offer(int id, int capacity, string time, string exam_date, int class_number, string professor_name)
{
    return new CourseOffering(cid, name, credit, prerequisite, major_ids, id, capacity, time, exam_date, class_number, professor_name);
}

CourseOffering::CourseOffering(string cid, string name, int credit, int prerequisite, vector<int> major_ids, int id_, int capacity_, string time, string exam_date_, int class_number_, string professor_name_)
    : Course(cid, name, credit, prerequisite, major_ids), time(time)
{
    string start_time_string;
    string end_time_string;
    id = id_;
    capacity = capacity_;
    class_number = class_number_;
    exam_date = exam_date_;
    professor_name = professor_name_;
    stringstream time_range(time);
    getline(time_range, week_day, ':');
    getline(time_range, start_time_string, '-');
    getline(time_range, end_time_string, '-');
    start_time = string_to_int(start_time_string);
    end_time = string_to_int(end_time_string);
}
void CourseOffering::check_major_id(int id)
{

    for (int i = 0; i < major_ids.size(); i++)
    {
        if (id == major_ids[i])
        {
            return;
        }
    }
    throw runtime_error(PERMISSION_ERROR);
}
void CourseOffering::has_interference(string new_week_day, int new_start_time, int new_end_time)
{

    if (new_week_day == week_day)
    {
        if (new_start_time < end_time && new_end_time > start_time)
        {
            throw runtime_error(PERMISSION_ERROR);
        }
    }
    return;
}
void CourseOffering::show_information()
{
    io.print_number(id);
    io.print_string(SPACE + name + SPACE);
    io.print_number(capacity);
    io.print_string(SPACE + professor_name);
    io.next_line();
}
void CourseOffering::show_full_information()
{
    io.print_number(id);
    io.print_string(SPACE + name + SPACE);
    io.print_number(capacity);
    io.print_string(SPACE + professor_name + SPACE + time + SPACE + exam_date + SPACE);
    io.print_number(class_number);
    io.next_line();
}
int CourseOffering::get_id()
{
    return id;
}
void CourseOffering::check_prerequisite(int semester)
{

    if (semester < prerequisite)
    {
        throw runtime_error(PERMISSION_ERROR);
    }
    return;
}