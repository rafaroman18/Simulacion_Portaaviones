#ifndef TADSTACK_PILA_H
#define TADSTACK_PILA_H
#include <cassert>
template <typename tElemento >class Pila {

public:
    explicit Pila(unsigned TamaMax);        //CONSTRUCTOR
    Pila(const Pila& P);
    Pila& operator =(const Pila& P);
    bool vacia() const;
    bool llena() const;
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
    ~Pila();
private:
    tElemento *elementos;
    int Lmax;
    int tope_;
};
template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax) :
        elementos(new tElemento[TamaMax]),
        Lmax(TamaMax),
        tope_(-1)
{}
template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    tope_(P.tope_)
{
    for (int i = 0; i <= tope_; i++)
        elementos[i] = P.elementos[i];
}
template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator =(const Pila<tElemento>& P)
{
    if (this != &P) {
        if (Lmax != P.Lmax) {
            delete[] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        tope_ = P.tope_;
        for (int i = 0; i <= tope_; i++)
        elementos[i] = P.elementos[i];
    }
    return *this;
}
template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
    {
        return (tope_ == -1);
    }
template <typename tElemento>

inline bool Pila<tElemento>::llena() const
    {
        return (tope_ == Lmax - 1);
    }
template <typename tElemento>
inline const tElemento& Pila<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}
template <typename tElemento>
inline void Pila<tElemento>::pop()
{
    assert(!vacia());
    --tope_;
}
template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}
template <typename tElemento>
inline Pila<tElemento>::~Pila()
{ delete[] elementos; }
#endif //TADSTACK_PILA_H
