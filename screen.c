
// in this file we are going to define a number of function for screen 
// manipulation. These functions include erase screen, set color attributes, 
// set cursor location, etc, ... using VT100 escape sequences
// move between files: alt_. , alt_,
// follow this reference: //www.termsys.demon.co.uk/vtansi.htm
// to paste to putty: shift_insert key
#include <stdio.h>
#include "screen.h"

// function definition
void setfgcolor(int fg){
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor (int bg){
	printf("%c[1;%dm", ESC, bg);
}

void setcolors(int f, int b){
	setfgcolor(f);
	setbgcolor(bg(b));
}

void clearscreen(void){
	printf("%c[2J", ESC);
}

void resetcolors(void){
	printf("%c[0m", ESC);
}

void gotoXY(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
}

void drawbar(int col, int height){
	int i;
	for(i=1; i<=height; i++){
		gotoXY(35-i, col);
#ifdef UNICODE		// following codes are in conditional compilation
		printf("%s", BAR);
#else
		printf("%c", '#');
#endif
	}
}
void drawrect(int row, int col, int height, int width){
	int i, j; 		// loop control variable
	for(i=row; i<row+height; i++){
		for(j=col; j<col+width; j++){
			gotoXY(i,j);
#ifdef UNICODE
		printf("%s", BAR);
#else 
		printf("%c", '#');
#endif
		}
		printf("\n");
	}
}

Position getscreensize(void){
	Position p;
	char ret[100] = "\0";	// make an empty string for query return
	int r, c;
	gotoXY(999, 999);		// move cursor to the right-bottom corner
	printf("%c[6n", ESC);	// send query sequence to the terminal
	scanf("%s", ret);
#ifdef DEBUG
	printf("%s\n", ret);
#endif
#include <string.h>
	// the following code will decode the return string from terminal
	if (strlen(ret)>0){
		char dum;			// dummy char to consume the chars in ret string
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else {
		p.row = 0;
		p.col = 0;
	}
	return p;
}


