#ifndef NO_H
#define NO_H

template <typename T>
class NO
{
private:
    T dado;
    NO* proximo;
    NO* anterior;
public:
    NO();
    NO(T newDado);
    T getDado()const;
    void setDado(T newDado);
    NO* getProximo()const;
    void setProximo(NO* newProximo);
    NO* getAnterior()const;
    void setAnterior(NO* newAnterior);
};

#endif // NO_H
