### Atividade Prática - Árvores AVL
***
**1) Qual é a estrutura do nó da árvore AVL?** 
Ela possui os campos:
- info (int)
- altura (int)
- *esq (No)
- *dir (No)

O campo altura serve para identificar em qual altura da árvore aquele Nó (dado) pertence
***
**2) O que a função fatorBalanceamento_NO calcula?**
Ela calcula o fator de balanceamento de uma árvore AVL, que é dado pela diferença entre a altura das sub-ávores de cada nó.

<p align="center">
    <img src="../Arvore%20AVL/assets/pratica_07_avl_fatorBalanceamento.png" />
</p>

A fórmula matemática do fator de balanceamento se da por 
> FB = AE - AD

**AE:** altura da sub-árvore ESQUERDA
**AD:**: altura da sub-árvore DIREITA

*Caso uma das sub-árvores de um nó não-existir, então a altura dessa sub-árvore será igual a -1.*
O intervalo de valores aceitáveis por uma árvore AVL balanceada é de [-1, 1].
***
**3) Observe a função insere_ArvAVL. Em quais situações a rotação LL é aplicada? Em quais situações a rotação LR é aplicada?**

