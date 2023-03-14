// lab2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

void initialization(unsigned data[], unsigned const n) {
	vector<int> types;
	vector<int>::iterator it;
	int number;
	unsigned seed = 1001;
	for (unsigned m = 0; m < n; m++)
		types.push_back(m);
	for (unsigned counter = 0; counter != n; ++counter) {
		std::default_random_engine rng(seed);
		std::uniform_int_distribution <unsigned> dstr(0, types.size() - 1);
		number = dstr(rng);
		it = types.begin();
		advance(it, number);
		data[counter] = types[number];
		types.erase(it);
	}
}

void step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned pace) {
	for (unsigned i = begin_idx; i != end_idx - end_idx*pace; ++i)
		if (arr[i] > arr[i + end_idx*pace]) {
			int a = arr[i];
			arr[i] = arr[i + end_idx * pace];
			arr[i + end_idx * pace] = a;
		}
}

void bubble_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
	bool flag = true;
	while (flag == true) {
		flag = false;
		for (unsigned i = begin_idx; i != end_idx; ++i)
			if (arr[i] > arr[i + 1]) {
				int a = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = a;
				flag = true;
			}
	}
}

void comb_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned pace) {
	step(arr, begin_idx, end_idx, pace);
	bubble_sort(arr, begin_idx, end_idx);
}

int main() {
	unsigned const n = 10;
	unsigned begin_idx = 0;
	unsigned end_idx = n;
	unsigned data[n] = { 0 };
	unsigned pace = 0.8;
	initialization(data, n);
	comb_sort(data, begin_idx, end_idx, pace);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
