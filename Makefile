all: src/main.c src/floyd.c
	gcc src/main.c src/floyd.c -o floyd

clean:
	rm -f src/a.out floyd
