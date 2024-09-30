% Реактор, запущенный в Марте - это либо DD реактор, либо реактор, построенный во Франции.
cond1(Solution) :-
    ( member(reactor(mar, _, dd, Country), Solution), Country \= france );
    ( member(reactor(mar, _, Principle, france), Solution), Principle \= dd ).

% Реактор Comati DX5 был запущен НЕ в Январе.
cond2(Solution) :-
    member(reactor(Month, comati, _, _), Solution),
    Month \= jan.

% Реактор, запущенный в Марте, TP реактор и реактор в Замбии - это три разных реактора.
cond3(Solution) :-
    member(reactor(Month1, _, tp, Country1), Solution),
    Month1 \= mar, Country1 \= zambia,

    member(reactor(mar, _, Principle2, Country2), Solution),
    Principle2 \= tp, Country2 \= zambia,

    member(reactor(Month3, _, Principle3, zambia), Solution),
    Month3 \= mar, Principle3 \= tp.

% Реактор, запущенный в Январе - это либо TP реактор, либо реактор из Катара.
cond4(Solution) :-
    (member(reactor(jan, _, tp, Country), Solution), Country \= qatar);
    (member(reactor(jan, _, Principle, qatar), Solution), Principle \= tp).

% Из двух реакторов, TP реактор и реактор, запущенный в Феврале, один - это Comati DX5, а другой из Эквадора.
cond5(Solution) :-
    (member(reactor(Month1, comati, tp, Country1), Solution),
    member(reactor(feb, Name1, Principle1, ecuador), Solution),
    Month1 \= feb,
    Name1 \= comati,
    Principle1 \= tp,
    Country1 \= ecuador);

    (member(reactor(feb, comati, Principle2, Country2), Solution),
    member(reactor(Month2, Name2, tp, ecuador), Solution),
    Month2 \= feb,
    Name2 \= comati,
    Principle2 \= tp,
    Country2 \= ecuador).

% Реактор Tamura BX12 построен в Замбии.
cond6(Solution) :-
    member(reactor(_, tamura, _, zambia), Solution).

% Реактор, запущенный в Апреле, Adtina V и fusor-реактор - это три разных реактора.
cond7(Solution) :-
    member(reactor(Month1, Name1, fusor, _), Solution),
    Month1 \= apr, Name1 \= adtina,

    member(reactor(apr, Name2, Principle2, _), Solution),
    Principle2 \= fusor, Name2 \= adtina,

    member(reactor(Month3, adtina, Principle3, _), Solution),
    Month3 \= apr, Principle3 \= fusor.

% Реактор из Катара - это либо реактор, запущенный в Марте, либо Dynotis X1.
cond8(Solution) :-
    (member(reactor(mar, Name, _, qatar), Solution), Name \= dynotis);
    (member(reactor(Month, dynotis, _, qatar), Solution), Month \= mar).

sol(S) :-

    % Определяем возможные параметры для каждого реактора
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

    cond1(Solution),
    cond2(Solution),
    cond3(Solution),
    cond4(Solution),
    cond5(Solution),
    cond6(Solution),
    cond7(Solution),
    cond8(Solution).

