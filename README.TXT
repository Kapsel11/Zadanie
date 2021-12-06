Úloha

V programovacom jazyku C++ napíšte konzolovú aplikáciu pre operačný systém Windows, ktorá si ako vstupný parameter vypýta cestu k lokálnemu textovému súboru a jej výstupom bude textový súbor v rovnakom adresári a s rovnakým názvom ako vstupný súbor avšak s príponou ".out".

Vstupný súbor má nasledovný formát:
A1-B1,A2-B2,A3-B3,...,An-Bn
X1,Y1
X2,Y2
...
Xk,Yk

Pričom Ai, Bi, Xi, Yi sú ľubovoľné reťazce obsahujúce len veľké a malé písmená bez diskritiky a číslice.
Tieto reťazce predstavujú názvy miest (napr. Zilina, Bratislava35, bRnO4W3A, 42, a pod.)

Prvý riadok vstupného súboru obsahuje čiarkou oddelené dvojice miest odelených znakom "-" (mínus), medzi ktorými existuje priama cesta.
Druhý a ďalšie riadky predstavujú dvojice miest (Xi,Yi) odelených čiarkou, pre ktoré chceme zistiť, či je možné sa dostať z mesta Xi do mesta Yi, t.j. či medzi nimi existuje nejaká (aj nepriama) cesta.

Výstupný súbor má formát:
Z1
Z2
...
Zk

pričom Zi je rovné "Yes", ak existuje spojenie medzi Xi a Yi, inak je rovné "No".

Príklad:

Vstupný súbor:
Google-Amazon,51X-Google,Amazon-Hello4,3X-Bingo,Hello4-A
Amazon,51X
Bingo,Google
Google,Hello4
A-3X

Výstupný súbor:
Yes
No
Yes
No

Pozn. 1: Môžte predpokladať, že formát vstupného súboru je správny, t.j. aplikácia ho nemusí kontrolovať.
Pozn. 2: Pri implementáciu je povolené použiť knižnicu STL (std), ktorá je štandardnou súčasťou jazyka C++.