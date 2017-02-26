format date.txt:

s t sinc  // s=nr de stari, t=nr de tranzitii, sinc=sincronizat(0/1)

0 0 -1 1  //matrice t x s
-1 0 2 0  //<-  iei 1 jeton din p1 si pui 2 in p3 
1 0 0 -1  //<- iei 1 jeton din p4 si pui 1 in p1
1 0 -2 0 //<- iei 2 jetoane din p3 si pui 1 jeton in p1

0 0 0 0  //pui matricea asta doar daca e sincronizata
0 0 1 0  //m(i,j)=1 daca tranzitiile i si j sunt sincronizate pe acelasi eveniment
0 1 0 0  //<- tranzitia 3 este sincronizata cu 2 pe acelasi eveniment
0 0 0 0

1 1 0 0 //marcaj initial



//daca e sincronizata si ai stari din care poti face mai multe tranzitii
//daca una dintre ele e sincronizata pe 'e' le elimini pe restul
//programul nu prioritizeaza 'e' pentru ca e idiot
//mi-a fost lene sa programez asta :)