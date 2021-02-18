#include<stdlib.h>
#include<string.h>
#include "indice_remissivo_hash.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct indice **itens;
};

Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct indice**) malloc (TABLE_SIZE * sizeof(struct indice*));
        if(ha->itens = NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0;i< ha->TABLE_SIZE;i++){
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0;i< ha->TABLE_SIZE;i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int sondagemLinear(int pos,int i, int TABLE_SIZE){
    return ((pos+i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto(Hash* ha,struct indice in){
      if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
      }
      int chave = in.chave;
      int i,pos,newPos;
      pos = chaveDivisao(chave,ha->TABLE_SIZE);
      for(i = 0;i< ha->TABLE_SIZE;I++){
        newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            struct indice* novo;
            novo = (struct indice*) malloc(sizeof(struct aindice));
            if(novo == NULL){
                return 0;
            }
            *novo = in;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
      }
      return 0;
}

int buscaHash_EnderAberto(Hash* ha,int ch,struct indice in){
      if(ha == NULL){
        return 0;
      }
      int i,pos,newPos;
      pos = chaveDivisao(ch,ha->TABLE_SIZE);
      for(i = 0;i< ha->TABLE_SIZE;i++){
        newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
        if(ha->itens[newPos]==NULL){
            return 0;
        }
        if(ha->itens[newPos]->chave == ch){
            *in = *(ha->itens[newPos]);
            return 1;
        }
      }
      return 0;
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
   }

void insertionSortPalavra(struct indice *V,int N){
    int i,j;
    struct indice aux;
    for(i=1;i<N;i++){
        aux = V[i];
        for(j=i;(j>0) && (aux.chave<V[j-1].chave);j--){
            V[j] = V[j-1];
            V[j] = aux;
        }
    }
}
