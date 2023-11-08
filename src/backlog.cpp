#include "../include/backlog.hpp"
#include <iostream>

Backlog::Backlog(){
  this->cauda = NULL;
  this->cabeca = NULL;
  this->quantidade = 0;
}

Backlog::Backlog(Tarefa * cabeca, Tarefa * cauda, int quantidade){
  this->cauda = cauda;
  this->cabeca = cabeca;
  this->quantidade = 0;
}

Backlog::~Backlog(){}

void Backlog::setCabeca(Tarefa * h){
  this->cabeca = h;
}

Tarefa* Backlog::getCabeca(){
  return this->cabeca;
}

void Backlog::setCauda(Tarefa * t){
  this->cauda = t;  
}

Tarefa* Backlog::getCauda(){
  return this->cauda;  
}

void Backlog::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

int Backlog::getQuantidade(){
  return this->quantidade;          
}

void Backlog::addTarefa(Tarefa *t) {
    if (this->cabeca == NULL) {
        // Se a lista está vazia, simplesmente defina a tarefa como a cabeça.
        this->cabeca = t;
    } else {
        // Caso contrário, insira a tarefa no início da lista.
        t->setProximo(this->cabeca);
        this->cabeca = t;
    }
    
    this->quantidade++;
}

void Backlog::deletarTarefa(Tarefa *t) {
    Tarefa *anterior = nullptr;
    Tarefa *atual = this->cabeca;

    while (atual != nullptr) {
        if (atual == t) {
            if (anterior != nullptr) {
                anterior->setProximo(atual->getProximo());
            } else {
                cabeca = atual->getProximo();
            }

            this->quantidade--;
            return;
        }

        anterior = atual;
        atual = atual->getProximo();
    }

    std::cout << "Tarefa não encontrada" << std::endl;
}



void Backlog::consultar(){
Tarefa * atual = this->cabeca;
    for(int i=0;i<this->quantidade;i++){
      if(atual != NULL){
        atual->imprimirTarefa();
        atual = atual->getProximo(); 
      }
    }
} //mostrar tarefas do backlog

//pega uma tarefa atraves do id
Tarefa * Backlog::getTarefa(int id) {
    Tarefa * atual = this->cabeca;

    while (atual != NULL) {
        if (atual->getId() == id) {
            return atual;
        } else {
            atual = atual->getProximo();
        }
    }

    return NULL;  // Retorna NULL se a tarefa não for encontrada
}
