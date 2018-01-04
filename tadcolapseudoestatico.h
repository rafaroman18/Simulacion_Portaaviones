#ifndef EJ1TADCOLA_TADCOLA_H
#define EJ1TADCOLA_TADCOLA_H
#include <cassert>
using namespace std;
template <typename T> class Cola
{
public:
    explicit Cola(size_t TamaMax);
    Cola(const Cola<T>& C);
    Cola<T>& operator =(const Cola<T>& C);
    bool vacia() const;
    bool llena() const;
    const T& frente() const;
    void pop();
    void push(const T& x);
    ~Cola();
private:
    T *elementos;
    int Lmax;
    int fin;
};

template <typename T>
inline Cola<T>::Cola(size_t TamaMax) :
        elementos(new T[TamaMax]),
        Lmax(TamaMax),
        fin(-1)
{}

template <typename T>
Cola<T>::Cola(const Cola<T>& C) :
        elementos(new T[C.Lmax]),
        Lmax(C.Lmax),
        fin(C.fin)
{
    for(int i=0;i<=fin;i++)
        elementos[i]=C.elementos[i];
}

template <typename T>
Cola<T>& Cola<T>::operator = (const Cola<T>& C)
{
    if(this != &C)
    {
        if(Lmax!=C.Lmax)
        {
            delete [] elementos;
            Lmax=C.Lmax;
            elementos=new T[Lmax];
        }
        fin=C.fin;
        for(int i=0;i<=fin;i++)
            elementos[i]=C.elementos[i];
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (fin==-1);
}

template<typename T>
inline bool Cola<T>::llena() const
{
    return (fin==Lmax-1);
}

template <typename T>
inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return elementos[0];
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    assert(!llena());
    fin++;
    elementos[fin]=x;
}

template <typename T>
void Cola<T>::pop()
{
assert(!vacia());
for (int i = 0; i < fin; i++)
elementos[i] = elementos[i+1];
fin--;
}

template <typename T>
inline Cola<T>::~Cola()
{
    delete[] elementos;
}

#endif //EJ1TADCOLA_TADCOLA_H
