#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <vector>
#include "generalfunctions.hpp"
#include "course.hpp"
#include "major.hpp"
#include "IO.hpp"
using namespace std;

class Person
{
public:
    Person(string id, string name, string password, int major_id)
        : id(id), name(name), password(password), major_id(major_id), last_post_id(1) {}
    ~Person();
    string get_password() { return password; };
    string get_id() { return id; };
    User who_are_you() { return user_type; };
    void connect_user(int index);
    void add_new_post(string title, string message);
    void delete_post(int id);
    void send_notification(string notification, vector<Person *> &people);
    void add_notification(Notification new_notif);
    void show_notification();
    void delete_notification();
    virtual void add_course(CourseOffering *&new_course, string time) = 0;
    virtual string get_name() { return name; };
    void has_interference(string time);
    virtual void show_information_courses() {}
    void delete_course(int id);
    void has_exam_conflict(string exam_date);
    virtual void show_personal_page(vector<Major *> majors) = 0;
    virtual void show_post(vector<Major *> majors, int post_id) = 0;

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
    StandardIO io;
};

class Student : public Person
{
public:
    Student(string id, string name, string password, int major_id, int semester)
        : Person(id, name, password, major_id), semester(semester) { user_type = STUDENT; }
    void add_course(CourseOffering *&new_course, string time);
    string get_name() { return name; };
    void show_information_courses();
    void show_personal_page(vector<Major *> majors);
    void show_post(vector<Major *> majors, int post_id);

private:
    int semester;
};

class Professor : public Person
{
public:
    Professor(string id, string name, string password, int major_id, string position)
        : Person(id, name, password, major_id), position(position) { user_type = PROFESSOR; }
    void add_course(CourseOffering *&new_course, string time);
    string get_name() { return name; };
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
    string get_name() { return name; };
    void show_personal_page(vector<Major *> majors);
    void show_post(vector<Major *> majors, int post_id);
};

#endif
