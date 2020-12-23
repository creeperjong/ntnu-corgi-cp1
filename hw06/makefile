all:int_editor.o step_ctrl.o rotation.o projection.o
	gcc hw0601.c int_editor.o -o hw0601
	gcc hw0602.c step_ctrl.o -o hw0602
	gcc hw0603.c rotation.o -o hw0603 -lm
	gcc hw0604.c projection.o -o hw0604
int_editor:
	gcc -c int_editor.c -o int_editor.o
step_ctrl:
	gcc -c step_ctrl.c -o step_ctrl.o
rotation:
	gcc -c rotation.c -o rotation.o
projection:
	gcc -c projection.c -o projection.o
clean:
	rm -rf *.o hw0601 hw0602 hw0603 hw0604