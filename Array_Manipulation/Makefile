########################################################################
#
#  DESCRIPTION  : Makefile to compile lab1
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
PROJECTS = lab01_batman lab01_3n
EXECUTABLE1 = lab01_batman
EXECUTABLE2 = lab01_3n

#list of all .o file for each .cpp file
OBJECTS := lab01_batman.o

OBJECTS2 := lab01_3n.o

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
