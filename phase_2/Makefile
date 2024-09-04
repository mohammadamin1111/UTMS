
utms:main.o system.o channel.o person.o major.o course.o generalfunctions.o IO.o
	g++ -std=c++20 main.o system.o channel.o person.o major.o course.o generalfunctions.o IO.o -o utms.out
main.o: main.cpp
	g++ -std=c++20 -c main.cpp
system.o: system.cpp
	g++ -std=c++20 -c system.cpp
channel.o: channel.cpp
	g++ -std=c++20 -c channel.cpp
person.o: person.cpp
	g++ -std=c++20 -c person.cpp
major.o: major.cpp
	g++ -std=c++20 -c major.cpp
course.o: course.cpp
	g++ -std=c++20 -c course.cpp
generalfunctions.o: generalfunctions.cpp
	g++ -std=c++20 -c generalfunctions.cpp
IO.o: IO.cpp
	g++ -std=c++20 -c IO.cpp
clean:
	rm *.o utms.out