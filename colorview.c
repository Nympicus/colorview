#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	char* str = argv[1];
	char valid[] = {"0123456789ABCDEFabcdefx"};
	int v = 1;
	
	if(argc > 2){printf("Please Give Less Arguments.\n"); return 1;}
	if(argc < 2){printf("Please Give More Arguments.\n"); return 1;}

	int start = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) start = 2;

	if(strlen(argv[1]) == 8 || strlen(argv[1]) == 6){
		for(int i=start; str[i]; i++ )
			if(strchr(valid, str[i]) == NULL){
				printf("Error: '%c' not a hex character.\n", str[i]);
				v = 0;
			} 
	}
	else{printf("Invalid Argument.\n"); return 0;}

	if(v){
		//printf("karaktrerlerin hepsi geçerli\n");
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
		//printf("r:%d g:%d b:%d", (int)rint,(int)gint,(int)bint);

		printf("\x1b[48;2;%u;%u;%um    \n    \x1b[0m\n", (int)rint, (int)gint, (int)bint);
		
	}

	return 0;
}
