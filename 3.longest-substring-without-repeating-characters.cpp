#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<windows.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool isUnique;
        int n = s.length();
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for(int j = (i+1); j <= n; j++){
                 isUnique = allUnique(s, i, j);
                 if (isUnique) {
                     maxLength = max((j-i), maxLength);
                 }
            }
        }
        return maxLength;
    }

    bool allUnique(string s, int start, int end) {
        unordered_set<char> set;
        for (start; start < end; start++) {
            if (set.find(s[start]) == set.end()) {
                set.insert(s[start]);
            }else {
                return false;
            }
        }
        return true;
    }
};

class OptimizedSolution{
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLength = 0;
        unordered_set<char> set;
        while(i < n && j < n) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                j = j + 1;
                maxLength = max((j-i), maxLength);
            }else {
                set.erase(s[i]);
                i = i + 1;
            }
        }
        return maxLength;
    }
};

class SuperOptimizedSolution{
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];    //记录字符最后出现的位置
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        int n = s.size();
        int left = 0;     //查找的左边界
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (hash[s[i]] < 0 || hash[s[i]] < left){
                maxLength = max(maxLength, (i-left+1));
            }else {
                left = hash[s[i]] + 1;
            }
            hash[s[i]] = i;
        }
        return maxLength;
    }
};

void test1(string s) {
    Solution so;
    int maxLength = so.lengthOfLongestSubstring(s);
    cout << "string: " << s << endl;
    cout << "length of logest substring: " << maxLength << endl;
}

void test2(string s) {
    OptimizedSolution so;
    int maxLength = so.lengthOfLongestSubstring(s);
    cout << "string: " << s << endl;
    cout << "length of logest substring: " << maxLength << endl;
}

void test3(string s) {
    SuperOptimizedSolution so;
    int maxLength = so.lengthOfLongestSubstring(s);
    cout << "string: " << s << endl;
    cout << "length of logest substring: " << maxLength << endl;
}

