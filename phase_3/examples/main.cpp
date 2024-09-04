#include <iostream>
#include <string>

#include "../server/server.hpp"
#include "../src/system.hpp"
#include "handlers.hpp"

const string STATIC_PATH = "static/";
const int PORT=8080;
int main(int argc, char *argv[])
{
    StandardIO io;
    System *utms = new System(io);
    utms->read_files(argv[1], argv[2], argv[3], argv[4]);
    try
    {
        Server server(PORT);
        server.get("/new_post", new ShowPage(STATIC_PATH+"new_post.html"));
        server.post("/new_post", new NewPost(utms));
        server.get("/change_profile_photo", new ShowPage(STATIC_PATH+"change_profile_photo.html"));
        server.post("/change_profile_photo", new ChangeProfilePhoto(utms));
        server.get("/profile_photo.png", new ProfilePhotoHandler(utms));
        server.get("/post_photo.png", new PostPhotoHandler(utms));
        server.get("/show_my_courses", new ShowMyCoursesHandler(utms));
        server.get("/show_all_courses", new ShowAllCoursesHandler(utms));
        server.post("/personal_page_person", new ShowPersonalPageHandler(utms));
        server.get("/personal_page", new ShowPage(STATIC_PATH+"personal_page.html"));
        server.get("/put_course", new ShowPage(STATIC_PATH+"put_course.html"));
        server.post("/put_course", new PutCourseHandler(utms));
        server.get("/delete_course", new ShowPage(STATIC_PATH+"delete_course.html"));
        server.post("/delete_course", new DeleteCourseHandler(utms));
        server.get("/course_offer", new ShowPage(STATIC_PATH+"course_offer.html"));
        server.post("/course_offer", new CourseOfferHandler(utms));
        server.get("/ok", new ShowPage(STATIC_PATH+"OK.html"));
        server.get("/not_found", new ShowPage(STATIC_PATH+"NotFound.html"));
        server.get("/permission_denied", new ShowPage(STATIC_PATH+"PermissionDenied.html"));
        server.get("/bad_request", new ShowPage(STATIC_PATH+"BadRequest.html"));
        server.get("/empty", new ShowPage(STATIC_PATH+"Empty.html"));
        server.get("/", new ShowPage(STATIC_PATH+"home.html"));
        server.get("/home.png", new ShowImage(STATIC_PATH+"home.png"));
        server.get("/logout", new LogoutHandler(utms));
        server.post("/login", new LoginHandler(utms));
        server.get("/login", new ShowPage(STATIC_PATH+"login.html"));
        server.run();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Server::Exception &e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    return 0;
}
