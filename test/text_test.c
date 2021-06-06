#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/text.h>

#include <ctest.h>

CTEST(read_text, test1){
	char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];
	
	strcpy(filename, "stdin.txt");
	strcpy(identifier, "S#1 | ");
	
	read_text(text, identifier, filename);
	
	char exp[MAX_LENGTH_OF_TEXT];
	strcpy(exp, "Hello world!");
	
	ASSERT_STR(exp, text);
}

CTEST(read_text, test2){
	char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];
	
	strcpy(filename, "stdin.txt");
	strcpy(identifier, "W#7 | ");
	
	read_text(text, identifier, filename);
	
	char exp[MAX_LENGTH_OF_TEXT];
	strcpy(exp, "mile river car feet care second enough plain girl usual young ready above ever red list though feel talk bird soon body dog family direct pose leave song measure door product black short numeral class wind question happen complete ship area half rock order fire south problem piece told knew pass");
	
	ASSERT_STR(exp, text);
}

CTEST(read_text, test3){
	char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];
	
	strcpy(filename, "stdin.txt");
	strcpy(identifier, "N#4 | ");
	
	read_text(text, identifier, filename);
	
	char exp[MAX_LENGTH_OF_TEXT];
	strcpy(exp, "938.577 546.141 -101.857 415.925 88.079 -165.696 518.560 638.259 363.320 -818.866 427.647 -773.357 586.360 725.798 222.424 -281.021 856.052 -166.864 664.500 392.728 725.444 737.927 371.883 -494.384 238.898");
	
	ASSERT_STR(exp, text);
}

CTEST(read_text, test4){
	char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];
	
	strcpy(filename, "stdin.txt");
	strcpy(identifier, "M#1 | ");
	
	read_text(text, identifier, filename);
	
	char exp[MAX_LENGTH_OF_TEXT];
	strcpy(exp, "1+2=3 5*6=30 6-6=0 (89*89)/89=89 log10(10)=1 x*3x+4=39/x 53*4=212 y=sin(x) y=x^2-x+4 (x+2)^2=x^2+2x+4 36y+23x=31 z=3x+4y-32 1/2+1/4=0.75 2^8=256 256/128=2 39*39=1521 26x+95=0 (x+2)^2+(y+2)^2=4 z=3xy z=0 x=43*39-3910 y=x^2+25");
	
	ASSERT_STR(exp, text);
}