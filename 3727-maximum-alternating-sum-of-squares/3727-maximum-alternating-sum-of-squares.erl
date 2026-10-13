
-spec max_alternating_sum(Nums :: [integer()]) -> integer().
max_alternating_sum(Nums) ->
    Squares = lists:sort([X * X || X <- Nums]),
    Arr = array:from_list(Squares),
    calculate(Arr, 0, array:size(Arr) - 1, 0).

calculate(_Arr, Left, Right, Sum) when Left > Right ->
    Sum;
calculate(Arr, Left, Right, Sum) when Left =:= Right ->
    Sum + array:get(Left, Arr);
calculate(Arr, Left, Right, Sum) ->
    Smallest = array:get(Left, Arr),
    Largest = array:get(Right, Arr),
    calculate(Arr, Left + 1, Right - 1, Sum + Largest - Smallest).
