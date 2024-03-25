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
    // ���������
    mt19937 gen;
public:
    random_sys() {
        random_device rd;
        gen.seed(rd());
    }
    // ���������� ����� ����� � ��������� [minValue, maxValue)
    unsigned random_int(unsigned minValue, unsigned maxValue)
    {
        // ��������� ������������ ����������
        assert(minValue < maxValue);

        // ������ �������������
        std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

        // ��������� ��������������� �����: ������� ������������� ��� �������,
        //  ������� ��������� ������������ ����� ����� ��� ��������.
        return distribution(gen);
    }
    //������ �������� � "<>" ��� map'�, ������ ������. � ������� ������ map ������ ������ �� ��������
    template<typename T,typename F>
    F random(map <int, T>variants,F(*algorytm)(map <int, T>)) {
       return algorytm(variants);
    }
};

