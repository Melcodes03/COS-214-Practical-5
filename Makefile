CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = CampusGuard

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)