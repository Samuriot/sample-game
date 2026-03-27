CXX = clang++
CXXFLAGS = $(shell sdl2-config --cflags) -Wall -std=c++17
LDFLAGS = $(shell sdl2-config --libs) -framework Cocoa

TARGET = my_program
SRCS = main.cpp object.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean

