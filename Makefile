SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c = obj/%.o)

CFLAGS = -c -Wall

main.exe : $(OBJS)
	gcc -o bin/$@ $^

obj/%.o : src/%.c
	gcc $(CFLAGS) $<

clean:
	rm -rf bin obj resultats
	mkdir bin obj resultats