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
    NO() :  proximo(0),
            anterior(0)
    {}

    NO(T newDado) :     dado(newDado),
                        proximo(0),
                        anterior(0)
    {}

    T getDado()const{
        return dado;
    }
    
    void setDado(T newDado){
        dado = newDado;
    }
    
    NO* getProximo()const{
        return proximo;
    }
    
    void setProximo(NO* newProximo){
        proximo = newProximo;
    }
    
    NO* getAnterior()const{
        return anterior;
    }
    
    void setAnterior(NO* newAnterior){
        anterior = newAnterior;
    }
};

#endif // NO_H
