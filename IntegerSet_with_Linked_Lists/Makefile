########################################################################
#
#  DESCRIPTION  : Makefile to compile lab3
# 
#  PLATFORM		: Linux
#
#Reference: Ioannis Karamouzas (ioannis@clemson.edu)
########################################################################

#compiler
CC = g++

#auxiliary flags
CFLAGS	= -g
LDFLAGS =

#executable name
PROJECTS = lab03_linked_list test_linked_list
EXECUTABLE1 = lab03_linked_list
EXECUTABLE2 = test_linked_list

#list of all .o file for each .cpp file
OBJECTS := jolly.o
OBJECTS += intset.o


OBJECTS2 := testIntSet.o
OBJECTS2 += intset.o

#this does the linking step  
all: ${PROJECTS}
${EXECUTABLE1} : ${OBJECTS} 
	${CC} ${CFLAGS} -o ${EXECUTABLE1} ${OBJECTS} ${LDFLAGS}
	
${EXECUTABLE2} : ${OBJECTS2} 
	${CC} ${CFLAGS} -o ${EXECUTABLE2} ${OBJECTS2} ${LDFLAGS}  

#compile the code 
%.o: %.cpp
	${CC} -c ${CFLAGS} $<
	
#this will clean up all temporary files created by make all
clean:
	rm -f core.* *.o *~ ${PROJECTS}
