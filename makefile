CC = gcc
CFLAGS = -Wall -g

OBJ = main.o screen.o draw.o transform.o

app: $(OBJ)
	$(CC) $(OBJ) -o app

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	del *.o app.exe
	