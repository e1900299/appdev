//This file will be used to test functions in screen.c

#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void){
	Position cur = getscreensize(); //get screen size
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d&id=e1900307", cur.row, cur.col);
	senddata(poststr, URL);
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("\nToday we will make some animation.  Press any key to continue\n");
	getchar();	//wait for user to press a key
	getchar();
	int ff, bb;
	float step = (float)cur.col/cur.row;
	for(int i=1; i<cur.row; i++){
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;
		setcolors(ff, bg(bb));
		clearscreen();
		drawrect(10, 10, 5, 30);
		gotoXY(cur.row-i, (i-1)*step+1);
		printf("HELLO\n");
		usleep(250000); //sleep(1);
	}
/*	for(int i=1; i<21; i++){
		getchar();
		clearscreen();
		gotoXY(21-i, i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(i, i, 2, 4);
		sleep(1);
	}
	getchar();
	 for(int i=1; i<21; i++){
		 getchar();
		clearscreen();
		gotoXY(i, 19+i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(21-i, 19+i, 2, 4);
		sleep(1);
	}*/
	getchar();
	resetcolors();
	clearscreen();
 	printf("Color is set back to default\n");
	FILE *fp;
	fp = fopen("test.wav", "r");	//open the wav file in read-only
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	wavdata(h, fp);		
	fclose(fp);
 /*	setfgcolor(GREEN);

	
	gotoXY(14, 35);
	printf("HEllO, WORLD!\n");
	getchar();	//wait for user to press a key
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();	//after drawing bars, wait for key
	resetcolors();
	printf("This text is displayed in default color \n"); */
}
