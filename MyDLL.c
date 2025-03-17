/**
 * @file MyDLL.c
 * @brief Implementação de uma lista duplamente ligada (DLL).
 */

#include "MyDLL.h"


/**
 * @brief Inicializa a lista duplamente ligada.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param max_elements Número máximo de elementos permitidos na lista.
 * @param element_size Tamanho de cada elemento em bytes.
 */
void MyDLLInit(DoublyLinkedList *list, size_t max_elements, size_t element_size) {
    list->head = NULL;
    list->tail = NULL;
    list->max_elements = max_elements;
    list->element_size = element_size;
    list->count = 0;
}

/**
 * @brief Insere um novo elemento na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave única que identifica o elemento.
 * @param data Ponteiro para os dados a serem armazenados.
 * @return 0 se a inserção foi bem-sucedida, -1 se falhou (lista cheia ou erro de alocação).
 */
int MyDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data) {
    if (list->count >= list->max_elements) {
        return -1; // Lista cheia
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        return -1;
    }

    new_node->key = key;
    new_node->data = (unsigned char *)malloc(list->element_size);
    if (!new_node->data) {
        free(new_node);
        return -1;
    }
    memcpy(new_node->data, data, list->element_size);

    new_node->prev = list->tail;
    new_node->next = NULL;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    
    list->tail = new_node;
    list->count++;
    
    return 0;
}

/**
 * @brief Remove um elemento da lista pelo key.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento a ser removido.
 * @return 0 se a remoção foi bem-sucedida, -1 se o elemento não for encontrado.
 */
int MyDLLRemove(DoublyLinkedList *list, uint16_t key) {
    Node *current = list->head;
    while (current) {
        if (current->key == key) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current->data);
            free(current);
            list->count--;
            return 0;
        }
        current = current->next;
    }
    return -1; // Elemento não encontrado
}

/**
 * @brief Procura um elemento na lista utilizando a key.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento a ser procurado.
 * @return Ponteiro para os dados do elemento, ou NULL se não for encontrado.
 */
unsigned char *MyDLLFind(DoublyLinkedList *list, uint16_t key) {
    Node *current = list->head;
    while (current) {
        if (current->key == key) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * @brief Retorna os dados do próximo elemento na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento atual.
 * @return Ponteiro para os dados do próximo elemento, ou NULL se não houver próximo.
 */
unsigned char *MyDLLFindNext(DoublyLinkedList *list, uint16_t key) {
    Node *current = list->head;
    while (current) {
        if (current->key == key && current->next) {
            return current->next->data;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * @brief Retorna os dados do elemento anterior na lista.
 * 
 * @param list Ponteiro para a estrutura da lista.
 * @param key Chave do elemento atual.
 * @return Ponteiro para os dados do elemento anterior, ou NULL se não houver anterior.
 */
unsigned char *MyDLLFindPrevious(DoublyLinkedList *list, uint16_t key) {
    Node *current = list->head;
    while (current) {
        if (current->key == key && current->prev) {
            return current->prev->data;
        }
        current = current->next;
    }
    return NULL;
}

