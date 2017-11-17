all: fork.c
	gcc -o forkin fork.c
run: all
	./forkin
clean:
	rm *~