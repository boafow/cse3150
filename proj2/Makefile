# g++ ECGraphicViewImp.cpp test-gv.cpp -lallegro -lallegro_font -lallegro_primitives -lallegro_image -lallegro_main

CC = g++
CFLAGS = -Wall -g

TARGET = test-gv

all: $(TARGET)

$(TARGET): ECGraphicViewImp.o test-gv.o
	$(CC) $(CFLAGS) -o $(TARGET) ECGraphicViewImp.o test-gv.o -lallegro -lallegro_font -lallegro_primitives -lallegro_image -lallegro_main

ECGraphicViewImp.o: ECGraphicViewImp.cpp ECGraphicViewImp.h

test-gv.o: test-gv.cpp ECGraphicViewImp.h

clean:
	rm -f *.o $(TARGET)