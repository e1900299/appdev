#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"
// function definitions
WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displayWAVhdr (WAVheader h){
	printf("Chunk ID: ");
	for(int i=0; i<4; i++)
	printf("%C", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Number of Channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	printf("Block align: %d\n", h.blockAlign);
	// -- to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n", duration);
}

void wavdata(WAVheader h, FILE *fp){
	// in this function, we will read sound samples from the opened file
	// the samples are calculated in to decibel value using Root Mean Square
	// (RMS) formula. We will display a 5-sec recorded sound into bar chart.
	// our sound file uses sample rate of 16000, for 5 sec, there are
	// 5*16000 = 800000 samples, we want to display them into 160 bars.
	int peaks = 0, flag = 0;
	short samples[SIZE];		// to read 500 samples from wav file
	for (int i=0; i<BARS; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;	// accumulate the sum
		for(int j=0; j<SIZE; j++){
			sum = sum + samples[j]*samples[j];
		}
		double dB = 20*log10(sqrt(sum/SIZE));
#ifdef SDEBUG
		printf("db[%d] = %f\n", i, dB);
#else
		// displaybar for re value);
		if(dB>70){
			 setfgcolor(RED);
			if (flag==0){
				peaks++;
				flag=1;
			}
		}
		else{
			setfgcolor(WHITE);
			if (flag==1);
				flag=0;
		}
		drawbar(i+1,(int) dB/3);
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate: %d\n", SAMPLERATE);
		gotoXY(1,65);
		setfgcolor(MAGENTA);
		printf("Duration: %.2f s\n",(double) h.subchunk2Size/h.byteRate);
		gotoXY(1,135);
		setfgcolor(YELLOW);
		printf("Peaks: %d\n", peaks);
#endif
		}
}
