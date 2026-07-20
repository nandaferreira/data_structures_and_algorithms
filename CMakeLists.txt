cmake_minimum_required(VERSION 4.3)
project(AED2 C)

set(CMAKE_C_STANDARD 11)

include_directories(algoritmos/hash_table)
include_directories(listas/lista_02_tabela_hash/hash_backes)
include_directories(praticas/pratica_03_tabela_hash)
include_directories(praticas/pratica_04_arvore_binaria)
include_directories("praticas/pratica_06_arvores_avl/Arvore AVL")

add_executable(AED2
        algoritmos/hash_table/hash.c
        algoritmos/hash_table/hash.h
        algoritmos/searchAlgs/sortedSearch.c
        algoritmos/sortingAlgs/bubbleSort.c
        algoritmos/sortingAlgs/insertionSort.c
        algoritmos/sortingAlgs/mergeSort.c
        algoritmos/sortingAlgs/selectionSort.c
        listas/lista_01_busca_ordenacao/02.c
        listas/lista_01_busca_ordenacao/03.c
        listas/lista_01_busca_ordenacao/04.c
        listas/lista_01_busca_ordenacao/05.c
        listas/lista_01_busca_ordenacao/06.c
        listas/lista_01_busca_ordenacao/07.c
        listas/lista_01_busca_ordenacao/08.c
        listas/lista_02_tabela_hash/hash_backes/main.c
        listas/lista_02_tabela_hash/hash_backes/TabelaHash.c
        listas/lista_02_tabela_hash/hash_backes/TabelaHash.h
        listas/lista_02_tabela_hash/02.c
        listas/lista_02_tabela_hash/03.c
        praticas/pratica_01_alocacao_dinamica/01.c
        praticas/pratica_01_alocacao_dinamica/02.c
        praticas/pratica_01_alocacao_dinamica/03.c
        praticas/pratica_01_alocacao_dinamica/4.c
        praticas/pratica_02_ordenacao/01.c
        praticas/pratica_03_tabela_hash/main.c
        praticas/pratica_03_tabela_hash/TabelaHash.c
        praticas/pratica_03_tabela_hash/TabelaHash.h
        praticas/pratica_04_arvore_binaria/arvore_bin.c
        praticas/pratica_04_arvore_binaria/arvore_bin.h
        praticas/pratica_04_arvore_binaria/main.c
        praticas/pratica_05_grafos/01.c
        "praticas/pratica_06_arvores_avl/Arvore AVL/ArvoreAVL.c"
        "praticas/pratica_06_arvores_avl/Arvore AVL/ArvoreAVL.h"
        "praticas/pratica_06_arvores_avl/Arvore AVL/main.c")
