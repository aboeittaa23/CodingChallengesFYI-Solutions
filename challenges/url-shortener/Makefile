SRCS = src/main.cpp src/url_shortener.cpp
HEADERS = src/url_shortener.h
TARGET = shortlink

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ $(SRCS) -std=c++17 -Wall -Wextra -o $(TARGET)

clean:
	rm -f $(TARGET)