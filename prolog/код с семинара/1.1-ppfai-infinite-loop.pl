/*
 * The following four predicate declarations (anc1, anc2, anc3 and anc4) are
 * declaratively equivalent, which means they have the same logical meaning.
 * But we made them having different procedurally by swapping goals and rules.
 */


parent('Pamela', 'Robert' ). % Pamela is a parent of Robert
parent('Tom',    'Robert' ). % As do Tom
parent('Tom',    'Jessica'). % Tom also is Jessica's parent
parent('Robert', 'Ann'    ). % Robert parented two persons,
parent('Robert', 'Kate'   ). % who are Ann and Kate
parent('Kate',   'Joseph' ). % Kate is Joseph's parent

% Original predicate
% Terminates always
anc1(A,D) :- parent(A,D).
anc1(A,D) :- parent(A,C), anc1(C,D).

% Swapping clauses
% Terminates always
anc2(A,D) :- parent(A,C), anc2(C,D).
anc2(A,D) :- parent(A,D).

% Swapping goals in the second clause
% If there are solutions it returns them and then loops.
% Otherwise loops indefinitely without returning anything.
anc3(A,D) :- parent(A,D).
anc3(A,D) :- anc3(C,D), parent(A,C).

% Do both swappings
% Loops indefinitely
anc4(A,D) :- anc4(C,D), parent(A,C).
anc4(A,D) :- parent(A,D).
