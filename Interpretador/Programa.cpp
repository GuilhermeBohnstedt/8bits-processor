//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Programa.h"
#include "iostream.h"
#include "fstream.h"
#include "iomanip.h"
#include "stdio.h"
#include "stdlib.h"
#include "gravador.h"
#include "sobre.h"
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
unsigned char inst[3];//variavel que guardará a instrução
bool Error;
bool variavel=false;
unsigned char v=0;
ifstream txtFile2;//Abre o arquivo para a entrada de dados
char c;//variavel do caracter

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int convert(char c){
  switch(c){
      case '0': return 0; break;
      case '1': return 1; break;
      case '2': return 2; break;
      case '3': return 3; break;
      case '4': return 4; break;
      case '5': return 5; break;
      case '6': return 6; break;
      case '7': return 7; break;
      case '8': return 8; break;
      case '9': return 9; break;
  }
}
//---------------------------------------------------------------------------
bool VerificaInst(void){
bool verifica=false;
if((inst[0]=='a')&&(inst[1]=='d')&&(inst[2]=='c')){
        verifica=true;
        return true;
        }
if((inst[0]=='s')&&(inst[1]=='u')&&(inst[2]=='b')){
        verifica=true;
        return true;
        }
if((inst[0]=='m')&&(inst[1]=='u')&&(inst[2]=='l')){
        verifica=true;
        return true;
        }
if((inst[0]=='d')&&(inst[1]=='i')&&(inst[2]=='v')){
        verifica=true;
        return true;
        }
if((inst[0]=='a')&&(inst[1]=='n')&&(inst[2]=='d')){
        verifica=true;
        return true;
        }
if((inst[0]=='o')&&(inst[1]=='u')&&(inst[2]=='.')){
        verifica=true;
        return true;
        }
if((inst[0]=='n')&&(inst[1]=='a')&&(inst[2]=='o')){
        verifica=true;
        return true;
        }
if((inst[0]=='s')&&(inst[1]=='i')&&(inst[2]=='m')){
        verifica=true;
        return true;
        }
if(verifica==false){//Verifica se a instrução existe ou nao
        return false;
        }
}
//--------------------------------------------------------------------------
//Verifica a instrução e executa os parametros
void instruction(void){

//Abre o arquivo onde será gravado o conteudo em binario
ofstream txtBinario;
txtBinario.open("CodBin.txt", ios::app);

char bin[8]; // guardara o valor em binario
int numero;

if((inst[0]=='a')&&(inst[1]=='d')&&(inst[2]=='c')){
        if(variavel==true){
           txtFile2.get(c);

           numero=v;//Valor do acumulador
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";//Número em binario tradicional

           txtBinario << "00000001\n";//Código da instrução

           numero=convert(c);//Valor a ser operacionado.
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";

           v=v+convert(c);
           txtBinario << "00100000\n";//Botão de igual
           txtBinario << "01000000\n";//Botão de resete
           txtFile2.get(c);
           txtFile2.get(c);
        }else{
           Application->MessageBox("Você tentou utilizar uma instrução operacional sem declarar variável!","Erro 003", MB_OK);
           Error=true;
        }
}
if((inst[0]=='s')&&(inst[1]=='u')&&(inst[2]=='b')){
        if(variavel==true){
           txtFile2.get(c);


           numero=v;//Valor do acumulador
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";//Número em binario tradicional

           txtBinario << "00000010\n";//Código da instrução

           numero=convert(c);//Valor a ser operacionado.
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";

           v=v-convert(c);
           txtBinario << "00100000\n";//Botão de igual
           txtBinario << "01000000\n";//Botão de reset
           txtFile2.get(c);
           txtFile2.get(c);
        }else{
           Application->MessageBox("Você tentou utilizar uma instrução operacional sem declarar variável!","Erro 003", MB_OK);
           Error=true;
        }
}
if((inst[0]=='m')&&(inst[1]=='u')&&(inst[2]=='l')){
        if(variavel==true){
           txtFile2.get(c);

           numero=v;//Valor do acumulador
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";//Número em binario tradicional

           txtBinario << "00000100\n";//Código da instrução

           numero=convert(c);//Valor a ser operacionado.
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";

           v=v*convert(c);
           txtBinario << "00100000\n";//Botão de igual
           txtBinario << "01000000\n";//Botão de reset
           txtFile2.get(c);
           txtFile2.get(c);
        }else{
           Application->MessageBox("Você tentou utilizar uma instrução operacional sem declarar variável!","Erro 003", MB_OK);
           Error=true;
        }
}
if((inst[0]=='d')&&(inst[1]=='i')&&(inst[2]=='v')){
        if(variavel==true){
           txtFile2.get(c);
           if(c=='0'){
              Application->MessageBox("Divisão por 0!","Erro 004", MB_OK);
           }else{

           numero=v;//Valor do acumulador
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";//Número em binario tradicional

           txtBinario << "00001000\n";//Código da instrução

           numero=convert(c);//Valor a ser operacionado.
           itoa(numero,bin,2);//Converte para base dois o numero da operação
           txtBinario << bin;
           txtBinario << "\n";

           v=v/convert(c);
           txtBinario << "00100000\n";//Botão de igual
           txtBinario << "01000000\n";//Botão de reset
           txtFile2.get(c);
           txtFile2.get(c);
           }
        }else{
           Application->MessageBox("Você tentou utilizar uma instrução operacional sem declarar variável!","Erro 003", MB_OK);
           Error=true;
        }
}
if((inst[0]=='a')&&(inst[1]=='n')&&(inst[2]=='d')){
        txtFile2.get(c);
           if((c<48) || (c>=52)){
              Application->MessageBox("Operação lógica inválida","Erro 005", MB_OK);
              Error=true;
           }else{

              numero=c;//Valor a ser operacionado.
             if(c=='0'){
                txtBinario << "00000000\n";
                txtBinario << "00010100\n";//Código da instrução
                txtBinario << "00000000\n";
             }else if(c=='1'){
                txtBinario << "00000001\n";
                txtBinario << "00010100\n";//Código da instrução
                txtBinario << "00000000\n";
             }else if(c=='2'){
                txtBinario << "00000000\n";
                txtBinario << "00010100\n";//Código da instrução
                txtBinario << "00000001\n";
             }else if(c=='3'){
                txtBinario << "00000001\n";
                txtBinario << "00010100\n";//Código da instrução
                txtBinario << "00000001\n";
              }
              txtBinario << "00100000\n";//Botão de igual
              txtBinario << "01000000\n";//Botão de reset
           }
           txtFile2.get(c);
           txtFile2.get(c);
}
if((inst[0]=='o')&&(inst[1]=='u')&&(inst[2]=='.')){
        txtFile2.get(c);
           if((c<48) || (c>=52)){
              Application->MessageBox("Operação lógica inválida","Erro 005", MB_OK);
              Error=true;
           }else{

              numero=c;//Valor a ser operacionado.
             if(c=='0'){
                txtBinario << "00000000\n";
                txtBinario << "00011000\n";//Código da instrução
                txtBinario << "00000000\n";
             }else if(c=='1'){
                txtBinario << "00000001\n";
                txtBinario << "00011000\n";//Código da instrução
                txtBinario << "00000000\n";
             }else if(c=='2'){
                txtBinario << "00000000\n";
                txtBinario << "00011000\n";//Código da instrução
                txtBinario << "00000001\n";
             }else if(c=='3'){
                txtBinario << "00000001\n";
                txtBinario << "00011000\n";//Código da instrução
                txtBinario << "00000001\n";
              }
              txtBinario << "00100000\n";//Botão de igual
              txtBinario << "01000000\n";//Botão de reset
           }
           txtFile2.get(c);
           txtFile2.get(c);
}
if((inst[0]=='n')&&(inst[1]=='a')&&(inst[2]=='o')){
           txtFile2.get(c);
           if((c<48) || (c>=50)){
              Application->MessageBox("Operação lógica inválida","Erro 005", MB_OK);
              Error=true;
           }else{
              numero=c;//Valor a ser operacionado.
              if(c=='0'){
                 txtBinario << "00000000\n";
                 txtBinario << "00010010\n";//Código da instrução
                 txtBinario << "00000000\n";
              }else if(c=='1'){
                 txtBinario << "00000001\n";
                 txtBinario << "00010010\n";//Código da instrução
                 txtBinario << "00000000\n";
              }
              txtBinario << "00100000\n";//Botão de igual
              txtBinario << "01000000\n";//Botão de reset
           }
           txtFile2.get(c);
           txtFile2.get(c);
}
if((inst[0]=='s')&&(inst[1]=='i')&&(inst[2]=='m')){
           txtFile2.get(c);
           if((c<48) || (c>=50)){
              Application->MessageBox("Operação lógica inválida","Erro 005", MB_OK);
              Error=true;
           }else{

              numero=c;//Valor a ser operacionado.
              if(c=='0'){
                 txtBinario << "00000000\n";
                 txtBinario << "00010001\n";//Binário da instrução
                 txtBinario << "00000000\n";
              }else if(c=='1'){
                 txtBinario << "00000001\n";
                 txtBinario << "00010001\n";//Binário da instrução
                 txtBinario << "00000000\n";
              }
              txtBinario << "00100000\n";//Botão de igual
              txtBinario << "01000000\n";//Botão de reset
           }
           txtFile2.get(c);
           txtFile2.get(c);
}

txtBinario.close();

}
//--------------------------------------------------------------------------
void __fastcall TForm1::Montar1Click(TObject *Sender)
{
//Gera o Arquivo com o programa
ofstream txtFile;
txtFile.open("txtFile.txt");
txtFile << txtCodigo->Lines->GetText();
txtFile.close();
// Le o arquivo gerado para processar as informações
txtFile2.open("txtFile.txt");
char i=0;
int continst=0;
Error=false;
while(txtFile2.get(c)){
        while(i!=3){//Guarda a instrução
           inst[i]=c;
           if(c!=' '){
                i++;
           }
           txtFile2.get(c);
        }
        continst++;
        i=0;
        if((inst[0]=='v')&&(inst[1]=='a')&&(inst[2]=='r')){
            variavel=true;
            txtFile2.get(c);
            goto Fim;
        }
        if(!VerificaInst()){
            Application->MessageBox("Instrução não reconhecida!","Erro 001", MB_OK);
            Error=true;
            goto Fim;
        }
        if( c != ' '){
            Application->MessageBox("Espaço não encontrado depois da instrução!","Erro 002", MB_OK);
            Error=true;
            goto Fim;
        }
        instruction();
        Fim:
        if(Error){
            break;
        }
}
txtFile2.close();
if(c=='\0'){
       Application->MessageBox("Arquivo em branco!","Erro 000", MB_OK);
}else{
     if(Error){
          char *mensagem; //Variavel que guardará a mensagem de erro
          char buff[3];//Varivel auxiliar
          itoa(continst,buff,10);//Converte para a base 10 o char
          mensagem=strcat("Montagem concluída com erro na instrução ",buff);
          Application->MessageBox(mensagem, "Fim", MB_OK);
     }else{
          Application->MessageBox("Montagem concluída!","Fim", MB_OK);
     }
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Salvar1Click(TObject *Sender)
{
   if(OpenDialog1->Execute()){
     txtCodigo->Lines->LoadFromFile(OpenDialog1->FileName);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Salvar2Click(TObject *Sender)
{
    if(SaveDialog1->Execute()){
        txtCodigo->Lines->SaveToFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Gravar1Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Sobre1Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------

