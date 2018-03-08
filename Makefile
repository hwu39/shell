SRCS = simple_shell.c
OBJS = $(SRCS:.c=.o)
BIN = simple_shell
CFLAGS = -g
LDFLAGS = -g

all: $(BIN)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f $(OBJS)
	-rm -f $(BIN)
