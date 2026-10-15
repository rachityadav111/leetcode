
-spec sum_counts(Nums :: [integer()]) -> integer().
sum_counts(Nums) ->
    sum_subarrays(Nums, 0).

sum_subarrays([], Sum) ->
    Sum;
sum_subarrays([_ | Rest] = Nums, Sum) ->
    sum_subarrays(Rest, Sum + count_from(Nums, #{}, 0)).

count_from([], _Seen, Sum) ->
    Sum;
count_from([X | Rest], Seen, Sum) ->
    NewSeen = Seen#{X => true},
    DistinctCount = map_size(NewSeen),
    count_from(Rest, NewSeen, Sum + DistinctCount * DistinctCount).
