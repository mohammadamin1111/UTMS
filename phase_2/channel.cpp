#include "channel.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

CourseChannel::CourseChannel(int id_, Person *&professor_, CourseOffering *&course_)
{
    professor = professor_;
    course = course_;
    id = id_;
    last_post_id = 1;
}
void CourseChannel::add_student(Person *&student)
{
    students.push_back(student);
}
void CourseChannel::add_ta_request(string student_id)
{
    id_ta_requests.push_back(student_id);
}
void CourseChannel::close_ta_form(vector<Person *> &people_)
{
    people = people_;
    io.print_string("We have received ");
    io.print_number(id_ta_requests.size());
    io.print_string(" requests for the teaching assistant position");
    io.next_line();
    if (id_ta_requests.size() != 0)
    {

        int i = 0;
        string input;
        while (i != id_ta_requests.size())
        {
            Person *person = find_user_by_id(id_ta_requests[i]);
            Student *student = dynamic_cast<Student *>(person);
            io.print_string(student->get_id() + SPACE + student->get_name() + SPACE);
            io.print_number(student->get_semester());
            io.print_string(": ");
            io.get_string(input);
            if (input == ACCEPT)
            {
                student->send_ta_notification(id, course->get_name(), ACCEPTED);
                teacher_assistants.push_back(person);
            }
            else if (input == REJECT)
            {
                student->send_ta_notification(id, course->get_name(), REJECTED);
            }
            else
            {

                continue;
            }
            i++;
        }
    }
}
Person *CourseChannel::find_user_by_id(string id)
{

    for (auto person : people)
    {

        if (person->get_id() == id)
        {
            return person;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void CourseChannel::has_permission_to_post(string author_id)
{
    if (professor->get_id() == author_id)
    {
        return;
    }
    for (auto ta : teacher_assistants)
    {
        if (ta->get_id() == author_id)
        {
            return;
        }
    }
    throw runtime_error(PERMISSION_ERROR);
}
void CourseChannel::new_course_post(CoursePost new_post, string author_id)
{
    new_post.id = last_post_id;
    course_posts.push_back(new_post);
    send_notification(author_id);
    last_post_id++;
}
void CourseChannel::send_notification(string author_id)
{
    Notification new_notif;
    new_notif.id = to_string(id);
    new_notif.name = course->get_name();
    new_notif.notif = NEW_COURSE_POST;
    if (professor->get_id() != author_id)
    {
        professor->add_notification(new_notif);
    }
    for (auto ta : teacher_assistants)
    {
        if (ta->get_id() != author_id)
        {
            ta->add_notification(new_notif);
        }
    }
    for (auto student : students)
    {
        if (student->get_id() != author_id)
        {
            student->add_notification(new_notif);
        }
    }
}
void CourseChannel::show_information_channel()
{

    course->show_full_information();
    for (int i = course_posts.size() - 1; i >= 0; --i)
    {
        io.print_number(course_posts[i].id);
        io.print_string(SPACE + course_posts[i].author_name + SPACE + course_posts[i].title);
        io.next_line();
    }
}
void CourseChannel::has_permission_to_show_info(string id)
{
    if (professor->get_id() == id)
    {
        return;
    }
    for (auto ta : teacher_assistants)
    {
        if (ta->get_id() == id)
        {
            return;
        }
    }
    for (auto student : students)
    {
        if (student->get_id() == id)
        {
            return;
        }
    }
    throw runtime_error(PERMISSION_ERROR);
}
void CourseChannel::show_information_post(int post_id)
{

    bool is_id_found = false;
    CoursePost post_to_show;
    for (auto post : course_posts)
    {
        if (post_id == post.id)
        {
            post_to_show = post;
            is_id_found = true;
        }
    }
    if (!is_id_found)
    {

        throw runtime_error(NOT_FOUND_ERROR);
    }
    course->show_full_information();

    io.print_number(post_to_show.id);
    io.print_string(SPACE + post_to_show.author_name + SPACE + post_to_show.title + SPACE + post_to_show.message);
    io.next_line();
}
CourseOffering *CourseChannel::get_course()
{
    return course;
}
int CourseChannel::get_id()
{
    return id;
}