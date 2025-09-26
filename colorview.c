#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initHEX(char* str, char* argument){
	int start = 0;
	int v=1;
	char* valid = {"0123456789ABCDEFabcdefx"};
	
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) start = 2;
	
		if(strlen(argument) == 8 || strlen(argument) == 6){
			for(int i=start; str[i]; i++ )
				if(strchr(valid, str[i]) == NULL){
					printf("Error: '%c' not a hex character.\n", str[i]);
					v = 0;
				} 
		}
		else{printf("Invalid Argument.\n"); exit(1);}
	
		if(v){
	
			char r[3], g[3], b[3];
	
			start = (str[0]=='0' && (str[1]=='x'||str[1]=='X')) ? 2 : 0;
			
			strncpy(r, str+start, 2);
			r[2] = '\0';
			
			strncpy(g, str+start+2, 2);
			g[2] = '\0';
			
			strncpy(b, str+start+4, 2);
			b[2] = '\0';
	
			long rint = strtol(r, NULL, 16);
			long gint = strtol(g, NULL, 16);
			long bint = strtol(b, NULL, 16);
	
	
			printf("\x1b[48;2;%u;%u;%um    \n    \x1b[0m\n", (int)rint, (int)gint, (int)bint);
			
		}
}




void initRGBorBGR(char* r, char* g, char* b) {

	char valid[] = {"0123456789"};
	int v=1;
	if(strlen(r) > 3 ){
			for(int i=0; r[i]; i++ )
				if(strchr(valid, r[i]) == NULL){
					printf("Error: '%c' not a decimal character.\n", r[i]);
					v = 0;
				} 
	}

	if(strlen(g) > 3 ){
				for(int i=0; g[i]; i++ )
					if(strchr(valid, g[i]) == NULL){
						printf("Error: '%c' not a decimal character.\n", g[i]);
						v = 0;
					} 
	}

	if(strlen(b) > 3 ){
				for(int i=0; b[i]; i++ )
					if(strchr(valid, b[i]) == NULL){
						printf("Error: '%c' not a decimal character.\n", b[i]);
						v = 0;
					} 
		}

	if(v){
		long rint = strtol(r, NULL, 10);
		long gint = strtol(g, NULL, 10);
		long bint = strtol(b, NULL, 10);

		if(rint > 255 || gint > 255 || bint > 255){
			printf("Not a RGB value\n");
			exit(1);
		}

		printf("\x1b[48;2;%u;%u;%um    \n    \x1b[0m\n", (int)rint, (int)gint, (int)bint);
		exit(0);
	}else exit(1);
	
}

int main(int argc, char** argv){

	char* str = argv[1];
	
	

	if(strcmp(argv[1], "-rgb") == 0){
		if(argc == 5){
			initRGBorBGR(argv[2], argv[3], argv[4]);
		}else{printf("more or less arguments.\n"); exit(1);}
	}

	if(strcmp(argv[1], "-bgr") == 0){
			if(argc == 5){
				initRGBorBGR(argv[4], argv[3], argv[2]);
			}else{printf("more or less arguments.\n"); exit(1);}
	}
	
	
	if(argc > 2){printf("Please Give Less Arguments.\n"); return 1;}
	if(argc < 2){printf("Please Give More Arguments.\n"); return 1;}

	initHEX(str, argv[1]);

	

	return 0;
}

