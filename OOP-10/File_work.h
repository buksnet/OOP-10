#pragma once

#include <iostream>
#include <fstream>
#include "Pair.h"

int make_file(const char* f_name) {
	std::fstream file(f_name, std::ios::out | std::ios::trunc);
	if (!file) return -1;
	int n;
	Pair pair;
	std::cout << "count: ";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> pair;
		file << pair << "\n";
	}
	file.close();
	return n;
}

int print_file(const char* f_name) {
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0;
	while (file >> pair) {
		std::cout << pair << std::endl;
		i++;
	}
	file.close();
	return i;
}

int del_by_position(const char* f_name, int k) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	int i = 0;
	Pair pair;
	while (file >> pair) {
		if (file.eof()) break;
		i++;
		if (i != k) tmp_file << pair;
	}
	tmp_file.close();
	file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Pair new_pair) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0, l = 0;
	while (file >> pair) {
		if (file.eof()) break;
		i++;
		if (i == k) {
			tmp_file << new_pair;
			l++;
		}
		tmp_file << pair;
	}
	if (++i == k) {
		tmp_file << new_pair;
		l++;
	}
	file.close();
	tmp_file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Pair new_pair) {
	std::fstream file(f_name, std::ios::app);
	if (!file) return -1;
	file << new_pair;
	return 1;
}

int change_file(const char* f_name, int k, Pair new_pair) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0, l = 0;
	char ch;
	while (file >> pair) {
		if (file.eof()) break;
		i++;
		if (i == k) {
			std::cout << pair << " is being changed. Continue[y/n]?" << std::endl;
			std::cin >> ch;
			if (ch == 'n' || ch == 'N') break;
			tmp_file << new_pair;
			l++;
		}
		else tmp_file << pair;
	}
	file.close();
	tmp_file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return l;
}

int delete_lt(const char* f_name, int num) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0;
	while (file >> pair) {
		if (file.eof()) break;
		if (pair.getFirst() >= num) {
			tmp_file << pair;
			i++;
		}
	}
	file.close();
	tmp_file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return i;
}

int increase_l(const char* f_name, int l) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0;
	while (file >> pair) {
		if (file.eof()) break;
		pair.setFirst(pair.getFirst() + l);
		tmp_file << pair;
		i++;
	}
	file.close();
	tmp_file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return i;
}

int increase_l(const char* f_name, double l) {
	std::fstream tmp_file("temp", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair;
	int i = 0;
	while (file >> pair) {
		if (file.eof()) break;
		pair.setFirst(pair.getFirst() + l);
		tmp_file << pair;
		i++;
	}
	file.close();
	tmp_file.close();
	std::remove(f_name);
	std::rename("temp", f_name);
	return i;
}

int add_afterK(const char * f_name, int n, int k) {
	std::fstream tmp1_file("temp1", std::ios::out);
	std::fstream tmp2_file("temp2", std::ios::out);
	std::fstream file(f_name, std::ios::in);
	if (!file) return -1;
	Pair pair, tmp_pair;
	int i = 0;
	while (file >> pair) {
		if (file.eof()) break;
		
		if (i < k) tmp1_file << pair;
		else tmp2_file << pair;
		i++;
	}
	file.close();
	tmp2_file.close();

	for (int j = 0; j < k; j++) {
		std::cin >> pair;
		tmp1_file << pair;
		i++;
	}

	tmp2_file.open("temp2", std::ios::in);

	while (tmp2_file >> pair) {
		if (file.eof()) break;
		tmp1_file << pair;
		i++;
	}

	tmp2_file.close();
	tmp1_file.close();

	std::remove(f_name);
	std::remove("temp2");
	std::rename("temp1", f_name);
	return i;
}