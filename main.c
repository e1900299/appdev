//This file will be used to test functions in screen.c

#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void){

	Position p = getscreensize();
	if(p.col<BARS){
		printf("Your screen size is not wide enough to display %d bars/n", BARS);
		return 1;
	}
	// use wget command to fetch a wav file from a URL
	// the following procedure can put into a forever loop (while(1))
	FILE *fp = fopen("test.wav", "r");	//open the wav file in read-only
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	getchar();
	clearscreen();
	wavdata(h,fp);
	fclose(fp);
	getchar();
	resetcolors();
}
