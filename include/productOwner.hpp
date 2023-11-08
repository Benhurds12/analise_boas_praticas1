//#include "pessoa.h"
#include "tarefa.hpp"

class ProductOwner : public Pessoa {
    public:
        //construtores e destrutores
        ProductOwner();
        explicit ProductOwner(string nome);
        ~ProductOwner();

        void cadastrarTarefa(Tarefa * t);
};
