class Solution {
public:

    string s;
    int i;

    set<string> expression() {

        set<string> result = term();

        while (i < s.size() && s[i] == ',') {

            i++;

            set<string> next = term();

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> term() {

        set<string> result = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> next;

            if (s[i] == '{') {

                i++;

                next = expression();

                i++;
            }
            else {

                next.insert(string(1, s[i]));

                i++;
            }

            set<string> temp;

            for (const string& a : result) {
                for (const string& b : next) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string exp) {

        s = exp;
        i = 0;

        set<string> result = expression();

        return vector<string>(
            result.begin(),
            result.end()
        );
    }
};