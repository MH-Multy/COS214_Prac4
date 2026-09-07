
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g


TARGET = taskforge

SRCS = main.cpp ProductionGroup.cpp Shot.cpp ShotState.cpp ShotDecorator.cpp SafetyDecorator.cpp InsuranceDecorator.cpp HierarchyIterator.cpp ShotIterator.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)


valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)