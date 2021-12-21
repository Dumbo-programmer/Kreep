CC = gcc
CFLAGS = -c -std=c99 -g
LDFLAGS = -g
SRC = ${wildcard src/*.c}
HDR = ${wildcard include/*.h}
OBJ = ${SRC:.c=.o}
EXEC = kreep

all: ${SRC} ${ONBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC}	${LDFLAGS}	$^ -o $@
%.o:	%.c	${HDR}
	${CC}	${CFLAGS} $^ -o $@	

clean:
	rm	src/*.o	${EXEC}