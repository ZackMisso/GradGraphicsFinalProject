CC=clang++
#CC=g++
CFLAGS+= -std=c++11 #-g -O0 -Wall -pedantic -I./ -I./include

GLUT2 =  -framework OpenGL -framework GLUT -framework IOKit -framework CoreVideo -lglfw3
LIBS = $(STRINGFIX) $(GLUT2) #$(GLUI2)

PROD= fracture

#HDRS= $(shell ls *.h)
SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls views/*.cpp)
SRCS+= $(shell ls test/*.cpp)
SRCS+= $(shell ls math/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@ #$(LIBGL) #$(LIBGLUT) $(LIBGL) $(LIBS)

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm -f views/*.o
	rm -f test/*.o
	rm -f math/*.o
