//---------------------------------------------------------------------------

#ifndef ProgramaH
#define ProgramaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *txtCodigo;
        TMainMenu *MainMenu1;
        TMenuItem *Arquivo1;
        TMenuItem *Salvar1;
        TMenuItem *Salvar2;
        TMenuItem *Fechar1;
        TMenuItem *Projeto1;
        TMenuItem *Montar1;
        TMenuItem *Gravar1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *Ajuda1;
        TMenuItem *Sobre1;
        void __fastcall Montar1Click(TObject *Sender);
        void __fastcall Salvar1Click(TObject *Sender);
        void __fastcall Salvar2Click(TObject *Sender);
        void __fastcall Gravar1Click(TObject *Sender);
        void __fastcall Sobre1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
