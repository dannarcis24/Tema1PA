# CERINTA:
Simularea unui concurs sportiv pe echipe, bazat pe 5cerinte (task 1, 2, 3 ,4 ,5).
Pentru a putea rula codul este necesara utilizarea a 3fisiere, toate 3 fiind percepute ca date de intrare din terminal (2fisiere de intrare ".in" si 1fisier de iesire ".out").
>Primul fisier: contine 5numere (1/0); 1 inseamna ca se executa cerinta, iar 0 contrariul                         
>Al doilea fisier: contine informatiile despre echipa si jucatorii acesteia                               
>Al trilea fisier: rezultatele rularii                                     

# PRINCIPALELE STRUCTURI UTILIZATE:

typedef struct {    
  char *nume, *prenume;             
  int punctaj;         
} Player; 

typedef struct{                      
    char *nume_echipa;                           
    int numar_concurenti;                               
    float punctaj_echipa;                    
    PlayerList *lista_concurenti;                        
} Team;

In concurs sunt inscrise mai multe echipe, iar despre fiecare echipa se stiu: numele, numarul de jucatori ai acesteia, punctajul acumulat si lista cu jucatori. De asemenea, se cunosc informatii despre fiecare concurent in parte, precum: numele, prenumele si punctajul individual.
Acestea 2 sunt principalele 2structuri utilizate.

# FUNCTIA MAIN:
Se verifica daca datele de intrare (cele 3fisiere) sunt introduse corect (.in, .in., out).                                     
Se initializeaza cu NULL structurile necesare rezolvarii celor 5task-uri, urmand citirea numerelor din primul fisier pentru efectuarea task-urilor.                               
In final se dezaloca memoria pentru toate structurile si alocarile utilizate pe parcurs.    

