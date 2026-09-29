/*
    Sistema Bancario - Banco INF101
    Nome: Filipe Pereira dos Santos
    Ra: 28787
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Declaracao de Variaveis
int main()
{
    int opcao;
    int numeroConta;
    int tipoConta;
    string cpf;
    string nomeCliente;
    double saldo;
    bool contaAtiva;

    do
    { // Repetição do while

        // Menu
        cout << "\n************";
        cout << "\n* BANCO INF101 *";
        cout << "\n************";
        cout << "\n1 - Cadastrar conta";
        cout << "\n2 - Consultar conta";
        cout << "\n3 - Vericar saldo";
        cout << "\n4 - Alterar tipo da conta";
        cout << "\n5 - Ativar/Desativar conta";
        cout << "\n6 - Sair";

        // Selecionar uma opcao
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        // Limpar o espaso
        cin.ignore();

        switch (opcao)
        {

        case 1: // * Cadastrar conta

            cout << "\n===== CADASTRO =====" << endl;
            // 2 - Leitura de Nome
            cout << "Digite o nome do titular: ";
            getline(cin, nomeCliente);

            // 3 - Validação de CPF (Aceitar exatamente 11 digitos)
            cout << "Digite o numero do seu CPF: ";
            cin >> cpf;

            // validação do CPF para aceitar exatamente 11 digitos
            while (cpf.length() != 11)
            {
                cout << "CPF invalido! Por favor, informe um CPF valido: ";
                cin >> cpf;
            }

            // 4 - Definir Tipo de Conta
            cout << "Escolha o tipo da conta:" << endl;
            cout << "1 - Corrente" << endl;
            cout << "2 - Poupança" << endl;
            cout << "Digite a opção: ";
            cin >> tipoConta;
            // validação do tipo de conta para aceitar apenas 1 ou 2
            while (tipoConta != 1 && tipoConta != 2)
            {
                cout << "Tipo de conta invalido! Por favor, informe um tipo valido: ";
                cin >> tipoConta;
            }

            // 5 - Define o numero da conta
            cout << "Informe o numero da conta: ";
            cin >> numeroConta;
            while (numeroConta <= 0)
            {
                cout << "Numero de conta invalido! Por favor, informe um numero valido: ";
                cin >> numeroConta;
            }

            // 6 - Validação de Saldo
            cout << "Informe qual é seu saldo atual: ";
            cin >> saldo;
            // validação do saldo para aceitar apenas valores positivos
            while (saldo < 0)
            {
                cout << "Saldo invalido! Por favor, informe um saldo valido: ";
                cin >> saldo;
            }
            cout << "Saldo valido! " << endl;

            // 7 - Definir Conta Ativa assim quando criar
            contaAtiva = true;

            // Exibição
            cout << "\n===== CADASTRO FINALIZADO =====" << endl;
            cout << "Nome: " << nomeCliente << endl;
            cout << "CPF: " << cpf << endl;
            cout << "Seu numero de conta: " << numeroConta << endl;
            cout << "Tipo de conta: " << (tipoConta == 1 ? "Corrente" : "Poupança") << endl;
            cout << "Saldo inicial: R$ " << saldo << endl;
            cout << "Situação da conta: "
                 << (contaAtiva ? "Ativa" : "Desativada") << endl;
            break;

        case 2: // *  Consultar conta
            // Implementar a funcionalidade de consulta de conta
            if (contaAtiva)
            {
                cout << "\n===== CONSULTA DE CONTA =====" << endl;
                cout << "Nome do Titular: " << nomeCliente << endl;
                cout << "CPF: " << cpf << endl;
                cout << "Numero da conta: " << numeroConta << endl;
                cout << "Tipo de conta: " << (tipoConta == 1 ? "Corrente" : "Poupança") << endl;
                cout << "Saldo atual: R$ " << saldo << endl;
                cout << "Situação da conta: ";
                cout << "Situaçao da conta: " << (contaAtiva ? "Ativa" : "Desativada") << endl;
            }
            else
            {
                cout << "A conta está desativada. Não é possível consultar." << endl;
            }
            break;

        case 3: // * Vericar Saldo
            if (contaAtiva)
            {
                cout << "\n===== VERIFICAR SALDO =====" << endl;
                cout << "Saldo atual: R$ " << saldo << endl;
            }
            else
            {
                cout << "A conta está desativada. Não é possível verificar o saldo." << endl;
            }

            break;

        case 4: // * Alterar tipo de conta
            if (contaAtiva)
            {
                // menu de alteração do tipo de conta
                cout << "\n===== ALTERAR TIPO DE CONTA =====" << endl;
                cout << "Tipo atual: " << (tipoConta == 1 ? "Corrente" : "Poupança") << endl;
                cout << "Escolha o novo tipo de conta:" << endl;
                cout << "1 - Corrente" << endl;
                cout << "2 - Poupança" << endl;
                cout << "Digite a opção: ";
                cin >> tipoConta;

                // validação do tipo de conta para aceitar apenas 1 ou 2
                while (tipoConta != 1 && tipoConta != 2)
                {
                    cout << "Tipo de conta invalido! Por favor, informe um tipo valido: ";
                    cin >> tipoConta;
                }

                cout << "Tipo de conta alterado com sucesso!" << endl;
            }
            else
            {
                cout << "A conta está desativada. Não é possível alterar o tipo de conta." << endl;
            }
            break;

        case 5: // * Ativar/Desativar
                // menu de ativação/desativação da conta
            if (numeroConta > 0)
            {
                // variável para armazenar a opção do usuário
                int opcaoStatus;
                cout << "\n===== ATIVAR / DESATIVAR CONTA =====" << endl;
                cout << "Status atual: " << (contaAtiva ? "Ativa" : "Desativada") << endl;
                cout << "1 - Ativar conta" << endl;
                cout << "2 - Desativar conta" << endl;
                cout << "Escolha uma opcao: ";
                cin >> opcaoStatus;

                while (opcaoStatus != 1 && opcaoStatus != 2)
                {
                    cout << "Opcao invalida! Digite 1 para Ativar ou 2 para Desativar: ";
                    cin >> opcaoStatus;
                }

                if (opcaoStatus == 1)
                {
                    contaAtiva = true;
                    cout << "Conta ATIVADA com sucesso!" << endl;
                }
                else
                {
                    contaAtiva = false;
                    cout << "Conta DESATIVADA com sucesso!" << endl;
                }
                cout << "====================================\n"
                     << endl;
            }
            else
            {
                cout << "\nErro: Nenhuma conta foi cadastrada ainda!\n"
                     << endl;
            }
            break;

        case 6: // ! Sair
            cout << "\nSaindo do sistema. Obrigado por utilizar o Banco INF101!" << endl;
            break;

        default:
            cout << "Opcao invalida! Por favor, escolha uma opcao de 1 a 6." << endl;
        }

    } while (opcao != 6);
    return 0;
}