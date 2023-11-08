//#include "pessoa.h"
//#include "dev.h"
#include "tarefa.hpp"

class Tester : public Pessoa {
public:
    // Construtores e destrutores
    Tester();
    explicit Tester(const string& nome);
    Tester(const string& nome, Pessoa* proximo);
    ~Tester();

    // Funções
    void validarTarefasDe(Dev* p);
    void declinarTarefasDe(Dev* p);
    void validarTarefa(Tarefa* t);
    void declinarTarefa(Tarefa* t);
};
