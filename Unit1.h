//---------------------------------------------------------------------------

#ifndef Unit1h
#define Unit1h
#include <vcl.h>
typedef double elem_type;
typedef DynamicArray<elem_type> vec;
typedef DynamicArray<DynamicArray<elem_type> > Matr;

enum cases {
	good,
	open_error,
	false_func_st,
	false_data,
	alloc_error,
};
struct calculations {
	double cost_per_km;
	double fixed_price;
	double q;
	double coeff_y;
	double summ_l;
	double time;
	double v_min;
	double v_max;
	double step;
	double rub_k_ton;
	double rub_k_t_km;
	vec coeff_b;
};

void calc_cost(calculations* calc, vec& Vmass, Matr& calc_mass);
cases file_loading(String file, calculations* data);
cases save_file(String file, calculations* data);
//---------------------------------------------------------------------------
#endif
