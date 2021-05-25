object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 500
  ClientWidth = 722
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 505
    Top = 440
    Width = 75
    Height = 23
    Caption = 'Open'
    TabOrder = 0
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 32
    Top = 24
    Width = 145
    Height = 21
    Hint = 'Criteria for finding free seats'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnChange = ComboBox1Change
  end
  object Button2: TButton
    Left = 102
    Top = 91
    Width = 75
    Height = 25
    Caption = 'Show'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 474
    Top = 8
    Width = 239
    Height = 426
    TabOrder = 3
  end
  object Edit1: TEdit
    Left = 32
    Top = 170
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object Button3: TButton
    Left = 32
    Top = 213
    Width = 75
    Height = 25
    Caption = 'Show flights'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 360
    Top = 384
    Width = 89
    Height = 25
    Caption = 'Show timetable'
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 505
    Top = 469
    Width = 75
    Height = 25
    Caption = 'Edit'
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 608
    Top = 440
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 8
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 608
    Top = 471
    Width = 75
    Height = 25
    Caption = 'Sort'
    TabOrder = 9
    OnClick = Button7Click
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 24
    Top = 432
  end
  object FileSaveDialog1: TFileSaveDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 104
    Top = 432
  end
end
