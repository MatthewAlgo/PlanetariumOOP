#pragma once

template<typename A = void, typename B = void, typename C = void> class TripleItemHolder;
template<typename A = void, typename B = void> class DoubleItemHolder;


template<typename A, typename B, typename C> class TripleItemHolder {
private:
    A* A_VAR; B* B_VAR; C* C_VAR;
public:
    TripleItemHolder(A* a, B* b, C* c) {
        A_VAR = a; B_VAR = b; C_VAR = c;
    }
    TripleItemHolder(TripleItemHolder* INST) {
        A_VAR = INST->getA(); B_VAR = INST->getB(); C_VAR = INST->getC();
    }
    ~TripleItemHolder() {
        // Should just hold the items, not delete them
    }
    A* getA() const { return A_VAR; }
    B* getB() const { return B_VAR; }
    C* getC() const { return C_VAR; }
    TripleItemHolder& getInstance() { return *this; };
    TripleItemHolder* getCopy() { return new TripleItemHolder(this); }

};
template<typename A, typename B> class DoubleItemHolder {
private:
    A* A_VAR; B* B_VAR;
public:
    DoubleItemHolder(A* a, B* b) {
        A_VAR = a; B_VAR = b;
    }
    DoubleItemHolder(DoubleItemHolder* INST) {
        A_VAR = INST->getA(); B_VAR = INST->getB();
    }
    ~DoubleItemHolder() {
        // Should just hold the items, not delete them
    }
    A* getA() const { return A_VAR; }
    B* getB() const { return B_VAR; }
    DoubleItemHolder& getInstance() { return *this; };
    DoubleItemHolder* getCopy() { return new DoubleItemHolder(this); }

};
