# Run Length Encoding and Decoding

Given a string s, implement a function encode that performs run-length encoding on the string. Run-length encoding is a form of compression where consecutive occurrences of the same character are replaced by the character followed by the count of its occurrences.

```bash
Input: s = aaaabbbccc
Output: a4b3c3
Explanation: The character 'a' repeated 4 times consecutively and 'b' 3 times, 'c' also 3 times, so answer for this test case is a4b3c3.

Input: s = abbbcdddd
Output: a1b3c1d4
Explanation:  The character 'a' is repeated 1 time, 'b' 3 times, 'c' 1 time and 'd' repeated 4 times, so answer for this test case is a1b3c1d4.
```