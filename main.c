#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//////////////////////////////// estruturas iniciais de data e paciente ///////////////
    struct tmx {

    int tm_mday; //dia do mês de 1 a 31
    int tm_mon; //representa os meses do ano de 0 a 11
    int tm_year; //representa o ano a partir de 1900
    };
    struct tm *data;// estrutura de captura de data do sistema;
   struct Paciente{ // Estrutura de criacao do paciente
    int idade,risco;
    char nome[500],cpf[500],datanasc[500],datadiagn[500],
         email[500],telefone[500],
         cidade[500],estado[500],rua[500],cep[500],numero[500],
         comob1[10],comob2[10],comob3[10],comob4[10],comob5[50000];
     };
  struct Paciente P;

//////////////////////////// Variaveis globais ////////////////////

   int j,cads,diaReal,mesReal,anoReal,tecla,idade,fluxo;
   char cadsCH[1],testaString[500],testoOk[500],ichar;

    int main() //////////principal funcao do software
    {
     CreateDirectory("Pacientes",NULL); ////// cria diretorio qeu funcionara como bando de dados dos pacientes
     CreateDirectory("P_Grupo_de_Risco",NULL);//// cria diretorio que recebera os pacientes de risco
     Hoje();/////////// chama a funcao que captura a data e hora do computador
     system("color b1");/////deine a cor geral de fundo em branco e textos em azul
     loginSenha(); //// Chama a funcao de entrada login e senha
     return 0;
    }
    void Hoje(){  // estrutura de captura de data do sistema;
    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);
    diaReal = data->tm_mday;
    mesReal = data->tm_mon+1;
    anoReal = data->tm_year+1900;
    }
    void loginSenha(){ ///// Funcao Login e senha: desenha a tela de login e senha e ///// solicita login e senha e verifica se esta certo
        char user[50]="Unip";
        char senha[50]= "VacinasSalvam";
        char testeUser[50],testSenha[50];
snh:    system("cls");
        cabecalho();
        margens();
        gotoxy(35,10);
        printf("______________________________________________");
        gotoxy(35,11);
        printf("|                                            |");
        gotoxy(35,12);
        printf("|                                            |");
        gotoxy(35,13);
        printf("|--------------------------------------------|");
        gotoxy(35,14);
        printf("|                                            |");
        gotoxy(35,15);
        printf("|                                            |");
        gotoxy(35,16);
        printf("|                                            |");
        gotoxy(35,17);
        printf("|____________________________________________|");
        gotoxy(43,12);
        printf("DIGITE SEU LOGIN PARA ACESSAR");
        gotoxy(38,14);
        printf("USUARIO:");
        gotoxy(38,16);
        printf("SENHA:");
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        gotoxy(38,20);
        printf("\033[35m\033[1m * DIGITE O USUARIO E TECLE ----'ENTER'----. \033[34m");
        gotoxy(38,22);
        printf("\033[35m\033[1m * DIGITE O SENHA E TECLE ----'ENTER'----. \033[34m");
        fflush(stdin);
        gotoxy(47,14);
        gets(testeUser);
        fflush(stdin);
        gotoxy(45,16);
        gets(testSenha);
        if((strcmp(user,testeUser)==0)&&(strcmp(senha,testSenha)==0))
            MenuPrincipal();//// se estiver correto vai para o menu principal;
        else{ // se nao, mostra que esta incorreto e solicita nova digitação
            for(j=0;j<5;j++)
            {
            gotoxy(38,14);
            printf("                                     ");
            gotoxy(38,16);
            printf("                                     ");
            gotoxy(38,14);
            Sleep(500);
            printf("       USUARIO OU SENHA INCORRETOS");
            gotoxy(38,16);
            printf("          TENTE NOVAMENTE");
            Sleep(500);
            }
            goto snh;
        }
    }
     int MenuPrincipal(){ // menu principal desenha a tela e fornece as opcoes de acao ao operador
     cabecalho();
     printf("\033[1;90m");
     margens();
     gotoxy(75,10);
     printf("\033[35m\033[1m=========              =========");
     gotoxy(74,11);
     printf("|          |        |  |");
     gotoxy(74,12);
     printf("|          |        |  |");
     gotoxy(74,13);
     printf("|          |        |  |");
     gotoxy(75,14);
     printf("========  |        |   ========");
     gotoxy(83,15);
     printf("| |        |           |");
     gotoxy(83,16);
     printf("| |        |           |");
     gotoxy(83,17);
     printf("| |        |           |");
     gotoxy(75,18);
     printf("========   ========    ========");
     gotoxy( 70,19);
     printf("\033[31m============================================ ");
     gotoxy( 73,20);
     printf("=======================================");
     gotoxy( 77,21);
     printf("===============================");
     gotoxy( 85,22);
     printf("\033[1;92m================");
     gotoxy( 85,23);
     printf("================");
     gotoxy( 85,24);
     printf("================");
     gotoxy( 85,25);
     printf("================");
     gotoxy( 85,26);
     printf("================");
     gotoxy( 85,27);
     printf("================");
     gotoxy( 85,28);
     printf("================\033[34m");
     gotoxy( 70,9);
     printf("\033[31m============================================ ");
     gotoxy( 73,8);
     printf("=======================================");
     gotoxy( 77,7);
     printf("===============================");
     gotoxy( 85,6);
     printf("\033[1;92m================\033[34m");
     gotoxy( 5,9);
     printf("\033[1;95m---< BEM VINDO AO CAD-DIGITAL SUS, DIGITE: >--<   >----");
     gotoxy( 10,12);
     printf("1 - PARA FAZER UM NOVO CADASTRO.");
     gotoxy( 10,14);
     printf("2 - PARA CONSULTAR O CADASTRO DE UM PACIENTE.");
     gotoxy( 10,16);
     printf("3 - PARA APAGAR O CADASTRO DE UM PACIENTE.");
     gotoxy( 10,18);
     printf("4 - INFORMACOES DO SOFTWARE");
     gotoxy( 10,20);
     printf("5 - SAIR");
     gotoxy( 43,10);
     gotoxy(10,2);
     printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
     gotoxy(53,9);
     tecla=getch();
     fflush(stdin);
     switch(tecla){ // Verifica a tecla prescionada e direciona para a funcao requerida pelo operador
     case 49: // digito 1
        fluxo=0;
        cadastraDadosPessoais();
        break;
     case 50: // digito 2
        capturaDados();
        break;
     case 51: // digito 3
       deleletarCadastro();
        return 0;
        break;
    case 52: // digito 4
       InfoSystema();
        return 0;
        break;
    case 53: // digito 5
        cabecalho();
        printf("\033[1;90m");
        margens();
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        gotoxy(10,10);
        printf("\033[35m\033[1m VOLTE SEMPRE!");
        gotoxy(10,26);
        exit(0);
        return 0;
        break;
    default:
     system("cls");
     printf("\n\n\n\n\n\n                                   Caracter invalido!, tente novamente \n\n\n\n\n");
     system("pause");
     MenuPrincipal();
     break;
    }
    return 0;
  }
     int InfoSystema(){ // desenha na tela a infos do software

     sis: cabecalho();
     printf("\033[1;90m");
     margens();
     gotoxy(75,10);
     printf("\033[35m\033[1m=========              =========");
     gotoxy(74,11);
     printf("|          |        |  |");
     gotoxy(74,12);
     printf("|          |        |  |");
     gotoxy(74,13);
     printf("|          |        |  |");
     gotoxy(75,14);
     printf("========  |        |   ========");
     gotoxy(83,15);
     printf("| |        |           |");
     gotoxy(83,16);
     printf("| |        |           |");
     gotoxy(83,17);
     printf("| |        |           |");
     gotoxy(75,18);
     printf("========   ========    ========");
     gotoxy( 70,19);
     printf("\033[31m============================================ ");
     gotoxy( 73,20);
     printf("=======================================");
     gotoxy( 77,21);
     printf("===============================");
     gotoxy( 85,22);
     printf("\033[1;92m================");
     gotoxy( 85,23);
     printf("================");
     gotoxy( 85,24);
     printf("================");
     gotoxy( 85,25);
     printf("================");
     gotoxy( 85,26);
     printf("================");
     gotoxy( 85,27);
     printf("================");
     gotoxy( 85,28);
     printf("================\033[34m");
     gotoxy( 70,9);
     printf("\033[31m============================================ ");
     gotoxy( 73,8);
     printf("=======================================");
     gotoxy( 77,7);
     printf("===============================");
     gotoxy( 85,6);
     printf("\033[1;92m================\033[34m");
     gotoxy( 5,10);
     printf("\033[35m\033[1mUNIVERSIDADE PAULISTA UNIP EaD");
     gotoxy( 5,12);
     printf("CURSO SUP. DE TEC. EM ANALISE E DESENVOLVIMENTO DE SISTEMAS");
     gotoxy( 5,14);
     printf("PROJETO INTEGRADO MULTIDISCIPLINAR - PIM IV");
     gotoxy( 5,16);
     printf("ALUNO: RAFAEL JUNGES");
     gotoxy( 5,18);
     printf("RA: 2173421");
     gotoxy(10,2);
     printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
     gotoxy(5,24);
     system("pause");
     MenuPrincipal();
    return 0;
  }
    void gotoxy(int x, int y){ // importante funcao q permite navegar com o cursor dentro da tela
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    }
    void consultar(){ //desenha tela de consulta
     system("cls");
     cabecalho();
     printf("\033[1;90m");
     margens();
        gotoxy(17,10);
        printf("___________________________________________________________________________________");
        gotoxy(17,11);
        printf("|                                                                                  |");
        gotoxy(17,12);
        printf("|                                                                                  |");
        gotoxy(17,13);
        printf("|----------------------------------------------------------------------------------|");
        gotoxy(17,14);
        printf("|                                                                                  |");
        gotoxy(17,15);
        printf("|                                                                                  |");
        gotoxy(17,16);
        printf("|                                                                                  |");
        gotoxy(17,17);
        printf("|__________________________________________________________________________________|");
        gotoxy(34,12);
        printf("DIGITE O NOME COMPLETO DO PACIENTE SEM ABREVIACOES");
    }
    void deleletarCadastro(){// desenha na tela a tela de deletar busca o arquivo e deleta se encontrado
     char extencao[10] = ".txt"; // extensao do arquivo a ser gerado
     char caminho[500]="Pacientes/"; // pasta local onde estao os arquivo dos pacientes
     char pesquisa[500];
     char texto[1000];
     FILE *arquivo;
     int w;
        consultar();
        gotoxy(17,6);
        printf("\033[31m___________________________________________________________________________________");
        gotoxy(17,7);
        printf("|\033[31m\033[1;103m                                                                                  |");
        gotoxy(17,8);
        printf("|                                                                                  |");
        gotoxy(17,9);
        printf("|__________________________________________________________________________________|");
        gotoxy(29,8);
        printf("\033[31m\033[1m------------------< BUSCAR E APAGAR ARQUIVO >------------------\033[34m\033[1;107m");
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\n",diaReal, mesReal ,anoReal);
        zeraTesteOK(); // esvasia a variavel teste ok
        testaSohCaracteres(20 ,15); // captura teclado e testa se sao soh caracteres
        strcpy(pesquisa, testoOk); // coloca a strinq aprovada na variavel pesquisa
        strcat(pesquisa,extencao); // concatena oq havia a em pesquisa com a extensao .txt
        strcat(caminho,pesquisa);  // concatena oq havia a em caminho com pesquisa e forma o caminho completo do arquivo
        arquivo = fopen(caminho,"r"); // procura arquivo digitado, se acha abre para leitura se nao, retorna NULL;
        fclose(arquivo); // fecha o arquivo
        if(arquivo!=NULL) // caso enconte o conteudo de arquivo é diferente de NULL e apaga arquivo
        {
           system("cls");
           cabecalho();
           margens();
           gotoxy(10,2);
           printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
           gotoxy(10,10);
           remove(caminho);
           printf("\033[31m\033[1;103m            Cadastro removido com sucesso!    \033[1;107m");
           gotoxy(55,10);
           system("pause");
        }else{ // caso nao enconte o arquivo retorna Null, mostra na tela arquivo nao encontrado
               system("cls");
               cabecalho();
               margens();
               gotoxy(10,2);
               printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
               gotoxy(10,10);
               printf("\033[31m\033[1;103m            Arquivo nao encontrado!       \033[1;107m");
              gotoxy(50,10);
              system("pause");
             }
        MenuPrincipal();
    }
    void capturaDados(){ //Captura os dados dos arquivos criados e printa na tela
     char extencao[10] = ".txt"; // extensao do arquivo a ser procurado
     char caminho[500]="Pacientes/"; // pasta onte estao os arquivos dos pacientes
     char pesquisa[500],texto[1000];
     int w;
     char aux0[500],aux1[500],aux2[500],aux3[500],aux4[500],aux5[500],aux6[500],aux7[500],aux8[500],
     aux9[500],aux10[500],aux11[500],aux12[500],aux13[500],aux14[500],aux15[500],aux16[500],aux17[500];
     FILE *arquivo;
        consultar();
        gotoxy(17,6);
        printf("___________________________________________________________________________________");
        gotoxy(17,7);
        printf("|                                                                                  |");
        gotoxy(17,8);
        printf("|                                                                                  |");
        gotoxy(17,9);
        printf("|__________________________________________________________________________________|");
        gotoxy(29,8);
        printf("\033[35m\033[1m------------------< BUSCAR E LER ARQUIVO >------------------\033[34m");
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        zeraTesteOK(); // esvasia a variavel teste ok
        testaSohCaracteres(20 ,15); // captura teclado e testa se sao soh caracteres
        strcpy(pesquisa, testoOk); // coloca a strinq aprovada na variavel pesquisa
        strcat(pesquisa,extencao); // concatena oq havia a em pesquisa com a extensao .txt
        strcat(caminho,pesquisa); // concatena oq havia a em caminho com pesquisa e forma o caminho completo do arquivo
        arquivo = fopen(caminho,"r"); // procura arquivo digitado, se acha abre para leitura se nao, retorna NULL;
        if(arquivo!=NULL) // Caso arquivo nao esta vazio
        {
                    for(w=0;w<18;w++) // pesquisa linha a linha do arquivo do paciente,  coloca o valor string de cada linha, nas variaveis aux
                    {
                        fgets(texto,1000,arquivo);
                        if(w==0)
                            strcpy(aux0,texto);
                        if(w==1)
                            strcpy(aux1,texto);
                        if(w==2)
                            strcpy(aux2,texto);
                        if(w==3)
                            strcpy(aux3,texto);
                        if(w==4)
                            strcpy(aux4,texto);
                        if(w==5)
                            strcpy(aux5,texto);
                        if(w==6)
                            strcpy(aux6,texto);
                        if(w==7)
                            strcpy(aux7,texto);
                        if(w==8)
                            strcpy(aux8,texto);
                        if(w==9)
                            strcpy(aux9,texto);
                        if(w==10)
                            strcpy(aux10,texto);
                        if(w==11)
                            strcpy(aux11,texto);
                        if(w==12)
                            strcpy(aux12,texto);
                        if(w==13)
                            strcpy(aux13,texto);
                        if(w==14)
                            strcpy(aux14,texto);
                        if(w==15)
                            strcpy(aux15,texto);
                        if(w==16)
                            strcpy(aux16,texto);
                        if(w==17)
                            strcpy(aux17,texto);
                    }
                    // Limpa a tela escre textos dos campos e coloca os valores capturaod acima nos campos corretamente
                    system("cls");
                    cabecalho();
                    margens();
                    gotoxy(10,2);
                    printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
                    gotoxy(7,8);
                    printf("Nome:");
                    gotoxy(7,10);
                    printf("Cpf:");
                    gotoxy(7,12);
                    printf("Data de nascimento:");
                    gotoxy(45,12);
                    printf("Idade:");
                    gotoxy(56,12);
                    printf("anos");
                    gotoxy(55,14);
                    printf("Email:");
                    gotoxy(7,14);
                    printf("Telefone:");
                    gotoxy(7,16);
                    printf("CEP:");
                    gotoxy(7,18);
                    printf("Estado:");
                    gotoxy(55,18);
                    printf("Cidade:");
                    gotoxy(7,20);
                    printf("Rua:");
                    gotoxy(85,20);
                    printf("Numero:");
                    gotoxy(7,22);
                    printf("Data do diagnostico:");
                    gotoxy(7,24);
                    printf("Diabetes:                Obesidade:                Hipertensao:                Tuberculose:");
                    gotoxy(7,26);
                    printf("Outros:");
                    gotoxy(13,8);
                    printf("\033[31m%s",aux0);
                    gotoxy(12,10);
                    printf("%s",aux1);
                    gotoxy(27,12);
                    printf("%c%c/%c%c/%c%c%c%c",aux2[0],aux2[1],aux2[2],aux2[3],aux2[4],aux2[5],aux2[6],aux2[7]);
                    gotoxy(52,12);
                    printf("%s",aux3);
                    gotoxy(56,12);
                    printf("anos");
                    gotoxy(17,14);
                    printf("%s",aux5);
                    gotoxy(62,14);
                    printf("%s",aux4);
                    gotoxy(12,16);
                    printf("%s",aux6);
                    gotoxy(15,18);
                    printf("%s",aux7);
                    gotoxy(63,18);
                    printf("%s",aux8);
                    gotoxy(12,20);
                    printf("%s",aux9);
                    gotoxy(93,20);
                    printf("%s",aux10);
                    gotoxy(28,22);
                    printf("%c%c/%c%c/%c%c%c%c",aux11[0],aux11[1],aux11[2],aux11[3],aux11[4],aux11[5],aux11[6],aux11[7]);
                    gotoxy(18,24);
                    printf("%s",aux12);
                    gotoxy(45,24);
                    printf("%s",aux13);
                    gotoxy(71,24);
                    printf("%s",aux14);
                    gotoxy(101,24);
                    printf("%s",aux15);
                    gotoxy(15,26);
                    printf("%s",aux16);
                    if(aux17[0]=='1')
                    {
                       gotoxy(68,12);
                       printf("\033[1;103m\033[1;32m    NAO PERTENCE AO GRUPO DE RISCO    \033[1;107m\033[31m");
                    }
                    else{
                       gotoxy(68,12);
                       printf("\033[31m\033[1;103m    PACIENTE PERTENCENTE AO GRUPO DE RISCO    \033[1m\033[31m\033[1;107m",P.idade);
                    }
                    gotoxy(7,28);
                    fclose(arquivo);
                    system("pause");
                    MenuPrincipal();
        }else{  // caso nao encontre o arquivo o retorno da variavel arquivo é NULL e o software printa arquivo nao encontrado
               system("cls");
               cabecalho();
               margens();
               gotoxy(10,2);
               printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
               gotoxy(10,10);
               printf("\033[31m\033[1;103m            Arquivo nao encontrado!       \033[1;107m");
              gotoxy(50,10);
              fclose(arquivo);
              system("pause");
              MenuPrincipal();
             }
    }

    void cadastraDadosPessoais(){ // desenha a tela de cad pessoal e captura do teclado o valor dos campos
        cabecalho();
        linhacheia2();                                                                                                                //
        linhaPontas2();
        linhaPontas2();
        printf("|               ENTER - CONFIRMA CAMPO DIGITADO            |               ESQ - APAGA CAMPO DIGITADO                 |\n");
        linhaPontas3();
        linhaPontas2();
        printf("|    \033[33mCAD PESSOAL - ANDAMENTO \033[34m|    \033[31mCAD ENDERECO - N PREENCHIDO \033[34m|    \033[31mCAD COMORBIDADES - N PREENCHIDO \033[34m|                  |\n");
        printf("|                            |________________________________________________________________________________________|\n");
        linhaPontas2();
        linhaPontas2();
        printf("|   Nome completo: \n");
        linhaPontas3();
        printf("\n|   CPF(Somente numeros 11122233344): \n");
        linhaPontas3();
        printf("\n|   Data de Nascimento (DDMMAAAA): \n");
        linhaPontas3();
        printf("\n|   Telefone para contato(51988888888): \n");
        linhaPontas3();
        printf("\n|   Email: \n");
        linhaPontas3();
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        printf("\033[31m");
        zeraTesteOK(); // zera a variavel testeok
        testaSohCaracteres(19 ,15);      // testa para aceitar somente caractres
        strcpy(P.nome, testoOk);      // coloca o valor de testeok - q foi aprovado no teste - em P[i].nome
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohNumeros(38 ,18,11);            // testa para acaeitar somente numeros
        strcpy(P.cpf, testoOk);          // coloca o valor testado em - em P.cpf
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaData(35 ,21); // testa para acaeitar somente numeros
        strcpy(P.datanasc, testoOk); // coloca o valor testado em - em P.datanasc
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohNumeros(40,24,11); // testa para acaeitar somente numeros
        strcpy(P.telefone, testoOk); // coloca o valor testado em - em P.telefone
         fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testecampoVazio(11,27); // testa para acaeitar somente se o campo nao estiver vazio
        strcpy(P.email, testoOk); // coloca o valor testado em - em P.email
        fflush(stdin); // zera buffer de teclado
        if(fluxo==0) // direciona o fluxo do programa, 0 para o proximo cad ou 1 para imprime cad
        refazCad(1); // vai para o cad endereço
        else
        refazCad(4); // vai para o imprime cad
    }
    void cadastroEndereco(){ // desenha a tela de cad endereco e captura do teclado o valor dos campos
        cabecalho();
        linhacheia2();
        linhaPontas2();
        printf("|       ENTER - CONFIRMA CAMPO DIGITADO       |       ESQ - APAGA CAMPO DIGITADO       |\n");
        linhaPontas3();
        linhaPontas2();
        linhaPontas2();
        printf("|   \033[32m CAD PESSOAL - OK     \033[34m   |    \033[33mCAD ENDERECO - ANDAMENTO   \033[34m |    \033[31mCAD COMORBIDADES - N PREENCHIDO \033[34m|                  |\n");
        printf(" ____________________________|                                |_______________________________________________________|\n");
        linhaPontas2();
        linhaPontas2();
        printf("|   CEP(12345678): \n");
        linhaPontas3();
        printf("\n|   Estado:\n");
        linhaPontas3();
        printf("\n|   Cidade:\n");
        linhaPontas3();
        printf("\n|   Rua:\n");
        linhaPontas3();
        printf("\n|   Numero:\n");
        linhaPontas3();
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        printf("\033[31m");
        zeraTesteOK(); // zera a variavel testeok
        testaSohNumeros(19 ,15,8); // testa para acaeitar somente numeros
        strcpy(P.cep, testoOk); // coloca o valor testado em - em P.cep
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohCaracteres(12 ,18); // testa para aceitar somente caractres
        strcpy(P.estado, testoOk); // coloca o valor de testeok - q foi aprovado no teste - em P.estado
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohCaracteres(12 ,21); // testa para aceitar somente caractres
        strcpy(P.cidade, testoOk); // coloca o valor de testeok - q foi aprovado no teste - em P.cidade
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohCaracteres(9, 24); // testa para aceitar somente caractres
        strcpy(P.rua, testoOk); // coloca o valor de testeok - q foi aprovado no teste - em P.rua
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a variavel testeok
        testaSohNumeros(12 , 27,0); // testa para acaeitar somente numeros
        strcpy(P.numero, testoOk); // coloca o valor testado em - em P.numero
        fflush(stdin); // zera buffer de teclado
        if(fluxo==0) // direciona o fluxo do programa, 0 para o proximo cad ou 1 para imprime cad
        refazCad(6); // vai para o cad comob
        else
        refazCad(2); // vai para o imprime cad
    }
    void cadastroComob(){ // desenha a tela de cad comob e captura do teclado o valor dos campos
        cabecalho();
        linhacheia2();
        linhaPontas2();
        printf("|       ENTER - CONFIRMA CAMPO DIGITADO       |       ESQ - APAGA CAMPO DIGITADO       |\n");
        linhaPontas3();
        linhaPontas2();
        linhaPontas2();
        printf("|    \033[32mCAD PESSOAL - OK        \033[34m|    \033[32mCAD ENDERECO - OK           \033[34m|    \033[33mCAD COMORBIDADES - ANDAMENTO  \033[34m|                    |\n");
        printf(" _____________________________________________________________|                                  |____________________|\n");
        linhaPontas2();
        printf("|        \033[1;90m PARA OS ITENS COM '*' ----------<  Digite 'S' para SIM e 'N' para NAO  >-------------\033[34m                        \n");
        linhaPontas3();
        printf("\n|   DATA DO DIAGNOSTICO (DDMMAAAA):              \n");
        linhaPontas3();
        printf("\n|   \033[1;90m*DIABETES:\033[34m                                               \033[1;90m*OBESIDADE:\033[34m                                             \n");
        linhaPontas3();
        printf("\n|   \033[1;90m*HIPERTENSAO:\033[34m                                            \033[1;90m*TUBERCULOSE:\033[34m                                           \n");
        linhaPontas3();
        printf("\n|   OUTROS:                                                                                                          \n");
        linhaPontas3();
        gotoxy(10,2);
        printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
        printf("\033[31m");
        zeraTesteOK(); // zera a testeOk
        testeData2(36 ,17);  // testa para acaeitar somente numeros
        strcpy(P.datadiagn, testoOk); // coloca o valor testado em - em P.datadiagn
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK();  // zera a testeOk
        testaSN(15 ,20); // testa para acaeitar somente "S" ou "N"
        strcpy(P.comob1, testoOk); // coloca o valor testado em - em P.comob1
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a testeOk
        testaSN(73 ,20); // testa para acaeitar somente "S" ou "N"
        strcpy(P.comob2, testoOk); // coloca o valor testado em - em P.comob2
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a testeOk
        testaSN(18 ,23); //// testa para acaeitar somente "S" ou "N"
        strcpy(P.comob3, testoOk); // coloca o valor testado em - em P.comob3
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a testeOk
        testaSN(75,23); // testa para acaeitar somente "S" ou "N"
        strcpy(P.comob4, testoOk); // coloca o valor testado em - em P.comob4
        fflush(stdin); // zera buffer de teclado
        zeraTesteOK(); // zera a testeOk
        testecampoVazio(12,26); // testa para acaeitar somente campo nao vaziu
        strcpy(P.comob5, testoOk); // coloca o valor testado em - em P.comob5
        fflush(stdin); // zera buffer de teclado
        refazCad(3); // vai para impreme cadastro
    }
    void refazCad(int c){ // Essa funcao permite refazer um cadastro, ela recebe um valor inteiro
                         //que serve de guia de fluxo para qual tela deve ir
        system("color e4");
ini2:    for(j=0;j<3;j++)
         {
         gotoxy(1,6);
         printf("\033[41m                                                                                                                      ");
         gotoxy(1,7);
         printf("\033[41m                                                                                                                      ");
         gotoxy(1,8);
         printf("\033[41m                                                                                                                      ");
         Sleep(100);
         gotoxy(1,7);
         printf("          \033[37m     \033[41m \033[1m Confirma formulario em - 'S' - ou Edite ele em  - 'N' -                                              ");
         Sleep(200);
         }
         gotoxy(44,7);
         tecla=getch();
         if((tecla==115)||(tecla==83)) // le teclado e analiza o retorno, 115 e 83 = a 's' e 110 e 78 = a 'n',
         {                             // de acordo com o valor recebido na int c, guia para a tela requerida
             if(c==1)
              cadastroEndereco();
             if(c==2)
              imprimeCadastro();
             if((c==3)||(c==4))
              imprimeCadastro();
             if(c==6)
                cadastroComob();
             system("color f1");
         }
         else if((tecla==110)||(tecla==78))
         {
            if(c==1)
                cadastraDadosPessoais();
            if(c==2)
                cadastroEndereco();
            if(c==3)
                cadastroComob();
            if(c==4)
             cadastraDadosPessoais();
            if(c==6)
              cadastroEndereco();
            system("color f1");
         }
         else
            goto ini2;
    }
    void imprimeCadastro(){ // essa função print na tela os dados recem criados e permite 5 osoes de acao
     fluxo=1;
    cabecalho();
    printf("|                                                                                                                     |\n");
    printf("|               1 - PARA SALVAR O CADASTRO         |         5 - PARA APAGAR TODO O CADASTRO DESTA FICHA              |\n");
    printf("|                                                                                                                     |\n");
    printf("|      2 - PARA EDITAR CAD PESSOAL    |     3 - PARA EDITAR CAD ENDERECO    |     4 - PARA EDITAR CAD COMORBIDADES    |\n");
    linhaPontas3();
    printf("\033[1;94m");
     gotoxy(3,11);
     printf("Nome:");
     gotoxy(3,13);
     printf("CPF:");
     gotoxy(25,13);
     printf("Data de nasciemnto:");
     gotoxy(03,15);
     printf("Telefone:");
     gotoxy(50,15);
     printf("Email:");
     gotoxy(03,17);
     printf("CEP:");
     gotoxy(03,19);
     printf("Estado:");
     gotoxy(65,19);
     printf("Cidade:");
     gotoxy(03,21);
     printf("Rua:");
     gotoxy(77,21);
     printf("Numero:");
     gotoxy(03,23);
     printf("Data do diagnostico:");
     gotoxy(03,25);
     printf("Diabetes:                    Obesidade:                    Hipertencao:                    Tuberculose:");
     gotoxy(03,27);
     printf("Outros:\n");
     linhaPontas3();
     printf("\033[31m");
     gotoxy(9,11);
     printf("\033[1;31m%s\033[1;34m",P.nome);
     gotoxy(8,13);
     printf("\033[1;31m%s\033[1;34m",P.cpf);
     gotoxy(45,13);
     printf("\033[1;31m%c%c/%c%c/%c%c%c%c", P.datanasc[0],P.datanasc[1],P.datanasc[2],P.datanasc[3],P.datanasc[4],P.datanasc[5],P.datanasc[6],P.datanasc[7]);
     gotoxy(57,13);
     printf("\033[1;31m%d anos de idade\033[1;34m",P.idade);
     if(idade>65){
         gotoxy(78,13);
         printf("\x1b[31m\033[1;103m PACIENTE PERTENCENTE AO GRUPO DE RISCO \033[1m\033[31m\033[1;107m",P.idade);}
      gotoxy(13,15);
      printf("\033[1;31m%s\033[1;34m",P.telefone);
      gotoxy(57,15);
      printf("\033[1;31m%s\033[1;34m",P.email);
      gotoxy(8,17);
      printf("\033[1;31m%s\033[1;34m",P.cep);
      gotoxy(11,19);
      printf("\033[1;31m%s\033[1;34m",P.estado);
      gotoxy(73,19);
      printf("\033[1;31m%s\033[1;34m",P.cidade);
      gotoxy(8,21);
      printf("\033[1;31m%s\033[1;34m",P.rua);
      gotoxy(85,21);
      printf("\033[1;31m%s\033[1;34m",P.numero);
      gotoxy(24,23);
      printf("\033[1;31m%c%c/%c%c/%c%c%c%c", P.datadiagn[0],P.datadiagn[1],P.datadiagn[2],P.datadiagn[3],P.datadiagn[4],P.datadiagn[5],P.datadiagn[6],P.datadiagn[7]);
      gotoxy(13,25);
      printf("\033[1;31m%s\033[1;34m",P.comob1);
      gotoxy(43,25);
      printf("\033[1;31m%s\033[1;34m",P.comob2);
      gotoxy(75,25);
      printf("\033[1;31m%s\033[1;34m",P.comob3);
      gotoxy(107,25);
      printf("\033[1;31m%s\033[1;34m",P.comob4);
      gotoxy(11,27);
      printf("\033[1;31m%s\033[1;34m",P.comob5);
    gotoxy(10,2);
    printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
    verificaNum(16,6); // verifica qual numero e guia para a acao digitado
    return 0;
    }

    void verificaNum(int x, int y){ // verifica qual numero e guia para a acao digitado

    char extencao[10] = ".txt";
    char caminho[500]="Pacientes/";
    char caminho2[500]="P_Grupo_de_Risco/Pacientes do grupo de risco do dia - ";
    char traco[10] = "-";
    char aux[500];
     char aux2[500];
    FILE *arquivo;
    FILE *arquivo2;
    arquivo = NULL;
    arquivo2 = NULL;
    char data1[10];
    char data2[10];
    char data3[10];
             v: tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla==49) // digitado 1
                {   cabecalho();
                    margens();
                    gotoxy(10,2);
                    printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
                        strcpy(aux,P.nome); // o arquivo é criado com o nome guardado na variavel P.nome
                        strcat(aux,extencao);
                        strcat(caminho,aux);
                    arquivo = fopen(caminho,"w"); // cria arquivo e salva o os dados nele
                    fprintf(arquivo,"%s\n",P.nome);
                    fprintf(arquivo,"%s\n",P.cpf);
                    fprintf(arquivo,"%s\n",P.datanasc);
                    fprintf(arquivo,"%d\n",P.idade);
                    fprintf(arquivo,"%s\n",P.email);
                    fprintf(arquivo,"%s\n",P.telefone);
                    fprintf(arquivo,"%s\n",P.cep);
                    fprintf(arquivo,"%s\n",P.estado);
                    fprintf(arquivo,"%s\n",P.cidade);
                    fprintf(arquivo,"%s\n",P.rua);
                    fprintf(arquivo,"%s\n",P.numero);
                    fprintf(arquivo,"%s\n",P.datadiagn);
                    fprintf(arquivo,"%s\n",P.comob1);
                    fprintf(arquivo,"%s\n",P.comob2);
                    fprintf(arquivo,"%s\n",P.comob3);
                    fprintf(arquivo,"%s\n",P.comob4);
                    fprintf(arquivo,"%s\n",P.comob5);
                    fprintf(arquivo,"%d\n",P.risco);
                    fclose(arquivo);
                    gotoxy(10,10);
                    printf("\033[31m\033[1mCadastro salvo com sucesso!");
                    if(idade>65){ // caso idade maior q 65 sava cep e idade em arquivo separado
                        itoa(diaReal,data1,10);
                        itoa(mesReal,data2,10);
                        itoa(anoReal,data3,10);
                        strcat(data1,traco);
                        strcat(data1,data2);
                        strcat(data1,traco);
                        strcat(data1,data3);
                        strcat(caminho2,data1);
                        strcat(caminho2,extencao);
                        arquivo2 = fopen(caminho2,"a");
                        fprintf(arquivo,"|----------------------------------------------------------------------|\n\n");
                        fprintf(arquivo,"   Idade do paciente: %d anos\n\n",P.idade);
                        fprintf(arquivo,"   CEP: %s \n\n",P.cep);
                        fprintf(arquivo,"|----------------------------------------------------------------------|\n\n");
                        fclose(arquivo2);
                    }
                    gotoxy(40,10);
                    system("pause");
                    MenuPrincipal();
                }
                if(tecla==50) // digitado 2 chama cad pessoal para edicao
                    cadastraDadosPessoais();
                if(tecla==51) // digitado 3 chama cad endereco para edicao
                    cadastroEndereco();
                if(tecla==52) // digitado 4 chama cad comob para edicao
                    cadastroComob();
                if(tecla==53) // digitado 5 zera cad
                 zeraCadastro();
                goto v;
        }

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void zeraCadastro(){ // Zera todos os dados do digitados
        system("color e4");
        gotoxy(0,10);
        printf("\033[41m                                                                                                                       \n");
        printf("\033[41m\033[37m\033[1m              TEM CERTEZA QUE VOCE QUER APAGAR TODO ESSE CADASTRO?  9 PARA SIM | \033[37mQUALQUER TECLA PARA SAIR \033[33m|           |\n");
        printf("\033[41m                                                                                                                       \n");
        gotoxy(84,11);
        tecla=getch();
        fflush(stdin);
        if(tecla==57)
        {
        zeraTesteOK();
        strcpy(P.nome, testoOk);
        strcpy(P.cpf, testoOk);
        strcpy(P.datanasc, testoOk);
        strcpy(P.datadiagn, testoOk);
        strcpy(P.telefone, testoOk);
        strcpy(P.email, testoOk);
        strcpy(P.cep, testoOk);
        strcpy(P.estado, testoOk);
        strcpy(P.cidade, testoOk);
        strcpy(P.rua, testoOk);
        strcpy(P.numero, testoOk);
        strcpy(P.comob1, testoOk);
        strcpy(P.comob2, testoOk);
        strcpy(P.comob3, testoOk);
        strcpy(P.comob4, testoOk);
        strcpy(P.comob5, testoOk);
        P.idade=0;
        P.risco=0;
        idade=0;
        system("cls");
                    cabecalho();
                    margens();
                    gotoxy(10,2);
                    printf("\033[35m\033[1m-< CADASTRAMENTO DE PACIENTE DIAGNOSTICADO COM COVID-19 >----------------< DATA: %d - %d - %d >--\033[34m\n",diaReal, mesReal ,anoReal);
                    gotoxy(10,15);
                    printf("Cadastro APAGADO com sucesso!  ");
                    system("pause");
                    MenuPrincipal();
        }
        else if(tecla!=0)
            imprimeCadastro();
    }

    void cabecalho(){ // funcao auxiliar desenha cabeçalho
        system("cls");
        system("color F1");
        linhacheia1();
        linhaPontas1();
        linhaPontas1();
        linhaPontas1();
        linhacheia1();
    }

    void margens(){ // funcao auxiliar desenha margens
        linhacheia2();                                                                                                                //
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas2();
        linhaPontas3();
    }

    void linhacheia1(){ // funcao auxiliar desenha linha cheia com #
             for(j=0;j<119;j++)    // constroe linha cheia
           {
               printf("#");
           }
            printf("\n");
    return 0;
    }

    void linhaPontas1(){ // funcao auxiliar desenha linha com # nas pontas e ' ' no meio

            for(j=0;j<119;j++)     // constroe linha pontas
        {
            if((j<=7)||(j>110))
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
        return 0;
    }

    void linhacheia2(){ // funcao auxiliar desenha linha cheia com '_'
           printf(" ");
             for(j=0;j<117;j++)    // constroe linha cheia
           {
               printf("_");
           }
            printf("\n");
    return 0;
    }

    void linhaPontas2(){ // funcao auxiliar desenha linha com | nas pontas e ' ' no meio

            for(j=0;j<119;j++)     // constroe linha pontas
        {
            if((j<1)||(j>117))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
        return 0;
    }

    void linhaPontas3(){ // funcao auxiliar desenha linha com '|' nas pontas e ' _' no meio

            for(j=0;j<119;j++)     // constroe linha pontas
        {
            if((j<1)||(j>117))
                printf("|");
            else
                printf("_");
        }
        printf("\n");
        return 0;
    }

   void testaSN(int x, int y ){ // Verifica para aceitar somente caracter "S" ou "N"
    char testeInternoCh[500];
    int comprimento = 0;
  ini3:     gotoxy(x,y);
            gets(testeInternoCh);
            fflush(stdin);
            comprimento =strlen(testeInternoCh);
            if((comprimento==0)||(comprimento>1)){
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m CARACTER INVALIDO!");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                          ");
                goto ini3;
             }
             else if(comprimento==1){
                    if((testeInternoCh[0]=='S')||(testeInternoCh[0]=='s')||(testeInternoCh[0]=='n')||(testeInternoCh[0]=='N'))
                    {
                      strcpy(testoOk, testeInternoCh);
                    }
                    else{
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m CARACTER INVALIDO!");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                          ");
                goto ini3;
                    }
             }
    }
   void zeraTesteOK(){ // zera a variavel auxiliar TesteoK
        for(j=0; j < strlen(testoOk);j++){ // zera testeok antes - caso haja sujeira de codigo
        testoOk[j]='\0';
        }
   }
   void testecampoVazio(int x, int y){ // Verifica se o campo esta vazio e solicita digitacao

    char testeInternoCh[500];
    int comprimento = 0;
  ini3:     gotoxy(x,y);
            gets(testeInternoCh);
            fflush(stdin);
            comprimento =strlen(testeInternoCh);
            if(comprimento==0){
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m CAMPO REQUERIDO! -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                           ");
                goto ini3;
             }
             else{
                strcpy(testoOk, testeInternoCh);
             }
   }

   void testaSohCaracteres(int x, int y){ // Verifica se o campo foram digitados somente caracteres
        char testeInternoCh[500];
        int resultAx=0;
        int resultX=0;
        int comprimento;
        do{
            gotoxy(x,y);
            gets(testeInternoCh); // captura texto do teclado
            fflush(stdin); // apaga buffer de teclado
            comprimento =strlen(testeInternoCh); // avalia o comprimento da string
            if(comprimento==0){ // caso igual a zero, o campo esta vazio, solicita nova digitação
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m CAMPO REQUERIDO! -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                           ");
            }
            else{ // caso comprimento maior que zero avalia se sao somente caracteres
                for(j=0; j < comprimento;j++){
                if((isalpha(testeInternoCh[j]))||(isblank(testeInternoCh[j])))
                {
                    resultAx=0;
                }
                else{ resultAx=1; // achando um caracter sai do IF
                      break;
                    }
            }
            if(resultAx>0) // solicita nova digitação
            {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m DIGITE SOMENTE TEXTO AQUI -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                           ");
                j=0;
            }
            else{
                strcpy(testoOk, testeInternoCh); // aceita a string digitada e coloca na var testeOK
                for(j=0; j <= comprimento;j++){  // esvasia a var testeinterno
                   testeInternoCh[j]='\0';
                }
                resultX=1; // encerra o teste
            }
          }
        }
        while(resultX==0);
    }
    void testaSohNumeros(int x, int y, int c){ // Verifica se o campo foram digitados somente numeros, e recebe o tamanho da string

    char testeInternoCh[500];
        int resultAx=0;
        int resultX=0;
        int comprimento;

  rec:  do{
            for(j=0; j < strlen(testeInternoCh);j++){ // zera testeInternoCh
            testeInternoCh[j]='\0';}
            gotoxy(x,y);
            gets(testeInternoCh); // captura texto do teclado
            fflush(stdin); // apaga buffer de teclado
            comprimento =strlen(testeInternoCh); // avalia o comprimento da string
            if(comprimento==0){ // caso igual a zero, campo vazio,  solicita nova digitação
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m REQUERIDO ");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m               ");
            }
            else{
                for(j=0; j < comprimento;j++){
                if(isalpha(testeInternoCh[j]))
                {
                    resultAx=1;
                    j=comprimento;
                }
                else{ resultAx=0;}
            }
            if(resultAx>0)
            {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m SOMENTE NUMEROS ");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                 ");
                j=0;
            }
            else{
                if(c==0) // avalia se C for igual a zero independe o tamanho do ada, aceita qualquer tamanho
                {
                  strcpy(testoOk, testeInternoCh); // aceita a string digitada e coloca na var testeOK
                }
                else { if(c==(strlen(testeInternoCh))) // compara se o tado digitado tem o tamanho requerido
                        {
                            strcpy(testoOk, testeInternoCh); // aceita a string digitada e coloca na var testeOK
                            for(j=0; j <= comprimento;j++){  // zera teste interno
                            testeInternoCh[j]='\0';
                            }
                        }
                        else{ // caso o tamanho do dado seja diferente do requerido, solicita nova digitação
                                gotoxy(x,y);
                                printf("\x1b[31m\033[1;103m NUMERO INVALIDO ");
                                tecla=0;
                                gotoxy(x,y);
                                tecla=getch();
                                fflush(stdin);
                                if(tecla!=0)
                                printf("\033[1m\033[31m\033[1;107m                             ");
                                goto rec;
                               }
                }
                                resultX=1;
            }
          }
        }
        while(resultX==0);
    }


    void testeData2(int x, int y){ // verifica se a data esta corretamente digitada

    int tamData;
    char dia[2];
    char mes[3];
    char ano[5];
    int diaN = 0;
    int mesN = 0;
    int anoN = 0;

 iniXX:     for(j=0; j < strlen(testoOk);j++){ // zera testeok antes - caso haja sujeira de codigo
            testoOk[j]='\0';
            }
            for(j=0; j < strlen(dia);j++){ // zera testeok antes - caso haja sujeira de codigo
            dia[j]='\0';
            }
            for(j=0; j < strlen(mes);j++){ // zera testeok antes - caso haja sujeira de codigo
            mes[j]='\0';
            }
            for(j=0; j < strlen(ano);j++){ // zera testeok antes - caso haja sujeira de codigo
            ano[j]='\0';
            }
            diaN=0;
            mesN=0;
            anoN=0;

            for(j=0; j < strlen(testoOk);j++){ // zera testeok antes - caso haja sujeira de codigo
            testoOk[j]='\0';
            }
            testaSohNumeros(x,y,8); // testa se sao somente numeros e o comprimentoda string deve ser de 8
            tamData = strlen(testoOk);

            if(tamData!=8)  // se tamanho da string for diferente de 8, solicita nova digitação
            {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m DATA INVALIDA DDMMAAAA! -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                              ");
                goto iniXX;
            }
            else{ // se tamanho da string for igual a 8 e forem soh numeros aceita o dado
                dia[0] = testoOk[0];
                dia[1] = testoOk[1];
                mes[0] = testoOk[2];
                mes[1] = testoOk[3];
                ano[0] = testoOk[4];
                ano[1] = testoOk[5];
                ano[2] = testoOk[6];
                ano[3] = testoOk[7];
                anoN = atoi(ano);
                mesN = atoi(mes);
                diaN = atoi(dia);
                gotoxy(x,y);
                printf("%c%c / %c%c / %c%c%c%c", testoOk[0],testoOk[1],testoOk[2],testoOk[3],testoOk[4],testoOk[5],testoOk[6],testoOk[7]); // printa a data
                if((diaN>31)||(mesN>12)||(anoN>2021)||(anoN<1900)) // verifica de os dados de data estao corretos, caso contrario solicita nova digitação
                {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m DATA INVALIDA DDMMAAAA! -                          ");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                           ");
                goto iniXX;
                }
    }}

    void testaData(int x, int y){
    int tamData;
    char dia[10];
    char mes[20];
    char ano[20];
    int diaN = 0;
    int mesN = 0;
    int anoN = 0;
    char idadeCH[50];
    char idadeFormatada[50];
      ini:  for(j=0; j < strlen(testoOk);j++){ // zera testeok antes - caso haja sujeira de codigo
            testoOk[j]='\0';
            }
            for(j=0; j < strlen(dia);j++){ // zera testeok antes - caso haja sujeira de codigo
            dia[j]='\0';
            }
            for(j=0; j < strlen(mes);j++){ // zera testeok antes - caso haja sujeira de codigo
            mes[j]='\0';
            }
            for(j=0; j < strlen(ano);j++){ // zera testeok antes - caso haja sujeira de codigo
            ano[j]='\0';
            }
            diaN=0;
            mesN=0;
            anoN=0;
            testaSohNumeros(x,y,8); // testa se sao somente numeros e o comprimentoda string deve ser de 8
            tamData = strlen(testoOk);
            if(tamData!=8) // se tamanho da string for diferente de 8, solicita nova digitação
            {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m DATA INVALIDA DDMMAAAA! -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                              ");
                goto ini;
            }
            else{ // se tamanho da string for igual a 8 e forem soh numeros aceita o dado
                gotoxy(x,y);
                printf("%c%c / %c%c / %c%c%c%c", testoOk[0],testoOk[1],testoOk[2],testoOk[3],testoOk[4],testoOk[5],testoOk[6],testoOk[7]);// printa a data

                gotoxy(x,21);
                diaN=0;
                mesN=0;
                anoN=0;
                dia[0] = testoOk[0];
                dia[1] = testoOk[1];
                diaN = atoi(dia);
                mes[0] = testoOk[2];
                mes[1] = testoOk[3];
                mesN = atoi(mes);
                ano[0] = testoOk[4];
                ano[1] = testoOk[5];
                ano[2] = testoOk[6];
                ano[3] = testoOk[7];
                anoN = atoi(ano);
                if((diaN>31)||(mesN>12)||(anoN>2021)||(anoN<1900)) // verifica de os dados de data estao corretos, caso contrario solicita nova digitação
                {
                gotoxy(x,y);
                printf("\x1b[31m\033[1;103m DATA INVALIDA DDMMAAAA! -   Digite qualquer tecla para continuar....");
                tecla=0;
                gotoxy(x,y);
                tecla=getch();
                fflush(stdin);
                if(tecla!=0)
                printf("\033[1m\033[31m\033[1;107m                                                                           ");
                goto ini;
                }
               anoN = anoReal - anoN;  // começa calcular data de aniversario
               mesN = mesReal - mesN;
               diaN = diaReal - diaN;
               if(mesN<0)
                idade = anoN-1;
               if(mesN>0)
                 idade = anoN;
               if(mesN==0)
               {
                   if(diaN>=0)
                    idade = anoN;
                   else
                    idade = anoN-1;
               }                      // termina calcular Data de nascimento
                gotoxy(68,21);
                printf("Idade: %d anos ",idade);// imprime o resultado
                P.idade = idade;

                if(idade>65) // verifica se idade maior que 65,
                    P.risco=2; //  se sim - Pasiente de risco
                   else
                    P.risco=1; // se nao - Nao é Pasiente de risco
            }
    }

