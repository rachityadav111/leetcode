
-spec sum_counts(Nums :: [integer()]) -> integer().
sum_counts(Nums) ->
    Mod = 1000000007,
    N = length(Nums),
    Size = 4 * N + 5,
    Sums = atomics:new(Size, []),
    Squares = atomics:new(Size, []),
    Lazy = atomics:new(Size, []),
    process_nums(Nums, 0, N, #{}, Sums, Squares, Lazy, 0, Mod).

process_nums([], _I, _N, _Last, _Sums, _Squares, _Lazy, Ans, _Mod) ->
    Ans;
process_nums([X | Rest], I, N, Last, Sums, Squares, Lazy, Ans, Mod) ->
    Prev = maps:get(X, Last, -1),
    update(Sums, Squares, Lazy, 1, 0, N - 1,
           Prev + 1, I, Mod),
    SqSum = atomics:get(Squares, 1),
    NewAns = (Ans + SqSum) rem Mod,
    process_nums(Rest, I + 1, N, maps:put(X, I, Last),
                 Sums, Squares, Lazy, NewAns, Mod).

apply_add(Sums, Squares, Lazy, Node, L, R, V, Mod) ->
    S = atomics:get(Sums, Node),
    Q = atomics:get(Squares, Node),
    Len = R - L + 1,
    NewS = (S + V * Len) rem Mod,
    NewQ = (Q + 2 * V * S + V * V * Len) rem Mod,
    atomics:put(Sums, Node, NewS),
    atomics:put(Squares, Node, NewQ),
    atomics:put(Lazy, Node, atomics:get(Lazy, Node) + V).

push(_Sums, _Squares, _Lazy, _Node, L, R, _Mod) when L >= R ->
    ok;
push(Sums, Squares, Lazy, Node, L, R, Mod) ->
    V = atomics:get(Lazy, Node),
    case V of
        0 ->
            ok;
        _ ->
            Mid = (L + R) div 2,
            apply_add(Sums, Squares, Lazy, Node * 2,
                      L, Mid, V, Mod),
            apply_add(Sums, Squares, Lazy, Node * 2 + 1,
                      Mid + 1, R, V, Mod),
            atomics:put(Lazy, Node, 0)
    end.

update(_Sums, _Squares, _Lazy, _Node, L, R, QL, QR, _Mod)
  when QR < L; R < QL ->
    ok;
update(Sums, Squares, Lazy, Node, L, R, QL, QR, Mod)
  when QL =< L, R =< QR ->
    apply_add(Sums, Squares, Lazy, Node, L, R, 1, Mod);
update(Sums, Squares, Lazy, Node, L, R, QL, QR, Mod) ->
    push(Sums, Squares, Lazy, Node, L, R, Mod),
    Mid = (L + R) div 2,
    update(Sums, Squares, Lazy, Node * 2, L, Mid, QL, QR, Mod),
    update(Sums, Squares, Lazy, Node * 2 + 1,
           Mid + 1, R, QL, QR, Mod),
    S1 = atomics:get(Sums, Node * 2),
    S2 = atomics:get(Sums, Node * 2 + 1),
    Q1 = atomics:get(Squares, Node * 2),
    Q2 = atomics:get(Squares, Node * 2 + 1),
    atomics:put(Sums, Node, (S1 + S2) rem Mod),
    atomics:put(Squares, Node, (Q1 + Q2) rem Mod).
