include ../../../config.mk

SRC		:=	Pacman.cpp	\
			Map.cpp		\
			Tile.cpp		\
			PacGum.cpp		\
			Wall.cpp

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

debug:
	$(CXX) $(CXXFLAGS) -g -o $(NAME) $^ $(LDFLAGS)
