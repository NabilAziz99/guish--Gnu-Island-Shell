README: Operating Systems - Project #1: guish (Gnu Island Shell)
Project Overview
This project implements a simple UNIX shell program called guish (Gnu Island Shell) as a part of the COSC 3346 Operating Systems course. The main objective of the project is to provide hands-on experience in system programming and system call interfaces while working with the UNIX environment. guish can execute simple Unix commands and supports internal shell commands such as exit, hist, and r n.
Features
	•	Execute simple Unix commands or executable program file names with optional arguments: progname [args].
	•	Exit the shell with the internal command exit.
	•	Display the 10 most recent commands entered by the user with the internal command hist.
	•	Execute the nth command from the history list using the internal command r n. Execute the most recent command with just r.
	•	Customizable shell prompt.
	•	Proper error handling and checking of return values.
Contents
	•	README.md: This file, which describes the project and its contents.
	•	Makefile: Contains rules for compiling the code, cleaning up the directory, and performing other required tasks.
	•	guish.c: The main source code for the guish shell.
	•	test_data.txt: Test data for the guish shell.
Compilation
	•	Ensure you have a C compiler (such as GCC) installed on your system.
	•	Navigate to the project directory containing the Makefile and the source code. 
	•	3. Run the following command to compile the code: “make”

This will compile the guish.c file and produce an executable named guish.
Usage
To run the guish shell, execute the following command from the terminal:
./guish 
You should now see the shell prompt, where you can start entering commands. Type the command and press Enter to execute it. For example:
bashCopy code
./guish$ ls ./guish$ mkdir test_directory ./guish$ cd test_directory ./guish$ touch test_file.txt ./guish$ hist ./guish$ r 2 ./guish$ exit 
Cleaning up
To clean up the project directory, run the following command:
make clean 
This will remove any object files and the guish executable from the project directory.
 

