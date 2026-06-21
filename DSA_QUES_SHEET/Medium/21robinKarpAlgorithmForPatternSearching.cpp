class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        int m = pattern.size();
        int n = text.size();
        vector<int> result;

        const int prime = 101;
        const int base = 256;

        int patternHash = 0, textHash = 0, h = 1;

        // Compute h = (base^(m-1)) % prime
        for (int i = 0; i < m - 1; ++i)
            h = (h * base) % prime;

        // Compute initial hash values for pattern and text
        for (int i = 0; i < m; ++i) {
            patternHash = (patternHash * base + pattern[i]) % prime;
            textHash = (textHash * base + text[i]) % prime;
        }

        // Slide pattern over text
        for (int i = 0; i <= n - m; ++i) {
            if (patternHash == textHash) {
                // Verify the match
                if (text.substr(i, m) == pattern)
                    result.push_back(i + 1); // Store 1-based index
            }

            // Compute hash for next window
            if (i < n - m) {
                textHash = (textHash - text[i] * h) % prime;
                textHash = (textHash * base + text[i + m]) % prime;

                // Ensure textHash is positive
                if (textHash < 0)
                    textHash += prime;
            }
        }

        return result;
    }
};
