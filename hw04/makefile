all:roman_calculator.o hanoi_steps_analyzer.o e_calculator.o game_system.o equivalent_r.o
	gcc hw0401.c roman_calculator.o -o hw0401
	gcc hw0402-1.c hanoi_steps_analyzer.o -o hw0402-1
	gcc hw0402-2.c hanoi_steps_analyzer.o -o hw0402-2
	gcc hw0403.c e_calculator.o -o hw0403
	gcc hw0404.c equivalent_r.o -o hw0404
	gcc hw0405.c game_system.o -o hw0405
roman_calculator:
	gcc -c roman_calculator.c -o roman_calculator.o
hanoi_steps_analyzer:
	gcc -c hanoi_steps_analyzer.c -o hanoi_steps_analyzer.o
e_calculator:
	gcc -c e_calculator.c -o e_calculator.o
game_system:
	gcc -c game_system.c -o game_system.o
equivalent_r:
	gcc -c equivalent_r.c -o equivalent_r.o
clean:
	rm -rf *.o hw0401 hw0402-1 hw0402-2 hw0403 hw0404 hw0405
