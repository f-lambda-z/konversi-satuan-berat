#!/bin/python3
# -*- coding: utf-8 -*-

def konversi_berat(berat, satuan_awal, satuan_akhir):
  """
  Fungsi untuk mengonversi satuan berat.

  Args:
    berat: Nilai berat yang ingin dikonversi.
    satuan_awal: Satuan awal berat.
    satuan_akhir: Satuan akhir berat.

  Returns:
    Nilai berat setelah dikonversi.
  """

  konversi_tabel = {
    "kg": {
      "hg": 10,
      "dag": 100,
      "g": 1000,
      "dg": 10000,
      "cg": 100000,
      "mg": 1000000,
    },
    "hg": {
      "kg": 0.1,
      "dag": 10,
      "g": 100,
      "dg": 1000,
      "cg": 10000,
      "mg": 100000,
    },
    "dag": {
      "kg": 0.01,
      "hg": 0.1,
      "g": 10,
      "dg": 100,
      "cg": 1000,
      "mg": 10000,
    },
    "g": {
      "kg": 0.001,
      "hg": 0.01,
      "dag": 0.1,
      "dg": 10,
      "cg": 100,
      "mg": 1000,
    },
    "dg": {
      "kg": 0.0001,
      "hg": 0.001,
      "dag": 0.01,
      "g": 0.1,
      "cg": 10,
      "mg": 100,
    },
    "cg": {
      "kg": 0.00001,
      "hg": 0.0001,
      "dag": 0.001,
      "g": 0.01,
      "dg": 0.1,
      "mg": 10,
    },
    "mg": {
      "kg": 0.000001,
      "hg": 0.00001,
      "dag": 0.0001,
      "g": 0.001,
      "dg": 0.01,
      "cg": 0.1,
    },
  }

  if satuan_awal not in konversi_tabel or satuan_akhir not in konversi_tabel:
    raise ValueError("Satuan tidak valid.")

  return berat * konversi_tabel[satuan_awal][satuan_akhir]

berat = float(input("Masukkan berat: "))
satuan_awal = input("Masukkan satuan (kg, hg, dag, g, dg, cg, mg): ").lower()
satuan_akhir = input("Konversi ke (kg, hg, dag, g, dg, cg, mg): ").lower()
hasil_konversi = konversi_berat(berat, satuan_awal, satuan_akhir)

print(f"Hasil: {hasil_konversi:.2f} {satuan_akhir}")
