#ifndef NO_H
#define NO_H

template <class T>
class NO
{
private:
    T dado;
    NO* proximo;
public:
    NO();
    NO(T newDado);
    T getDado()const;
    void setDado(T newDado);
    NO* getProximo()const;
    void setProximo(NO* newProximo);
};

#endif // NO_H