int main() {
    string s[10];
    s[0] = "abcabcbb";
    s[1] = "bbbbb";
    s[2] = "pwwkew";
    s[3] = "";
    s[4] = " ";
    s[5] = "Cjy9VhcjZnNSDL0jTfCUjTi1EDTOi5mXWbHRg5LV83Zfy8N9gE3MyQLJMS4PLg5ZHs74xbUZBOQqXumhZWroKEbGiovpfO7YCirYcH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2y";
    s[6] = "sdfdffsahjytddnkdfgejfakjdbaniwueniquadkjhflksjdhvbvudajvbriuijqkjelkajvoiuanlincalkjmncbviCjy9VhcjZnNSDL0jTfCUjTi1EDTOi5mXWbHRg5LV83Zfy8N9gE3MyQLJMS4PLg5ZHs74xbUZBOQqXumhZWroKEbGiovpfO7YCirYcH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2yerqapdfbpbjlfvbhiudlkajfviuqjenlwqkjnvlvajnaieuwkbvkjgaiueiwM0yb1UO6tKLJPqESgLWQEJ39Nrt5IMiQmPCptrwWuiwSy8oKEDW5gojnL73qBAj99d9Yk8yxxkWCr9TpWRNdrawddtu0y3TkbdiOktqaogycuEKjQ50o5Hb4Umg94vPf8hkGg5i1X5nEg0cdAjF4JmzUYXwylEJ4";
    s[7] = "M0yb1UO6tKLJPqESgLWQEJ39Nrt5IMiQmPCptrwWuiwSy8oKEDW5gojnL73qBAj99d9Yk8yxxkWCr9TpWRNdrawddtu0y3TkbdiOktqaogycuEKyJhzHj4jrvYfewLVry9A1AY71gTWfWphoAtLfubpC75OOjuN6Ch3bcOcSw3KfbQljpZdKqzZmPeyIFUIko1aeKu24J1n04dEm7lem6zSAHwbXy4Oqjbvi3G7oNbv9YVHoc1RpdIxMhEukpUSkxzCUfEB6TB5cVTI4nYExboMwxHyTp3UXM39qJdf3AsBGYeZB6KsuE7jjQ50o5Hb4Umg94vPf8hkGg5i1X5nEg0cdAjF4JmzUYXwylEJ4";
    s[8] = "yJhzHj4jrvYfewLVry9A1AY71gTWfWphoAtLfubpC75OOjuN6Ch3bcOcSw3KfbQljpZdKcH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTsdfdffsahjytddnkdfgejfakjdbaniwueniquadkjhflksjdhvbvudajvbriuijqkjelkajvoiuanlincalkjmncbviCjy9VhcjZnNSDL0jTfCUjTi1EDTOi5mXWbHRg5LV83Zfy8N9gE3MyQLJMS4PLg5ZHs74xbUZBOQqXumhZWroKEbGiovpfO7YCirYcH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2yerqapdfbpbjlfvbhiudlkajfviuqjenlwqkjnvlvajnaieuwkbvkjgaiueiwM0yb1UO6tKLJPqESgLWQEJ39Nrt5IMiQmPCptrwWuiwSy8oKEDW5gojnL73qBAj99d9Yk8yxxkWCr9TpWRNdrawddtu0y3TkbdiOktqaogycuEKjQ50o5Hb4Umg94vPf8hkGg5i1X5nEg0cdAjF4JmzUYXwylEJ4Fo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2yqzZmPeyIFUIko1aeKu24J1n04dEm7lem6zSAHwbXy4Oqjbvi3G7oNbv9YVHoc1RpdIxMhEukpUSkxzCUfEB6TB5cVTI4nYExboMwxHyTp3UXM39qJdf3AsBGYeZB6KsuE7j";
    s[9] = "cH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTsdfdffsahjytddnkdfgejfakjdbaniwueniquadkjhflksjdhvbvudajvbriuijqkjelkajvoiuanlincalkjmncbviCjy9VhcjZnNSDL0jTfCUjTi1EDTOi5mXWbHRg5LV83Zfy8N9gE3MyQLJMS4PLg5ZHs74xbUZBOQqXumhZWroKEbGiovpfO7YCirYcH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2ycH21oyL6sBcrToAKkxmJXxcQEuDRwzonxQPGN65RGBy4n0p8Ci8EkfIeJoUaZsqu2OjCLPOgsvTFo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2yerqapdfbpbjlfvbhiudlkajfviuqjenlwqkjnvlvajnaieuwkbvkjgaiueiwM0yb1UO6tKLJPqESgLWQEJ39Nrt5IMiQmPCptrwWuiwSy8oKEDW5gojnL73qBAj99d9Yk8yxxkWCr9TpWRNdrawddtu0y3TkbdiOktqaogycuEKjQ50o5Hb4Umg94vPf8hkGg5i1X5nEg0cdAjF4JmzUYXwylEJ4Fo8mv0MNJ5UoUe5nAhTHMgTI9Y9fmRY090B6Kg5E0rKjzDJ09n4nMT7E8KCLqD2Wb1VzQz5gAngwlFhpoc3d6xa4wq3HeAODXJeoKqR7YDRrfJt2WLz7hTUFjoF2y";

    DWORD start;
    DWORD end;

    start = GetTickCount();
    for (int i = 0; i < 10; i++) {
        test1(s[i]);
    }
    end = GetTickCount();
    cout << "normal solution " << "time: " << (end - start) << "ms" << endl << endl;

    start = GetTickCount();
    for (int i = 0; i < 10; i++) {
        test2(s[i]);
    }
    end = GetTickCount();
    end = GetTickCount();
    cout << "optimized solution " << "time: " << (end - start) << "ms" << endl << endl;

    start = GetTickCount();
    for (int i = 0; i < 10; i++) {
        test3(s[i]);
    }
    end = GetTickCount();
    end = GetTickCount();
    cout << "super optimized solution " << "time: " << (end - start) << "ms" << endl;

    cout << "press enter to continue" << endl;
    cin.get();

    return 0;
}