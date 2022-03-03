# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/ST_F765II/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/ST_F765II

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
