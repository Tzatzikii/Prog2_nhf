TARGET = main

SOURCE = src
DEPENDENCIES = dep
ENGINE = $(SOURCE)/k2_engine
CLASSES = $(ENGINE)/classes
CLASS_HEADERS = $(ENGINE)/classes/headers
CC = g++
FLAGS = -Werror
DEBUGFLAGS = -g

OBJS = main.o engine_main.o \
		mat4.o vec4.o output.o
MISC = dep/output.hpp

$(TARGET): $(OBJS) $(MISC)
	$(CC) -o $(TARGET) $(FLAGS) $(OBJS)

main.o: $(SOURCE)/main.cpp
	$(CC) -c $(SOURCE)/main.cpp

engine_main.o: $(ENGINE)/engine_main.cpp $(ENGINE)/engine_main.hpp
	$(CC) -c $(ENGINE)/engine_main.cpp 	

mat4.o: $(CLASSES)/mat4.cpp $(CLASS_HEADERS)/mat4.hpp
	$(CC) -c $(CLASSES)/mat4.cpp

vec4.o: $(CLASSES)/vec4.cpp $(CLASS_HEADERS)/vec4.hpp
	$(CC) -c $(CLASSES)/vec4.cpp

output.o: $(DEPENDENCIES)/output.cpp $(DEPENDENCIES)/output.hpp
	$(CC) -c $(DEPENDENCIES)/output.cpp

run: $(TARGET)
	./main

clean:
	rm $(OBJS) main