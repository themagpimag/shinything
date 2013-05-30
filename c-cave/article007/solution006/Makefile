# W. H. Bell
# A Makefile to build Pythia.exe

CC=gcc
F77=gfortran
TARGET=Pythia
OBJECTS=main.o pythia-6.4.27.o 

LIBS = -lgfortran

$(TARGET): $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm $(TARGET)

%.o: %.c
	@echo "**"
	@echo "** Compiling C Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 

%.o: %.f
	@echo "**"
	@echo "** Compiling Fortran Source"
	@echo "**"
	$(F77) -c -m64 $<
