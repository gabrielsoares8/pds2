#ifndef ENERGIA_HPP
#define ENERGIA_HPP

class Energia {
private:
    int carga_;
public:
    Energia();
    Energia(int carga_inicial);
    int getCarga() const;
    void consumir(int quantidade);
};

#endif

//2 erro achados