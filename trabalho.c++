/********************************************************************************

Nome: Matheus de Castro Faria Caetano

Matricula: 28940

********************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    // utilizaçao de array para conseguir cadastrar 5 contas bancarias "[5]"

    int numeroConta[5];
    int tipoConta[5];
    int opcao;
    int alterarConta;
    int numeroConsulta;

    string nomeCliente[5];
    string cpf[5];

    double saldo[5];

    bool contaAtiva[5];

    int quantidadeContas = 0;

    do {

        cout << "================================" << endl
             << "========  Banco MCF  ========" << endl
             << "================================" << endl
             << "1 - Cadastrar conta" << endl
             << "2 - Consultar Conta" << endl
             << "3 - Verificar saldo" << endl
             << "4 - Alterar tipo da conta" << endl
             << "5 - Ativar/Desativar conta" << endl
             << "6 - Sair" << endl
             << "Digite uma Opcao: ";

        cin >> opcao;

        switch (opcao) {

        case 1:

            if (quantidadeContas >= 5) {

                cout << "Limite de 5 contas atingido!" << endl;

                break;
            }
            do {

                cout << "== Cadastrar de conta ==" << endl;

                cout << "Digite o numero da sua conta: ";

                cin >> numeroConta[quantidadeContas];

                if (numeroConta[quantidadeContas] <= 0) {

                    cout << "Numero invalido! Digite um numero maior que zero"
                         << endl;
                }

            } while (numeroConta[quantidadeContas] <= 0);

            cout << "Digite o nome do Titular da Conta: ";

            // comando para pegar o nome completo
            cin.ignore();

            getline(cin, nomeCliente[quantidadeContas]);

            cout << "Digite o CPF: ";

            cin >> cpf[quantidadeContas];

            do {
                cout << "---- Informe o tipo da conta ----" << endl;
                cout << "1 - Conta corrente" << endl;
                cout << "2 - Conta poupanca" << endl;
                cout << "Digite: ";

                cin >> tipoConta[quantidadeContas];

                // Validacao do tipo de conta, so pode digitar 1 ou 2
                if (tipoConta[quantidadeContas] == 1) {

                    cout << "Tipo de conta selecionado: Corrente"
                         << endl;

                }
                else if (tipoConta[quantidadeContas] == 2) {

                    cout << "Tipo de conta selecionado: Poupanca"
                         << endl;

                }
                else {

                    cout << "Tipo de conta invalido, digite 1 ou 2!"
                         << endl;
                }

            } while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2);
            do {

                cout << "Digite o saldo da conta R$ : ";

                cin >> saldo[quantidadeContas];

                // validacao numero nao pode ser negativo
                if (saldo[quantidadeContas] < 0) {

                    cout << "Valor invalido!" << endl;
                }

            } while (saldo[quantidadeContas] < 0);


            contaAtiva[quantidadeContas] = true;

            cout << "Conta cadastrada com sucesso!" << endl;

            quantidadeContas++;

            break;

        case 2:

            if (quantidadeContas == 0) {

                cout << "Nenhuma conta cadastrada!" << endl;

                break;
            }

            cout << "Digite o numero da conta que deseja consultar: ";

            cin >> numeroConsulta;

            {

                int posicaoConta = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    //utilizaçao do for para achar a posiçao das contas 
                    if (numeroConta[i] == numeroConsulta) {
                        
                        posicaoConta = i;
                        break;
                    }
                }
                // Se continuar -1, significa que o for passou por todas as contas e não encontrou o número procurado.
                if (posicaoConta == -1) {

                    cout << "Conta nao encontrada!" << endl;

                    break;
                }

                cout << "------- Consulta de Conta -------"
                     << endl;

                cout << "Nome do titular: "
                     << nomeCliente[posicaoConta]
                     << endl;
                //condiçao para saber qual tipo de conta é a conta cadastrada
                if (tipoConta[posicaoConta] == 1) {

                    cout << "Tipo de Conta: Corrente"
                         << endl;

                }
                else {

                    cout << "Tipo de Conta: Poupanca"
                         << endl;
                }

                cout << "Saldo: R$ "
                     << fixed << setprecision(2)
                     << saldo[posicaoConta]
                     << endl;

                if (contaAtiva[posicaoConta]) {

                    cout << "Situacao da conta: Ativa!"
                         << endl;

                }
                else {

                    cout << "Situacao da conta: Desativada"
                         << endl;
                }

                cout << "---------------------------------"
                     << endl;
            }

            break;

        case 3:

            if (quantidadeContas == 0) {

                cout << "Nenhuma conta cadastrada!" << endl;

                break;
            }

            cout << "Digite o numero da conta: ";

            cin >> numeroConsulta;

            {

                int posicaoConta = -1;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroConsulta) {

                        posicaoConta = i;
                        break;
                    }
                }

                if (posicaoConta == -1) {

                    cout << "Conta nao encontrada!" << endl;

                    break;
                }

                cout << "--------- Consulta de saldo ---------"
                     << endl;

                cout << fixed << setprecision(2);

                cout << "Saldo da conta: R$ "
                     << saldo[posicaoConta]
                     << endl;

                cout << "-------------------------------------"
                     << endl;
            }

            break;


        case 4:

            if (quantidadeContas == 0) {

                cout << "Nenhuma conta cadastrada!" << endl;

                break;
            }

            cout << "Digite o numero da conta: ";

            cin >> numeroConsulta;

            {

                int posicaoConta = -1;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroConsulta) {

                        posicaoConta = i;
                        break;
                    }
                }

                if (posicaoConta == -1) {

                    cout << "Conta nao encontrada!" << endl;

                    break;
                }

                if (!contaAtiva[posicaoConta]) {

                    cout << "A conta esta desativada!" << endl;

                    break;
                }

                cout << "-------- Alterar tipo de conta ------"
                     << endl;

                cout << "------ Tipo Atual da conta ------"
                     << endl;

                if (tipoConta[posicaoConta] == 1) {

                    cout << "A sua conta e: Corrente"
                         << endl;

                }
                else {

                    cout << "A sua conta e: Poupanca"
                         << endl;
                }

                cout << endl;

                cout << "Deseja alterar o tipo de conta?"
                     << endl;

                cout << "1 - Sim" << endl;
                cout << "2 - Nao" << endl;
                cout << "Digite: ";

                cin >> alterarConta;


                if (alterarConta == 1) {

                    do {

                        cout << endl;

                        cout << "Escolha um novo tipo"
                             << endl;

                        cout << "1 - Corrente" << endl;
                        cout << "2 - Poupanca" << endl;

                        cout << "Digite: ";

                        cin >> tipoConta[posicaoConta];


                        if (tipoConta[posicaoConta] == 1) {

                            cout << "Tipo de conta selecionada: Corrente"
                                 << endl;

                        }
                        else if (tipoConta[posicaoConta] == 2) {

                            cout << "Tipo de conta selecionada: Poupanca"
                                 << endl;

                        }
                        else {

                            cout << "Tipo invalido! Digite 1 ou 2."
                                 << endl;
                        }

                    } while (tipoConta[posicaoConta] != 1 &&
                             tipoConta[posicaoConta] != 2);


                    cout << "----- Tipo de conta alterado com sucesso! ------"
                         << endl;
                }

                else if (alterarConta == 2) {

                    cout << "Sem alteracoes." << endl;

                }

                else {

                    cout << "Opcao invalida." << endl;
                }
            }

            break;


        case 5:

            if (quantidadeContas == 0) {

                cout << "Nenhuma conta cadastrada!" << endl;

                break;
            }

            cout << "Digite o numero da conta: ";

            cin >> numeroConsulta;

            {

                int posicaoConta = -1;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroConsulta) {

                        posicaoConta = i;
                        break;
                    }
                }

                if (posicaoConta == -1) {

                    cout << "Conta nao encontrada!" << endl;

                    break;
                }

                cout << "----- Ativar/Desativar Conta -----"
                     << endl;


                if (contaAtiva[posicaoConta]) {

                    cout << "A sua Conta esta Ativa"
                         << endl;

                    cout << "Deseja desativar a sua conta?"
                         << endl;

                    cout << "1 - Sim" << endl;
                    cout << "2 - Nao" << endl;

                    cout << "Digite: ";

                    cin >> alterarConta;


                    if (alterarConta == 1) {

                        contaAtiva[posicaoConta] = false;

                        cout << "Conta desativada com sucesso!"
                             << endl;
                    }

                }
                else {

                    cout << "Sua conta esta desativada!"
                         << endl;

                    cout << "Deseja Ativar?"
                         << endl;

                    cout << "1 - Sim" << endl;
                    cout << "2 - Nao" << endl;

                    cout << "Digite: ";

                    cin >> alterarConta;


                    if (alterarConta == 1) {

                        contaAtiva[posicaoConta] = true;

                        cout << "Conta ativada com sucesso!"
                             << endl;
                    }
                }
            }
            break;
        case 6:
            cout << "Saindo do sistema ..." << endl;
            break;
        default:
            cout << "Opcao invalida! digite um numero de 1 a 6"
                 << endl;

            break;
        }
    } while (opcao != 6);
    return 0;
}