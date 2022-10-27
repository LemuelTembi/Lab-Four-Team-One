
#  Build an executable module named assign4 which will be rebuilt
#  if either assign4.o,or book.o has been updated.
#  The command
#
#     c++ assign4.o book.o -o assign3
#
#  link assign4.o,and book.o to the math library to build
#  an executable (or load) module named assign4.
#

assign4: assign4.o book.o
	c++ assign4.o book.o -o assign4

#  Build an object file named book.o which will be built
#  if book.cpp or book.h has been updated.
#  The command
#
#    c++ -c book.cpp
#
# compile the source program book.cpp and build an object
#  file named assign4.o.

book.o: book.cpp book.h
	c++ -c book.cpp


#  Build an object file named assign4.o which will be built
#  if assign4.cpp or book.h has been updated.
#  The command
#
#    c++ -c assign4.cpp
#
# compile the source program utility.cpp and build an object
#  file named assign4.o.
#

assign4.o: assign4.cpp book.h book.cpp
	c++ -c assign4.cpp

