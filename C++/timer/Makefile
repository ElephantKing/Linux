DIR_INC = ./
DIR_SRC = ./
DIR_OBJ = ./
DIR_BIN = ./

SRC = $(wildcard ${DIR_SRC}/*.cpp)
DIR = $(notdir ${SRC})
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))

FLAGS=

VPATH = ./
EXE = main

CC = g++
CFLAGS = -Wall
INCLUDES=-I/usr/local/include

OBJECTS = main.o timer.o

all:${OBJECTS}
	${CC} -o ${EXE} *.o ${INCLUDES}

%.o : %.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

%.o : %.cc
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


clean:
	rm -f ${EXE} ${OBJECTS}
