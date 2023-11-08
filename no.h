#ifndef NO_H
#define NO_H

template <class L>
class NO
{
private:
    L dado;
    int chave;
    NO* proximo;
    NO* anterior;
public:
    NO() :  dado(),
            proximo(0),
            anterior(0),
            chave(0)
    {}

    NO(L newDado, int chave) :  dado(newDado),
                                proximo(0),
                                anterior(0),
                                chave(0)
    {
        if (chave < 0){
            throw QString("Chave invalida");
        }
        this->chave = chave;
    }

    L getDado()const{
        return dado;
    }
    
    void setDado(L newDado){
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

    void setChave(int chave){
        if (chave < 0){
            throw QString("Chave invalida");
        }
        this->chave = chave;
    }

    int getChave()const{
        return chave;
    }
};

#endif // NO_H
