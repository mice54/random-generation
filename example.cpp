//пример использования
#include "rand.h"

using namespace std;

//микрокласс
class cha {
public:
	float res;
};

//две системы рандома, одна для алмазов, другая для монет, например
random_sys r, r1;

//пример алгоритма, внутри может быть что угодно, а аргументы должны иметь такой же тип, и должен остаться template с такимже именами!!!
template<typename F, typename T>
F algory(map <int, T> var) {
	cha cha1;
	cha1.res=var[r.random_int(1, 2)];
	return cha1;
}

int main() {
	map<int, float> var1 = { {1, 5.4},
	{2, 4.5}
	};
	//первый параметь в "<>" тип map'а, второй класса. в круглых первый map второй ссылка на алгоритм
	cha cha2 = r.random<float, cha>(var1, algory);
	cout << r.random_int(1, 100) << endl << r1.random_int(1, 100) << endl << cha2.res << endl;
	system("pause");
}