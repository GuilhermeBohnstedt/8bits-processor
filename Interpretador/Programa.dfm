object Form1: TForm1
  Left = 205
  Top = 187
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Cloud Code Assembler'
  ClientHeight = 429
  ClientWidth = 672
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object txtCodigo: TMemo
    Left = 0
    Top = 0
    Width = 673
    Height = 449
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    object Arquivo1: TMenuItem
      Caption = 'Arquivo'
      object Salvar1: TMenuItem
        Caption = 'Abrir'
        ShortCut = 16463
        OnClick = Salvar1Click
      end
      object Salvar2: TMenuItem
        Caption = 'Salvar'
        ShortCut = 16467
        OnClick = Salvar2Click
      end
      object Fechar1: TMenuItem
        Caption = 'Fechar'
      end
    end
    object Projeto1: TMenuItem
      Caption = 'Projeto'
      object Montar1: TMenuItem
        Caption = 'Montar'
        ShortCut = 120
        OnClick = Montar1Click
      end
      object Gravar1: TMenuItem
        Caption = 'Gravar'
        ShortCut = 121
        OnClick = Gravar1Click
      end
    end
    object Ajuda1: TMenuItem
      Caption = 'Ajuda'
      object Sobre1: TMenuItem
        Caption = 'Sobre'
        ShortCut = 122
        OnClick = Sobre1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.txt'
    Filter = 'Arquivos do Code Cloud|*.txt'
    Left = 32
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.txt'
    Filter = 'Arquivos do Cloud Code|*.txt'
    Left = 64
  end
end
