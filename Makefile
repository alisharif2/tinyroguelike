CXX = gcc
CXXFLAGS = -Wall -c -O2
LDFLAGS = 
SOURCES = program.c weapon.c entity.c
OBJECTS = $(SOURCES:.c=.o)
BINARY = program

default: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(BINARY)

%.o: %.c
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm $(OBJECTS) $(BINARY)

run: $(BINARY)
	./$(BINARY)
