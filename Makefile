build:
	clang ./src/*.c -o game -I include -L lib -l SDL2-2.0.0

run:
	./game

clean:
	rm game
