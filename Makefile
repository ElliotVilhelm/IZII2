#
# Makefile for CSE 30 -- PA4
# You should not need to change anything in this file.
#
# XXX DO NOT EDIT
#

HEADERS		= constants.h
C_SRCS		= arrayToBitBoards.c

C_OBJS		= $(C_SRCS:.c=.o)
OBJS		= $(C_OBJS)

EXE		= IZII2
TEST_BINS	= testarrayToBitBoards

GCC		= gcc
RM		= rm

GCC_FLAGS	= -c -g -std=c99 -pedantic -Wall -D__EXTENSIONS__
LD_FLAGS	= -g -Wall

.c.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#
$(EXE): $(OBJS)
	@echo "Linking all object modules ..."
	$(GCC) $(LD_FLAGS) -o $(EXE) $(OBJS)
	@echo ""
	@echo "Compilation Successful!"

$(C_OBJS): $(HEADERS)


clean:
	@echo "Cleaning up project directory ..."
	$(RM) -f *.o $(EXE) core a.out $(TEST_BINS)
	@echo ""
	@echo "Clean."

new:
	make clean
	make

#
# Unit test targets
#
testarrayToBitBoards: constants.h testarrayToBitBoards.o arrayToBitBoards.o
	@echo "Compiling testarrayToBitBoards.c"
	$(GCC) $(LD_FLAGS) -o testarrayToBitBoards testarrayToBitBoards.o arrayToBitBoards.o
	@echo "Compilation Successful!"

