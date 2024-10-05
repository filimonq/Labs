/*
 * Logical puzzle.
 *
 * Butsie is a brown cat, Cornie is a black cat, Mac is a red cat.
 * Flash, Rover and Spot are dogs. Flash is a spotted dog, Rover
 * is a red dog and Spot is a white dog. Fluffy is a black dog.
 *
 * Tom owns any pet that is either brown or black. Kate owns all
 * non-white dogs, not belonging to Tom.
 *
 * All pets Kate or Tom owns are pedigree animals.
 *
 * Alan owns Mac if Kate does not own Butsie and Spot is not a pedigree
 * animal.
 *
 * Write a Prolog program that answers, which animals do not have an owner.
*/


cat('Butsie', 'brown').
cat('Cornie', 'black').
cat('Mac', 'red').

dog('Flash', 'spotted').
dog('Rover', 'red').
dog('Spot', 'white').
dog('Fluffy', 'black').

own('Tom', X) :- cat(X, 'brown').
own('Tom', X) :- cat(X, 'black').
own('Tom', X) :- dog(X, 'brown').
own('Tom', X) :- dog(X, 'black').
own('Kate', X) :- dog(X, C), dif(C, 'white'), not(own('Tom', X)).
own('Alan', 'Mac') :- not(own('Kate', 'Butsie')), not(pedigree('Spot')).

pedigree(Y) :- own(X, Y), dif(X, 'Alan').


animal(X) :- cat(X, _); dog(X, _).
no_owner(X) :- animal(X), \+ (own(_, X)).
