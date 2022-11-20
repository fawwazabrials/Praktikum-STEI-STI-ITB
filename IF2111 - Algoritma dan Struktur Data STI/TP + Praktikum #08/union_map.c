/* File : union_map.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 31 Oktober 2022
    Topik praktikum     : Praktikum #08 - Set, Map dan Hashtable
    Deskripsi           : Realisasi dari union_map.h
*/

#include "union_map.h"

Map UnionMap(Map m1, Map m2, boolean key_based ) {
	// KAMUS LOKAL
	int i, j, keytemp, valtemp;
	Map m3;
	
	// ALGORITMA
	CreateEmpty(&m3);
	for (i=0; i<m1.Count;i++) {
		Insert(&m3, m1.Elements[i].Key, m1.Elements[i].Value);
	} for (i=0; i<m2.Count;i++) {
		if (!IsMember(m3, m2.Elements[i].Key)) {
			Insert(&m3, m2.Elements[i].Key, m2.Elements[i].Value);
		}
	}
	if (key_based) {
		for (i=0; i<m3.Count; i++) {
			for (j=0; j<m3.Count-1; j++) {
				if (m3.Elements[j+1].Key < m3.Elements[j].Key) {
					keytemp = m3.Elements[j+1].Key;
					valtemp = m3.Elements[j+1].Value;
					
					m3.Elements[j+1].Key = m3.Elements[j].Key;
					m3.Elements[j+1].Value = m3.Elements[j].Value;
					
					m3.Elements[j].Key = keytemp;
					m3.Elements[j].Value = valtemp;
				}
				 
			}
		}
	}
	
	else {
		for (i=0; i<m3.Count; i++) {
			for (j=0; j<m3.Count-1; j++) {
				if (m3.Elements[j+1].Value < m3.Elements[j].Value) {
					keytemp = m3.Elements[j+1].Key;
					valtemp = m3.Elements[j+1].Value;
					
					m3.Elements[j+1].Key = m3.Elements[j].Key;
					m3.Elements[j+1].Value = m3.Elements[j].Value;
					
					m3.Elements[j].Key = keytemp;
					m3.Elements[j].Value = valtemp;
				}
				 
			}
		}
	}
	return m3;
}
