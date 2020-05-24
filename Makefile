all: 
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -DYYDEBUG 

		./glf < exemplo.mec > teste.cpp

		g++ teste.cpp -lm -o t
		./t

pontoc:
		g++ teste.cpp -lm -o t
		./t

exemplo:
		./glf < exemplo.mec > teste.cpp

terminal:
		./glf < exemplo.mec

exemplocpp:

		./glf < exemplo.mec > teste.cpp
		g++ teste.cpp -lm -o t
		./t

install:
	sudo apt-get install libboost-all-dev