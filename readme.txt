##############################################
Installation for linux distros
Just cd to simple_csv folder and run:
	su
	source exec.sh


if [ everything is ok ]; then 
	You see that.
fi

##############################################
Installation for anything but linux
First:
	DO NOT USE ANY FILE THAT END WITH SH.
Second:
	Open all files and change <hello.cpp> <hello.h> to "hello.cpp" and "hello.h".
Third:
	Compile and link main.cpp files with any compiler you like to test everyting is ok.
Force:
	Coding...
##############################################
How to use it
I put two files for testing the codes. First is "btc_usdt_1d.csv" and second is "main.cpp".

For reading the csv files this line must be work:
	std::vector<std::vector<std::string>> a{ csv_reader("btc_usdt_1d.csv") };
For getting a column of 2d vector that defined this line should be work:
	std::vector<std::string> b{ col(a, 0) };
For getting a row of 2d vector that definded this line may be work:
	std::vector<std::string> c{ row(a, 13) };

The problem is when you want to work with digits since your row and column are string vector.
For solving this issue I made a function that makes life easier than before:
	std::vector<double> d{ to_double(b) };
##############################################
Destruction
If you thought that my code is a piece of shame just run this magic on terminal:
	su
	source cleaner.sh
and follow the instruction.
##############################################
Last words
I just tested this code on csv file that exist in the folder.
If you tested it on the other files and didn't get what you want please tell me to solve this disaster.

I didn't test it on windows or macos.
##############################################
