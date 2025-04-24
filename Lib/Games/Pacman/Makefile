include ../../../config.mk

SRC		:= Pacman.cpp
OBJ		:= $(SRC:.cpp=.o)
NAME	:= $(PACMAN_SO)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

