#include "Pair.h"
#include <fstream>
void Pair::setFirst(int first) {
	this->first = first;
}
void Pair::setSecond(double second) {
	this->second = second;
}

int Pair::getFirst() {
	return this->first;
}

double Pair::getSecond() {
	return this->second;
}

Pair::Pair() {
	this->first = 0;
	this->second = 0.0;
}

Pair::Pair(int first, double second) {
	this->first = first;
	this->second = second;
}

Pair::~Pair(){}

std::istream& operator>>(std::istream& in, Pair& pair) {
	in >> pair.first >> pair.second;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& pair) {
	out << pair.first << " : " << pair.second << std::endl;
	return out;
}

std::fstream& operator>>(std::fstream& fin, Pair& pair) {
	fin >> pair.first;
	fin >> pair.second;
	return fin;
}
std::fstream& operator<<(std::fstream& fout, const Pair& pair) {
	fout << pair.first << '\n' << pair.second << '\n';
	return fout;
}

Pair* Pair::subPairs(Pair& p1, Pair& p2) {
	Pair* new_pair = new Pair;
	new_pair->first = p1.first - p2.first;
	new_pair->second = p1.second - p2.second;
	return new_pair;
}
void Pair::add(int first) {
	this->first += first;
}
void Pair::add(double second) {
	this->second += second;
}
