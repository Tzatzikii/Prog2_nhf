TARGET = main

SOURCE = src
DEPENDENCIES = dep
ENGINE = $(SOURCE)/k2_engine
CLASSES = $(ENGINE)/classes
CLASS_HEADERS = $(ENGINE)/classes/headers
CC = g++
FLAGS = -Werror
DEBUGFLAGS = -g

OBJS =  main.o engine_main.o mat4.o vec4.o vertex.o \
		lightsource.o camera.o \
		output.o
HEADERS = $(CLASS_HEADERS)/camera.hpp $(CLASS_HEADERS)/lightsource.hpp \
			$(CLASS_HEADERS)/mat4.hpp $(CLASS_HEADERS)/vec4.hpp $(CLASS_HEADERS)/vertex.hpp \
			$(DEPENDENCIES)/output.hpp $(DEPENDENCIES)/utils.hpp

$(TARGET): $(OBJS) $(HEADERS)
	$(CC) -o $(TARGET) $(FLAGS) $(OBJS)

main.o: $(SOURCE)/main.cpp
	$(CC) -c $(SOURCE)/main.cpp

engine_main.o: $(ENGINE)/engine_main.cpp $(ENGINE)/engine_main.hpp
	$(CC) -c $(ENGINE)/engine_main.cpp 	

mat4.o: $(CLASSES)/mat4.cpp $(CLASS_HEADERS)/mat4.hpp
	$(CC) -c $(CLASSES)/mat4.cpp

vec4.o: $(CLASSES)/vec4.cpp $(CLASS_HEADERS)/vec4.hpp
	$(CC) -c $(CLASSES)/vec4.cpp

vertex.o: $(CLASSES)/vertex.cpp $(CLASS_HEADERS)/vertex.hpp
	$(CC) -c $(CLASSES)/vertex.cpp

lightsource.o: $(CLASSES)/lightsource.cpp $(CLASS_HEADERS)/lightsource.hpp
	$(CC) -c $(CLASSES)/lightsource.cpp

camera.o: $(CLASSES)/camera.cpp $(CLASS_HEADERS)/camera.hpp
	$(CC) -c $(CLASSES)/camera.cpp

output.o: $(DEPENDENCIES)/output.cpp $(DEPENDENCIES)/output.hpp
	$(CC) -c $(DEPENDENCIES)/output.cpp

run: $(TARGET)
	./main

clean:
	rm $(OBJS) main