include ../config.mk

TARGET	:= $(CORE_BIN)

CORE_FOLDER	:= $(ABS_PATH)/Core

SRC	:= $(CORE_FOLDER)/Core.cpp 							\
	$(CORE_FOLDER)/main.cpp 							\
	$(CORE_FOLDER)/Event/ASubject.cpp					\
	$(CORE_FOLDER)/Event/AObserver.cpp					\
	$(CORE_FOLDER)/Event/DisplayEventManager.cpp		\
	$(CORE_FOLDER)/Event/GameEventManager.cpp			\
	$(CORE_FOLDER)/Event/Observer/KeyboardObserver.cpp	\
	$(CORE_FOLDER)/Event/Subject/KeyboardSubject.cpp	\
	$(CORE_FOLDER)/Event/Subject/DrawSquareSubject.cpp	\
	$(CORE_FOLDER)/Event/Subject/CloseAppSubject.cpp	\
	$(CORE_FOLDER)/DLL/LDDLL.cpp						\
	$(CORE_FOLDER)/Buffer/DisplayBuffer.cpp				\
	$(CORE_FOLDER)/Buffer/Square.cpp					\
	$(CORE_FOLDER)/Buffer/Vec2.cpp						\

OBJ	:= $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking..."
	@$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Done."

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@echo "Done."

fclean: clean
	@rm -f $(TARGET)

re: fclean all

tests:
	@echo "Work in progres.."

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Done."
