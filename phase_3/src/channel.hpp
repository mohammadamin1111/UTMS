#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "person.hpp"
#include "generalfunctions.hpp"
#include "course.hpp"
#include "IO.hpp"
using namespace std;
struct CoursePost
{
    int id;
    string title;
    string message;
    string author_name;
    string image_adress = "";
};
class CourseChannel
{

public:
    CourseChannel(int id_, Person *&professor_, CourseOffering *&course_);
    void add_student(Person *&student);
    void add_ta_request(string student_id);
    void close_ta_form(vector<Person *> &people);
    Person *find_user_by_id(string id);
    void has_permission_to_post(string id);
    void new_course_post(CoursePost new_post, string author_id);
    void send_notification(string author_id);
    void show_information_channel();
    void has_permission_to_show_info(string id);
    void show_information_post(int post_id);
    CourseOffering *get_course();
    int get_id();

private:
    int id;
    int last_post_id;
    vector<Person *> people;
    CourseOffering *course;
    Person *professor;
    vector<Person *> teacher_assistants;
    vector<Person *> students;
    vector<string> id_ta_requests;
    StandardIO io;
    vector<CoursePost> course_posts;
};

#endif