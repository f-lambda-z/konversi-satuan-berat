#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

unordered_map<string, unordered_map<string, double>> konversi_tabel = {
  {"kg", {{"hg", 10}, {"dag", 100}, {"g", 1000}, {"dg", 10000}, {"cg", 100000}, {"mg", 1000000}}},
  {"hg", {{"kg", 0.1}, {"dag", 10}, {"g", 100}, {"dg", 1000}, {"cg", 10000}, {"mg", 100000}}},
  {"dag", {{"kg", 0.01}, {"hg", 0.1}, {"g", 10}, {"dg", 100}, {"cg", 1000}, {"mg", 10000}}},
  {"g", {{"kg", 0.001}, {"hg", 0.01}, {"dag", 0.1}, {"dg", 10}, {"cg", 100}, {"mg", 1000}}},
  {"dg", {{"kg", 0.0001}, {"hg", 0.001}, {"dag", 0.01}, {"g", 0.1}, {"cg", 10}, {"mg", 100}}},
  {"cg", {{"kg", 0.00001}, {"hg", 0.0001}, {"dag", 0.001}, {"g", 0.01}, {"dg", 0.1}, {"mg", 10}}},
  {"mg", {{"kg", 0.000001}, {"hg", 0.00001}, {"dag", 0.0001}, {"g", 0.001}, {"dg", 0.01}, {"cg", 0.1}}},
};

double konversi_berat(double berat, string satuan_awal, string satuan_akhir) {
  if (konversi_tabel.find(satuan_awal) == konversi_tabel.end() || 
      konversi_tabel.find(satuan_akhir) == konversi_tabel.end()) {
    throw invalid_argument("Satuan tidak valid.");
  }

  return berat * konversi_tabel[satuan_awal][satuan_akhir];
}

int main() {
  double berat;
  string satuan_awal, satuan_akhir;

  cout << "Masukkan berat (hanya angka): ";
  cin >> berat;

  cout << "Masukkan satuan (kg, hg, dag, g, dg, cg, mg): ";
  cin >> satuan_awal;

  transform(satuan_awal.begin(), satuan_awal.end(), satuan_awal.begin(), ::tolower);

  cout << "Konversi ke (kg, hg, dag, g, dg, cg, mg): ";
  cin >> satuan_akhir;

  transform(satuan_akhir.begin(), satuan_akhir.end(), satuan_akhir.begin(), ::tolower);

  double hasil_konversi = konversi_berat(berat, satuan_awal, satuan_akhir);

  cout << "Hasil: " << fixed << setprecision(2) << hasil_konversi << " " << satuan_akhir << endl;

  return 0;
}
