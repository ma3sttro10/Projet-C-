# Compiler and flags
CXX = g++
CXXFLAGS = 

# Source files
SRCS = main.cpp polynomial.cpp LegendreCoeffs.cpp harmoniques.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp to main.o
main.o: main.cpp polynomial.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile polynomial.cpp to polynomial.o
polynomial.o: polynomial.cpp polynomial.hpp
	$(CXX) $(CXXFLAGS) -c polynomial.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
