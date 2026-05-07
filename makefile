CC = gcc

CFLAGS = -Wall -g -Iinclude

OBJ = main.o draw.o screen.o transform.o viewPort.o object.o

app: $(OBJ)
	$(CC) $(OBJ) -o app -lm

main.o: main/main.c
	$(CC) $(CFLAGS) -c main/main.c -o main.o

draw.o: draw/draw.c
	$(CC) $(CFLAGS) -c draw/draw.c -o draw.o

screen.o: screen/screen.c
	$(CC) $(CFLAGS) -c screen/screen.c -o screen.o

transform.o: transform/transform.c
	$(CC) $(CFLAGS) -c transform/transform.c -o transform.o

viewPort.o: viewPort/viewPort.c
	$(CC) $(CFLAGS) -c viewPort/viewPort.c -o viewPort.o

object.o: object/object.c
	$(CC) $(CFLAGS) -c object/object.c -o object.o

clean:
	del *.o app.exe