#include "../include/dev.hpp"
#include "../include/pessoa.hpp"

//Construtores
Dev::Dev() {}
Dev::Dev(const string& nome) : Pessoa(nome) {}
Dev::Dev(const string& nome, Pessoa * proximo) : Pessoa(nome, proximo) {}

//Destrutor
Dev::~Dev() {}

//Realização de tarefas
void Dev::RealizarTarefas(const string& status) {}

void Dev::RealizarTarefaEspecifica(const string& status, int idTarefa) {}
