-spec generate_parenthesis(N :: integer()) -> [string()].

generate_parenthesis(N) ->
    generate("", 0, 0, N).

generate(Current, Open, Close, N) ->
    case length(Current) of
        Len when Len == 2 * N ->
            [list_to_binary(Current)];

        _ ->
            OpenResults =
                case Open < N of
                    true ->
                        generate(Current ++ "(", Open + 1, Close, N);
                    false ->
                        []
                end,

            CloseResults =
                case Close < Open of
                    true ->
                        generate(Current ++ ")", Open, Close + 1, N);
                    false ->
                        []
                end,

            OpenResults ++ CloseResults
    end.