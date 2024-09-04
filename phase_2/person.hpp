#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "generalfunctions.hpp"
#include "course.hpp"
#include "major.hpp"
#include "IO.hpp"
using namespace std;

enum PostType
{
    DEFAULT,
    TA_FORM

};
struct Post
{
    PostType type = DEFAULT;
    int id;
    string title;
    string message;
    string image_adress = "";
    CourseOffering *course = NULL;
};

class Person
{
public:
    Person(string id, string name, string password, int major_id)
        : id(id), name(name), password(password), major_id(major_id), last_post_id(1) {}
    ~Person();
    string get_password();
    string get_id();
    User who_are_you();
    string get_name();
    void connect_user(int index);
    void add_new_post(string title, string message);
    void add_new_post_with_image(string title, string message, string image_adress);
    void delete_post(int id);
    void send_notification(string notification, vector<Person *> &people);
    void add_notification(Notification new_notif);
    void show_notification();
    void delete_notification();
    virtual void add_course(CourseOffering *&new_course, string time) = 0;
    void has_interference(string time);
    virtual void show_information_courses() {}
    void delete_course(int id);
    void has_exam_conflict(string exam_date);
    virtual void show_personal_page(vector<Major *> majors) = 0;
    virtual void show_post(vector<Major *> majors, int post_id) = 0;
    void add_profile_photo(string photo_adress);
    void is_professor_of_course(int id);
    void add_ta_form(CourseOffering *course, string message);
    Post find_ta_form(string id);
    void chack_has_ta_form(int id);

protected:
    string id;
    string name;
    string password;
    int major_id;
    User user_type;
    vector<int> index_connections;
    vector<Post> posts;
    vector<Notification> notifications;
    vector<CourseOffering *> courses;
    int last_post_id;
    string photo_adress = "";
    StandardIO io;
};

class Student : public Person
{
public:
    Student(string id, string name, string password, int major_id, int semester)
        : Person(id, name, password, major_id), semester(semester) { user_type = STUDENT; }
    void add_course(CourseOffering *&new_course, string time);
    void show_information_courses();
    void show_personal_page(vector<Major *> majors);
    void show_post(vector<Major *> majors, int post_id);
    void can_be_ta(Post ta_form);
    int get_semester();
    void send_ta_notification(int course_id, string course_name, string notif);

private:
    int semester;
};

class Professor : public Person
{
public:
    Professor(string id, string name, string password, int major_id, string position)
        : Person(id, name, password, major_id), position(position) { user_type = PROFESSOR; }
    void add_course(CourseOffering *&new_course, string time);
    void show_personal_page(vector<Major *> majors);
    void show_post(vector<Major *> majors, int post_id);

private:
    string position;
};

class Admin : public Person
{
public:
    Admin(string id, string name, string password, int major_id)
        : Person(id, name, password, major_id) { user_type = ADMIN; }
    void add_course(CourseOffering *&new_course, string time);
    void show_personal_page(vector<Major *> majors);
    void show_post(vector<Major *> majors, int post_id);
};

#endif
