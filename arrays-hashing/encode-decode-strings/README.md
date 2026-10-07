# Encode and Decode Strings

**Problem:** [NeetCode – Encode and Decode Strings](https://neetcode.io/problems/string-encode-and-decode/question)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

Encode each string as `length@content` and concatenate the encoded pieces. Decode by reading the length up to `@`, then reading exactly that many bytes of content.

Example:

```text
["hello", "a@b", ""] -> "5@hello3@a@b0@" -> ["hello", "a@b", ""]
```

The length makes the content boundaries unambiguous, even when a string contains digits or `@`. Empty strings are encoded as `0@`; an empty list is encoded as an empty string.

## Decoding indices

- `i` points to the start of the length.
- `j` moves forward to the separator, so multi-digit lengths work.
- `s.substr(i, j - i)` extracts the length text.
- `stoul(...)` converts that text to an unsigned integer.
- The content starts at `j + 1` and has `length` bytes.
- The next length starts at `j + 1 + length`.

## C++ notes

- `strs` is a `vector<string>`; `s` is one string, while `s.size()` is its length in bytes.
- `to_string(number)` converts a number to a string.
- `append(text)` appends a string, and `push_back('@')` appends one character.
- Single quotes represent a character (`'@'`); double quotes represent a string literal (`"@"`).
- `substr(position, count)` returns a substring without changing the original string.
- `size_t` is an unsigned type used for sizes and indices.

## Complexity and assumptions

**Time:** O(m + n) for both encoding and decoding under the problem's bounded string lengths.  
**Space:** O(m + n), including the encoded string or decoded output.

Here, `m` is the total input content length and `n` is the number of strings. The decoder assumes valid input from the matching encoder. No network implementation is required. This format stores byte lengths, so it preserves the original string bytes.
