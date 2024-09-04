#ifndef HANDLERS_HPP_INCLUDE
#define HANDLERS_HPP_INCLUDE

#include <map>
#include <string>

#include "../server/server.hpp"
#include "../src/system.hpp"
#include "../src/generalfunctions.hpp"
#include "../src/person.hpp"
class Person;
Response *main_page(System *utms, User user);
class ShowAllCoursesHandler : public RequestHandler
{
public:
    ShowAllCoursesHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class ChangeProfilePhoto : public RequestHandler
{
public:
    ChangeProfilePhoto(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class ShowPersonalPageHandler : public RequestHandler
{
public:
    ShowPersonalPageHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class NewPost : public RequestHandler
{
public:
    NewPost(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class LoginHandler : public RequestHandler
{
public:
    LoginHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class ProfilePhotoHandler : public RequestHandler
{
public:
    ProfilePhotoHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class CourseOfferHandler : public RequestHandler
{
public:
    CourseOfferHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class PutCourseHandler : public RequestHandler
{
public:
    PutCourseHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class ShowMyCoursesHandler : public RequestHandler
{
public:
    ShowMyCoursesHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class DeleteCourseHandler : public RequestHandler
{
public:
    DeleteCourseHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class LogoutHandler : public RequestHandler
{
public:
    LogoutHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
class PostPhotoHandler: public RequestHandler
{
public:
    PostPhotoHandler(System *utms);
    Response *callback(Request *) override;

private:
    System *utms;
};
string find_exeption(runtime_error e);
#endif
