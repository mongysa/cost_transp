//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *changing_pan;
	TPanel *edit_pan;
	TButton *add_col;
	TButton *del_col;
	TButton *insert_col;
	TPanel *add_option_pan;
	TLabel *font_size_l;
	TLabel *rounding_l;
	TCheckBox *auto_corr;
	TSpinEdit *rouding_b;
	TSpinEdit *font_size_b;
	TCheckBox *graph_3d_on;
	TPanel *grid;
	TStringGrid *calcul_output;
	TPanel *data;
	TPanel *chart;
	TSplitter *Splitter;
	TPanel *input;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *fixed_price;
	TEdit *rub_k_tonn;
	TEdit *time;
	TEdit *q;
	TEdit *coeff_y;
	TEdit *v_max;
	TEdit *v_min;
	TEdit *rub_k_t_km;
	TEdit *cost_per_km;
	TEdit *summ_l;
	TButton *calc;
	TEdit *v_step;
	TLabel *Label2;
	TStatusBar *StatusBar;
	TMainMenu *MainMenu;
	TMenuItem *File;
	TMenuItem *New;
	TMenuItem *Open;
	TMenuItem *Save;
	TMenuItem *SaveAs;
	TMenuItem *N1;
	TMenuItem *Exit;
	TMenuItem *Edit;
	TMenuItem *Add;
	TMenuItem *Insert;
	TMenuItem *Delete;
	TMenuItem *Result;
	TMenuItem *MenuItem1;
	TMenuItem *SaveResult;

private:
	String LastEdCell;
	float fTotalWidth;
		// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
