DIR_INC = ./include
DIR_SRC = ./
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.cpp)
DIR = $(notdir ${SRC})
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))

FLAGS=-I./tinyxml

VPATH = ./tinyxml ./
EXE = main

CC = g++
CFLAGS = -Wall
INCLUDES=-I/usr/local/include

OBJECTS = main.o tinyxml2.o

all:${OBJECTS}
	${CC} -o ${EXE} *.o ${INCLUDES}

%.o : %.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

%.o : %.cc
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


clean:
	rm -f ${EXE} ${OBJECTS}
