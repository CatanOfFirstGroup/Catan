CC = gcc
LDLIBS = -lncurses

SRCDIR = .
FUNCTION_DIR = function
GAME_DIR = game
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
FUNCTION_SRC = $(wildcard $(FUNCTION_DIR)/*.c)
GAME_SRC = $(wildcard $(GAME_DIR)/*.c)

OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
FUNCTION_OBJ = $(patsubst $(FUNCTION_DIR)/%.c,$(OBJDIR)/%.o,$(FUNCTION_SRC))
GAME_OBJ = $(patsubst $(GAME_DIR)/%.c,$(OBJDIR)/%.o,$(GAME_SRC))

EXECUTABLE = main

all: $(EXECUTABLE)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(EXECUTABLE): $(OBJ) $(FUNCTION_OBJ) $(GAME_OBJ)
	$(CC) $^ -o $@ $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@

$(OBJDIR)/%.o: $(FUNCTION_DIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@

$(OBJDIR)/%.o: $(GAME_DIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@


clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE) *.o a.out
