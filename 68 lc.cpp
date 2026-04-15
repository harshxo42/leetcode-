#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            // Determine how many words to put in current line
            vector<string> lineWords;
            int lineLength = 0;
            
            while (i < words.size()) {
                // Check if adding next word would exceed maxWidth
                // Need at least 1 space between words
                if (!lineWords.empty()) {
                    if (lineLength + 1 + words[i].length() <= maxWidth) {
                        lineWords.push_back(words[i]);
                        lineLength += 1 + words[i].length();
                        i++;
                    } else {
                        break;
                    }
                } else {
                    // First word in line
                    if (words[i].length() <= maxWidth) {
                        lineWords.push_back(words[i]);
                        lineLength = words[i].length();
                        i++;
                    } else {
                        break;
                    }
                }
            }
            
            // Now justify the current line
            int numWords = lineWords.size();
            int totalChars = 0;
            for (const string& word : lineWords) {
                totalChars += word.length();
            }
            int totalSpacesNeeded = maxWidth - totalChars;
            
            if (i == words.size() || numWords == 1) {
                // Last line or single word line (left-justified)
                string line = lineWords[0];
                for (int j = 1; j < numWords; j++) {
                    line += " " + lineWords[j];
                }
                line += string(totalSpacesNeeded - (numWords - 1), ' ');
                result.push_back(line);
            } else {
                // Fully justify line
                int spacesBetween = totalSpacesNeeded / (numWords - 1);
                int extraSpaces = totalSpacesNeeded % (numWords - 1);
                
                string line;
                for (int j = 0; j < numWords - 1; j++) {
                    line += lineWords[j];
                    // Add spaces
                    int spaces = spacesBetween + (j < extraSpaces ? 1 : 0);
                    line += string(spaces, ' ');
                }
                line += lineWords[numWords - 1];  // Add last word
                result.push_back(line);
            }
        }
        
        return result;
    }
};
