#include "../include/sprint.hpp"
#include <iostream>

Sprint::Sprint(){
  this->cabeca = NULL;
  this->cauda = NULL;
  this->tempoPassado=0;//tempo passado em dias
  this->quantidade=0;//quantidade de tarefas na sprint
}

Sprint::Sprint(Tarefa * cabeca, Tarefa * cauda){
  this->cabeca = cabeca;
  this->cauda = cauda;
  this->tempoPassado=0;//tempo passado em dias
  this->quantidade=0;//quantidade de tarefas na sprint
}

Sprint::~Sprint(){}

void Sprint::setCabeca(Tarefa * h){
  this->cabeca = h;
}
Tarefa* Sprint::getCabeca(){
  return this->cabeca;
}
void Sprint::setCauda(Tarefa * t){
  this-> cauda = t;
}
Tarefa* Sprint::getCauda(){
  return this->cauda;
}
void Sprint::setTempoPassado(int tempo){
  this->tempoPassado=tempo;
}
int Sprint::getTempoPassado(){
  return tempoPassado;
}
void Sprint::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}
int Sprint::getQuantidade(){
  return this->quantidade;
}



//gerar relatório pôs ‘n’ tempo passado
void Sprint::gerarRelatorio(){
  Tarefa * atual = this->cabeca;
    for(int i=0;i<this->quantidade;i++){
      if(atual != NULL){
        atual->imprimirTarefa();
        atual = atual->getProximo(); 
      }
    }
}

void Sprint::gerarRelatorioDe(Dev * p){
  
}//gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação).


//SPRINT SO ADICIONA TAREFA DO BACKLOG AJUSTAR ISSO NA MAIN
void Sprint::addTarefa(Tarefa *t) {
  if (t == nullptr) {
    std::cout << "Tarefa inválida. Não pode ser adicionada." << std::endl;
    return;
  }

  if (this->cabeca == nullptr) {
    // Se a lista estiver vazia, insira a tarefa como a cabeça.
    this->cabeca = t;
    t->setProximo(nullptr);  // Garanta que a próxima tarefa seja nula.
  } else {
    // Encontre o último elemento da lista e adicione a nova tarefa a seguir.
    Tarefa *atual = this->cabeca;
    while (atual->getProximo() != nullptr) {
      atual = atual->getProximo();
    }
    atual->setProximo(t);
    t->setProximo(nullptr);  // Garanta que a próxima tarefa seja nula.
  }

  this->quantidade++;
}



void Sprint::deletarTarefa(Tarefa * t) {
  Tarefa * atual = this->cabeca;
  Tarefa * anterior = nullptr;

  for (int i = 0; i < this->quantidade; i++) {
    if (atual != t) {
      // If the current task is not the one we want to delete
      if (atual->getProximo() == t) {
        // If the next task is the one we want to delete
        Tarefa * proximo = t->getProximo();

        if (atual == this->cabeca) {
          this->cabeca = proximo;
        } else {
          anterior->setProximo(proximo);
        }

        this->quantidade--;
        break;
      } else {
        anterior = atual;
        atual = atual->getProximo();
      }
    } else if (atual == NULL) {
      std::cout << "Tarefa não encontrada" << std::endl;
      break;
    } else if (atual == cabeca) {
      cabeca = atual->getProximo();
      this->quantidade--;
      break;
    }
  }
}

