#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <random>
#include <regex>
#include "system.hpp"

using namespace std;
System ::System(StandardIO &io_)
{
    io = io_;
    current_user_state = LOGOUT;
    current_user = NULL;
    Person *admin = new Admin(ADMIN_ID, ADMIN_NAME, ADMIN_PASSWORD, 0);
    people.push_back(admin);
}
System::~System()
{

    for (Person *person : people)
    {
        delete person;
    }
    for (Course *course : courses)
    {
        delete course;
    }

    for (CourseOffering *offered_course : offered_courses)
    {
        delete offered_course;
    }

    for (Major *major : majors)
    {
        delete major;
    }
}
void System::read_files(string majors_file, string students_file, string courses_file, string professors_file)
{
    read_file_majors(majors_file, majors);
    read_file_courses(courses_file, courses);
    read_file_students(students_file, people);
    read_file_professors(professors_file, people);
    return;
}
void System::read_file_majors(string majors_file, vector<Major *> &majors)
{

    ifstream inFile(majors_file);
    string line;
    bool is_first_line = true;
    while (getline(inFile, line))
    {
        if (is_first_line)
        {
            is_first_line = false;
            continue;
        }
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        stringstream line_stream(line);
        string mid_string;
        string major;

        getline(line_stream, mid_string, ',');
        getline(line_stream, major, ',');
        int mid = string_to_int(mid_string);
        Major *new_major = new Major(mid, major);
        majors.push_back(new_major);
    }
    inFile.close();
    return;
}
void System::read_file_courses(string courses_file, vector<Course *> &courses)
{
    ifstream inFile(courses_file);
    string line;
    bool is_first_line = true;
    while (getline(inFile, line))
    {
        if (is_first_line)
        {
            is_first_line = false;
            continue;
        }
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        stringstream line_stream(line);
        string cid, name, credit_string, prerequisite_string, major_ids_string;

        getline(line_stream, cid, ',');
        getline(line_stream, name, ',');
        getline(line_stream, credit_string, ',');
        getline(line_stream, prerequisite_string, ',');
        getline(line_stream, major_ids_string, ',');

        int credits = string_to_int(credit_string);
        int prerequisite = string_to_int(prerequisite_string);
        vector<int> majors_ids;
        stringstream major_stream(major_ids_string);
        string major_id;

        while (getline(major_stream, major_id, ';'))
        {
            int id = string_to_int(major_id);
            majors_ids.push_back(id);
        }
        Course *new_course = new Course(cid, name, credits, prerequisite, majors_ids);
        courses.push_back(new_course);
    }
    inFile.close();
    return;
}
void System::read_file_students(string students_file, vector<Person *> &people)
{
    ifstream inFile(students_file);
    string line;
    bool is_first_line = true;
    while (getline(inFile, line))
    {
        if (is_first_line)
        {
            is_first_line = false;
            continue;
        }
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        stringstream line_stream(line);
        string sid;
        string name;
        string major_id_string;
        string semester_string;
        string password;

        getline(line_stream, sid, ',');
        getline(line_stream, name, ',');
        getline(line_stream, major_id_string, ',');
        getline(line_stream, semester_string, ',');
        getline(line_stream, password, ',');
        int major_id = string_to_int(major_id_string);
        int semester = string_to_int(semester_string);
        Person *new_person = new Student(sid, name, password, major_id, semester);
        people.push_back(new_person);
    }
    inFile.close();
    return;
}
void System::read_file_professors(string professors_file, vector<Person *> &professors)
{
    ifstream inFile(professors_file);
    string line;
    bool is_first_line = true;
    while (getline(inFile, line))
    {
        if (is_first_line)
        {
            is_first_line = false;
            continue;
        }
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        stringstream line_stream(line);
        string sid;
        string name;
        string major_id_string;
        string position;
        string password;

        getline(line_stream, sid, ',');
        getline(line_stream, name, ',');
        getline(line_stream, major_id_string, ',');
        getline(line_stream, position, ',');
        getline(line_stream, password, ',');
        int major_id = string_to_int(major_id_string);
        Person *new_person = new Professor(sid, name, password, major_id, position);
        people.push_back(new_person);
    }
    inFile.close();
    return;
}
void System::login_user(string id, string password)
{
    current_user = find_user(id, password);
    current_user_state=current_user->who_are_you();
}
void System::connect_user(vector<string> &command_words)
{
    if (command_words.size() != 5)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    if (command_words[3] == ID)
    {
        regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
        if (!regex_match(command_words[4], natural_number_pattern))
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        int index = find_index_of_user(command_words[4]);
        current_user->connect_user(index);
        people[index]->connect_user(find_index_of_user(current_user->get_id()));
        throw runtime_error(SUCCESSFUL_RESPONSE);
    }
}

