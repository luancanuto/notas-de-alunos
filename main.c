#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// mat n1 n2 med
int mat[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//Matriz q posso cadastrar 5 alunos onde cada aluno 
//tera 3 notas - ap1, ap2 e media
float notas[70][4];
int aluno = 0, nota = 0, aprovados = 0, reprovados = 0, recuperacao = 0;
bool condicao = false;

int main(int argc, char** argv) {
	//BLOCO QUE RECEBE AS NOTAS NP1 E NP2
	while (!condicao){
		for(int nota=0; nota<2; nota++){
			printf("\nDigite nota: ");
			scanf("%f", &notas[aluno][nota]);
		}
		notas[aluno][3] = (notas[aluno][0] + notas[aluno][1])/2;
		printf("\nMedia do aluno Matricula 00%d: %.2f.", mat[aluno], notas[aluno][3]);
		printf("\nDigite 1 (um) para encerrar. ");
		scanf("%d", &condicao);
		aluno++;
	} //NO FINAL TEM TODAS AS MEDIAS CALCULADAS
	/*
	VERIFICAR QUEM ESTA DE RECUPERACAO
	MOSTRAR NA TELA TODOS OS ALUNOS DE RECUPERACAO
	SOLICITAR AS NOTAS DE RECUPERACAO
	*/
	printf("Registro de notas dos alunos matriculados.");
	printf("\n\n                             | AP1 | AP2 | REC | MF ");
	for (int linha = 0; linha < aluno; linha++){
		printf("\nAluno Matricula: 00%d -> Notas:", mat[linha]);
		
		if (notas[linha][3] >= 7){
			notas[linha][2] = 0; //Aluno aprovado
		}
		else if(notas[linha][3] >= 4){
			recuperacao++;
			notas[linha][2] = 8; //Nota de recuperacao
			notas[linha][3] = (notas[linha][3] + notas[linha][2])/2;
		} 
		else{
			notas[linha][2] = 0; //Aluno reprovado
		}
		
		for(int coluna = 0; coluna < 4; coluna++){
			printf("%.2f, ", notas[linha][coluna]);
		}
		
		if (notas[linha][3] >= 7){
			printf("\tAprovado");
		}
		else{
			printf("\tReprovado");
		}
	}
	int num_aluno = aluno;
	
	for (int mf = 0; mf < num_aluno; mf++){
		if (notas[mf][3] >= 7){
			aprovados++;
		}
		/*
		else if(notas[mf][2] >= 4){
			recuperacao++;
		}
		*/
		else{
			reprovados++;
		}
	}
	printf("\n\nAlunos aprovados: \t%d.", aprovados);
	printf("\nAlunos em recuperacao: \t%d.", recuperacao);
	printf("\nAlunos reprovados: \t%d.", reprovados);
	
	return 0;
}