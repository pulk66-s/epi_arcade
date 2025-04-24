include config.mk

all:
	make -C Core/ all
	make -C Lib/Games/ all
	make -C Lib/Graphics/ all

clean:
	make -C Core/ clean
	make -C Lib/Games/ clean
	make -C Lib/Graphics/ clean

fclean: clean
	make -C Core/ fclean
	make -C Lib/Games/ fclean
	make -C Lib/Graphics/ fclean

re: fclean all

run:
	./$(NAME) -g $(PACMAN_SO) -d $(SDL2_SO)
