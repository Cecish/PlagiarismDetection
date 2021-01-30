# PlagiarismDetection
Source code similarity detection program able to compare two source codes (written in C files which can compile) and evaluate the percentage of similarity between them using two different methods: the function call graph technique and the [Pomp-O-Metre](https://hal.archives-ouvertes.fr/hal-01066127/document) detection method.

Several code source plagiarism methods exist. This program considers five of them when evaluating the similarity of two source codes:
1. Variables and functions renaming,
2. Moving independant code snippets,
3. Adding and removing comments in the source code,
4. Changing the code indentation,
5. Alteration of the type of variables (e.g. replacing an integer by a double).

## Compilation
Via the *make* command in a terminal

## Program execution
*./detecSim -h*: prints help  
*./detecSim path1 path2*: executes the program on files path1 and path2, the files must exist and compile

## Documentation generation
Via the *make doc* in a terminal
 
## Warnings
1. Prerequisites: Having installed gcc et uncrustify
2. Do not delete the files config.cfg, Doxyconf, and Makefile, as well as the folders src, bin and doc

## Notes:
- The execution of the second detection method can take some time with files over 300 lines of code and/or made of numerous blocks
- Only .C files which compile can be used to calculate similarity percentage.
