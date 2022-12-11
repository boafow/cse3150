CC = g++
CFLAGS = -Wall -g

TARGET = test-gv

all: $(TARGET)

$(TARGET): ECGraphicViewImp.o  test-gv.o ECCommand.o ECGraphicCtrl.o
	$(CC) $(CFLAGS) -o $(TARGET) ECGraphicViewImp.o ECGraphicCtrl.o ECCommand.o test-gv.o -lallegro -lallegro_font -lallegro_primitives -lallegro_image -lallegro_main

ECGraphicViewImp.o: ECGraphicViewImp.cpp ECGraphicViewImp.h ECObserver.h

ECGraphicCtrl.o: ECGraphicCtrl.cpp ECGraphicCtrl.h ECCommand.h ECGraphicViewImp.h

ECCommand.o: ECCommand.cpp ECCommand.h

test-gv.o: test-gv.cpp ECGraphicViewImp.h

clean:
	rm -f *.o $(TARGET)
	