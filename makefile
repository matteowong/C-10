all: signal.c
	gcc signal.c
run: all
	./a.out
clean:
	rm a.out
	rm foo
	rm *~