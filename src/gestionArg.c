/*!
\file gestionArg.c
\version 1.0
\date 10-06-2014
\brief Code source pour la gestion des arguments
\remarks Aucune
*/

/*Headers */
#include "gestionArg.h"

/* Affichage de l'aide */
void affHelp(void) {
	printf("\nDETECTSIM(7)\n\nNAME\n\tdetectSim - automatically detect similarity rates between two C code files\n\n");
	printf("SYNOPSIS\n\tdetectSim [OPTION][FILE1][FILE2]\n\nDESCRIPTION\n\tHelper to find similarities between two C code files\n\n");
	printf("USAGE\n\tUsage : detectSim [OPTION]\n\n\tHelp options\n\t -h\tShows this help message\n\n");
	printf("\tGeneral options\n\tfile1 file2\t\tDetect similarities in code between file1 and file2\n");
	printf("\n\nINDICATIONS\n\nAll the files you mention have to exist and be C source code for the program to work correctly.\nWARNING : You also have to install uncrustify (Use ""apt-get install uncrustify"") or it will cause program crashes\n");
}

/*Vérification de l'existence d'un dossier*/
int dirExists (char* str_dirName) {
	DIR* dirTest; 
	int int_res; 

	dirTest = opendir (str_dirName);
	int_res = dirTest != NULL;

	if (int_res) {
		closedir(dirTest);
	}
return int_res;	
}

/*Vérificatin de l'existence d'un fichier*/
int fileExists (char* str_fileName) {
	FILE* fileTest; 
	int int_res; 

	fileTest=fopen(str_fileName,"r");
	int_res = fileTest!=NULL;
	if (int_res) {
		fclose(fileTest);
		int_res = !dirExists(str_fileName);	
	}
	return int_res;
}


/*Vérification de l'existence des fichiers donnés */
void verifFiles(char** strTab_argv) {
	if ((fileExists(strTab_argv[1])) && (fileExists(strTab_argv[2]))) {
		printf("Both files found, beginning operations\n");	
		mainPreTraitement(strTab_argv[1],strTab_argv[2]);		
	} else {
		if (!fileExists(strTab_argv[1])) {
			printf("%s does not exist or is not a correct file\n", strTab_argv[1]);
		} 
		if (!fileExists(strTab_argv[2])) {
			printf("%s does not exist or is not a correct file\n", strTab_argv[2]);	
		}
		printf("Exiting program\n");
	}
}



/* Vérification des arguments entrés par l'utilisateur */
void verifArguments(int int_argc, char** strTab_argv) {
	if (int_argc == 1) {
		if (!(strcmp(strTab_argv[1],"-h"))) {
			affHelp();
		} else {
			printf("Wrong set of arguments, use ./detectSim -h to display help\n");		
		}
	} 
	else if(int_argc == 2) {
		verifFiles(strTab_argv);
	} 
	else {
		printf("Wrong set of arguments, use ./detectSim -h to display help\n");
	}
}