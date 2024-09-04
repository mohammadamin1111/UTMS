#include "handlers.hpp"

#include <cstdlib>
#include <iostream>

ShowAllCoursesHandler::ShowAllCoursesHandler(System *system_)
{
    utms = system_;
}
ProfilePhotoHandler::ProfilePhotoHandler(System *system_)
{
    utms = system_;
}
PostPhotoHandler::PostPhotoHandler(System *system_)
{
    utms = system_;
}
LoginHandler::LoginHandler(System *system_)
{
    utms = system_;
}
ShowPersonalPageHandler::ShowPersonalPageHandler(System *system_)
{
    utms = system_;
}
ChangeProfilePhoto::ChangeProfilePhoto(System *system_)
{
    utms = system_;
}
LogoutHandler::LogoutHandler(System *system_)
{
    utms = system_;
}
CourseOfferHandler::CourseOfferHandler(System *system_)
{
    utms = system_;
}
PutCourseHandler::PutCourseHandler(System *system_)
{
    utms = system_;
}
DeleteCourseHandler::DeleteCourseHandler(System *system_)
{
    utms = system_;
}
ShowMyCoursesHandler::ShowMyCoursesHandler(System *system_)
{
    utms = system_;
}
NewPost::NewPost(System *system_)
{
    utms = system_;
}

Response *ShowPersonalPageHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT && utms->get_current_user_state() != PROFESSOR)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string id = req->getBodyParam(ID);
        string body;
        utms->show_personal_page(id, body);

        std::ostringstream html;

        html << "<!DOCTYPE html>\n";
        html << "<html lang=\"en\">\n";
        html << "\n";
        html << "<head>\n";
        html << "  <meta charset=\"UTF-8\">\n";
        html << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        html << "  <title>Personal Page</title>\n";
        html << "  <style>\n";
        html << "    body {\n";
        html << "      font-family: Arial, sans-serif;\n";
        html << "      background: linear-gradient(200deg, #74eb8e, #2a518b);\n";
        html << "      display: flex;\n";
        html << "      justify-content: center;\n";
        html << "      align-items: center;\n";
        html << "      height: 100vh;\n";
        html << "      margin: 0;\n";
        html << "      color: #fff;\n";
        html << "    }\n";
        html << "\n";
        html << "    .container {\n";
        html << "      text-align: center;\n";
        html << "      background: rgba(255, 255, 255, 0.1);\n";
        html << "      padding: 20px;\n";
        html << "      border-radius: 10px;\n";
        html << "      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);\n";
        html << "    }\n";
        html << "\n";
        html << "    h1 {\n";
        html << "      font-size: 2.5em;\n";
        html << "      margin-bottom: 20px;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links {\n";
        html << "      margin: 20px 0;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a {\n";
        html << "      display: inline-block;\n";
        html << "      margin: 10px;\n";
        html << "      padding: 10px 20px;\n";
        html << "      text-decoration: none;\n";
        html << "      color: #fff;\n";
        html << "      background-color: rgba(0, 0, 0, 0.2);\n";
        html << "      border-radius: 5px;\n";
        html << "      transition: background-color 0.3s ease, transform 0.3s ease;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a:hover {\n";
        html << "      background-color: rgba(0, 0, 0, 0.4);\n";
        html << "      transform: scale(1.05);\n";
        html << "    }\n";
        html << "  </style>\n";
        html << "</head>\n";
        html << "\n";
        html << "<body>\n";
        html << "  <div class=\"container\">\n";
        html << body;
        html << "  </div>\n";
        html << "</body>\n";
        html << "\n";
        html << "</html>";

        Response *res = new Response();
        res->setHeader("Content-Type", "text/html");
        res->setBody(html.str());
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}

