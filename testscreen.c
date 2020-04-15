// we test functions of screen.c
#include  <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"

int main(void){
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
	senddata(poststr, URL);
	gotoXY(1,1);
	printf("Screen size, ROW=%d, COL=%d\n", cur.row, cur.col);
	printf("Press any key the screen will be cleared\n");
	getchar(); 	//wait for the user to press a key
	getchar();
	for(int i = 0; i < 20; i++){
		int j = 20 - i;
		clearscreen();
		
		setfgcolor(GREEN);
		gotoXY(i+1, 2*i+1);
		printf("%s", REC);
		gotoXY(i+1, 2*i+2);
		printf("%s", REC);
		gotoXY(i+1, 2*i+3);
		printf("%s", REC);
		gotoXY(i+1, 2*i+4);
		printf("%s", REC);
		
		setfgcolor(RED);
		gotoXY(j, 2*i+1);
		printf("HELLO\n");
		
		sleep(1);
	}
	int ff, bb;

	for(int i=1; i<21; i++){
		clearscreen();
		gotoXY(21-i, i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(i, i, 2, 4);
		usleep(500000);
	}
 	getchar();
	for(int i=1; i<21; i++){
		clearscreen();
        gotoXY(i, 19+i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(21-i, 19+i, 2, 4);
        usleep(500000);
    }
	getchar();
	resetcolors();
	clearscreen();
}
	


