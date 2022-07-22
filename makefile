SRC = ./src
BUILD = ./build
BIN = ./bin
SRCS := $(wildcard $(SRC)/*.cpp)
OBJ := $(subst $(SRC), $(BUILD), $(SRCS:.cpp=.o))
NAME = $(BIN)/main
LIBFLAGS = -mwindows -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
INCFLAGS = -I./SFML/include
TARGET =  run


# 	rm ${SRC}/*.o ${BIN}/main.exe
run : $(NAME)
	$(NAME)
$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) -c -o $@ $(INCFLAGS) $<
$(NAME): $(OBJ)
	g++ -o $@ $^ $(LIBFLAGS) 
$(BUILD):
	mkdir $@
clean:
	rm $(OBJ)
testst:
	sdad $(OBJ)