Response *ShowMyCoursesHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        string course_info;
        utms->get_current_user()->show_information_courses(course_info);

        std::ostringstream html;

        html << "<!DOCTYPE html>\n";
        html << "<html lang=\"en\">\n";
        html << "\n";
        html << "<head>\n";
        html << "  <meta charset=\"UTF-8\">\n";
        html << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        html << "  <title>My course Page</title>\n";
        html << "  <style>\n";
        html << "    body {\n";
        html << "      font-family: Arial, sans-serif;\n";
        html << "      background: linear-gradient(200deg, #74eb8e, #2a518b);\n";
        html << "      display: flex;\n";
        html << "      justify-content: center;\n";
        html << "      align-items: center;\n";
        html << "      height: 100vh;\n";
        html << "      margin: 0;\n";
        html << "      color: #fff;\n";
        html << "    }\n";
        html << "\n";
        html << "    .container {\n";
        html << "      text-align: center;\n";
        html << "      background: rgba(255, 255, 255, 0.1);\n";
        html << "      padding: 20px;\n";
        html << "      border-radius: 10px;\n";
        html << "      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);\n";
        html << "    }\n";
        html << "\n";
        html << "    h1 {\n";
        html << "      font-size: 2.5em;\n";
        html << "      margin-bottom: 20px;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links {\n";
        html << "      margin: 20px 0;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a {\n";
        html << "      display: inline-block;\n";
        html << "      margin: 10px;\n";
        html << "      padding: 10px 20px;\n";
        html << "      text-decoration: none;\n";
        html << "      color: #fff;\n";
        html << "      background-color: rgba(0, 0, 0, 0.2);\n";
        html << "      border-radius: 5px;\n";
        html << "      transition: background-color 0.3s ease, transform 0.3s ease;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a:hover {\n";
        html << "      background-color: rgba(0, 0, 0, 0.4);\n";
        html << "      transform: scale(1.05);\n";
        html << "    }\n";
        html << "  </style>\n";
        html << "</head>\n";
        html << "\n";
        html << "<body>\n";
        html << "  <div class=\"container\">\n";
        html << course_info;
        html << "  </div>\n";
        html << "</body>\n";
        html << "\n";
        html << "</html>";

        Response *res = new Response();
        res->setHeader("Content-Type", "text/html");
        res->setBody(html.str());
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *ShowAllCoursesHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT && utms->get_current_user_state() != PROFESSOR)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        string course_info;
        utms->show_all_offered_courses(course_info);

        std::ostringstream html;

        html << "<!DOCTYPE html>\n";
        html << "<html lang=\"en\">\n";
        html << "\n";
        html << "<head>\n";
        html << "  <meta charset=\"UTF-8\">\n";
        html << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        html << "  <title>All courses Page</title>\n";
        html << "  <style>\n";
        html << "    body {\n";
        html << "      font-family: Arial, sans-serif;\n";
        html << "      background: linear-gradient(200deg, #74eb8e, #2a518b);\n";
        html << "      display: flex;\n";
        html << "      justify-content: center;\n";
        html << "      align-items: center;\n";
        html << "      height: 100vh;\n";
        html << "      margin: 0;\n";
        html << "      color: #fff;\n";
        html << "    }\n";
        html << "\n";
        html << "    .container {\n";
        html << "      text-align: center;\n";
        html << "      background: rgba(255, 255, 255, 0.1);\n";
        html << "      padding: 20px;\n";
        html << "      border-radius: 10px;\n";
        html << "      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);\n";
        html << "    }\n";
        html << "\n";
        html << "    h1 {\n";
        html << "      font-size: 2.5em;\n";
        html << "      margin-bottom: 20px;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links {\n";
        html << "      margin: 20px 0;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a {\n";
        html << "      display: inline-block;\n";
        html << "      margin: 10px;\n";
        html << "      padding: 10px 20px;\n";
        html << "      text-decoration: none;\n";
        html << "      color: #fff;\n";
        html << "      background-color: rgba(0, 0, 0, 0.2);\n";
        html << "      border-radius: 5px;\n";
        html << "      transition: background-color 0.3s ease, transform 0.3s ease;\n";
        html << "    }\n";
        html << "\n";
        html << "    .nav-links a:hover {\n";
        html << "      background-color: rgba(0, 0, 0, 0.4);\n";
        html << "      transform: scale(1.05);\n";
        html << "    }\n";
        html << "  </style>\n";
        html << "</head>\n";
        html << "\n";
        html << "<body>\n";
        html << "  <div class=\"container\">\n";
        html << course_info;
        html << "  </div>\n";
        html << "</body>\n";
        html << "\n";
        html << "</html>";

        Response *res = new Response();
        res->setHeader("Content-Type", "text/html");
        res->setBody(html.str());
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *LoginHandler::callback(Request *req)
{
    try
    {
        
        std::string id = req->getBodyParam(ID);
        std::string password = req->getBodyParam(PASSWORD);
        utms->login_user(id, password);
        User user = utms->get_current_user()->who_are_you();
        return main_page(utms, user);
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *ChangeProfilePhoto::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT && utms->get_current_user_state() != PROFESSOR)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string name = req->getBodyParam("profile_photo_name");
        utms->add_profile_photo(name);
        Response *res = Response::redirect("/");
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *NewPost::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() == LOGOUT)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string title = req->getBodyParam(TITLE);
        std::string message = req->getBodyParam(MESSAGE);
        std::string photo_name = req->getBodyParam(PROFILE_PHOTO_NAME);
        utms->new_post_with_image(title, message, photo_name);
        Response *res = Response::redirect("/");
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *main_page(System *utms, User user)
{
    if (utms->get_current_user_state() == LOGOUT)
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    Response *res = new Response();
    res->setHeader("Content-Type", "text/html");
    std::ostringstream html;

    html << "<!DOCTYPE html>\n";
    html << "<html lang=\"en\">\n";
    html << "\n";
    html << "<head>\n";
    html << "  <meta charset=\"UTF-8\">\n";
    html << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html << "  <title>Main Page</title>\n";
    html << "  <style>\n";
    html << "    body {\n";
    html << "      font-family: Arial, sans-serif;\n";
    html << "      background: linear-gradient(200deg, #74eb8e, #2a518b);\n";
    html << "      display: flex;\n";
    html << "      justify-content: center;\n";
    html << "      align-items: center;\n";
    html << "      height: 100vh;\n";
    html << "      margin: 0;\n";
    html << "      color: #fff;\n";
    html << "    }\n";
    html << "\n";
    html << "    .container {\n";
    html << "      text-align: center;\n";
    html << "      background: rgba(255, 255, 255, 0.1);\n";
    html << "      padding: 20px;\n";
    html << "      border-radius: 10px;\n";
    html << "      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);\n";
    html << "    }\n";
    html << "\n";
    html << "    h1 {\n";
    html << "      font-size: 2.5em;\n";
    html << "      margin-bottom: 20px;\n";
    html << "    }\n";
    html << "\n";
    html << "    .nav-links {\n";
    html << "      margin: 20px 0;\n";
    html << "    }\n";
    html << "\n";
    html << "    .nav-links a {\n";
    html << "      display: inline-block;\n";
    html << "      margin: 10px;\n";
    html << "      padding: 10px 20px;\n";
    html << "      text-decoration: none;\n";
    html << "      color: #fff;\n";
    html << "      background-color: rgba(0, 0, 0, 0.2);\n";
    html << "      border-radius: 5px;\n";
    html << "      transition: background-color 0.3s ease, transform 0.3s ease;\n";
    html << "    }\n";
    html << "\n";
    html << "    .nav-links a:hover {\n";
    html << "      background-color: rgba(0, 0, 0, 0.4);\n";
    html << "      transform: scale(1.05);\n";
    html << "    }\n";
    html << "  </style>\n";
    html << "</head>\n";
    html << "\n";
    html << "<body>\n";
    html << "  <div class=\"container\">\n";
    html << "    <img src=\"profile_photo.png\" alt=\"Profile Image\" style=\"max-width: 100px; border-radius: 150%; margin-bottom: 20px;\">\n";
    html << "    <h1>Welcome ";
    html << utms->get_current_user()->get_name() << "</h1>\n";
    switch (user)
    {
    case STUDENT:

        html << "    <h2>Your id is: ";
        html << utms->get_current_user()->get_id() << "</h2>\n";
        html << "    <h2>";
        html << utms->get_major(utms->get_current_user()->get_major_id()) << "</h2>\n";
        html << "    <div class=\"nav-links\">\n";
        html << "      <a href=\"/put_course\">Put a course</a>\n";
        html << "      <a href=\"/delete_course\">Delete a course</a>\n";
        html << "      <a href=\"/show_my_courses\">Show info of my courses</a>\n";
        html << "      <a href=\"/change_profile_photo\">Change profile photo</a>\n";
        html << "      <a href=\"/show_all_courses\">Show all of offered courses</a>\n";
        html << "      <a href=\"/personal_page\">Show personal page</a>\n";
        break;

    case PROFESSOR:
        html << "    <h2>Your id is: ";
        html << utms->get_current_user()->get_id() << "</h2>\n";
        html << "    <h2>";
        html << utms->get_major(utms->get_current_user()->get_major_id()) << "</h2>\n";
        html << "    <div class=\"nav-links\">\n";
        html << "      <a href=\"/change_profile_photo\">Change profile photo</a>\n";
        html << "      <a href=\"/show_all_courses\">Show all of offered courses</a>\n";
        html << "      <a href=\"/personal_page\">Show personal page</a>\n";
        break;

    case ADMIN:
        html << "    <div class=\"nav-links\">\n";
        html << "      <a href=\"/course_offer\">New Course Offer</a>\n";
        break;
    }
    html << "      <a href=\"/new_post\">New post</a>\n";
    html << "      <a href=\"/logout\">Logout</a>\n";
    html << "    </div>\n";
    html << "  </div>\n";
    html << "</body>\n";
    html << "\n";
    html << "</html>";
    res->setBody(html.str());
    return res;
}

