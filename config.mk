ABS_PATH		:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

CXX			:=	g++
CXXFLAGS	:=	-g3 -W -Wall -Wextra -std=c++23 -I$(ABS_PATH)

BIN_FOLDER		:=	$(ABS_PATH)/Bin

NAME			:=	Arcatek

CORE_BIN		:= $(ABS_PATH)/$(NAME)
PACMAN_SO		:=	$(BIN_FOLDER)/pacman.so
SDL2_SO			:=	$(BIN_FOLDER)/sdl2.so
