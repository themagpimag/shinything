CC = g++
TARGETS = $(patsubst %.cpp,%.exe, $(wildcard *.cpp))

all: $(TARGETS)

%.exe: %.cpp
	@echo "** Compiling C++ and linking executable" 
	$(CC) $(INCFLAGS) $< -o $(notdir $@)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGETS)
