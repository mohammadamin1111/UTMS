#include "person.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;
Person::~Person()
{

    index_connections.clear();
    posts.clear();
    notifications.clear();
}
void Person::connect_user(int index)
{

    for (int i = 0; i < index_connections.size(); i++)
    {
        if (index == index_connections[i])
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
    }
    index_connections.push_back(index);
    return;
}
void Person::add_new_post(string title, string message)
{

    Post new_post;
    new_post.id = last_post_id;
    new_post.title = title;
    new_post.message = message;
    posts.push_back(new_post);
    last_post_id++;
}
void Person::delete_post(int id)
{
    for (int i = 0; i < posts.size(); ++i)
    {
        if (id == posts[i].id)
        {
            posts.erase(posts.begin() + i);
            return;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}

void Person::send_notification(string notification, vector<Person *> &people)
{

    Notification new_notif;
    new_notif.id = id;
    new_notif.name = name;
    new_notif.notif = notification;
    if (user_type == ADMIN || notification == NEW_COURSE_OFFERING)
    {
        for (int i = 1; i < people.size(); i++)
        {

            people[i]->add_notification(new_notif);
        }
    }
    else
    {
        for (int i = 0; i < people.size(); i++)
        {
            for (int j = 0; j < index_connections.size(); j++)

                if (i == index_connections[j])
                {

                    people[i]->add_notification(new_notif);
                }
        }
    }
}
void Person::add_notification(Notification new_notif)
{
    notifications.push_back(new_notif);
}
void Person::show_notification()
{
    if (notifications.size() == 0)
    {
        throw runtime_error(EMPTY_ERROR);
    }
    for (int i = notifications.size() - 1; i >= 0; i--)
    {
        io.print_string(notifications[i].id + SPACE + notifications[i].name + ": " + notifications[i].notif);
        io.next_line();
    }
    delete_notification();
}
void Person::delete_notification()
{
    notifications.clear();
}
void Professor::add_course(CourseOffering *&new_course, string time)
{
    has_interference(time);
    new_course->check_major_id(major_id);
    courses.push_back(new_course);
}

void Student::add_course(CourseOffering *&new_course, string time)
{
    time = new_course->get_time();
    string exam_date = new_course->get_exam_date();
    has_exam_conflict(exam_date);
    has_interference(time);
    new_course->check_major_id(major_id);
    new_course->check_prerequisite(semester);
    courses.push_back(new_course);
    return;
}
void Person::has_exam_conflict(string exam_date)
{
    for (auto course : courses)
    {
        if (exam_date == course->get_exam_date())
        {
            throw runtime_error(PERMISSION_ERROR);
        }
    }
}
void Admin::add_course(CourseOffering *&new_course, string time)
{
    return;
}
void Person::has_interference(string time)
{
    string week_day;
    string start_time_str;
    string end_time_str;
    int start_time;
    int end_time;
    stringstream time_range(time);
    getline(time_range, week_day, ':');
    getline(time_range, start_time_str, '-');
    getline(time_range, end_time_str, '-');
    start_time = string_to_int(start_time_str);
    end_time = string_to_int(end_time_str);
    for (auto course : courses)
    {
        course->has_interference(week_day, start_time, end_time);
    }
}
void Student::show_information_courses()
{
    if (courses.size() == 0)
    {
        throw runtime_error(EMPTY_ERROR);
    }
    for (auto course : courses)
    {

        course->show_full_information();
    }
}
void Person::delete_course(int id)
{
    for (int i = 0; i < courses.size(); ++i)
    {
        if (id == courses[i]->get_id())
        {
            courses.erase(courses.begin() + i);
            return;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void Student::show_personal_page(vector<Major *> majors)
{

    string name_of_major;
    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    io.print_string(name + SPACE + name_of_major + SPACE);
    io.print_number(semester);
    io.print_string(SPACE);
    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            io.print_char(COMMA);
        }
    }
    io.next_line();
    for (int i = posts.size() - 1; i >= 0; --i)
    {
        io.print_number(posts[i].id);
        io.print_string(SPACE + posts[i].title);
        io.next_line();
    }
}
void Professor::show_personal_page(vector<Major *> majors)
{
    string name_of_major;
    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    io.print_string(name + SPACE + name_of_major + SPACE + position + SPACE);

    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            io.print_char(COMMA);
        }
    }
    io.next_line();
    for (int i = posts.size() - 1; i >= 0; --i)
    {
        io.print_number(posts[i].id);
        io.print_string(SPACE + posts[i].title);
        io.next_line();
    }
}
void Admin::show_personal_page(vector<Major *> majors)
{
    io.print_string(ADMIN_NAME);
    io.next_line();
    for (int i = posts.size() - 1; i >= 0; --i)
    {
        io.print_number(posts[i].id);
        io.print_string(SPACE + posts[i].title);
        io.next_line();
    }
}
void Student::show_post(vector<Major *> majors, int post_id)
{
    string name_of_major, post_title, post_message;
    bool is_id_found = false;

    for (auto post : posts)
    {
        if (post_id == post.id)
        {
            post_message = post.message;
            post_title = post.title;
            is_id_found = true;
        }
    }
    if (!is_id_found)
    {

        throw runtime_error(NOT_FOUND_ERROR);
    }
    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    io.print_string(name + SPACE + name_of_major + SPACE);
    io.print_number(semester);
    io.print_string(SPACE);
    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            io.print_char(COMMA);
        }
    }
    io.next_line();
    io.print_number(post_id);
    io.print_string(SPACE + post_title + SPACE + post_message);
    io.next_line();
}
void Professor::show_post(vector<Major *> majors, int post_id)
{

    string name_of_major, post_title, post_message;
    bool is_id_found = false;

    for (auto post : posts)
    {
        if (post_id == post.id)
        {
            post_message = post.message;
            post_title = post.title;
            is_id_found = true;
        }
    }
    if (!is_id_found)
    {

        throw runtime_error(NOT_FOUND_ERROR);
    }

    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    io.print_string(name + SPACE + name_of_major + SPACE + position + SPACE);
    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            io.print_char(COMMA);
        }
    }
    io.next_line();
    io.print_number(post_id);
    io.print_string(SPACE + post_title + SPACE + post_message);
    io.next_line();
}
void Admin::show_post(vector<Major *> majors, int post_id)
{

    string post_title, post_message;
    bool is_id_found = false;

    for (auto post : posts)
    {
        if (post_id == post.id)
        {
            post_message = post.message;
            post_title = post.title;
            is_id_found = true;
        }
    }
    if (!is_id_found)
    {
        throw runtime_error(NOT_FOUND_ERROR);
    }
    io.print_string(ADMIN_NAME);
    io.next_line();
    io.print_number(post_id);
    io.print_string(SPACE + post_title + SPACE + post_message);
    io.next_line();
}
