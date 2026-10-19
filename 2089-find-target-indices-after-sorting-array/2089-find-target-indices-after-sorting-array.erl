
-spec target_indices(Nums :: [integer()], Target :: integer()) -> [integer()].
target_indices(Nums, Target) ->
    Sorted = lists:sort(Nums),
    find_indices(Sorted, Target, 0, []).

find_indices([], _Target, _Index, Acc) ->
    lists:reverse(Acc);
find_indices([X | Rest], Target, Index, Acc) ->
    case X of
        Target ->
            find_indices(Rest, Target, Index + 1, [Index | Acc]);
        _ when X > Target ->
            lists:reverse(Acc);
        _ ->
            find_indices(Rest, Target, Index + 1, Acc)
    end.
