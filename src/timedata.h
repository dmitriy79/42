// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://opensource.org.
#ifndef BITCOIN_TIMEDATA_H
#define BITCOIN_TIMEDATA_H

#include <cstdint>
#include <vector>
#include <algorithm>

class CNetAddr;

/** Класс-фильтр для вычисления медианного значения (возвращен обратно для main.cpp) */
template <typename T>
class CMedianFilter
{
private:
    std::vector<T> vValues;
    unsigned int nSize;

public:
    CMedianFilter(unsigned int size, T initial_value) : nSize(size)
    {
        vValues.reserve(size);
        vValues.push_back(initial_value);
    }

    void input(T value)
    {
        if (vValues.size() >= nSize)
            vValues.erase(vValues.begin());
        vValues.push_back(value);
    }

    size_t size() const
    {
        return vValues.size();
    }

    T median() const
    {
        std::vector<T> vTmp = vValues;
        std::sort(vTmp.begin(), vTmp.end());
        return vTmp[vTmp.size() / 2];
    }

    std::vector<T> sorted() const
    {
        std::vector<T> vTmp = vValues;
        std::sort(vTmp.begin(), vTmp.end());
        return vTmp;
    }
};

// Чистые прототипы глобальных функций без inline-тел (реализация строго в timedata.cpp)
int64_t GetTimeOffset();
int64_t GetNodesOffset();
int64_t GetAdjustedTime();
void AddTimeData(const CNetAddr& ip, int64_t nTime);

#endif // BITCOIN_TIMEDATA_H
