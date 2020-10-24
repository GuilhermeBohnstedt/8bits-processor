//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sobre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
HANDLE  hCom; // Handle para a Porta Serial (identificador).
   char *NomePorta = "COM1";  //COM1, COM2...COM9 ou portas virtuais "\\.\COMx".

   hCom = CreateFile(
                                  NomePorta,   //Nome da porta.
                                  GENERIC_READ | GENERIC_WRITE,   //Para leitura e escrita.
                                  0,       //(Zero) Nenhuma outra abertura ser� permitida.
                                  NULL,  //Atributos de seguran�a. (NULL) padr�o.
                                  OPEN_EXISTING,  //Cria��o ou abertura. 
                                  0,         //Entrada e sa�da sem overlapped.
                                  NULL     //Atributos e Flags. Deve ser NULL para COM.
                               );
}
//---------------------------------------------------------------------------

