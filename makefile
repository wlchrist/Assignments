# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -w -g

# Target executable
TARGET = pa1

# Source files and object files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Build
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
