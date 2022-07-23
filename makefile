SRC = ./src
BUILD = ./build
BIN = ./bin
SRCS := $(wildcard $(SRC)/*.cpp)
OBJ := $(subst $(SRC), $(BUILD), $(SRCS:.cpp=.o))
NAME = $(BIN)/main
LIBFLAGS = -mwindows -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
INCFLAGS = -I./SFML/include -static
TARGET =  run


# 	rm ${SRC}/*.o ${BIN}/main.exe
run : $(NAME)
	$(NAME)
$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) -c -o $@ $(INCFLAGS) $<
$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(LIBFLAGS) 
$(BUILD):
	mkdir $@
clean:
	rm $(OBJ)
testst:
	sdad $(OBJ)