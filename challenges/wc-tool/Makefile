SRCS = src/main.cpp src/ccwc.cpp
HEADERS = src/ccwc.h
TARGET = ccwc

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS) 
	g++ $(SRCS) -std=c++17 -Wall -Wextra -o $(TARGET)

clean:
	rm -f $(TARGET)