########################################################################
#
#  DESCRIPTION  : Makefile to compile lab5
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
PROJECTS = lab05_BST test_BST
EXECUTABLE1 = lab05_BST
EXECUTABLE2 = test_BST

#list of all .o file for each .cpp file
OBJECTS := intset.o
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
