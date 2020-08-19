A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________--

class Solution {
public:
    int isVowel(char t)
    {
        if(t == 'a' || t == 'o' || t =='i' || t =='u' || t=='e' || t =='A' || t == 'E' || t =='O' || t =='I' || t=='U')
            return 1;
        
        return 0;
    }
    string toGoatLatin(string S) {
        
        string s="";
        int len =0;
        string a = "a";
        vector <string> A;
        if(S.length() == 0)
            return "";
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == ' ' && s != "")
              A.push_back(s) , s="";
            else
                s=s+S[i];
        }
        
        if(s != "")
            A.push_back(s);
        
       s ="";
        for(int i=0;i<A.size();i++)
        {
            string B = A[i];
            
            if(isVowel(B[0]))
            {
                B = B + "ma" + a;
            }
            
            else
            {
                char t = B[0];
                B.erase(B.begin());
                B = B + t;
                B = B + "ma" + a;
            }
            
            a = a + "a";
            s = s + " " + B;
        }
        
        s.erase(s.begin());
        return s;
        
        
    }
};
