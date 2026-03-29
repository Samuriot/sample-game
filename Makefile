CXX = clang++
CXXFLAGS = $(shell sdl2-config --cflags) -I include -Wall -std=c++17
LDFLAGS = $(shell sdl2-config --libs) -framework Cocoa

TARGET = build/my_program
SRCS = src/main.cpp src/object.cpp src/player.cpp src/engine.cpp
OBJS = $(SRCS:src/%.cpp=build/%.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: clean
