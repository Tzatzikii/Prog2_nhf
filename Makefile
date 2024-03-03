

TARGET = main

SOURCE = src
ENGINE = $(SOURCE)/k2_engine
CLASSES = $(ENGINE)/classes
CLASS_HEADERS = $(ENGINE)/classes/headers
CC = g++
DEBUGFLAGS = -g

OBJS = main.o engine_main.o \
		mat4.o vec4.o

$(TARGET): $(OBJSs)
	$(CC) -o $(TARGET) $(OBJS)

main.o: $(SOURCE)/main.cpp
	$(CC) -c $(SOURCE)/main.cpp

engine_main.o: $(ENGINE)/engine_main.cpp \
			   $(ENGINE)/engine_main.hpp
	$(CC) -c $(ENGINE)/engine_main.cpp 	

mat4.o: $(CLASSES)/mat4.cpp \
		$(CLASS_HEADERS)/mat4.hpp
	$(CC) -c $(CLASSES)/mat4.cpp

vec4.o: $(CLASSES)/vec4.cpp \
		$(CLASS_HEADERS)/vec4.hpp
	$(CC) -c $(CLASSES)/vec4.cpp

clean:
	rm $(OBJS) main