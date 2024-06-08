#pragma once
#include <iostream>


class Pair
{
private:
	int first;
	double second;
public:
	void setFirst(int);
	void setSecond(double);

	int getFirst();
	double getSecond();

	Pair();
	Pair(int, double);
	~Pair();

	friend std::istream& operator>>(std::istream&, Pair&);
	friend std::ostream& operator<<(std::ostream&, const Pair&);

	friend std::fstream& operator>>(std::fstream&, Pair&);
	friend std::fstream& operator<<(std::fstream&, const Pair&);

	Pair* subPairs(Pair&, Pair&);
	void add(int);
	void add(double);
};

