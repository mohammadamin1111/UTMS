------------------ command: POST login ? password randompass2 id 810102456
OK
------------------ command: GET personal_page ? id 810102456
Sarah Computer Engineering 5 
------------------ command: POST connect ? id 810102789
OK
------------------ command: POST post ? title "title1" image xyz/dhd/kkk message "dkooooooo azizammm !!!!! khkhkhkhkh@!"
OK
------------------ command: POST post ? title "title1" image xyz/dhd/kkk
Bad Request
------------------ command: POST post ? title "title1" message "jygjyjyjt trrub tf rrrrrr"
OK
------------------ command: GET personal_page ? id 810102456
Sarah Computer Engineering 5 
2 "title1"
1 "title1"
------------------ command: GET post ? post_id 1 id 810102456
Sarah Computer Engineering 5 
1 "title1" "dkooooooo azizammm !!!!! khkhkhkhkh@!"
------------------ command: GET post ? post_id 2 id 810102456
Sarah Computer Engineering 5 
2 "title1" "jygjyjyjt trrub tf rrrrrr"
------------------ command: GET post ? id 810102456 post_id 2
Sarah Computer Engineering 5 
2 "title1" "jygjyjyjt trrub tf rrrrrr"
------------------ command: GET post ? id 810102456 post_id 3
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass4 id 810102789
Permission Denied
------------------ command: POST login ? password randompass3 id 810102789
OK
------------------ command: GET notification ?
810102456 Sarah: New Post
810102456 Sarah: New Post
------------------ command: GET notification ?
Empty
------------------ command: POST profile_photo ? photo photos/ponio.png
OK
------------------ command: POST profile_photo ? phttttoto photos/ponio.png
Bad Request
------------------ command: POST logout ?
OK
------------------ command: POST login ? password UT_account id 0
OK
------------------ command: POST course_offer ? course_id 1 professor_id 810420434 capacity 70 time Sunday:13-15 exam_date 1403/4/4 class_number 3
Permission Denied
------------------ command: POST course_offer ? course_id 1 capacity 70 time Sunday:13-15 exam_date 1403/4/4 class_number 3 professor_id 810420436
OK
------------------ command: POST course_offer ? course_id 4 capacity 70 time Sunday:14-16 exam_date 1403/4/5 class_number 3 professor_id 810420436
Permission Denied
------------------ command: POST course_offer ? course_id 4 capacity 70 time Sunday:15-16 exam_date 1403/4/6 class_number 3 professor_id 810420436
OK
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass4 id 810102987
OK
------------------ command: PUT my_courses ? id 1
Permission Denied
------------------ command: PUT my_courses ? id 2
Permission Denied
------------------ command: PUT my_courses ? id 3
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password meoow id 810102342
OK
------------------ command: PUT my_courses ? id 1
OK
------------------ command: PUT my_courses ? id 2
OK
------------------ command: PUT my_courses ? id 3
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password def456 id 810420434
OK
------------------ command: GET courses ?
1 Advanced Programming 70 Sarah Williams
2 Web Development 70 Sarah Williams
------------------ command: POST course_post ? id 4 title "Homework 6" message "Phase 2"
Not Found
------------------ command: POST course_post ? id 2 title "Homework 6" message "Phase 2"
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password jkl012 id 810420436
OK
------------------ command: POST course_post ? id 4 title "Homework 6" message "Phase 2"
Not Found
------------------ command: POST course_post ? id 2 title "Homework 6" message "Phase 2"
OK
------------------ command: POST course_post ? id 1 title "Homework 6" message "Phaffffse 2" image ./sdvihv/ddfdd
OK
------------------ command: POST course_post ? id 2 title "Homework 7777" message "pareh in 2"
OK
------------------ command: POST course_post ? id 1 image ./sdvihv/ddfdd title "Homework yohahahaha" message "Phaffffse 2"
OK
------------------ command: GET notification ?
810420436 Sarah Williams: New Course Offering
810420436 Sarah Williams: New Course Offering
------------------ command: POST logout ?
OK
------------------ command: POST login ? password meoow id 810102342
OK
------------------ command: GET notification ?
1 Advanced Programming: New Course Post
2 Web Development: New Course Post
1 Advanced Programming: New Course Post
2 Web Development: New Course Post
810420436 Sarah Williams: New Course Offering
810420436 Sarah Williams: New Course Offering
------------------ command: POST logout ?
OK
------------------ command: POST login ? password meoow id 810102342
OK
------------------ command: POST course_post ? id 1 title "Homework 6" message "Phase 2"
Permission Denied
------------------ command: GET course_channel ? id 3
Not Found
------------------ command: GET course_channel ? id 2
2 Web Development 70 Sarah Williams Sunday:15-16 1403/4/6 3
2 Sarah Williams "Homework 7777"
1 Sarah Williams "Homework 6"
------------------ command: GET course_channel ? id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
2 Sarah Williams "Homework yohahahaha"
1 Sarah Williams "Homework 6"
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass5 id 810102654
OK
------------------ command: GET course_channel ? id 3
Not Found
------------------ command: GET course_channel ? id 2
Permission Denied
------------------ command: GET course_channel ? id 1
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password ghi789 id 810420435
OK
------------------ command: GET course_channel ? id 3
Not Found
------------------ command: GET course_channel ? id 2
Permission Denied
------------------ command: GET course_channel ? id 1
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password jkl012 id 810420436
OK
------------------ command: GET course_channel ? id 3
Not Found
------------------ command: GET course_channel ? id 2
2 Web Development 70 Sarah Williams Sunday:15-16 1403/4/6 3
2 Sarah Williams "Homework 7777"
1 Sarah Williams "Homework 6"
------------------ command: GET course_channel ? id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
2 Sarah Williams "Homework yohahahaha"
1 Sarah Williams "Homework 6"
------------------ command: GET course_post ? id 1 post_id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
1 Sarah Williams "Homework 6" "Phaffffse 2"
------------------ command: GET course_post ? post_id 2 id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
2 Sarah Williams "Homework yohahahaha" "Phaffffse 2"
------------------ command: GET course_post ? post_id 3 id 1
Not Found
------------------ command: GET course_post ? post_id 2 id 1 k 8aD
Bad Request
------------------ command: GET course_post ? id 2 post_id 1
2 Web Development 70 Sarah Williams Sunday:15-16 1403/4/6 3
1 Sarah Williams "Homework 6" "Phase 2"
------------------ command: GET course_post ? post_id 2 id 2
2 Web Development 70 Sarah Williams Sunday:15-16 1403/4/6 3
2 Sarah Williams "Homework 7777" "pareh in 2"
------------------ command: GET course_post ? post_id 3 id 2
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password ghi789 id 810420435
OK
------------------ command: GET course_post ? id 1 post_id 1
Permission Denied
------------------ command: GET course_post ? post_id 2 id 1
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password meoow id 810102342
OK
------------------ command: GET course_post ? id 1 post_id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
1 Sarah Williams "Homework 6" "Phaffffse 2"
------------------ command: GET course_post ? post_id 2 id 1
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
2 Sarah Williams "Homework yohahahaha" "Phaffffse 2"
------------------ command: GET course_post ? post_id 3 id 1
Not Found
------------------ command: GET courses ?
1 Advanced Programming 70 Sarah Williams
2 Web Development 70 Sarah Williams
------------------ command: POST ta_form ? course_id 1 message "sdclkn sdlkcnc dlkvjnnn"
Permission Denied
------------------ command: POST ta_form ? course_id 2 message "sdclkn sdlkcnc dlkvjnnn"
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password ghi789 id 810420435
OK
------------------ command: GET courses ?
1 Advanced Programming 70 Sarah Williams
2 Web Development 70 Sarah Williams
------------------ command: POST ta_form ? course_id 1 message "sdclkn sdlkcnc dlkvjnnn"
Permission Denied
------------------ command: POST ta_form ? course_id 2 message "sdclkn sdlkcnc dlkvjnnn"
Permission Denied
------------------ command: POST logout ?
OK
------------------ command: POST login ? password jkl012 id 810420436
OK
------------------ command: POST connect ? id 810102789
OK
------------------ command: POST connect ? id 810102789
Bad Request
------------------ command: GET courses ?
1 Advanced Programming 70 Sarah Williams
2 Web Development 70 Sarah Williams
------------------ command: POST ta_form ? course_id 1 message "sdclkn sdlkcnc dlkvjnnn"
OK
------------------ command: POST post ? title "sacjk" message "sac  cvvd  dv dddd !! jk"
OK
------------------ command: POST ta_form ? course_id 2 message "sdclkn sdlkcnc dlkvjnndffdn"
OK
------------------ command: POST ta_form ? course_id 3 message "sdclkn sdlkcnc dlkvjnfdfdadssnn"
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass3 id 810102789
OK
------------------ command: GET notification ?
810420436 Sarah Williams: New Form
810420436 Sarah Williams: New Post
810420436 Sarah Williams: New Form
810420436 Sarah Williams: New Course Offering
810420436 Sarah Williams: New Course Offering
------------------ command: GET personal_page ? id 810420436
Sarah Williams Electrical Engineering assistant professor Advanced Programming,Web Development
3 TA form for Web Development course
2 "sacjk"
1 TA form for Advanced Programming course
------------------ command: GET post ? id 810420436 post_id 1
Sarah Williams Electrical Engineering assistant professor Advanced Programming,Web Development
1 TA form for Advanced Programming course
1 Advanced Programming 70 Sarah Williams Sunday:13-15 1403/4/4 3
"sdclkn sdlkcnc dlkvjnnn"
------------------ command: GET post ? id 810420436 post_id 2
Sarah Williams Electrical Engineering assistant professor Advanced Programming,Web Development
2 "sacjk" "sac  cvvd  dv dddd !! jk"
------------------ command: GET post ? id 810420436 post_id 3
Sarah Williams Electrical Engineering assistant professor Advanced Programming,Web Development
3 TA form for Web Development course
2 Web Development 70 Sarah Williams Sunday:15-16 1403/4/6 3
"sdclkn sdlkcnc dlkvjnndffdn"
------------------ command: POST ta_request ? professor_id 810420436 form_id 4
Not Found
------------------ command: POST ta_request ? professor_id 810420436 form_id 3
OK
------------------ command: POST ta_request ? professor_id 810420436 form_id 2
Not Found
------------------ command: POST ta_request ? professor_id 810420436 form_id 1
Permission Denied
------------------ command: POST ta_request ? professor_id 810102123 form_id 2
Not Found
------------------ command: POST ta_request ? professor_id 810102123 form_id 1
Not Found
------------------ command: POST ta_request ? professor_id 810420434 form_id 2
Not Found
------------------ command: POST ta_request ? professor_id 810420434 form_id 1
Not Found
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass2 id 810102456
OK
------------------ command: POST ta_request ? professor_id 810420436 form_id 4
Not Found
------------------ command: POST ta_request ? professor_id 810420436 form_id 3
OK
------------------ command: POST ta_request ? professor_id 810420436 form_id 2
Not Found
------------------ command: POST ta_request ? professor_id 810420436 form_id 1
OK
------------------ command: POST logout ?
OK
------------------ command: POST login ? password jkl012 id 810420436
OK
------------------ command: POST ta_request ? professor_id 810420436 form_id 4
Permission Denied
------------------ command: POST ta_request ? professor_id 810420436 form_id 3
Permission Denied
------------------ command: POST ta_request ? professor_id 810420436 form_id 2
Permission Denied
------------------ command: POST ta_request ? professor_id 810420436 form_id 1
Permission Denied
------------------ command: POST close_ta_form ? id 2
Not Found
------------------ command: POST close_ta_form ? id 1
We have received 1 requests for the teaching assistant position
810102456 Sarah 5:
------------------ command: POST close_ta_form ? id 3
We have received 2 requests for the teaching assistant position
810102789 Michael 2:
810102456 Sarah 5:
810102456 Sarah 5:
------------------ command: GET personal_page ? id 810420436
Sarah Williams Electrical Engineering assistant professor Advanced Programming,Web Development
2 "sacjk"
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass3 id 810102789
OK
------------------ command: GET notification ?
2 Web Development: Your request to be a teaching assistant has been accepted.
------------------ command: POST course_post ? id 1 title "ddvvd sd" message "sdvcdsvc dssd" image sdvsdv/dsd
Permission Denied
------------------ command: POST course_post ? id 2 title "ddvvd ccsd" message "sdvccccdsvc dssd"
OK
------------------ command: POST logout ?
OK
------------------ command: POST login ? password randompass2 id 810102456
OK
------------------ command: GET notification ?
2 Web Development: Your request to be a teaching assistant has been rejected.
1 Advanced Programming: Your request to be a teaching assistant has been accepted.
810420436 Sarah Williams: New Course Offering
810420436 Sarah Williams: New Course Offering
------------------ command: POST course_post ? id 1 title "ddvvd sd" message "sdvcdsvc dssd" image sdvsdv/dsd
OK
------------------ command: POST course_post ? id 2 title "ddvvd ccsd" message "sdvccccdsvc dssd"
Permission Denied
