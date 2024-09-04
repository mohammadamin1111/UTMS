#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include "person.hpp"
#include "course.hpp"
#include "major.hpp"
#include "generalfunctions.hpp"
#include "IO.hpp"
#include "channel.hpp"

using namespace std;

class System
{

public:
  System(StandardIO &io_);
  ~System();
  void read_files(string magors_file, string students_file, string courses_file, string professors_file);
  void read_file_majors(string magors_file, vector<Major *> &majors);
  void read_file_courses(string courses_file, vector<Course *> &courses);
  void read_file_students(string students_file, vector<Person *> &people);
  void read_file_professors(string professors_file, vector<Person *> &professors);
  void login_user(string id, string password);
  Person *get_current_user() { return current_user; };
  void course_offer(string course_id, string professor_id, string capacity_str, string time, string exam_date, string class_number_str);
  void put_course(string id);
  void delete_course(string id);
  void logout();
  string get_major(int major_id);
  void show_information_my_courses(vector<string> &command_words);
  void add_profile_photo(string photo_adress);
  void show_all_offered_courses(string &course_info);
  void new_post_with_image(string title, string message, string image_adress);
  void new_post(vector<string> &command_words);
  void show_personal_page(string id, string &html);
  User get_current_user_state() { return current_user_state; };

private:
  void connect_user(vector<string> &command_words);
  Person *find_user(string id, string password);
  Person *find_user_by_id(string id);
  Course *find_course(string course_id);
  CourseOffering *find_offered_course(int id);
  int find_index_of_user(string id);
  void delete_post(vector<string> &command_words);
  void send_notification(string notification);
  void get_notification(vector<string> &command_words);
  void validate_argument(vector<bool> has_argument);
  void is_professor(string professor_id);
  void show_offered_course(vector<string> &command_words);
  void show_post(vector<string> &command_words);
  void add_ta_form(vector<string> &command_words);
  void ta_request(vector<string> &command_words);
  void add_student_to_channel(int id, Person *&student);
  void add_ta_request(int channel_id, string student_id);
  void close_ta_form(vector<string> &command_words);
  CourseChannel *find_channel(int channel_id);
  void add_course_post(vector<string> &command_words);
  void show_information_channel(vector<string> &command_words);
  void show_course_post(vector<string> &command_words);

  Person *find_professor_by_id(string id);
  CourseChannel *find_channel_with_form_id(int form_id);
  StandardIO io;
  User current_user_state;
  Person *current_user;
  vector<Person *> people;
  vector<Course *> courses;
  vector<CourseOffering *> offered_courses;
  vector<Major *> majors;
  vector<CourseChannel *> course_channels;
};

#endif