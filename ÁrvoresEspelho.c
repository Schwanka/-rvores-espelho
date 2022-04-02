/*
    Nome: Gustavo Schwanka
    GRR20193748
    Estrutura de Dados 2
    Árvores espelho
*/
// Imaginando esta estrutura de árvore:
    typedef struct arvore {
        int info;
        struct arvore *esq;
        struct arvore *dir;
    } Arvore;
int eh_espelho(Arvore * arv_a, Arvore * arv_b){
    if(espelho(arv_a,arv_b)){ // se verdadeiro o retorno de espelho
        return 1; // retorna 1.
    }else{ // se não
        return 0; // retorna 0.
    }
}
bool espelho(Arvore * arv_a, Arvore * arv_b){
//Para essa função, com esseção a raiz, percorre-se a arv_a em pré ordem e a arv_b em pos ordem. Se em todos os momentos os valores forem iguais, é espelho.
    bool resultado = true; // define o resultado para verdadeiro, só altera se verificar que não é espelho.
    if ((arv_a != NULL) && (arv_b != NULL)){ // se ambos nulos, então são iguais, nesse caso, são espelho.
        if((arv_a.esq != NULL)&& (arv_b.dir != NULL)){ // se arv_a.esq tiver algo e arv_b.dir tiver também então verifica
            resultado = espelho(arv_a.esq,arv_b.dir);// se ambas tiverem informação, chama a mesma função pra ver se são espelho.
        }
        if(resultado){ // se o resultado se manteve verdadeiro, logo o elemento à esquerda de a é igual o da direita de b
            if((arv_a.dir != NULL)&& (arv_b.esq != NULL)){ // faz o inverso, verificando direita de a igual direita de b
                resultado = espelho(arv_a.dir,arv_b.esq); // mesma ideia.
            }
            if(resultado){ // se resultado se manteve verdadeiro, verifica o nó em sí
                if(arv_a.info != arv_b.info){
                    return false; // se for diferente o valor, então é espepelho
                }else{  // se igual,
                    return true; //então se mantem verdadeiro e retorna ( nas chamadas recursivas resultado recebe o valor).
                }
            }else{ // se o resultado se tornou falso na chamada para  espelho(arv_a.dir,arv_b.esq), então
                return false; // retorna falso.
            }
        }else{ // se o resultado se tornou falso na chamada para  espelho(arv_a.esq,arv_b.dir), então
            return false; // retorna falso.
        }
    }// se passou por todas as verificações ou ambas são nulas
        return true; // retorna verdadeiro.
}
Arvore * cria_espelho(Arvore * arv_a){
    Arvore *b = (Arvore*)malloc(sizeof(Arvore)); // aloca memoria para b
    b = NULL; // define como nulo
    if(arv_a != NULL){ // se arvore a for nula não faz nada
        if(arv_a.esq != NULL){ // Se tiver filho a esquerda
            b.dir = cria_espelho(arv_a.esq); // chama a mesma função para b.dir receber o resultado passando arv_a.esq
        }if(arv_a.dir != NULL){ // se tiver filho a direita
            b.esq = cria_espelho(arv_a.dir); // chama a mesma funçao para b.esq receber o resultado passando arv_a.dir
        }
        b.info = arv_a.info; // se o nó não tiver filhos / já entrou nos ifs e voltou com o resultado, então insere a informação
    }
        return b; // retona a arvore pronta.
}
