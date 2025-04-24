include ../../../config.mk

SRC		:= SDL2.cpp
OBJ		:= $(SRC:.cpp=.o)
NAME	:= $(SDL2_SO)

# Ajout des flags SDL2
CXXFLAGS += $(shell sdl2-config --cflags)
LDLIBS   += $(shell sdl2-config --libs)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CXX) -shared -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
	@echo "Done compiling $<"
