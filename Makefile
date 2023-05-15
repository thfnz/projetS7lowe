SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c = obj/%.o)

CFLAGS = -c -Wall

main.exe : $(OBJS)
	gcc -o bin/$@ $^ -std=c99 -lm

obj/%.o : src/%.c
	gcc $(CFLAGS) $<

clean:
	rm -rf bin obj resultats
	mkdir bin obj resultats