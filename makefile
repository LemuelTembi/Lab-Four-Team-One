//  Build an executable module named assign3 which will be rebuilt
//  if either assign3.o,or book.o has been updated.
//  The command
//
//     c++ assign3.o book.o -o assign3
//
//  link assign3.o,and book.o to the math library to build
//  an executable (or load) module named assign3.
//
assign3: assign3.o book.o
    c++ assign3.o book.o -o assign3

//  Build an object file named book.o which will be built
//  if book.cpp or book.h has been updated.
//  The command
//
//    c++ -c book.cpp
//
// compile the source program book.cpp and build an object
//  file named assign3.o.
book.o: book.cpp book.h
    c++ -c book.cpp


//  Build an object file named assign3.o which will be built
//  if assign3.cpp or book.h has been updated.
//  The command
//
//    c++ -c assign3.cpp
//
// compile the source program utility.cpp and build an object
//  file named assign3.o.
//
assign3.o: assign3.cpp book.h book.cpp
    c++ -c assign3.cpp
