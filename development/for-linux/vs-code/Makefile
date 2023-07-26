CXX 		:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb

BIN		:= bin
SRC 	:= src
INCLUDE := include

LIBRARIES := 
EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)	#bin/main

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)	

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp main.cpp	#bin/main <-- depends on -- src/<file_name.cpp>
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES) #g++ -std=c++17 -ggdb -I include -o 

clean:
	-rm $(BIN)/*