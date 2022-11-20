/*
Nama        : Nazhif Haidar Putra Wibowo
NIM         : 18221083
Topik       : Prapraktikum 10
Deskripsi   : Implementasi List Sirkuler
*/

# include "listsirkuler.h"
# include <stdio.h>
# include <stdlib.h>

boolean IsEmpty (List L)    {
    return First(L) == Nil;
}

void CreateEmpty (List *L)  {
    First(*L) = Nil;
}

address Alokasi (infotype X)    {
    address P = (address)malloc(1 * sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    {
        return Nil;
    }
}

void Dealokasi (address P)  {
    free(P);
}

address Search (List L, infotype X) {
	address P = First(L);
	boolean found = false;
	if (!IsEmpty(L)) {
        if (Info(P) == X)   {
            return P;
        }
        else    {
            P = Next(P);
            while ((P != First(L)) && (!found)) {
                if (Info(P) == X) {
                    found = true;
                } else {
                    P = Next(P);
                }
            }
            if (found)  {
                return P;
            }
            else    {
                return Nil;
            }
        }
	}
    else    {
        return Nil;
    }
}

void InsVFirst (List *L, infotype X)    {
    address P = Alokasi(X);
    if (P != Nil)   {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil)   {
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, infotype *X)   {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X)    {
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void InsertFirst (List *L, address P)   {
	InsertLast(L, P);
	First(*L) = P;
}

void InsertLast (List *L, address P)    {
	if (IsEmpty(*L)) {
		First(*L) = P;
		Next(P) = P;
	} else {
		address PL = First(*L);
		while (Next(PL) != First(*L)) {
			PL = Next(PL);
		}
		Next(PL) = P;
		Next(P) = First(*L);
	}
}

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
    
    //Next(P) = Next(Prec);
    //Next(Prec) = P;
}

void DelFirst (List *L, address *P)     {
	*P = First(*L);
	//
	if (Next(*P) == *P) {
		First(*L) = Nil;
	} else {
		address last = First(*L);
		while (Next(last) != First(*L)) {
			last = Next(last);
		}
		First(*L) = Next(First(*L));
		Next(last) = First(*L);
	}
}

void DelLast (List *L, address *P)  {
	if (Next(First(*L)) == First(*L)) {
		*P = First(*L);
		First(*L) = Nil;
	} else {
		address Preclast = First(*L);
		while (Next(Next(Preclast)) != First(*L)) {
			Preclast = Next(Preclast);
		}
		*P = Next(Preclast);
		Next(Preclast) = First(*L);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)    {
    *Pdel = Next(Prec);
    if (Next(Prec) == Prec)  {
        First(*L) = Nil;
    }
    else if (Next(Prec) == First(*L))    {
        DelFirst(L, Pdel);
    }
    else   
    {
        Next(Prec) = Next(Next(Prec));
    }
}

void DelP (List *L, infotype X) {
    /*
    address Prec;
    address P;
    boolean bFound = false;

    if (!IsEmpty(*L))
    {
        if (X == Info(First(*L)))
        {
            DelFirst(L, &P);
            Dealokasi(P);
        }
        else
        {
            P = First(*L);
            while (!bFound && (Next(P) != First(*L)))
            {
                if (Info(P) == X)
                {
                    bFound = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (bFound)
            {
                DelAfter(L, &P, Prec);
                Dealokasi(P);
            }
        }
    }
    */

    address P = Search(*L, X);
    if (P != Nil) {
        address P2 = First(*L);
        while (Next(P2) != P) {
            P2 = Next(P2);
        }
        DelAfter(L, &P, P2);
        Dealokasi(P);
    }
}

void PrintInfo (List L)     {
    address p;
    p = First(L);
    if (IsEmpty(L))   {
        printf("[]");
    }
    else    {
        printf("[");
        while (Next(p) != First(L))    {
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d", Info(p));
        printf("]");
    }
}