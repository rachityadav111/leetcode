-spec longest_valid_parentheses(S :: string()) -> integer().

longest_valid_parentheses(S) ->
    String = binary_to_list(S),
    solve(String, 0, [-1], 0).


solve([], _Index, _Stack, Answer) ->
    Answer;

solve([Char | Rest], Index, Stack, Answer) ->

    case Char of

        $( ->
            % Push index of '('
            solve(
                Rest,
                Index + 1,
                [Index | Stack],
                Answer
            );

        $) ->
            case Stack of

                [_Top | Remaining] ->

                    case Remaining of

                        [] ->
                            % No matching '('.
                            % Current ')' becomes new boundary.
                            solve(
                                Rest,
                                Index + 1,
                                [Index],
                                Answer
                            );

                        [Last | _] ->
                            NewAnswer = max(
                                Answer,
                                Index - Last
                            ),

                            solve(
                                Rest,
                                Index + 1,
                                Remaining,
                                NewAnswer
                            )
                    end;

                [] ->
                    solve(
                        Rest,
                        Index + 1,
                        [Index],
                        Answer
                    )
            end
    end.