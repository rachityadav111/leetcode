defmodule Solution do
  @spec longest_valid_parentheses(String.t()) :: integer()
  def longest_valid_parentheses(s) do
    chars = String.to_charlist(s)

    solve(chars, 0, [-1], 0)
  end

  defp solve([], _i, _stack, ans) do
    ans
  end

  defp solve([char | rest], i, stack, ans) do
    if char == ?( do
      solve(rest, i + 1, [i | stack], ans)
    else

      case stack do
        [_top | remaining] ->
          case remaining do
            [] ->
              solve(rest, i + 1, [i], ans)

            [last | _] ->
              new_ans = max(ans, i - last)

              solve(rest, i + 1, remaining, new_ans)
          end

        [] ->
          solve(rest, i + 1, [i], ans)
      end
    end
  end
end