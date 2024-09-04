#ifndef GENERALFUNCTIONS_HPP
#define GENERALFUNCTIONS_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum User
{
  ADMIN,
  STUDENT,
  PROFESSOR,
  LOGOUT
};
struct Notification
{
  string id;
  string name;
  string notif;
};
const string ARITHMETIC_NUMBER_PATTERN = "^(0|[1-9][0-9]*)$";
const string NATURAL_NUMBER_PATTERN = "^([1-9][0-9]*)$";
const string STRING_PATTERN = "^\"[^\"]*\"$";
const string COURSE_ID = "course_id";
const string IMAGE = "image";
const string BAD_REQUEST_ERROR = "Bad Request";
const string PERMISSION_ERROR = "Permission Denied";
const string SUCCESSFUL_RESPONSE = "OK";
const string NOT_FOUND_ERROR = "Not Found";
const string EMPTY_ERROR = "Empty";
const string QUESTION_MARK = "?";
const string ID = "id";
const string POST_ID = "post_id";
const string PASSWORD = "password";
const string TITLE = "title";
const string MESSAGE = "message";
const string NEW_POST = "New Post";
const string NEW_COURSE_OFFERING = "New Course Offering";
const string GET_COURSE = "Get Course";
const string DELETE_COURSE = "Delete Course";
const string NEW_FORM = "New Form";
const string ADMIN_NAME = "UT_account";
const string ADMIN_PASSWORD = "UT_account";
const string NEW_COURSE_POST = "New Course Post";
const string ADMIN_ID = "0";
const string ACCEPT="accept";
const string REJECT="reject";
const string ACCEPTED="accepted";
const string REJECTED="rejected";
const char COMMA = ',';
const string SPACE = " ";
const string PROFILE_PHOTO_NAME="profile_photo_name";

int string_to_int(string input_string);
bool is_command_type_correct(string command_type, vector<string> command_words);
vector<string> string_splitter(string command_line, char splitter);

#endif