CC = gcc
TARGETS = $(patsubst %.c,%.exe, $(wildcard *.c))

all: $(TARGETS)

%.exe: %.c
	@echo "** Compiling C and linking executable" 
	$(CC) $(INCFLAGS) $< -o $(notdir $@)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGETS)
