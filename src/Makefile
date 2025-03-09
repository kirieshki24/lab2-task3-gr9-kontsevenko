CC = gcc
CFLAGS = -Wall -Werror -std=c11
SOURCES = main.c marshrut.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	