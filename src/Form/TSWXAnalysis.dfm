object Analysis: TAnalysis
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'Analysis'
  ClientHeight = 370
  ClientWidth = 560
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    560
    370)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupAnalysis: TGroupBox
    Left = 8
    Top = 8
    Width = 537
    Height = 354
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Analysis'
    TabOrder = 1
    DesignSize = (
      537
      354)
    object m_analyze: TLabel
      Left = 16
      Top = 24
      Width = 160
      Height = 13
      Caption = 'Click analyze to identify the fields'
    end
    object m_status: TLabel
      Left = 16
      Top = 80
      Width = 72
      Height = 13
      Caption = 'Status analysis'
    end
    object m_SearchNodes: TLabel
      Left = 16
      Top = 128
      Width = 69
      Height = 13
      Caption = 'Search nodes:'
      Color = clBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Visible = False
    end
    object m_FileAnalysis: TLabel
      Left = 16
      Top = 109
      Width = 66
      Height = 13
      Caption = 'Files analysis:'
      Color = clBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Visible = False
    end
    object m_countFiles: TLabel
      Left = 132
      Top = 109
      Width = 3
      Height = 13
      Color = clBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object m_quantNodes: TLabel
      Left = 132
      Top = 128
      Width = 3
      Height = 13
      Color = clBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object m_grid: TStringGrid
      Left = 16
      Top = 147
      Width = 505
      Height = 182
      Anchors = [akLeft, akTop, akRight, akBottom]
      ColCount = 3
      DefaultColWidth = 100
      RowCount = 2
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSizing, goColSizing, goEditing]
      PopupMenu = PopupMenu1
      TabOrder = 0
      OnKeyDown = m_gridKeyDown
      OnSetEditText = m_gridSetEditText
      ColWidths = (
        67
        166
        204)
    end
  end
  object m_progress: TProgressBar
    Left = 24
    Top = 51
    Width = 505
    Height = 25
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    Visible = False
  end
  object PopupMenu1: TPopupMenu
    Left = 232
    Top = 88
    object Insertline1: TMenuItem
      Action = actionInsert
      Caption = 'Insert line'
      ShortCut = 16429
    end
    object Removeline1: TMenuItem
      Action = actionRemove
      Caption = 'Remove line'
      ShortCut = 16430
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Clearitens1: TMenuItem
      Action = actionClear
      Caption = 'Clear lines'
      ShortCut = 16460
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Cut1: TMenuItem
      Action = actionCut
      Caption = 'Cut'
      ShortCut = 16472
    end
    object Copy1: TMenuItem
      Action = actionCopy
      Caption = 'Copy'
      ShortCut = 16451
    end
    object Paste1: TMenuItem
      Action = actionPaste
      Caption = 'Paste'
      ShortCut = 16470
    end
  end
  object ActionList1: TActionList
    Left = 304
    Top = 88
    object actionClear: TAction
      OnExecute = actionClearExecute
    end
    object actionRemove: TAction
      OnExecute = actionRemoveExecute
    end
    object actionInsert: TAction
      OnExecute = actionInsertExecute
    end
    object actionCopy: TAction
      OnExecute = actionCopyExecute
    end
    object actionPaste: TAction
      OnExecute = actionPasteExecute
    end
    object actionCut: TAction
      OnExecute = actionCutExecute
    end
  end
end
