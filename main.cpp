#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define argc_input_val 1

using namespace std;

// 		non cancellate questo:	g++ -Wall main.cpp per compilare
// 			./a.out <filename> 1> file.out per runnare
// quindi per essere sicura devo scrivere prima g++...ecc.. e poi la seconda
// roba
// yes
// ma e scusate l'ignoranza il file name metto?
// per ora nulla pero' il filename sara' il dataset che ci daranno
// ahhh ookay
// comunque non è necessario scrivere il comando ogni volta, premendo la freccia
// in su si scorre lo storico dei comandi, quindi sarà solo questione... sisi
// quello lo so

int main(int argc, char** argv) {
	fstream in;
	if (argc != 2) {
		cerr << "Usage " << argv[0] << " <inputfile>" << endl;
		return 1;
	}

	in.open(argv[argc_input_val], ios::in);
	return 0;
}