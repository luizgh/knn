CC=g++
CC_FLAGS=-std=c++11 -Wall -g -O3  -DDEBUG_KNN



# File names
EXEC = bin/main
EXECOBJ = $(EXEC:bin/%=obj/%.o)
SOURCES = $(wildcard src/*.cpp)
INCLUDES = $(wildcard src/*.h)
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)

TESTSOURCES = $(wildcard test/*.cpp)
TESTOBJECTS = $(filter-out $(EXECOBJ), $(OBJECTS))
TESTTARGETS = $(TESTSOURCES:test/%.cpp=bin/%)

all: $(EXEC)

test: $(TESTTARGETS)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

$(TESTTARGETS): bin/% : test/%.cpp $(TESTOBJECTS)
	$(CC) $(CC_FLAGS) -o $@ $< $(TESTOBJECTS) -Isrc/
#	./$@

# To obtain object files
$(OBJECTS): obj/%.o : src/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS) $(TESTTARGETS)
