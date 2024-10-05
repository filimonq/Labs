/*
 * Family relations.
 */

parent('Pamela', 'Robert' ). % Pamela is a parent of Robert
parent('Tom',    'Robert' ). % As do Tom
parent('Tom',    'Jessica'). % Tom also is Jessica's parent
parent('Robert', 'Ann'    ). % Robert parented two persons,
parent('Robert', 'Kate'   ). % who are Ann and Kate
parent('Kate',   'Joseph' ). % Kate is Joseph's parent

% Tom, Robert and Joseph are men
male('Tom').
male('Robert').
male('Joseph').

% Pamela, Jessica, Ann and Kate are women
female('Pamela').
female('Jessica').
female('Ann').
female('Kate').

grandparent(Gp, Gc) :- % Gp is a grandparent of Gc
    parent(Gp, C),parent(C, Gc).
grandchild(Gc, Gp) :- % Gc is a grandchild of Gp
    parent(P, Gc),parent(Gp, P).

mother(M, Ch) :- parent(M, Ch), female(M). % Mother is a female parent
father(F, Ch) :- parent(F, Ch), male(F).   % Father is a male parent

sister(Sis, Sib) :- % Sister is a female person who has the same parent
    parent(P, Sis), parent(P, Sib), female(Sis), dif(Sis, Sib).
brother(Br, Sb) :- % Brother is a male person who has the same parent
    parent(P, Br), parent(P, Sb), male(Br), dif(Br, Sb).

aunt(A, N) :- % Aunt is a sister of a parent
    parent(P, N), sister(A, P).

% Recursive definition of an ancestor relation
ancestor(An, Dc) :- parent(An, Dc).
ancestor(An, Dc) :- parent(An, P), ancestor(P, Dc).
