
CC = g++

SRCS = dfs_rec.cpp graph.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = dfs_rec

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

