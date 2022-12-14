//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
void calc_cost(calculations* calc, vec& Vmass, Matr& calc_mass) {

	int count_vt = 1;
	int i = calc->v_min;

	do {
		i += calc->step;
		count_vt++;
	} while (i < calc->v_max);

	try {
		Vmass.Length = count_vt;
	}
	catch (...) {
		calc_mass.Length = 0;
		Vmass.Length = 0;
		return;
	}

	try {
		calc_mass.Length = count_vt;
		for (int i = 0; i < Vmass.Length; i++)
			calc_mass[i].Length = calc->coeff_b.Length;
	}
	catch (...) {
		return;
	}
	double V = calc->v_min;
	i = 0;

	while (Vmass.Length != i) {
		if (V > calc->v_max) {
			Vmass[i] = calc->v_max;
			break;
		}
		Vmass[i] = V;
		V += calc->step;
		i++;
	}

	for (i = 0; i < Vmass.Length; i++) {
		for (int j = 0; j < calc->coeff_b.Length; j++) {
			double TranspTime = calc->time + calc->summ_l / (Vmass[i] * calc->coeff_b[j]);
			calc_mass[i][j] = calc->cost_per_km * Vmass[i] /
				(calc->q * calc->coeff_y * calc->coeff_b[j])
				+ calc->fixed_price * TranspTime / (calc->q * calc->coeff_y)
				+ (calc->rub_k_ton + calc->rub_k_t_km * calc->summ_l) * 1.27;
		}
	}
}

cases file_loading(String file, calculations* data) {
	if (file.Trim().IsEmpty())
		return false_func_st;
	fstream file;
	file.open(AnsiString(file).c_str(), std::ios_base::in | std::ios_base::binary);
	if (!file.is_open())
		return open_error;
	int L;
	file.read((char*)&L, sizeof(int));

	file.seekg(0, std::ios::end);
	int pos = file.tellg();
	int NumbersByte = (int)pos - sizeof(int);
	int ArrayByte = 11 * sizeof(elem_type) + L * sizeof(elem_type);
	if (NumbersByte != ArrayByte) {
		file.close();
		return false_data;
	}
	try {
		(data->coeff_b).Length = L;
	}
	catch (...) {
		file.close();
		return alloc_error;
	}
	file.clear();
	file.seekg(sizeof(int));
	file.read((char*)&(data->cost_per_km), sizeof(elem_type));
	file.read((char*)&(data->fixed_price), sizeof(elem_type));
	file.read((char*)&(data->q), sizeof(elem_type));
	file.read((char*)&(data->coeff_y), sizeof(elem_type));
	file.read((char*)&(data->summ_l), sizeof(elem_type));
	file.read((char*)&(data->time), sizeof(elem_type));
	file.read((char*)&(data->v_min), sizeof(elem_type));
	file.read((char*)&(data->v_max), sizeof(elem_type));
	file.read((char*)&(data->step), sizeof(elem_type));
	file.read((char*)&(data->rub_k_ton), sizeof(elem_type));
	file.read((char*)&(data->rub_k_t_km), sizeof(elem_type));
	if (L)
		file.read((char*)&(data->coeff_b[0]), L * sizeof(elem_type));

	file.close();
	return good;
}

cases save_file(String file, calculations* data) {
	if (file.IsEmpty())
		return false_func_st;
	fstream file;
	file.open(AnsiString(file).c_str(), std::ios_base::out | std::ios_base::binary);
	if (!file.is_open())
		return open_error;

	int L = (data->coeff_b).Length;
	file.write((char*)&L, sizeof(int));

	file.write((char*)&(data->cost_per_km), sizeof(elem_type));
	file.write((char*)&(data->fixed_price), sizeof(elem_type));
	file.write((char*)&(data->q), sizeof(elem_type));
	file.write((char*)&(data->coeff_y), sizeof(elem_type));
	file.write((char*)&(data->summ_l), sizeof(elem_type));
	file.write((char*)&(data->time), sizeof(elem_type));
	file.write((char*)&(data->v_min), sizeof(elem_type));
	file.write((char*)&(data->v_max), sizeof(elem_type));
	file.write((char*)&(data->step), sizeof(elem_type));
	file.write((char*)&(data->rub_k_ton), sizeof(elem_type));
	file.write((char*)&(data->rub_k_t_km), sizeof(elem_type));
	if (L)
		file.write((char*)&((data->coeff_b)[0]), L * sizeof(elem_type));
	file.close();
	return good;
}
