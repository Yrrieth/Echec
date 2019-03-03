CC=gcc
SRC=echec.c main.c
OBJ=$(SRC:.c=.o)
FLAGS=-Wall

echec:	$(OBJ) echec.h
	$(CC) -o $@ $(OBJ)
%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *~ core
