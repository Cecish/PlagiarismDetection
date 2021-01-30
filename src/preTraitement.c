/*!
\file preTraitement.c
\version 1.0
\date 10-06-2014
\brief Code source pour les pré-traitements
\remarks Aucune
*/

/*Headers */
#include "preTraitement.h"

/* À appliquer seulement sur un fichier existant */
void extractNomFichier(char* str_file, int int_nbFichier, char** strPtr_resBis) {
	char* str_ch; 
	char* str_res; 
	char* str_tmpRes;
	char* str_tmpFile;

	str_tmpFile = strdup(str_file);
	str_ch = strtok (str_tmpFile, "/"); 
	while (str_ch != NULL) {
		str_res = str_ch;
   	 	str_ch = strtok (NULL, "/");
	}
	
	str_tmpRes = strdup(str_res);
	switch (int_nbFichier) {
		case 1 : *strPtr_resBis = malloc((strlen(str_res) + strlen("1")+1)*sizeof(char));
			sprintf(*strPtr_resBis,"1%s",str_tmpRes);
			break;
		case 2 : *strPtr_resBis = malloc((strlen(str_res) + strlen("2")+1)*sizeof(char));
			sprintf(*strPtr_resBis,"2%s",str_tmpRes); 
			break;
	}
	free(str_tmpRes);
	free(str_tmpFile);
}

/* Construction du chemin résultat pour les fichiers temporaires à manipuler */
void construireCheminFichierTmp(char* str_fileName, char** strPtr_fileTmpPath) {

	*strPtr_fileTmpPath = malloc((strlen(str_fileName) + sizeof("Tmp") + sizeof(".tmpDetectSim/") + 1)*sizeof(char));
	sprintf(*strPtr_fileTmpPath,".tmpDetectSim/Tmp%s",str_fileName);
}

/* Vérifie si la compilation est correcte, nettoie le code et renvoie le résultat du gcc -E et uncrustify dans un fichier pour traitements */
int correctCompilation(char* str_file, char* str_fileName) {
	int int_resCmd;
	char* str_compile;


	str_compile = malloc((strlen("gcc -E -P -w -nostdinc") + strlen(" 2>/dev/null >/dev/null") + strlen(str_file) + strlen("Tmp") + strlen(str_fileName)+1)*sizeof(char));

	sprintf(str_compile,"gcc -E -P -w -nostdinc %s 2>/dev/null >/dev/null",str_file);
	system("mkdir .tmpDetectSim 2>/dev/null");

	appliqueCorrect(str_file,str_fileName);
	int_resCmd = system(str_compile);
	free(str_compile);

	return int_resCmd;
}

/* Application de indent */
void appliqueCorrect(char* str_file, char* str_fileName) {
	char* str_cmdComplete;

	str_cmdComplete = malloc((strlen("gcc -E -P -w -nostdinc") + strlen(" 2> /dev/null | uncrustify -c config.cfg -L C | egrep -v -e '^[[:blank:]]*[[:alnum:]]+\\**[[:blank:]]+[[:alnum:]]+[[:blank:]]*\\(.*\\);' 2>/dev/null >.tmpDetectSim/Tmp") + strlen(str_file) + strlen("Tmp") + strlen(str_fileName)+1)*sizeof(char));

	sprintf(str_cmdComplete,"gcc -E -P -w -nostdinc %s 2> /dev/null | uncrustify -c config.cfg -L C | egrep -v -e '^[[:blank:]]*[[:alnum:]]+\\**[[:blank:]]+[[:alnum:]]+[[:blank:]]*\\(.*\\);' 2>/dev/null >.tmpDetectSim/Tmp%s",str_file,str_fileName);

	system(str_cmdComplete);
	printf("%s\n", str_cmdComplete);
	free(str_cmdComplete);
}

/*Effectue la mise en mémoire avec mmap*/
void miseEnMemoireMmap(char* str_fileName, int* statusRes, int* sizeRes, char** f) {
    int fd;
    int size;
    int status;
    struct stat s;

    fd = open(str_fileName,O_RDONLY);
    status = fstat(fd, &s);
    *statusRes = status;

    if (status == 0) {
      size = s.st_size;
      *sizeRes =  size;
      *f = (char *) mmap (NULL, size, PROT_READ, MAP_SHARED, fd, 0);
      close(fd);
    }
}

/* Mise en mémoire des deux fichiers */
void miseEnMemoireFichiers(char* str_fileName1, char* str_fileName2) {
    int status1;
    int status2;
    int size1;
    int size2;
    char* f1;
    char* f2;

    printf("\nStoring files in memory : \n");
    miseEnMemoireMmap(str_fileName1,&status1,&size1,&f1);
    miseEnMemoireMmap(str_fileName2,&status2,&size2,&f2);

    if ((status1 == 0) && (status2 == 0)) {
        printf("%s correctly stored in memory\n",str_fileName1);
        printf("%s correctly stored in memory\n",str_fileName2);
        mainTraitementFichiersMem(f1,f2);/* Appel des traitements suivants */
    } else {
        fprintf(stderr,"A problem occured trying to store the files in memory, exiting program\n");
    }
}


/* Application de indent aux deux fichiers et appels opérations suivantes */
void appliqueIndentEtOpSuiv(char* str_fileName1, char* str_fileName2) {
	char* str_fileTmpPath1;
	char* str_fileTmpPath2;

	construireCheminFichierTmp(str_fileName1,&str_fileTmpPath1);
	construireCheminFichierTmp(str_fileName2,&str_fileTmpPath2);

	miseEnMemoireFichiers(str_fileTmpPath1,str_fileTmpPath2);
	free(str_fileTmpPath1);
	free(str_fileTmpPath2);
}


/* Main pour l'appel des diverses fonctions de pré-traitement */
void mainPreTraitement(char* str_file1, char* str_file2) {
	char* str_fileName1;
	char* str_fileName2;

	extractNomFichier(str_file1,1,&str_fileName1);
	extractNomFichier(str_file2,2,&str_fileName2);

	printf("\nVeryfing code integrity and cleaning :\n");

	if (correctCompilation(str_file1,str_fileName1) && correctCompilation(str_file2,str_fileName2)) {
		printf("Both files do not show any coding errors, pursuing operations\n");
		appliqueIndentEtOpSuiv(str_fileName1,str_fileName2);
		free(str_fileName1);
		free(str_fileName2);
	} else {
		fprintf(stderr,"Provided files do not compile correctly, please correct your code errors and try again\n");
		free(str_fileName1);
		free(str_fileName2);
	}
}