# BIBLIOTECI:
> <stdio.h>, <stdlib.h>,  <string.h> incluse in "libs.h", care este inclusa in "structs.h", care este inclusa in "tasks.h", fiind inclusa in main(); in acest mod nu este necesara folosirea pragma once si nu se dubleaza functiile 
1. "tasks.h": toate apelurile pentru fiecare task (biblioteca principala, fiind cea, care le contine pe toate si este inclusa in main)
2. "structs.h": toate apelurile pentru structuri (stive, cozi, arbori binari) si declararile acestora (biblioteca specializata pentru structuri, este apelata si este inclusa in "tasks.h")
3. "libs.h": toate apelurile pentru principalele structuri (Player, Team), listele inlantuite (PlayerList, TeamList) si declararile acestora (biblioteca initiala, unde sunt incluse <stdio.h>, <stdlib.h>, <string.h>, fiind apelata in "structs.h"

# TASK 1
>Cel de-al doilea fisier este formatat astfel: pe prima linie se afla numarul de echipe, pe liniile ce urmeaza sunt informatiile legate de echipe, fiind despartite printr-un rand liber, pentru fiecare echipa este mentionat pe o linie numarul de concurenti si numele echipei, apoi numele, prenumele si punctajul fiecarui jucator pe cate o linie separata.

Pentru rezolvarea primului task s-a creat o lista inlantuita (TeamList), in care se retin echipele, la nivelul fiecarei echipe, a fost necesara crearea altei liste inlantuite (PlayerList), pentru gestionare jucatorilor. Fisierul este parcurs rand cu rand, in cadrul unui for, deorece se cunosc numarul de echipe, si se retin informatiile despre fiecare echipa in parte ca fiind un element distinct al listei inlantuite (TeamList), adaugarea facandu-se la inceput (prima echipa citita devina ultima echipa din lista, pe cand ultima echipa citita devina capul listei, la fel si in cazul jucatorilor).

!! FUNCTIILE PENTRU TASK 1 -> data.c                                      
!! FUNCTIILE PENTRU GESTIONAREA LISTELOR INLANTUITE -> lists.c                                 

Dupa finalizarea citirii, numele echipelor vor fi afisate in fisierul de iesire pe cate o linie separata, in cadrul unui for.

# TASK 2
Pentru rezolvarea celui de-al doilea task, este necesar ca numarul de echipe, care concureaza sa fie putere a lui 2.
In cazul, in care numarul de echipe este deja putere a lui 2 se va trece mai departe, altfel se vor elimina echipele, care au punctajul de echipa minim (=media aritmetica a punctajelor individuale ale jucatorilor), deci se va calcula punctajul minim, apoi se va cauta PRIMA echipa, care detine acest punctaj, in lista inlantuita (TeamList). Functia de stergere (delTeamPoints) se imparte in 3cazuri:
1. Echipa este prima in lista
2. Echipa este in interiorul listei (nu prima, dar nici ultima)
3. Echipa este ultima in lista

!! FUNCTIILE PENTRU TASK 2 -> data.c                                 
!! FUNCTIILE PENTRU GESTIONAREA LISTELOR INLANTUITE -> lists.c                                        

Dupa ce se obtine numarul de echipe cerut se vor afisa in fisierul de iesire echipele, exact ca in primul task, cate o echipa pe rand.

# TASK 3
Pentru rezolvarea celui de al treilea task, este necesara simularea meciurilor dintre echipa. Echipele vor concura 2 cate 2 (primele 2, urmatoarele 2...), in urma viictoriilor obtinute vor avea loc urmatoarele meciuri dupa aceeasi regula (primele 2, urmatoarele 2...), pana cand se decide echipa castigatoare, de asemenea este necesara retinerea echipelor, in momentul, in care ajung in ultimele 8.                   
Criteriul de alegere al echipei castigatoare al unui meci este echipa cu punctajul cel mai mare, iar daca au punctaje egale, atunci se va alege prima echipa din lista (punctaj_echipa1 => punctaj_echipa2 ->echipa1:echipa2).
De asemenea este necesara afisarea in fisierul de iesire al fiecarei runde ("ROUND NO:%d" ,format linie: "%-33s-%33s" pentru 2 echipe), dar si echipele castigatoare("WINNERS OF ROUND NO:%d", format linie: "%-34s-  %.2f" pentru cate o echipa).          
>%-nr: formatare la stanga in nr de spatii a sirului                       
>%nrs: formatare la dreapta in nr de spatii a sirului                                     

Sunt necesare implementarea unei cozi si a 2stive, acestea sunt niste liste inlantuite, care au ca element un pointer, care primeste adresa echipei din lista de echipe (TeamList), astfel nu este necesara alocarea memoriei pentru fiecare echipa introdusa intr-una din aceste structuri.

!! FUNCTIILE PENTRU TASK 3 -> problems.c                                 
!! FUNCTIILE PENTRU STIVE -> stack.c                               
!! FUNCTIILE PENTRU COADA -> queue.c                                                  
       
Initial in coada sunt introduse toate elementele listei, apoi sunt procesate 2 cate 2 echipe distincte, pentru a stabili echipele castigatoare si echipele pierzatoare ale primei runde, toate echipele vor fi introduse pe rand in cate o stiva, prima va contine echipele castigatoare, din care vor fi extrase si adaugate in coada, pentru a urmari urmatoarele runde, iar cea de a doua coada va contine echipele invinse, care doar vor fi eliminate la finalul rundei. Rundele vor continua, pana cand numarul de echipa va fi egal cu 1, deci s-a gasit echipa castigatoare.                        
Pentru a se retine primele 8echipe s-a creat o lista inlantuita (TeamList), pentru a se retine echipele cu punctajele acumulat pana-n acel moment, dar, pentru a nu incarca prea mult memoria, nume_echipa si lista_concurenti, va putea fi accesata prin intermediul listei initiale (*top8->echipa = *lista->echipa, adica nume_echipa si lista_concurenti sunt pointeri, care au acces la elementele din lista cu toate echipele, restul informatiilor fiind preluate individual, respectiv numar_concurenti, punctaj_echipa).

# TASK 4
Pentru realizarea celui de al patrulea task, este necesara crearea unui arbore binar de cautare (element_stanga < element < element_dreapta), folosind lista inlantuita salvata la task 3 (primele 8echipe).     

Se implementeaza un arbore binar, care are ca si campuri 3pointeri, unul va duce catre elementul din lista salvata de la task 3 (primele 8echipe), iar ceilalti 2pointeri vor retine adresele catre urmatoarele noduri ale arborelui (*left, *right), folosind aceasta metoda se salveaza memorie, nu este necesara alocarea unui camp de dimensiunea tipului elementului pe care il retine. Motiul, pentru care se foloseste void * este retine diferite tipuri de date, nu doar unul unic.

>Criteriul de ordonare este luat dupa punctaj (punctaj_echipa), iar in cazul, in care punctajele sunt egale, se vor folosi ordonarea dupa numele echipei (nume_echipa).

Crearea arborelui binar de cautare functioneaza dupa urmatoarele reguli:                             
1. Radacina = capul listei (prima echipa retinuta in lista)                       
2. In stanga = echipele, care sunt inferioare (punctaj mai mic || punctaje egale, atunci numele echipei mai mic)                           
3. In dreapta = echipele, care sunt superioare (punctaj mai mare || punctaje egale, atunci numele echipei mai mare), astfel se va cauta primul nod nealocat, pentru a se introduce un nod nou, dupa aceasta regula.

!! FUNCTIILE PENTRU TASK 4 -> binarytree.c                         
!! FUNCTIILE PENTRU ARBORI BINARI -> binarytree.c             

In final se vor afisa echipele si punctajul, in ordine descrescatoare, respectiv inordine din dreapta (dreapta - radacina - stanga), pastrand formatul de la task-ul 3 ("TOP 8 TEAMS:", format linie: "%-34s-  %.2f" pentru cate o echipa).      

# TASK 5
Pentru realizarea celui de al cincilea task, este necesara crearea unui arbore AVL (arbore binar de cautare echilibrat), bazat pe arborele anterior, de la task-ul 4 (BST).
>Gradul de echilibru al unui nod: inaltimea subarborelui stang - inaltimea subarborelui drept.                    
>Ca arborele sa fie echilibrat este necesar ca gradul in modul sa fie mai mic sau egal cu 1 (0 sau 1, inaltimea este un numar natural), deci daca gradul unui nod este dezechilibrat, atunci intregul arbore se va considera dezechilibrat.

Pentru a se crea noul arbore, se va crea un al doilea arbore (AVL), astfel va avea ca si element un nod din arborele de la task-ul 4 (BST).
Se pacurge arborele in inordine din dreapta (dreapta - radacina - stanga), se va introduce nodul respectiv dupa urmatoarele reguli (criteriul de la task-ul 4):
1. Radacina = capul listei (prima echipa retinuta in lista)                       
2. In stanga = echipele, care sunt inferioare (punctaj mai mic || punctaje egale, atunci numele echipei mai mic)                           
3. In dreapta = echipele, care sunt superioare (punctaj mai mare || punctaje egale, atunci numele echipei mai mare), astfel se va cauta primul nod nealocat, pentru a se introduce un nod nou, dupa aceasta regula.    
Urmatorul pas este echilibrarea, in cazul, in care este dezechilibrat, prin rotatii (dreapta, stanga, dreapta-stanga, stanga-dreapta), respectand conditiile (criteriul de la task-ul 4), in acest mod ne asiguram ca arborele este binar de cautare si echilibrat.

!! FUNCTIILE PENTRU TASK 5 -> binarytree.c                                      
!! FUNCTIILE PENTRU ARBORII AVL -> binarytree.c                                                  

In final se vor afisa numele echipeleor, aflate pe nivelul al doilea in acest arbore (AVL), in ordine descrescatoare, adica de la dreapta catre stanga ("THE LEVEL 2 TEAMS ARE:", format linie: "%s" pentru cate o echipa).
