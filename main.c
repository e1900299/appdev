//This file will be used to test functions in screen.c

#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void){
	FILE *fp;
	fp = fopen("test.wav", "r");	
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	clearscreen();
	wavdata(h, fp);		// calculate dB
	fclose(fp);
	getchar();
}
