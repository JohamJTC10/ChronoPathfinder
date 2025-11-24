#ifndef TWOSAT_H
#define TWOSAT_H

#include <iostream>
#include "DataStructures.h"
using namespace std;

class TwoSAT
{
    private:
        int N;
        Vec *g;
        Vec *gr;
        Vec used;
        Vec comp;
        Vec order;
        Vec assignment;

        void dfs1(int v);
        void dfs2(int v, int c);

    public:
        TwoSAT(int n);
        ~TwoSAT();

        int var(int x, bool val);
        void addImp(int a, int b);
        void addOr(int a, int b);
        void setTrue(int a);
        bool solve();
};

#endif
