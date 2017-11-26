OBJ_DIR = obj/
SRC_DIR = src/
HPP_DIR = header/
CFLAGS = g++ -std=gnu++11 -g

TARGET_MAIN = main
TARGET_REMOVE = rm
TARGET_ALL = all

_DEPS = dirty.inl
DEPS = $(patsubst %,$(HPP_DIR)%,$(_DEPS))

_OBJ = dirty.o
OBJ = $(patsubst %,$(OBJ_DIR)%,$(_OBJ))

$(TARGET_ALL): $(TARGET_REMOVE) $(TARGET_MAIN)

$(TARGET_MAIN): $(OBJ)
	$(CFLAGS) -o $@ $^ -I$(HPP_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(DEPS)
	$(CFLAGS) -c -o $@ $< -I$(HPP_DIR)

$(TARGET_REMOVE):
	rm -r $(OBJ_DIR)
	mkdir $(OBJ_DIR)
