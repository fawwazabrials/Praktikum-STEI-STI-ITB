/**
 * DaftarMataKuliah.java
 * Program untuk menambahkan mata kuliah sebagai administrator STEI
 * 
 * @author 18221067 Fawwaz Abrial Saffa
 */

import java.util.Scanner;
import java.lang.System;


public class DaftarMataKuliah {
	public static void main (String[] args) {
		String kode;
		String nama;
		int sks;
		String dosen;
		int kapasitas;
		int tambahan;
		
		Scanner scan = new Scanner(System.in);
		
		kode = scan.next();
		nama = scan.next();
		sks = scan.nextInt();
		dosen = scan.next();
		kapasitas = scan.nextInt();
		tambahan = scan.nextInt();
		
		scan.close();
		
		MataKuliah matkul = new MataKuliah(kode, nama, sks, dosen, kapasitas);
		
		
		System.out.println("Kode Mata Kuliah: " + matkul.getKode());
		System.out.println("Nama Mata Kuliah: " + matkul.getNama());
		System.out.println("SKS Mata Kuliah: " + matkul.getSks());
		System.out.println("Nama Dosen: " + matkul.getDosen());
		System.out.println("Kapasitas Kuliah: " + matkul.getKapasitas());
		matkul.tambahKapasitas(tambahan);
		System.out.println("Total Revisi Kapasitas Kuliah: " + matkul.getKapasitas());
		
	}
}
