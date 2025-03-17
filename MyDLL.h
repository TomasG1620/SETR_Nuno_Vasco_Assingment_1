/**
 * @file MyDLL.h
 * @brief Módulo para implementação de uma lista duplamente ligada (DLL).
 * 
 * Este módulo contém a estrutura de dados e as funções necessárias para 
 * manipular uma lista duplamente ligada.
 */

#ifndef MYDLL_H
#define MYDLL_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Node
 * @brief Estrutura de um nó da lista duplamente ligada.
 */
typedef struct Node {
    uint16_t key;           /**< Chave única do nó */
    unsigned char *data;    /**< Dados armazenados no nó */
    struct Node *prev;      /**< Ponteiro para o nó anterior */
    struct Node *next;      /**< Ponteiro para o próximo nó */
} Node;

/**
 * @struct DoublyLinkedList
 * @brief Estrutura da lista duplamente ligada.
 */
typedef struct {
    Node *head;             /**< Ponteiro para o primeiro nó da lista */
    Node *tail;             /**< Ponteiro para o último nó da lista */
    size_t max_elements;    /**< Número máximo de elementos */
    size_t element_size;    /**< Tamanho de cada elemento */
    size_t count;           /**< Número de elementos na lista */
} DoublyLinkedList;

/**
 * @brief Inicializa a lista duplamente ligada.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param max_elements Número máximo de elementos permitidos na lista.
 * @param element_size Tamanho de cada elemento em bytes.
 */
void MyDLLInit(DoublyLinkedList *list, size_t max_elements, size_t element_size);

/**
 * @brief Insere um novo elemento na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave única que identifica o elemento.
 * @param data Ponteiro para os dados a serem armazenados.
 * @return 0 se a inserção foi bem-sucedida, -1 se falhou (lista cheia ou erro de alocação).
 */
int MyDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data);

/**
 * @brief Remove um elemento da lista pelo key.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento a ser removido.
 * @return 0 se a remoção foi bem-sucedida, -1 se o elemento não for encontrado.
 */
int MyDLLRemove(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Procura um elemento na lista utilizando a key.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento a ser procurado.
 * @return Ponteiro para os dados do elemento, ou NULL se não for encontrado.
 */
unsigned char *MyDLLFind(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Retorna os dados do próximo elemento na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento atual.
 * @return Ponteiro para os dados do próximo elemento, ou NULL se não houver próximo.
 */
unsigned char *MyDLLFindNext(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Retorna os dados do elemento anterior na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento atual.
 * @return Ponteiro para os dados do elemento anterior, ou NULL se não houver anterior.
 */
unsigned char *MyDLLFindPrevious(DoublyLinkedList *list, uint16_t key);

#endif // MYDLL_H

