SRCS = src/main.cpp src/tokenizer.cpp
HEADERS = src/tokenizer.h
TARGET = json_parser

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ $(SRCS) -std=c++20 -Wall -Wextra -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)