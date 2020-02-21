#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define argc_input_val 1

using namespace std;

// 		g++ -Wall mainA.cpp
// 		./a.out <filename> 1> file.out

uint32_t n_books;
uint32_t n_libraries;
uint32_t n_days;

typedef struct book {
	uint32_t id;
	uint32_t score;
} book_t;

typedef struct library {
	vector<book_t *> books;
	uint32_t i;
	uint32_t sign_d;
	uint32_t book_rate;
} library_t;

vector<book_t> books;
vector<library_t> libraries;

bool compare_sign_d(library &a, library &b) { return (a.sign_d < b.sign_d); };
bool compare_library_books(library &a, library &b) {
	uint32_t suma = 0;
	uint32_t sumb = 0;
	for (uint32_t i = 0; i < a.books.size(); i++) {
		suma += a.books[i]->score;
	}

	for (uint32_t i = 0; i < b.books.size(); i++) {
		sumb += b.books[i]->score;
	}
	return (suma > sumb);
}

bool compare_library_books_cut(library &a, library &b) {
	uint32_t suma = 0;
	uint32_t sumb = 0;

	uint32_t min_a = min((uint32_t)a.books.size(), a.book_rate * 200);

	uint32_t min_b = min((uint32_t)b.books.size(), b.book_rate * 200);

	for (uint32_t i = 0; i < min_a; i++) {
		suma += a.books[i]->score;
	}

	for (uint32_t i = 0; i < min_b; i++) {
		sumb += b.books[i]->score;
	}

	return (suma > sumb);
}

bool compare_book_score(book_t *a, book_t *b) { return (a->score > b->score); }

// function to solve datata set B
void functionB() { sort(libraries.begin(), libraries.end(), compare_sign_d); }

// function to solve datata set C
void functionC() {
	sort(libraries.begin(), libraries.end(), compare_sign_d);

	for (uint32_t l = 0; l < libraries.size(); l++) {
		for (uint32_t b = 0; b < libraries[l].books.size(); b++) {
			sort(libraries[l].books.begin(), libraries[l].books.end(),
				 compare_book_score);
		}
		sort(libraries.begin(), libraries.end(), compare_library_books);
	}
}
// function to solve datata set D
void functionD() { sort(libraries.begin(), libraries.end(), compare_sign_d); }

// function to solve datata set E (first iteration)
void functionE() {
	sort(libraries.begin(), libraries.end(), compare_sign_d);

	sort(libraries.begin(), libraries.end(), compare_library_books_cut);
}

// function to solve datata set E (second iteration)
void functionE2() {
	sort(libraries.begin(), libraries.end(), compare_sign_d);

	for (uint32_t i = 0; i < libraries.size(); i++) {
		if (!((libraries[i].books.size() > 170))) {
			libraries.erase(libraries.begin() + i);
		}
	}
}

// function to solve datata set F
void functionF() {
	sort(libraries.begin(), libraries.end(), compare_sign_d);

	for (uint32_t i = 0; i < libraries.size(); i++) {
		if (!((libraries[i].book_rate > 3) &&
			  (libraries[i].books.size() > 180))) {
			libraries.erase(libraries.begin() + i);
		}
	}
}

void print_solution() {
	cout << libraries.size() << endl;

	for (uint32_t l = 0; l < libraries.size(); l++) {
		cout << libraries[l].i << " " << libraries[l].books.size() << endl;
		for (uint32_t b = 0; b < libraries[l].books.size(); b++) {
			cout << libraries[l].books[b]->id << " ";
		}
		cout << endl;
	}
}
int main(int argc, char **argv) {
	fstream in;
	if (argc != 2) {
		cerr << "Usage " << argv[0] << " <inputfile>" << endl;
		return 1;
	}

	in.open(argv[argc_input_val], ios::in);

	char data[255];

	in >> data;
	n_books = atoi(data);

	in >> data;
	n_libraries = atoi(data);

	in >> data;
	n_days = atoi(data);

	// get books score
	for (uint32_t i = 0; i < n_books; i++) {
		in >> data;
		uint32_t value = atoi(data);
		books.push_back({i, value});
	}

	// get libraries
	for (uint32_t i = 0; i < n_libraries; i++) {
		in >> data;
		uint32_t book_n = atoi(data);

		in >> data;
		uint32_t sign_d = atoi(data);

		in >> data;
		uint32_t book_rate = atoi(data);

		libraries.push_back({.i = i, .sign_d = sign_d, .book_rate = book_rate});

		for (uint32_t b = 0; b < book_n; b++) {
			in >> data;
			uint32_t book_i = atoi(data);

			libraries[i].books.push_back(&books[book_i]);
		}
	}

	//	functionB();
	//	functionC();
	//	functionD();
	//	functionE();
	//	functionE2();
	functionF();
	print_solution();

	in.close();
	return 0;
}
