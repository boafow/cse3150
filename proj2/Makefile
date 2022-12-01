CC = g++
CFLAGS = -Wall -g

TARGET = test-gv

all: $(TARGET)

$(TARGET): ECGraphicViewImp.o ECObserver.o test-gv.o 
	$(CC) $(CFLAGS) -o $(TARGET) ECGraphicViewImp.o ECObserver.o test-gv.o -lallegro -lallegro_font -lallegro_primitives -lallegro_image -lallegro_main

ECGraphicViewImp.o: ECGraphicViewImp.cpp ECGraphicViewImp.h

ECObserver.o: ECObserver.cpp ECObserver.h

test-gv.o: test-gv.cpp ECGraphicViewImp.h

clean:
	rm -f *.o $(TARGET)
	