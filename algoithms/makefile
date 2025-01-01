
CC = g++

SRCS = test.cpp 

OBJS = $(SRCS:.cpp=.o)

TARGET = test

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

# End of makefile

