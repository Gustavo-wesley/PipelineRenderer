CC = gcc
CFLAGS = -Wall -g -Iinclude

SRC = main/main.c draw/draw.c screen/screen.c transform/transform.c
OBJ = main.o draw.o screen.o transform.o

app: $(OBJ)
	$(CC) $(OBJ) -o app

main.o: main/main.c
	$(CC) $(CFLAGS) -c main/main.c -o main.o

draw.o: draw/draw.c
	$(CC) $(CFLAGS) -c draw/draw.c -o draw.o

screen.o: screen/screen.c
	$(CC) $(CFLAGS) -c screen/screen.c -o screen.o

transform.o: transform/transform.c
	$(CC) $(CFLAGS) -c transform/transform.c -o transform.o

clean:
	del *.o app.exe