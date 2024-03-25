#pragma once
#include <string>
#include <map>
#include <cassert>
#include <random>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class random_sys {
    // генератор
    mt19937 gen;
public:
    random_sys() {
        random_device rd;
        gen.seed(rd());
    }
    // Генерирует целое число в диапазоне [minValue, maxValue)
    unsigned random_int(unsigned minValue, unsigned maxValue)
    {
        // Проверяем корректность аргументов
        assert(minValue < maxValue);

        // Создаём распределение
        std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

        // Вычисляем псевдослучайное число: вызовем распределение как функцию,
        //  передав генератор произвольных целых чисел как аргумент.
        return distribution(gen);
    }
    //первый параметь в "<>" тип map'а, второй класса. в круглых первый map второй ссылка на алгоритм
    template<typename T,typename F>
    F random(map <int, T>variants,F(*algorytm)(map <int, T>)) {
       return algorytm(variants);
    }
};

