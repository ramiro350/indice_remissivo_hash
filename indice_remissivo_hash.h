struct indice{
    char palavra[40];
    int chave = atoi(palavra);
}

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int insereHash_EnderAberto(Hash* ha, struct indice in);

int buscaHash_EnderAberto(Hash* ha, int chave, struct indice in);

void insertionSortPalavra(struct indice *V,int N);
