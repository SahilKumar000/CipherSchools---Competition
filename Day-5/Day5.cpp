
#include <iostream>
#include <vector>
using namespace std;

vector<string> Spaces(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;

    while (i < n) {
        int lt = words[i].length();
        int j = i + 1;

        while (j < n && lt + words[j].length() + (j - i) <= maxWidth) {
            lt += words[j].length();
            j++;
        }

        int nw = j - i;
        int space = maxWidth - lt;

        string line = words[i];
        int gaps = nw - 1;

        if (j == n || gaps == 0) {
            
            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }
            line += string(maxWidth - line.length(), ' ');
        } else {
            
            int spacebtw = space / gaps;
            int extspace = space % gaps;

           
            for (int k = i + 1; k < j; k++) {
                int spaces = spacebtw;
                if (extspace > 0) {
                    spaces++;
                    extspace--;
                }
                line += string(spaces, ' ') + words[k];
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {
    vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth = 16;
    vector<string> justified = Spaces(words, maxWidth);

    for (string& line : justified) {
        cout << line << endl;
    }

    return 0;
}
