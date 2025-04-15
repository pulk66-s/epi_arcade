## Arcatek Makefile

# DEFINES
CFLAGS = -Wall -Wextra -std=c++20

TARGET = Arcatek

CORE_FOLDER = ./Core

SRC = $(CORE_FOLDER)/Core.cpp
OBJ = $(SRC:.cpp=.o)

# RULES
all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking..."
	@$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Done."

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@rm -f $(TARGET)
	@echo "Done."

re:
	@echo "Rebuilding..."
	@make clean
	@make all
	@echo "Done."

tests:
	@echo "Work in progres.."
