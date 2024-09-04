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

void Person::add_ta_form(CourseOffering *course, string message)
{
    course->add_ta_form_id(last_post_id);
    Post new_ta_form;
    new_ta_form.type = TA_FORM;
    new_ta_form.id = last_post_id;
    new_ta_form.message = message;
    new_ta_form.course = course;
    posts.push_back(new_ta_form);
    last_post_id++;
}
void Person::add_new_post_with_image(string title, string message, string image_adress)
{

    Post new_post;
    new_post.id = last_post_id;
    new_post.title = title;
    new_post.message = message;
    new_post.image_adress = image_adress;
    posts.push_back(new_post);
    last_post_id++;
}
void Person::add_profile_photo(string photo_adress_)
{
    photo_adress = photo_adress_;
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
void Person::is_professor_of_course(int id)
{
    for (auto course : courses)
    {
        if (course->get_id() == id)
        {
            return;
        }
    }
    throw runtime_error(PERMISSION_ERROR);
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
Post Person::find_ta_form(string id_)
{
    int id = string_to_int(id_);
    for (auto post : posts)
    {

        if (post.id == id && post.type == TA_FORM)
        {

            return post;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void Student::can_be_ta(Post ta_form)
{
    ta_form.course->check_prerequisite_ta(semester);
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
void Student::show_information_courses(string &html)
{
    if (courses.size() == 0)
    {
        throw runtime_error(EMPTY_ERROR);
    }
    ostringstream body;
    for (auto course : courses)
    {

        body << "<div>" << course->show_full_information() << "</div>\n";
    }
    html = body.str();
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
void Student::show_personal_page(vector<Major *> majors, string &html)
{
    ostringstream body;
    string name_of_major;
    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    body << "<h>" << name + SPACE + name_of_major + SPACE + to_string(semester) + SPACE;
    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            body << COMMA;
        }
    }
    body << "</h>\n";
    for (int i = posts.size() - 1; i >= 0; --i)
    {
        body << "<div>"
             << "<img src=\"post_photo.png?address=" << posts[i].image_adress << "\" alt=\"Profile Image\" style=\"max-width: 10px; border-radius: 15%; margin-bottom: 20px; margin-right: 10px;\"/>"
             << to_string(posts[i].id) << SPACE << posts[i].title
             << "</div>\n";
    }
    html = body.str();
}
void Professor::show_personal_page(vector<Major *> majors, string &html)
{
    ostringstream body;
    string name_of_major;
    for (auto major : majors)
    {
        if (major_id == major->get_id())
        {
            name_of_major = major->get_name();
        }
    }
    body << "<h>" << name + SPACE + name_of_major + SPACE + position + SPACE;

    for (int i = 0; i < courses.size(); i++)
    {
        io.print_string(courses[i]->get_name());
        if (i != courses.size() - 1)
        {
            body << COMMA;
        }
    }
    body << "</h>\n";
    for (int i = posts.size() - 1; i >= 0; --i)
    {
        io.print_number(posts[i].id);
        if (posts[i].type == DEFAULT)
        {
            body << "<div>"
                 << "<img src=\"post_photo.png?address=" << posts[i].image_adress << "\" alt=\"Profile Image\" style=\"max-width: 10px; border-radius: 15%; margin-bottom: 20px; margin-right: 10px;\"/>"
                 << to_string(posts[i].id) << SPACE << posts[i].title
                 << "</div>\n";
        }
        else if (posts[i].type == TA_FORM)
        {
            io.print_string(SPACE + "TA form for " + posts[i].course->get_name() + " course");
        }
    }
    html = body.str();
}
void Admin::show_personal_page(vector<Major *> majors, string &html)
{
    ostringstream body;
    body << "<h>" << ADMIN_NAME << "</h>\n";
    for (int i = posts.size() - 1; i >= 0; --i)
    {

        body << "<div>"
             << "<img src=\"post_photo.png?address=" << posts[i].image_adress << "\" alt=\"Profile Image\" style=\"max-width: 10px; border-radius: 15%; margin-bottom: 20px; margin-right: 10px;\"/>"
             << to_string(posts[i].id) << SPACE << posts[i].title
             << "</div>\n";
    }
    html = body.str();
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

    string name_of_major;
    bool is_id_found = false;
    Post post_to_show;
    for (auto post : posts)
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

    if (post_to_show.type == DEFAULT)
    {
        io.print_number(post_id);
        io.print_string(SPACE + post_to_show.title + SPACE + post_to_show.message);
    }
    else if (post_to_show.type == TA_FORM)
    {
        io.print_number(post_id);
        io.print_string(SPACE + "TA form for " + post_to_show.course->get_name() + " course");
        io.next_line();
        post_to_show.course->show_full_information();
        io.print_string(post_to_show.message);
    }
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
void Student::send_ta_notification(int course_id, string course_name, string notification)
{
    Notification new_notif;
    new_notif.id = to_string(course_id);
    new_notif.name = course_name;
    new_notif.notif = "Your request to be a teaching assistant has been " + notification + '.';
    notifications.push_back(new_notif);
}
void Person::chack_has_ta_form(int id)
{
    for (auto post : posts)
    {
        if (post.type == TA_FORM)
        {
            if (id == post.id)
            {
                return;
            }
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
string Person::get_password() { return password; };
string Person::get_id() { return id; };
User Person::who_are_you() { return user_type; };
string Person::get_name() { return name; };
int Student::get_semester() { return semester; };