Response *LogoutHandler::callback(Request *req)
{
    try
    {
        utms->logout();
        Response *res = new Response();
        res = Response::redirect("/login");
        return res;
    }
     catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *ProfilePhotoHandler::callback(Request *req)
{
    Response *res = new Response();
    res->setHeader("Content-Type", "image/png");
    res->setBody(utils::readFile(utms->get_current_user()->get_photo_adress()));
    return res;
}
Response *PostPhotoHandler::callback(Request *req)
{   std::string image_adress=req->getBodyParam("image_adress");
    Response *res = new Response();
    res->setHeader("Content-Type", "image/png");
    res->setBody(utils::readFile(image_adress));
    return res;
}
Response *CourseOfferHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != ADMIN)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string course_id = req->getBodyParam("course_id");
        std::string professor_id = req->getBodyParam("professor_id");
        std::string capacity = req->getBodyParam("capacity");
        std::string time = req->getBodyParam("time");
        std::string exam_date = req->getBodyParam("exam_date");
        std::string class_number = req->getBodyParam("class_number");
        utms->course_offer(course_id, professor_id, capacity, time, exam_date, class_number);
        Response *res = new Response();
        res = Response::redirect("/admin");
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
string find_exeption(runtime_error e)
{
    string exp = e.what();
    if (exp == SUCCESSFUL_RESPONSE)
    {
        return "/ok";
    }
    else if (exp == NOT_FOUND_ERROR)
    {
        return "/not_found";
    }
    else if (exp == PERMISSION_ERROR)
    {
        return "/permission_denied";
    }
    else if (exp == EMPTY_ERROR)
    {
        return "/empty";
    }
    else
    {
        return "/bad_request";
    }
}
Response *PutCourseHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string id = req->getBodyParam("id");
        utms->put_course(id);
        Response *res = Response::redirect("/");
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
Response *DeleteCourseHandler::callback(Request *req)
{
    try
    {
        if (utms->get_current_user_state() != STUDENT)
        {
            throw runtime_error(BAD_REQUEST_ERROR);
        }
        std::string id = req->getBodyParam("id");
        utms->delete_course(id);
        Response *res = Response::redirect("/");
        return res;
    }
    catch (const std::runtime_error &e)
    {
        string exception_url = find_exeption(e);
        Response *res = Response::redirect(exception_url);
        return res;
    }
}
