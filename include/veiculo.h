#ifndef VEICULO_H
#define VEICULO_H

#include <string>
#include <ostream>

class Veiculo {
protected:
    double posicaoX_;      // metros na estrada
    double velocidade_;    // m/s
    int prioridade_;       // 0=normal, 100=escolar

public:
    Veiculo(double posX = 0.0, double vel = 0.0, int prio = 0);
    virtual ~Veiculo() = default;

    // Getters puros (interface pública)
    double posicaoX() const { return posicaoX_; }
    double velocidade() const { return velocidade_; }
    int prioridade() const { return prioridade_; }

    // Movimentação
    virtual void atualizar(double deltaTempo);
    virtual std::string tipo() const = 0;  // Polimorfismo

    // Sobrecarga para fila de prioridade
    bool operator<(const Veiculo& outro) const;
};

#endif // VEICULO_H
