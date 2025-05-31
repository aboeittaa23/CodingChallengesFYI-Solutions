SRCS = src/main.cpp src/url_shortener.cpp
HEADERS = src/url_shortener.h
TARGET = shortlink
CROW_HEADER = src/crow_all.h

all: $(CROW_HEADER) $(TARGET)

$(CROW_HEADER):
	@echo "Downloading Crow v1.2.1..."
	@wget https://github.com/CrowCpp/Crow/releases/download/v1.2.1.2/crow_all.h -O $(CROW_HEADER)
	# Download single header file

	


$(TARGET): $(SRCS) $(HEADERS) $(CROW_HEADER)
	g++ $(SRCS) -std=c++17 -Wall -Wextra -pthread -o $(TARGET)

clean:
	rm -f $(TARGET)

clean-all: clean
	rm -f $(CROW_HEADER)