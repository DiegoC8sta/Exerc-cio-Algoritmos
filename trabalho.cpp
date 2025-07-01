// Integrantes: João Miguel Mendonça, Diego Matias Costa, Maria Luiza Miquelato
// Data: 01/07/2025
// Professor: Lucas Debatin
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX = 5;
    int quantidade;

    // Pergunta quantos alunos o usuário quer cadastrar
    cout << "Quantos alunos deseja cadastrar (max " << MAX << ")? ";
    cin >> quantidade;

    while (quantidade < 1 || quantidade > MAX) {
        cout << "Valor invalido! Digite um numero entre 1 e " << MAX << ": ";
        cin >> quantidade;
    }

    string nomes[quantidade];
    float notas[quantidade][3];
    float media[quantidade];

    // Dados dos alunos
    for (int i = 0; i < quantidade; i++) {
        cout << "\nNome do aluno " << i + 1 << ": ";
        cin >> nomes[i];

        float somaNotas = 0;

        for (int j = 0; j < 3; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> notas[i][j];

            while (notas[i][j] < 0 || notas[i][j] > 10) {
                cout << "Nota invalida. Digite novamente (0 a 10): ";
                cin >> notas[i][j];
            }

            somaNotas += notas[i][j];
        }

        media[i] = somaNotas / 3;
    }

    cout << "\n=== SITUAÇÃO DOS ALUNOS ===\n";
    cout << "Nome\tNota1\tNota2\tNota3\tMedia\tSituacao\n";

    float maior = media[0];
    string destaque = nomes[0];

    for (int i = 0; i < quantidade; i++) {
        cout << nomes[i] << "\t";
        for (int j = 0; j < 3; j++) {
            cout << notas[i][j] << "\t";
        }
        cout << media[i] << "\t";

        if (media[i] >= 7) {
            cout << "Aprovado\n";
        } else {
            cout << "Reprovado\n";
        }

        if (media[i] > maior) {
            maior = media[i];
            destaque = nomes[i];
        }
    }

    cout << "\nAluno com melhor media: " << destaque << " (" << maior << ")\n";

    return 0;
}