void System::new_post(vector<string> &command_words)
{

    regex string_pattern(STRING_PATTERN);
    if (!regex_match(command_words[4], string_pattern) || !regex_match(command_words[6], string_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }

    if (command_words[3] == TITLE && command_words[5] == MESSAGE)
    {
        current_user->add_new_post(command_words[4], command_words[6]);
    }
    else if (command_words[3] == MESSAGE && command_words[5] == TITLE)
    {
        current_user->add_new_post(command_words[6], command_words[4]);
    }
    else
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    send_notification(NEW_POST);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::new_post_with_image(string title, string message, string image_adress)
{
    current_user->add_new_post_with_image(title, message, image_adress);
    send_notification(NEW_POST);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::send_notification(string notification)
{
    current_user->send_notification(notification, people);
}
int System::find_index_of_user(string id)
{

    for (int i = 0; i < people.size(); i++)
    {

        if (people[i]->get_id() == id)
        {
            return i;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
Person *System::find_user(string id, string password)
{
    for (Person *person : people)
    {
        if (person->get_id() == id)
        {
            if (person->get_password() == password)
            {
                current_user_state = person->who_are_you();
                return person;
            }
            throw runtime_error(PERMISSION_ERROR);
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void System::delete_post(vector<string> &command_words)
{
    if (command_words.size() != 5)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    if (command_words[3] != ID)
    {

        throw runtime_error(BAD_REQUEST_ERROR);
    }
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (!regex_match(command_words[4], natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int id = string_to_int(command_words[4]);
    current_user->delete_post(id);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::get_notification(vector<string> &command_words)
{
    if (command_words.size() != 3)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    current_user->show_notification();
}
void System::is_professor(string professor_id)
{

    for (auto person : people)
    {
        if (person->get_id() == professor_id)
        {
            if (person->who_are_you() == PROFESSOR)
            {
                return;
            }
            else
            {
                throw runtime_error(PERMISSION_ERROR);
            }
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
Person *System::find_user_by_id(string id)
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
Person *System::find_professor_by_id(string id)
{
    for (auto person : people)
    {

        if (person->get_id() == id && person->who_are_you() == PROFESSOR)
        {
            return person;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void System::course_offer(string course_id, string professor_id, string capacity_str, string time, string exam_date, string class_number_str)
{
    regex natural_number(NATURAL_NUMBER_PATTERN);
    if (!regex_match(course_id, natural_number) || !regex_match(professor_id, natural_number) || !regex_match(capacity_str, natural_number) || !regex_match(class_number_str, natural_number))
    {

        throw runtime_error(BAD_REQUEST_ERROR);
    }
    is_professor(professor_id);
    int capacity = string_to_int(capacity_str);
    int class_number = string_to_int(class_number_str);
    static int id = 1;
    Course *new_course = find_course(course_id);
    Person *professor = find_user_by_id(professor_id);
    CourseOffering *new_course_offering = new_course->offer(id, capacity, time, exam_date, class_number, professor->get_name());
    professor->add_course(new_course_offering, time);
    Person *temp = current_user;
    current_user = professor;
    send_notification(NEW_COURSE_OFFERING);
    current_user = temp;
    offered_courses.push_back(new_course_offering);
    course_channels.push_back(new CourseChannel(id, professor, new_course_offering));
    id++;
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::add_profile_photo(string photo_adress)
{
    current_user->add_profile_photo(photo_adress);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::add_ta_form(vector<string> &command_words)
{
    if (command_words.size() != 7)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    string course_id;
    string message;
    if (command_words[3] == COURSE_ID && command_words[5] == MESSAGE)
    {
        course_id = command_words[4];
        message = command_words[6];
    }
    else if (command_words[3] == MESSAGE && command_words[5] == COURSE_ID)
    {
        course_id = command_words[6];
        message = command_words[4];
    }
    else
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    regex string_pattern(STRING_PATTERN);
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);

    if (!regex_match(message, string_pattern) || !regex_match(course_id, natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int id = string_to_int(course_id);
    CourseOffering *course = find_offered_course(id);
    current_user->is_professor_of_course(id);
    current_user->add_ta_form(course, message);
    send_notification(NEW_FORM);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::add_student_to_channel(int id, Person *&student)
{
    for (auto channel : course_channels)
    {
        if (channel->get_id() == id)
        {
            channel->add_student(student);
        }
    }
}
void System::put_course(string id_)
{
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (!regex_match(id_, natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int id = string_to_int(id_);
    CourseOffering *course = find_offered_course(id);
    current_user->add_course(course, "");
    send_notification(GET_COURSE);
    add_student_to_channel(id, current_user);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::show_information_my_courses(vector<string> &command_words)
{
    // current_user->show_information_courses();
}
string System::get_major(int major_id)
{

    for (auto major : majors)
    {

        if (major->get_id() == major_id)
        {
            return major->get_name();
        }
    }
    return "";
}
Course *System::find_course(string course_id)
{
    for (Course *course : courses)
    {
        if (course->get_cid() == course_id)
        {
            return course;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
CourseOffering *System::find_offered_course(int id)
{

    for (CourseOffering *course : offered_courses)
    {
        if (course->get_id() == id)
        {
            return course;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
void System::validate_argument(vector<bool> has_argument)
{
    for (bool argument : has_argument)
    {
        if (!argument)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
    }
    return;
}
void System::show_all_offered_courses(string &course_info)
{
    if (offered_courses.size() == 0)
    {
        throw runtime_error(EMPTY_ERROR);
    }
    ostringstream body;
    for (auto course : offered_courses)
    {
        body << "<div>" << course->show_information() << "</div>\n";
    }
    course_info = body.str();
}
void System::show_offered_course(vector<string> &command_words)
{
    if (command_words[3] != ID)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (!regex_match(command_words[4], natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int id = string_to_int(command_words[4]);
    CourseOffering *course = find_offered_course(id);
    course->show_full_information();
}
void System::ta_request(vector<string> &command_words)
{
    if (command_words.size() != 7)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    string professor_id, form_id;
    if (command_words[3] == "professor_id" && command_words[5] == "form_id")
    {
        professor_id = command_words[4];
        form_id = command_words[6];
    }
    else if (command_words[5] == "professor_id" && command_words[3] == "form_id")
    {
        professor_id = command_words[6];
        form_id = command_words[4];
    }
    else
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    Person *professor = find_professor_by_id(professor_id);
    Post form = professor->find_ta_form(form_id);
    Student *student = dynamic_cast<Student *>(current_user);
    student->can_be_ta(form);
    add_ta_request(form.course->get_id(), current_user->get_id());
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::add_ta_request(int channel_id, string student_id)
{
    for (auto channel : course_channels)
    {
        if (channel->get_id() == channel_id)
        {
            channel->add_ta_request(student_id);
        }
    }
}
CourseChannel *System::find_channel(int channel_id)
{
    for (auto channel : course_channels)
    {
        if (channel->get_id() == channel_id)
        {
            return channel;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}
CourseChannel *System::find_channel_with_form_id(int form_id)
{
    for (auto channel : course_channels)
    {
        if (channel->get_course()->get_form_id() == form_id)
        {
            return channel;
        }
    }
    throw runtime_error(NOT_FOUND_ERROR);
}

void System::close_ta_form(vector<string> &command_words)
{
    if (command_words.size() != 5 || command_words[3] != ID)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (!regex_match(command_words[4], natural_number_pattern))
    {
        throw runtime_error(PERMISSION_ERROR);
    }

    int form_id = string_to_int(command_words[4]);
    current_user->chack_has_ta_form(form_id);
    CourseChannel *channel = find_channel_with_form_id(form_id);
    channel->close_ta_form(people);
    current_user->delete_post(form_id);
}

void System::show_course_post(vector<string> &command_words)
{
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (command_words.size() != 7)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    if (!regex_match(command_words[4], natural_number_pattern) || !regex_match(command_words[6], natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int channel_id, post_id;

    if (command_words[3] == ID && command_words[5] == POST_ID)
    {
        channel_id = string_to_int(command_words[4]);
        post_id = string_to_int(command_words[6]);
    }
    else if (command_words[5] == ID && command_words[3] == POST_ID)
    {
        channel_id = string_to_int(command_words[6]);
        post_id = string_to_int(command_words[4]);
    }
    else
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    CourseChannel *channel = find_channel(channel_id);
    channel->has_permission_to_show_info(current_user->get_id());
    channel->show_information_post(post_id);
}
void System::show_information_channel(vector<string> &command_words)
{
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (command_words.size() != 5 || command_words[3] != ID || !regex_match(command_words[4], natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int channel_id = string_to_int(command_words[4]);
    CourseChannel *channel = find_channel(channel_id);
    channel->has_permission_to_show_info(current_user->get_id());
    channel->show_information_channel();
}
void System::add_course_post(vector<string> &command_words)
{
    int number_of_arg = (command_words.size() - 3) / 2;
    regex string_pattern(STRING_PATTERN);
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    vector<bool> has_argument(number_of_arg, false);
    int id;
    string title;
    string message;
    string image_adress;
    string argument;
    if (number_of_arg == 4)
    {
        for (int i = 3; i < 10; i += 2)
        {
            argument = command_words[i];
            if (argument == ID)
            {
                has_argument[0] = true;
                if (!regex_match(command_words[i + 1], natural_number_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                id = string_to_int(command_words[i + 1]);
            }
            if (argument == TITLE)
            {
                has_argument[1] = true;
                if (!regex_match(command_words[i + 1], string_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                title = command_words[i + 1];
            }
            if (argument == MESSAGE)
            {
                has_argument[2] = true;
                if (!regex_match(command_words[i + 1], string_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                message = command_words[i + 1];
            }
            if (argument == IMAGE)
            {
                has_argument[3] = true;
                image_adress = command_words[i + 1];
            }
        }
    }
    else if (number_of_arg == 3)
    {

        for (int i = 3; i < 8; i += 2)
        {

            argument = command_words[i];
            if (argument == ID)
            {
                has_argument[0] = true;
                if (!regex_match(command_words[i + 1], natural_number_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                id = string_to_int(command_words[i + 1]);
            }
            if (argument == TITLE)
            {
                has_argument[1] = true;
                if (!regex_match(command_words[i + 1], string_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                title = command_words[i + 1];
            }
            if (argument == MESSAGE)
            {
                has_argument[2] = true;
                if (!regex_match(command_words[i + 1], string_pattern))
                {
                    throw runtime_error(BAD_REQUEST_ERROR);
                }
                message = command_words[i + 1];
            }
        }
    }

    validate_argument(has_argument);
    CourseChannel *channel = find_channel(id);
    channel->has_permission_to_post(current_user->get_id());
    CoursePost new_post = {0, title, message, current_user->get_name(), image_adress};
    channel->new_course_post(new_post, current_user->get_id());
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::show_personal_page(string id , string &html)
{   
    regex arithmetic_number_pattern(ARITHMETIC_NUMBER_PATTERN);
    if ( !regex_match(id, arithmetic_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    Person *user = find_user_by_id(id);
    user->show_personal_page(majors ,html);
}
void System::show_post(vector<string> &command_words)
{
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    regex arithmetic_number_pattern(ARITHMETIC_NUMBER_PATTERN);
    if (command_words.size() != 7)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    if (command_words[3] == ID && command_words[5] == POST_ID)
    {
        if (!regex_match(command_words[6], natural_number_pattern) || !regex_match(command_words[4], arithmetic_number_pattern))
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        string id = command_words[4];
        int post_id = string_to_int(command_words[6]);
        Person *user = find_user_by_id(id);
        user->show_post(majors, post_id);
    }
    else if (command_words[5] == ID && command_words[3] == POST_ID)
    {
        if (!regex_match(command_words[6], arithmetic_number_pattern) || !regex_match(command_words[4], natural_number_pattern))
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        string id = command_words[6];
        int post_id = string_to_int(command_words[4]);
        Person *user = find_user_by_id(id);
        user->show_post(majors, post_id);
    }
    else
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
}
void System::delete_course(string id_)
{
    regex natural_number_pattern(NATURAL_NUMBER_PATTERN);
    if (!regex_match(id_, natural_number_pattern))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    int id = string_to_int(id_);
    current_user->delete_course(id);
    send_notification(DELETE_COURSE);
    throw runtime_error(SUCCESSFUL_RESPONSE);
}
void System::logout()
{  
    current_user_state = LOGOUT;
    current_user = NULL;
   
}
