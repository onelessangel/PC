Stroe Teodora - 311CA

# First Blood

## 1. NINEL

Se verifica daca exista copaci 'speciali'.

In cazul in care sunt mai mult de 2 copaci:
- se citesc primii 3 copaci;
- se verifica daca copacul din mijloc e 'special' si se updateaza valoarea lui xmax_impar.
   
Daca sunt mai mult de 3 copaci:
- se citeste in continuare, pe rand, cate un copac;
- se verifica daca a mai aparut un copac 'special'.

Se afiseaza valorile cerute.

## 2. VECTSECV

Luam o valoare **x** pe care o implementam cu **n**.

**x** ia valoarea diferentei dintre **nr_descrescator** si **nr_crescator**.

Aceasta prima diferenta este bagata intr-un vector **v**.

Se realizeaza scaderi pana cand secventa cautata incepe sa se repete.
- Fiecare valoare a diferentelor este bagat in vector.
- Cand se realizeaza o scadere al carei rezultat a mai aparut o data, este retinuta pozitia primei aparitii a diferentei acesteia.
    	
*) **nr_crescator** se formeaza astfel:
- se formeaza un vector care contine cifrele nr. x
- se sorteaza crescator vectorul, utilizand algoritmul *bubble_sort*
- se formeaza numarul format din cifrele lui n, dar ordonate crescator
    	
*) **nr_descrescator** se formeaza astfel:
- se formeaza un vector care contine cifrele nr. x
- se sorteaza crescator vectorul, utilizand algoritmul *bubble_sort*
- se formeaza numarul format din cifrele lui n, dar ordonate crescator
    
Se afiseaza valorile cerute.
    
## 3. CODEINVIM

Se introduc intr-o matrice 2 x n, valorile introduse de la tastatura:
- pe prima linie: notele x_i
- pe a doua linie: creditele c_i

Se parcurge matricea coloana cu coloana, calculand media actuala a lui Mihai si, in cazul in care nota nu este 10, se calculeaza cu cat ar putea creste media o eventuala nota de 10 la respectiva materie. Aceste valori se introduc in vectorul crestere_posibila.
    
In cazul in care toate notele au fost de 10, este imposibila cresterea mediei, deci se afiseaza valoarea "-1".
    
In cazul in care media poate fi imbunatatita:
- Vectorul crestere_posibila este sortat crescator.
- Cat timp vectorul mai are valori nenule in el (mai exista eventuale cresteri care se pot adauga la media actuala):
    - la media actuala se adauga cate o valoare din coada vectorului
    - casuta corespunzatoare din vector este umpluta cu 0
    - se verifica daca noua media actuala este mai mare sau egala cu punctajul minim cerut. Daca da, atunci s-a gasit solutia si se iese din functia repetitiva.
    	
Se afiseaza valoarea ceruta.
    	
## 4. NONOGRAM

Se citeste matricea si se verifica liniile si coloanele, afisand mesajul corespunzator.
