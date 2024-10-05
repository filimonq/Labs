% 1 - Реактор, запущенный в Марте - это либо DD реактор, либо реактор, построенный во Франции.
condition1(Solution) :-
    (member(reactor(mar, _, dd, Сountry), Solution), Сountry \= france) ;
    
    (member(reactor(mar, _, Pr, france), Solution), Pr \= dd).

% 2 - Реактор Comati DX5 был запущен НЕ в Январе.
condition2(Solution) :-
    member(reactor(Month, comati, _, _), Solution), Month \= jan.

% 3 - Реактор, запущенный в Марте, TP реактор и реактор в Замбии - это три разных реактора.
condition3(Solution) :-
    (member(reactor(mar, _, Pr1, Country1), Solution), Pr1 \= tp, Country1 \= zambia),

    (member(reactor(Month2, _, tp, Country2), Solution), Month2 \= mar, Country2 \= zambia),

    (member(reactor(Month3, _, Pr3, zambia), Solution), Month3 \= mar, Pr3 \= tp).

% 4 - Реактор, запущенный в Январе - это либо TP реактор, либо реактор из Катара.
condition4(Solution) :- 
    (member(reactor(jan, _, tp, Country), Solution), Country \= qatar) ;
    
    (member(reactor(jan, _, Pr, qatar), Solution), Pr \= tp).

% 5 - Из двух реакторов, TP реактор и реактор, запущенный в Феврале, один - это Comati DX5, а другой из Эквадора.
condition5(Solution) :-
    (member(reactor(Month1, comati, tp, Country1), Solution),
    member(reactor(feb, Name1, Pr1, ecuador), Solution),
    Month1 \= feb, Country1 \= ecuador, Name1 \= comati, Pr1 \= tp);
    
    (member(reactor(feb, comati, Pr2, Country2), Solution),
    member(reactor(Month2, Name2, tp, ecuador), Solution),
    Pr2 \= tp, Country2 \= ecuador, Month2 \= feb, Name2 \= comati).

% 6 - Реактор Tamura BX12 построен в Замбии.
condition6(Solution) :-
  (member(reactor(_, tamura, _, zambia), Solution)).
                
% 7 - Реактор, запущенный в Апреле, Adtina V и fusor-реактор - это три разных реактора.
condition7(Solution) :-
    (member(reactor(apr, Name1, Pr1, _), Solution), Pr1 \= fusor, Name1 \= adtina),

    (member(reactor(Month2, adtina, Pr2,  _), Solution), Month2 \= apr, Pr2 \= fusor),

    (member(reactor(Month3, Name3, fusor, _), Solution), Month3 \= apr, Name3 \= adtina).

% 8 - Реактор из Катара - это либо реактор, запущенный в Марте, либо Dynotis X1.
condition8(Solution) :-
    (member(reactor(mar, Name1, _, qatar), Solution), Name1 \= dynotis) ;
    
    (member(reactor(Month2, dynotis, _, france), Solution), Month2 \= mar).



sol(S) :-
    Solution = [
        reactor(jan, JanName, JanPrinciple, JanCountry),
        reactor(feb, FebName, FebPrinciple, FebCountry),
        reactor(mar, MarName, MarPrinciple, MarCountry),
        reactor(apr, AprName, AprPrinciple, AprCountry)
    ],

    S = [
        jan-JanName-JanPrinciple-JanCountry,
        feb-FebName-FebPrinciple-FebCountry,
        mar-MarName-MarPrinciple-MarCountry,
        apr-AprName-AprPrinciple-AprCountry
    ],

    permutation([dynotis, comati, adtina, tamura], [JanName, FebName, MarName, AprName]),

    permutation([tp, fusor, dd, poly], [JanPrinciple, FebPrinciple, MarPrinciple, AprPrinciple]),

    permutation([qatar, ecuador, zambia, france], [JanCountry, FebCountry, MarCountry, AprCountry]),

	condition1(Solution),
	condition2(Solution),
	condition3(Solution),
	condition4(Solution),
	condition5(Solution),
	condition6(Solution),
	condition7(Solution),
	condition8(Solution).
