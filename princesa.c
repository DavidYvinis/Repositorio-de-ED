//Relátorio de ED

//Este trabalho foi feito com ajuda dos meus companheiros Ananias Caetano e Robson Caetano.
//Tive uma leve dificuldade em implementar o código na linguagem C++, então resolvi fazer em linguagem C.
//Se isso interferir na minha nota, por favor me avise.
//Meu código é simples, mas acredito que esse seja o jeito mais fácil de resolver este problema.
//Resolvi alterar o nome do exercício para se tornar mais dinamico para se realizar.
//Primeiro temos as entradas, que serão de quantos Clones estão na DeathStar, e de quem erraria o primeiro disparo.
//Logo precisamos de um vetor, para que possamos fazer o movimento da arma e de quem morreria.
//Chamamos duas funções, cada uma com o dever de movimentar e eliminar um elemento do vetor.
//Assim, fazendo com que sempre que um matar o seu sucessor, ele assuma seu lugar.
//Ao final, restará apenas um clone, e seu registro númerico será exibido.

//Resumo da história: Os clones são péssimos atiradores.



//Exercício dos Clones
#include <stdio.h>

void mudar(int clones[], int total){
	int cont = clones[0];

	for(int i = 0; i < total - 1; i++ ){
		clones[i] = clones[i + 1];
    }
	clones[total - 1] = cont;

}

void tiros(int clones[], int total){
	for(int i = 1; i < total - 1; i++ ){
		clones[i] = clones[i + 1];
    }
}


int main(){
	 int prim, total;
	 int i;
	 
	 printf("Quantos clones vivos há na estrela da morte?\n");
	 scanf("%d", &total);
	 
	 printf("Quem vai ser o primeiro a errar o tiro e acertar o companheiro?\n");
	 scanf("%d", &prim);
	 
	 int clones[total];
	 
	 for(i = 0; i <= total - 1; i++ ){
		clones[i] = i + 1;
	 }
	
	 while(clones[0] != prim){
		mudar(clones, total);
	 }
	
	while(total > 1){	
		tiros(clones, total);
		total--;
		mudar(clones, total);
	}

	printf("O numero do clone sobrevivente foi: %d", clones[0]);

	return 0;
}
